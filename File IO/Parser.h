// Created by Berk on 21.09.2017.
//

#ifndef RAYCASTER3000_PARSER_H
#define RAYCASTER3000_PARSER_H

#include <fstream>
#include <vector>
#include "../Primitives/Color.h"
#include "../Scenes/Scene.h"
#include "Basic_IO.h"
//#include "Json_components.h"

using namespace std;

class Parser : public Basic_IO{
protected:
    ios_base::openmode file_mode();
    string invalid_file_error();
public:
    Parser(char *file_path);
//    bool parse_json_to( Scene & scene ); TODO
    bool parse_txt_to( Scene & scene );
    bool add_instance_of( const string &name, const vector<double> &parameters, Scene &scene, int line_n );
};

#endif //RAYCASTER3000_PARSER_H

















