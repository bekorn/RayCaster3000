#include <iostream>
//#include <string>
//#include "Primitives/Vector3.h"
//#include "Primitives/Ray.h"
#include "Modals/Shapes/Shape.h"
#include "Modals/Shapes/Sphere.h"
#include "File IO/Parser.h"
#include "File IO/Composer.h"

using namespace std;

int main( int argc, char *argv[] ) {

    if( argc < 3 ) {
        cout << "Please specify [input path] [output path]";
        return 1;
    }

    Parser parser( argv[1] );
    if( ! parser.is_open() ) {
        return 1;
    };

    Scene scene = Scene();
    if( ! parser.parse_txt_to( scene ) ) {
        return 2;
    }

    Composer composer( argv[2] );
    if( ! composer.is_open() ) {
        return 1;
    }

    composer.compose_bmp( scene.capture(), scene.settings.resolution_width, scene.settings.resolution_height );

//  ANIMATION
/*
//
//    string file_path = "INPUT\\Anim1\\",
//            file_extension = ".bmp";
//
//    for( int i=0 ; i<20 ; i++ ) {
//
//        string str = file_path + to_string(i) + file_extension;
//        char * writable = new char[str.size() + 1];
//        copy(str.begin(), str.end(), writable);
//        writable[str.size()] = '\0'; // don't forget the terminating 0
//
//        Composer composer( writable );
//        composer.compose_bmp( scene.capture(), scene.resolution_width, scene.resolution_height );
//
//        scene.camera.position.z += 1;
//
//        // don't forget to free the string after finished using it
//        delete[] writable;
//    }
*/

/*
//    Ray r( Vector3(0, 0, 0), Vector3(1, 0, 0) );
//
//    Sphere s( Vector3(-1, 0, 0), Color(5, 5, 5), 1 );
//
//    Intersection * i = s.intersect_with( r );
//
//    cout << "Sphere Center: " << endl;
//    cout << "X = " << s.position.x << endl;
//    cout << "Y = " << s.position.y << endl;
//    cout << "Z = " << s.position.z << endl;
//
//    if( i != nullptr ) {
//        cout << "Minimum distance: " << i->intersection_distance << endl;
//        cout << "Intersect Normal: " << endl;
//        cout << "X = " << i->intersection_normal.x << endl;
//        cout << "Y = " << i->intersection_normal.y << endl;
//        cout << "Z = " << i->intersection_normal.z << endl;
//    }
//    else {
//        cout << "No intersection" << endl;
//    }
//
//    cout << "Distance from camera to center: " << (r.origin - s.position).length << endl;
*/

    cout << "Successful Render";
    return 0;
}