#pragma once

#include "vector.hpp"

template<typename T>
class Ray {
    private:
        Vec3<T> o, d;

    public:
        constexpr Ray() : o(Vec3<T>(0)), d(Vec3<T>(0)) {}
        constexpr Ray(Vec3<T> &origin, Vec3<T> &direction) : o(origin), d(direction) {}

        Vec3<T> getO() const;
        Vec3<T> getD() const;
        Vec3<T> at(T t) const;


};

/* ***************************************************************** */

template<typename T>
Vec3<T> Ray<T>::getO() const {
    return o;
}

template<typename T>
Vec3<T> Ray<T>::getD() const {
    return d;
}

template<typename T>
Vec3<T> Ray<T>::at(T t) const {
    return o + t * d;
}
