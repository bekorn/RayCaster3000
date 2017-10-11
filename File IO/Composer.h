// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_COMPOSER_H
#define RAYCASTER3000_COMPOSER_H

#include <fstream>
#include <vector>
#include "../Primitives/Color.h"
#include "../Scenes/Scene.h"
#include "Basic_IO.h"

using namespace std;

class Composer : public Basic_IO {
protected:
    ios_base::openmode file_mode() override;
    string invalid_file_error() override;
public:
    Composer( char *file_path );
    bool compose_bmp( Color *color_array[], int resolution_width, int resolution_height );
    // TODO: bool compose_json( Scene scene );
};


#endif //RAYCASTER3000_COMPOSER_H
