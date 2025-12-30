#ifndef POINT_DATABASE_H
#define POINT_DATABASE_H

#include <vector>
#include "RangeTree.h"

class PointDatabase {
private:
    RangeTree tree;

public:
    explicit PointDatabase(const std::vector<Point>& points);
    std::vector<Point> searchNearby(Point q, int d);
};

#endif
