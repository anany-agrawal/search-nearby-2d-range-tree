#include "RangeTree.h"
#include <iostream>

RangeTree::RangeTree(const std::vector<Point>& points) {
    root = build(points);
}

RangeTree::Node* RangeTree::build(std::vector<Point> pts) {
    if (pts.empty()) return nullptr;

    std::sort(pts.begin(), pts.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });

    int mid = pts.size() / 2;
    Node* node = new Node(pts[mid]);
    node->y_sorted = pts;

    std::vector<Point> left_pts(pts.begin(), pts.begin() + mid);
    std::vector<Point> right_pts(pts.begin() + mid + 1, pts.end());

    node->left = build(left_pts);
    node->right = build(right_pts);

    return node;
}

std::vector<Point> RangeTree::rangeQuery(int x1, int x2, int y1, int y2) {
    std::vector<Point> result;
    query(root, x1, x2, y1, y2, result);
    return result;
}

void RangeTree::query(Node* node, int x1, int x2, int y1, int y2, std::vector<Point>& result) {
    if (!node) return;

    if (x1 <= node->p.x && node->p.x <= x2 && y1 <= node->p.y && node->p.y <= y2)
        result.push_back(node->p);

    if (node->p.x > x1) query(node->left, x1, x2, y1, y2, result);
    if (node->p.x < x2) query(node->right, x1, x2, y1, y2, result);
}
