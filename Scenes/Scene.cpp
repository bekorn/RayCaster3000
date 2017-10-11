// Created by Berk on 21.09.2017.
//
# define M_PI 3.14159265358979323846

#include "Scene.h"

Scene::Scene() {};

void Scene::set_settings( const Settings &settings ) {
    this->settings = settings;
}

void Scene::set_camera( const Camera &camera ) {
    this->camera = camera;
}

bool Scene::add_modal( Modal *modal ) {
    this->modals.emplace_back( modal );
    return true;
}

bool Scene::add_point_light( PointLight *point_light ) {
    this->point_lights.emplace_back( point_light );
    return true;
}

bool Scene::add_ambient_light( AmbientLight *ambient_light ) {
    this->ambient_lights.emplace_back( ambient_light );
    return true;
}

Color** Scene::capture() {

    Color **pixels = new Color*[ this->settings.resolution_width ];
    Color *column;
    Color cell_color;

    this->ambient_color = get_ambient_color();

    this->camera.view_height = 1.0;
    this->camera.view_width = this->settings.resolution_ratio;

    double aa_margin = 1.0 / (this->settings.anti_alias * this->settings.anti_alias);
    int total_aa_rays = this->settings.anti_alias * this->settings.anti_alias;

    //  Bitmap Matrix Loop
    for( int w=0 ; w<this->settings.resolution_width ; w++ ) {
        column = new Color[ this->settings.resolution_height ];

        for( int h=0 ; h<this->settings.resolution_height ; h++ ) {
            cell_color = Color(0,0,0);

            //  Anti-Aliasing Loop
            for( int aa_w=0 ; aa_w<this->settings.anti_alias ; aa_w++ ) {
                for( int aa_h=0 ; aa_h<this->settings.anti_alias ; aa_h++ ) {

                    double view_w = ((w + (aa_w / (double)this->settings.anti_alias + aa_margin) - this->settings.resolution_width/2.0)  / this->settings.resolution_width) * this->camera.view_width;
                    double view_h = ((h + (aa_h / (double)this->settings.anti_alias + aa_margin) - this->settings.resolution_height/2.0) / this->settings.resolution_height);
                    Ray ray(
                            this->camera.position,
                            (this->camera.direction
                            + (this->camera.horizontal_direction * view_w)
                            + (this->camera.vertical_direction * view_h)
                            ).unit_vector()
                    );

                    //  Ray Bounce Loop (inside get_color)
                    cell_color += this->get_color_of( ray, this->settings.bounce_limit );
                }
            }

            column[h] = cell_color / total_aa_rays;
        }

        pixels[w] = column;
    }

    return pixels;
}

Color Scene::get_color_of( const Ray &ray, int bounces_left ) {

    Intersection *closest_intersection = closest_intersection_of( ray );

    Color color;

    if( closest_intersection == nullptr ) {
        color = this->settings.background_color;
    }
    else {
        Material *material = closest_intersection->modal->material;

        color = material->color *
                ( ( this->ambient_color )
                  + ( get_diffuse_color_of( closest_intersection->point, closest_intersection->normal ) * material->diffuse_reflectance )
                );

        if( material->specular_reflectance != 0 ) {
            color += ( get_specular_color_of( ray.direction, *closest_intersection, material->specular_reflectance ) * (material->specular_reflectance * 3.0) );
        }

        if( material->mirror_reflectance != 0 && bounces_left > 0 ) {
            color += ( get_color_of( Ray(closest_intersection->point, closest_intersection->reflection), bounces_left-1 ) * material->mirror_reflectance );
        }
        color.limit();
    }

    delete closest_intersection;

    return color;
}

Color Scene::get_ambient_color() {
    Color color( 0, 0, 0 );

    for( AmbientLight *light : this->ambient_lights ) {
        color += (light->color * light->intensity);
    }

    return color;
}

Color Scene::get_diffuse_color_of( const Vector3 &intersection_point, const Vector3 &intersection_normal ) {
    Color color( 0, 0, 0 );

    for( PointLight *light : this->point_lights ) {
        if( ! is_occluded( intersection_point, light->position ) ) {
            Vector3 light_to_intersection = (light->position - intersection_point).unit_vector();
            color += ((light->color * light->intensity) * fmax(0, intersection_normal.dot_product( light_to_intersection )) );
        }
    }

    return color;
}

Color Scene::get_specular_color_of(const Vector3 &view_direction, const Intersection &intersection, double k) {

    Color color( 0, 0, 0 );

    for( PointLight *light : this->point_lights ) {
        if( ! is_occluded( intersection.point, light->position ) ) {
            double specular_intensity = intersection.reflection.dot_product( (light->position - intersection.point).unit_vector() );
            color += (light->color * light->intensity * pow(fmax(0, specular_intensity), floor( pow(k + 1.0, 10.0))) );
        }
    }

    return color;
}



Intersection *Scene::closest_intersection_of( const Ray &ray ) {

    Intersection *closest_intersection = nullptr;
    Intersection *intersection;

    for( Modal *modal : this->modals ) {
        intersection = modal->intersect_with( ray );

        if( intersection != nullptr && (closest_intersection == nullptr || intersection->distance < closest_intersection->distance) ) {
            closest_intersection = intersection;
        }
        else {
            delete intersection;
        }
    }

    return closest_intersection;
}

bool Scene::is_occluded( const Vector3 &a, const Vector3 &b ) {

    Ray ray( a, b - a );

    for( Modal *modal : this->modals ) {

        if( modal->intersect_with( ray ) ) {
            return true;
        }
    }

    return false;
}
