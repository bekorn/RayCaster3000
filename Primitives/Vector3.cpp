// Created by Berk on 20.09.2017.
//

#include "Vector3.h"

const Vector3 Vector3::unit_x = Vector3(1.0, 0.0, 0.0);
const Vector3 Vector3::unit_y = Vector3(0.0, 1.0, 0.0);
const Vector3 Vector3::unit_z = Vector3(0.0, 0.0, 1.0);

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {
    this->length = sqrt( x*x + y*y + z*z );
}

Vector3 Vector3::operator +( const Vector3 &v3 ) const {
    return Vector3( this->x + v3.x,
                    this->y + v3.y,
                    this->z + v3.z );
}

Vector3 Vector3::operator -( const Vector3 &v3 ) const {
    return Vector3( this->x - v3.x,
                    this->y - v3.y,
                    this->z - v3.z );
}

Vector3 Vector3::operator *( double n ) const {
    return Vector3( this->x * n,
                    this->y * n,
                    this->z * n );
}

Vector3 Vector3::operator /( double n ) const {
    return Vector3( this->x / n,
                    this->y / n,
                    this->z / n );
}

Vector3 Vector3::unit_vector() const {
    return *this / this->length;
}

Vector3 Vector3::cross_product( const Vector3 &v3 ) const {
    return Vector3( this->y * v3.z - this->z * v3.y,
                    this->z * v3.x - this->x * v3.z,
                    this->x * v3.y - this->y * v3.x );
}

double Vector3::dot_product(const Vector3 &v3) const {
    return this->x * v3.x + this->y * v3.y + this->z * v3.z;
}
