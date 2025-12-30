#pragma once
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
    Point(int _x=0, int _y=0) : x(_x), y(_y) {}
};

class RangeTree {
public:
    struct Node {
        Point p;
        Node* left;
        Node* right;
        std::vector<Point> y_sorted; // linked list sorted by y
        Node(Point point) : p(point), left(nullptr), right(nullptr) {}
    };

    Node* root;

    RangeTree(const std::vector<Point>& points);
    std::vector<Point> rangeQuery(int x1, int x2, int y1, int y2);

private:
    Node* build(std::vector<Point> pts);
    void query(Node* node, int x1, int x2, int y1, int y2, std::vector<Point>& result);
};
