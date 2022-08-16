#include <iostream>

#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"


int main() {
    // Image
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

    Vec3<int> a(1, 3, 4);
    Vec3<int> b(1, 1, 1);
    Ray<int> ray(a, b);

    return 0;
}
