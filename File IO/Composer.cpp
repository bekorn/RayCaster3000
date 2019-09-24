// Created by Berk on 21.09.2017.
//

#include <iostream>
#include <cstring>
#include "Composer.h"

ios_base::openmode Composer::file_mode() {
    return fstream::out | fstream::binary;
}

string Composer::invalid_file_error() {
    return "Output File Path is not valid.";
}

Composer::Composer( char *file_path ) : Basic_IO(file_path) {
    if( this->open( file_path ) ) {
        cout << "Successfully Opened/Created \""+ (string)file_path +"\"" << endl;
    }
}

bool Composer::compose_bmp( Render render, int resolution_width, int resolution_height ) {

    FILE *f = fopen( this->file_path, "wb" );
    unsigned char *img = new unsigned char[3*resolution_width*resolution_height];
    int filesize = 54 + 3*resolution_width*resolution_height;  //w is your image width, h is image height, both int

    memset(img,0,(size_t)3*resolution_width*resolution_height);

    for(int i=0; i<resolution_width; i++)
    {
        for(int j=0; j<resolution_height; j++)
        {
            int x = i;
            int y = (resolution_height - 1) - j;
            Color* current_color = render.get(i, j);

            img[(x+y*resolution_width)*3+2] = (unsigned char)current_color->r;
            img[(x+y*resolution_width)*3+1] = (unsigned char)current_color->g;
            img[(x+y*resolution_width)*3+0] = (unsigned char)current_color->b;
        }
    }

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};

    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);

    bmpinfoheader[ 4] = (unsigned char)(       resolution_width    );
    bmpinfoheader[ 5] = (unsigned char)(       resolution_width>> 8);
    bmpinfoheader[ 6] = (unsigned char)(       resolution_width>>16);
    bmpinfoheader[ 7] = (unsigned char)(       resolution_width>>24);
    bmpinfoheader[ 8] = (unsigned char)(       resolution_height    );
    bmpinfoheader[ 9] = (unsigned char)(       resolution_height>> 8);
    bmpinfoheader[10] = (unsigned char)(       resolution_height>>16);
    bmpinfoheader[11] = (unsigned char)(       resolution_height>>24);

    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i=resolution_height-1; i>=0; i--)
    {
        fwrite(img+(resolution_width*(resolution_height-i-1)*3),3,(size_t)resolution_width,f);
        fwrite(bmppad,1,(size_t)(4-(resolution_width*3)%4)%4,f);
    }

    delete[] img;
    fclose(f);

    return true;
}
