// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_SCENE_H
#define RAYCASTER3000_SCENE_H

#include <vector>
#include "../Primitives/Color.h"
#include "../Cameras/Camera.h"
#include "../Modals/Modal.h"
#include "../Lights/Light.h"
#include "Settings.h"
#include "../Lights/AmbientLight.h"
#include "../Lights/PointLight.h"

using namespace std;

class Scene {
private:
    Camera camera;
    vector<AmbientLight*> ambient_lights;
    vector<PointLight*> point_lights;
    vector<Modal*> modals;

    Color ambient_color;
public:
    Settings settings;
    Scene();
    void set_settings( const Settings &settings );
    void set_camera( const Camera &camera );
    bool add_modal( Modal *modal );
    bool add_point_light( PointLight *point_light );
    bool add_ambient_light( AmbientLight *ambient_light );

    Color** capture();
    Color get_color_of( const Ray &ray, int bounces_left );
    Color get_ambient_color();
    Color get_diffuse_color_of( const Vector3 &intersection_point, const Vector3 &intersection_normal );
    Color get_specular_color_of( const Vector3 &view_direction, const Intersection &intersection, double k );

    Intersection* closest_intersection_of( const Ray &ray );
    bool is_occluded( const Vector3 &a, const Vector3 &b );
};


#endif //RAYCASTER3000_SCENE_H
