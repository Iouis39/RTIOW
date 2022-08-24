#pragma once

#include "vector.hpp"

template<typename T>
class Ray {
    private:
        Vec3<T> o, d;

    public:
        constexpr Ray() : o(Vec3<T>(0)), d(Vec3<T>(0)) {}
        constexpr Ray(Vec3<T> const &origin, Vec3<T> const &direction) : o(origin), d(direction) {}

        Vec3<T> getO() const;
        Vec3<T> getD() const;
        Vec3<T> at(T t) const;
        void normalizeD();
        void printRay() const;


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

template<typename T>
void Ray<T>::normalizeD() {
    d.normalize();
}

template<typename T>
void Ray<T>::printRay() const {
    std::cout << "[";
    std::cout << "{\"X\": " << d.getX() << ',' << '\n';
    std::cout << "\"Y\": " << d.getY() << ',' << '\n';
    std::cout << "\"Z\": " << d.getZ() << ',' << '\n';
    std::cout << "\"Length\": " << d.length() << "}" << '\n';
    std::cout << "]" << '\n';

    std::cout << "[";
    std::cout << "{\"X\": " << o.getX() << ',' << '\n';
    std::cout << "\"Y\": " << o.getY() << ',' << '\n';
    std::cout << "\"Z\": " << o.getZ() << "}" << '\n';
    std::cout << "]" << std::endl;
}
