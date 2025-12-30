#ifndef RANGE_TREE_H
#define RANGE_TREE_H

#include <vector>
#include "Point.h"

class RangeTree {
private:
    struct Node {
        Point point;                    // split point
        Node* left;
        Node* right;
        std::vector<Point> y_sorted;    // points sorted by y

        Node(const Point& p) : point(p), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* build(std::vector<Point>& points);
    void rangeQuery(Node* node,
                    int x1, int x2,
                    int y1, int y2,
                    std::vector<Point>& result) const;

public:
    RangeTree(const std::vector<Point>& points);
    std::vector<Point> rangeQuery(int x1, int x2, int y1, int y2) const;
};

#endif
