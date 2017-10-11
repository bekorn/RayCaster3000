// Created by Berk on 22.09.2017.
//

#include "Basic_IO.h"

Basic_IO::Basic_IO( char * file_path ) : file_path(file_path) {};

bool Basic_IO::open( char *file_path ) {
    this->file_path = file_path;
    this->file.open( file_path, this->file_mode() );

    if( this->file.is_open() ) {
        return true;
    }
    else {
        this->log.emplace_back( this->invalid_file_error() );
        this->cout_all_log();
        return false;
    }
}

bool Basic_IO::close() {
    this->file.close();
    return true;
}

bool Basic_IO::is_open() {
    return this->file.is_open();
}

void Basic_IO::cout_all_log() {
    for( string & error : this->log ) {
        cout << error << endl;
    }
}

Basic_IO::~Basic_IO() {
    this->file.close();
    delete this->file_path;
}
