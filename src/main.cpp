#include <iostream>

#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"

template<typename T>
Vec3<T> rayColor(const Ray<T> &r) {
    Vec3<T> unitDirection;
    
    unitDirection.print();
    return unitDirection;
}

int main() {
    // Image
    /*
    const int imageWidth = 256;
    const int imageHeight = 256;

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
    */

    Vec3<double> a(1, 2, 3);
    Vec3<double> b(5, 4, 5);
    Ray<double> r(a, b);
    r.normalizeD();

    r.printRay();

    return 0;
}
