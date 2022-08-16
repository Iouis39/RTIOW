#pragma once

#include "vector.hpp"

static void writeColor(std::ostream &out, Vec3<double> pixelColor) {
    out << static_cast<int>(255.999 * pixelColor.getX()) << ' '
        << static_cast<int>(255.999 * pixelColor.getY()) << ' '
        << static_cast<int>(255.999 * pixelColor.getZ()) << std::endl;
}
