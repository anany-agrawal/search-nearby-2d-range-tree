#include "RangeTree.h"
#include <algorithm>

using namespace std;

RangeTree::Node* RangeTree::build(vector<Point>& points) {
    if (points.empty()) return nullptr;

    int mid = points.size() / 2;
    Node* node = new Node(points[mid]);

    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid + 1, points.end());

    node->left = build(left);
    node->right = build(right);

    node->y_sorted = points;
    sort(node->y_sorted.begin(), node->y_sorted.end(),
         [](const Point& a, const Point& b) {
             return a.y < b.y;
         });

    return node;
}

RangeTree::RangeTree(const vector<Point>& points) {
    vector<Point> pts = points;
    sort(pts.begin(), pts.end(),
         [](const Point& a, const Point& b) {
             return a.x < b.x;
         });
    root = build(pts);
}

void RangeTree::rangeQuery(Node* node,
                           int x1, int x2,
                           int y1, int y2,
                           vector<Point>& result) const {
    if (!node) return;

    if (x1 <= node->point.x && node->point.x <= x2) {
        if (y1 <= node->point.y && node->point.y <= y2)
            result.push_back(node->point);

        rangeQuery(node->left, x1, x2, y1, y2, result);
        rangeQuery(node->right, x1, x2, y1, y2, result);
    }
    else if (node->point.x < x1) {
        rangeQuery(node->right, x1, x2, y1, y2, result);
    }
    else {
        rangeQuery(node->left, x1, x2, y1, y2, result);
    }
}

vector<Point> RangeTree::rangeQuery(int x1, int x2, int y1, int y2) const {
    vector<Point> result;
    rangeQuery(root, x1, x2, y1, y2, result);
    return result;
}
