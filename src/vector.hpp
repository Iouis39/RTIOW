#pragma once

#include <iostream>
#include <cmath>


template<typename T>
class Vec3 {
    private:
        T x, y, z;

    public:
        constexpr Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
        constexpr Vec3(const T &xyzValue) : x(xyzValue), y(xyzValue), z(xyzValue) {}
        constexpr Vec3(T const &xValue, T const &yValue, T const &zValue) : x(xValue), y(yValue), z(zValue) {}

        Vec3 operator+(const Vec3<T> &summand) const; 
        Vec3 operator-(const Vec3<T> &subtrahend) const;
        Vec3 operator*(const T &factor) const;
        Vec3 operator/(const T &divisor) const;
        Vec3 operator+=(const Vec3<T> &summand);
        Vec3 operator-=(const Vec3<T> &subtrahend);
        Vec3 operator*=(const T &factor);
        Vec3 operator/=(const T &divisior);
        
        std::ostream& operator<<(std::ostream &out) const;

        T getX() const;
        T getY() const;
        T getZ() const;

        T length() const;
        T lengthSquared() const;
        void normalize(); 
        Vec3<T> crossProduct(const Vec3<T> &vec) const;
        T dotProduct(const Vec3<T> &vec) const;
        void print() const;
};

/* ***************************************************************** */

template<typename T>
T Vec3<T>::getX() const {
    return x;
}

template<typename T>
T Vec3<T>::getY() const {
    return y;
}

template<typename T>
T Vec3<T>::getZ() const {
    return z;
}

template<typename T> 
T Vec3<T>::length() const {
    return sqrt(x * x + y * y + z * z);
 
}

template<typename T>
T Vec3<T>::lengthSquared() const {
    return x*x + y*y + z*z;
}

template<typename T>
void Vec3<T>::normalize() {
    T vectorLength = length();

    if (vectorLength > 0) {
        double lengthBuffer = 1 / vectorLength;
        x *= lengthBuffer;
        y *= lengthBuffer;
        z *= lengthBuffer;
    }
}

template<typename T>
Vec3<T> Vec3<T>::crossProduct(const Vec3<T> &vec) const {
    Vec3<T> crossVec;
    crossVec.x = y * vec.z - z * vec.y;
    crossVec.y = z * vec.x - x * vec.z;
    crossVec.z = x * vec.y - y * vec.x;

    return crossVec;
}

template<typename T>
T Vec3<T>::dotProduct(const Vec3<T> &vec) const {
    T scalar;
    scalar = x * vec.x + y * vec.y + z * vec.z;
}

template<typename T>
void Vec3<T>::print() const {
    std::cout << "[";
    std::cout << "{\"X\": " << x << ',' << '\n';
    std::cout << "\"Y\": " << y << ',' << '\n';
    std::cout << "\"Z\": " << z << "," << '\n';
    std::cout << "\"Length\": " << length() << "}" << '\n';
    std::cout << "]" << std::endl;
}

/* ***************************************************************** */

template<typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T> &summand) const {
    Vec3<T> sum;
    sum.x = x + summand.x;
    sum.y = y + summand.y;
    sum.z = z + summand.z;

    return sum;
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T> &subtrahend) const {
    Vec3<T> diff;
    diff.x = x - subtrahend.x;
    diff.y = y - subtrahend.y;
    diff.z = z - subtrahend.z;

    return diff;
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const T &factor) const {
    Vec3<T> product;
    product.x = factor * x;
    product.y = factor * y;
    product.z = factor * z;

    return product;
}

template<typename T>
Vec3<T> operator*(const T &factor, const Vec3<T> &vec) {
    return vec * factor;
}

template<typename T>
Vec3<T> Vec3<T>::operator/(const T &divisor) const {
    Vec3<T> quotient;
    quotient.x = x * 1 / divisor;
    quotient.y = y * 1 / divisor;
    quotient.z = z * 1 / divisor;

    return quotient;
}

template<typename T>
Vec3<T> Vec3<T>::operator+=(const Vec3<T> &summand) {
    x += summand.x;
    y += summand.y;
    z += summand.y;

    return *this;
}

template<typename T>
Vec3<T> Vec3<T>::operator-=(const Vec3<T> &subtrahend) {
    x -= subtrahend.x;
    y -= subtrahend.y;
    z -= subtrahend.y;

    return *this;
}

template<typename T>
Vec3<T> Vec3<T>::operator*=(const T &factor) {
    x *= factor;
    y *= factor;
    z *= factor;

    return *this;
}

template<typename T>
Vec3<T> Vec3<T>::operator/=(const T &divisor) {
    return *this *= 1/divisor;
}

template<typename T>
std::ostream& Vec3<T>::operator<<(std::ostream &out) const {
   return out << x << ' ' << y << ' ' << z;
}

/* ***************************************************************** */

template<typename T>
T dotProduct(const Vec3<T> &Vec1, const Vec3<T> &Vec2) {
    T scalar;
    return (scalar = Vec1.getX() * Vec2.getX() + Vec1.getY() * Vec2.getY() + Vec1.getZ() * Vec2.getZ());
}
