#include "PointDatabase.h"

PointDatabase::PointDatabase(const std::vector<Point>& points)
    : tree(points) {}

std::vector<Point> PointDatabase::searchNearby(Point q, int d) {
    return tree.rangeQuery(
        q.x - d, q.x + d,
        q.y - d, q.y + d
    );
}
