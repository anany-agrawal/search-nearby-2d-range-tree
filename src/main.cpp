#include <iostream>
#include "PointDatabase.h"

int main() {
    std::vector<Point> points = {
        {1,6}, {2,4}, {3,7}, {4,9}, {5,1},
        {6,3}, {7,8}, {8,10}, {9,2}, {10,5}
    };

    PointDatabase db(points);

    auto res = db.searchNearby({5,5}, 2);

    std::cout << "Nearby points:\n";
    for (auto &p : res) {
        std::cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
