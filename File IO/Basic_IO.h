// Created by Berk on 22.09.2017.
//

#ifndef RAYCASTER3000_BASIC_IO_H
#define RAYCASTER3000_BASIC_IO_H

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class Basic_IO {
protected:
    char * file_path;
    fstream file;
    virtual fstream::openmode file_mode() = 0;
    vector<string> log;
    virtual string invalid_file_error() = 0;
public:
    Basic_IO( char * file_path );
    ~Basic_IO();
    bool open( char *file_path );
    bool close();
    bool is_open();
    void cout_all_log();
};


#endif //RAYCASTER3000_BASIC_IO_H
