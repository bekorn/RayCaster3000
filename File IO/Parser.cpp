// Created by Berk on 21.09.2017.
//

#include <string>
#include <sstream>
#include "Parser.h"
#include "../Modals/Shapes/Sphere.h"
#include "../Modals/Shapes/Plane.h"
#include "../Modals/Shapes/Disk.h"

using namespace std;

ios_base::openmode Parser::file_mode() {
    return fstream::in;
}

string Parser::invalid_file_error() {
    return "FilePath["+ (string)this->file_path +"] is not valid or file doesn't exists.";
}

Parser::Parser( char *file_path ) : Basic_IO(file_path) {
    if( this->open( file_path ) ) {
        cout << "Successfully Opened \""+ (string)file_path +"\"" << endl;
    }
}

bool Parser::parse_txt_to( Scene &scene ) {
    string line,
            key,
            value;
    int line_n = 0,
        current_instance_line = 0;
    istringstream line_stream;
    string current_instance_name;
    vector<double> parameters;
    bool error_flag = false;

    while( getline( file, line ) ) {
        line_n++;

        if( line.empty() ) {
            if( ! current_instance_name.empty() ) {
                if( ! add_instance_of( current_instance_name, parameters, scene, current_instance_line ) ) {
                    error_flag = true;
                }
                current_instance_name.clear();
                parameters.clear();
            }
        }
        else {
            line_stream.clear();
            line_stream.str(line);

            if( line_stream >> key >> value ) {

                if( key == "+" ) {
                    current_instance_line = line_n;
                    current_instance_name = value;
                }
                else {
                    while( ! value.empty() ) {
                        unsigned int first_seperator = value.find_first_of(',');
                        parameters.emplace_back( stod( value.substr(0, first_seperator ) ) );
                        if( first_seperator == EOF ) {
                            value.clear();
                        }
                        else {
                            value = value.substr( first_seperator+1, value.length() );
                        }
                    }
                }
            }
            else {
                this->log.emplace_back( "Line:"+ to_string(line_n) +" is not valid" );
                error_flag = true;
            }
        }
    }

    if( error_flag ) {
        this->log.emplace_back( "Scene configuration contains errors. See above for details." );
        this->log.emplace_back( "Exiting RayCaster3000" );
        this->cout_all_log();
        return false;
    }

    this->cout_all_log();
    return true;
}

bool Parser::add_instance_of( const string &name, const vector<double> &parameters, Scene &scene, int line_n ) {
    try {
        if( name == "scene>settings" ) {
            scene.set_settings( Settings(
                    (int)parameters.at(0), (int)parameters.at(1),
                    Color( parameters.at(2), parameters.at(3), parameters.at(4) ),
                    (int)parameters.at(5),
                    (int)parameters.at(6)
            ) );
        }
        else if( name == "camera>perspective" ) {
            scene.set_camera( Camera(
                    Vector3(parameters.at(0), parameters.at(1), parameters.at(2)),
                    Vector3(parameters.at(3), parameters.at(4), parameters.at(5)),
                    Vector3(parameters.at(6), parameters.at(7), parameters.at(8))
            ) );
        }
        else if( name == "light>point" ) {
            scene.add_point_light( new PointLight(
                    Color(parameters.at(0), parameters.at(1), parameters.at(2)),
                    parameters.at(3),
                    Vector3(parameters.at(4), parameters.at(5), parameters.at(6))
            ) );
        }
        else if( name == "light>ambient" ) {
            scene.add_ambient_light( new AmbientLight(
                    Color(parameters.at(0), parameters.at(1), parameters.at(2)),
                    parameters.at(3)
            ) );
        }
        else if( name == "modal>sphere" ) {
            scene.add_modal( new Modal(
                    new Sphere(
                            Vector3(parameters.at(0), parameters.at(1), parameters.at(2)),
                            parameters.at(3)
                    ),
                    new Material(
                            Color(parameters.at(4), parameters.at(5), parameters.at(6)),
                            parameters.at(7),
                            parameters.at(8),
                            parameters.at(9),
                            parameters.at(10)
                    )
            ) );
        }
        else if( name == "modal>plane" ) {
            scene.add_modal( new Modal(
                    new Plane(
                            Vector3(parameters.at(0), parameters.at(1), parameters.at(2)),
                            Vector3(parameters.at(3), parameters.at(4), parameters.at(5))
                    ),
                    new Material(
                            Color(parameters.at(6), parameters.at(7), parameters.at(8)),
                            parameters.at(9),
                            parameters.at(10),
                            parameters.at(11),
                            parameters.at(12)
                    )
            ) );
        }
        else if( name == "modal>disk" ) {
            scene.add_modal( new Modal(
                    new Disk(
                            Vector3(parameters.at(0), parameters.at(1), parameters.at(2)),
                            Vector3(parameters.at(3), parameters.at(4), parameters.at(5)),
                            parameters.at(6)
                    ),
                    new Material(
                            Color(parameters.at(7), parameters.at(8), parameters.at(9)),
                            parameters.at(10),
                            parameters.at(11),
                            parameters.at(12),
                            parameters.at(13)
                    )
            ) );
        }
        else {
            this->log.emplace_back( "Unknown object \""+ name +"\" | Line:"+ to_string(line_n) );
            return false;
        }
    }
    catch( out_of_range &error ) {
        this->log.emplace_back( "Parameter Error[ "+ (string)error.what() +" ] | Line:"+ to_string(line_n)  );
        return false;
    }

    this->log.emplace_back( "Created: "+ name +" | Line:"+ to_string(line_n) );

    return true;
}
