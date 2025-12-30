#include <iostream>
#include "RangeTree.h"

int main() {
    std::vector<Point> points = {
        {1,6}, {2,4}, {3,7}, {4,9}, {5,1}, {6,3}, {7,8}, {8,10}, {9,2}, {10,5}
    };

    RangeTree tree(points);

    int qx = 5, qy = 5, d = 1;
    std::cout << "Nearby points:\n";
    auto nearby = tree.rangeQuery(qx - d, qx + d, qy - d, qy + d);
    for (auto &p : nearby)
        std::cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}
