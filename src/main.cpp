#include <iostream>

#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"

template<typename T>
Vec3<T> rayColor(Ray<T> &r) {
    r.normalizeD();
    Vec3<T> rDirection = r.getD();
    auto t = 0.5*(rDirection.getY() + 1.0);
    return (1.0-t)*Vec3<T>(1.0, 1.0, 1.0) + t*Vec3<T>(0.5, 0.7, 1.0);
}

int main() {
    // Image
    const auto aspectRatio =  16.0 / 9.0;
    const int imageWidth = 256;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

    // Camera
    auto viewportHeight = 2.0;
    auto viewportWidth = aspectRatio * viewportHeight;
    auto focalLength = 1.0;

    Vec3<double> origin(0.0,0.0,0.0);
    Vec3<double> vertical(0.0, viewportHeight, 0.0);
    Vec3<double> horizontal(viewportWidth, 0.0, 0.0);



    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            Vec3<double> pixelColor(double(i)/imageWidth-1, double(j)/imageHeight-1, 0.25);
            writeColor(std::cout, pixelColor);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}


