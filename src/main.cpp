#include <iostream>

#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"

template<typename T>
bool hitSphere(const Vec3<T> center, double radius, const Ray<T> &r) {
    Vec3<T> oc(r.getO() - center);
    auto a = dotProduct(r.getD(), r.getD());
    auto b = 2.0 * dotProduct(oc, r.getD());
    auto c = dotProduct(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;

    return (discriminant > 0);
}


template<typename T>
Vec3<T> rayColor(Ray<T> &r) {
    if(hitSphere(Vec3<double>(0, 0, -1), 0.5, r)) {
        return Vec3<double>(1, 0, 0);
    }
    r.normalizeD();
    Vec3<T> rDirection = r.getD();
    auto t = 0.5*(rDirection.getY() + 1.0);
    return (1.0-t)*Vec3<T>(1.0, 1.0, 1.0) + t*Vec3<T>(0.5, 0.7, 1.0);
}

int main() {
    // Image
    const auto aspectRatio =  16.0 / 9.0;
    const int imageWidth = 400;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

    // Camera
    auto viewportHeight = 2;
    auto viewportWidth = aspectRatio * viewportHeight;
    auto focalLength = 1;

    Vec3<double> origin(0, 0, 0);
    Vec3<double> horizontal(viewportWidth, 0, 0);
    Vec3<double> vertical(0, viewportHeight, 0);
    auto lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3<double>(0, 0, focalLength);

    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
    
    for (int j = imageHeight-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            auto u = double(i) / (imageWidth - 1);
            auto v = double(j) / (imageHeight - 1);
            Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
            Vec3<double> pixelColor = rayColor(r);
            writeColor(std::cout, pixelColor);
        }
    }
    std::cerr << "\nDone.\n";

    return 0;
}


