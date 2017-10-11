// Created by Berk on 22.09.2017.
//

#ifndef RAYCASTER3000_JSON_COMPONENTS_H
#define RAYCASTER3000_JSON_COMPONENTS_H

#include <map>

enum json_type {
    Object,
    Array,
    String,
    Number,

    True,
    False,
    Null
};

template< class C >
class json_layer {
private:
    C container;
    json_layer *inner_layer;
public:
    json_layer(C container) : container(container) {}

    void set_inner_layer( json_layer *inner_layer ) {
        this->inner_layer = inner_layer;
    }
};


class json_object {
public:
    json_type type = json_type::Object;
    map<const string, int> pairs;
    char begin = '{';
    char end = '}';
};

class json_array {
public:
    json_type type = json_type::Array;
    char begin = '[';
    char end = ']';
};

//  JSON String or Number
struct json_value {

};











struct json_string {
    char begin = '"';
    char end = '"';
};

#endif //RAYCASTER3000_JSON_COMPONENTS_H
