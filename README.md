# Search Nearby - 2D Range Tree

**Author:** Anany Agrawal  
**Language:** C++

## Overview

This project implements a **2D Range Tree** data structure to efficiently store and query 2D points. It enables fast retrieval of all points within a specified rectangular area. This is ideal for applications like:

- GIS and map-based queries  
- Nearest neighbor searches  
- Real-time spatial data visualization  

The project achieves **O(N log N)** construction time and **O(m + log² N)** query time, where **m** is the number of points in the query result.

---

## Features

- Construct a 2D Range Tree from a list of 2D points  
- Perform range queries to find all points within a specified rectangle  
- Optimized for fast queries with a logarithmic search component  
- Easy-to-use interface through the `RangeTree` class  

---

## File Structure

search-nearby-2d-range-tree/
├── CMakeLists.txt # Build configuration
├── README.md # Project documentation
├── include/
│ └── RangeTree.h # Header file for RangeTree class
├── src/
│ ├── main.cpp # Example usage
│ └── RangeTree.cpp # RangeTree implementation
├── build/ # Build directory (generated)
└── tests/ # Optional: unit tests
---

## Installation & Build

### Prerequisites

- C++17 or later  
- CMake (≥3.10)  
- Make

### Build Steps

```bash
# Clone the repository
git clone git@github.com:anany-agrawal/search-nearby-2d-range-tree.git
cd search-nearby-2d-range-tree

# Create build directory
mkdir build
cd build

# Generate Makefiles
cmake ..

# Compile the project
make

# Run the example
./search_nearby
```

Usage Example
#include <iostream>
#include "RangeTree.h"

int main() {
    std::vector<Point> points = {
        {1,6}, {2,4}, {3,7}, {4,9}, {5,1}, {6,3}, {7,8}, {8,10}, {9,2}, {10,5}
    };

    RangeTree tree(points);

    int qx = 5, qy = 5, d = 3; // search distance
    std::cout << "Nearby points:\n";
    auto nearby = tree.rangeQuery(qx - d, qx + d, qy - d, qy + d);
    for (auto &p : nearby)
        std::cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}
Sample Output:
Nearby points:
(2, 4)
(3, 7)
(5, 1)
(6, 3)
(7, 8)
Notes
Points are represented as struct Point { int x, y; };

RangeTree handles construction and queries

Can be extended for k-nearest neighbor search or dynamic updates

References
2D Range Tree - GeeksforGeeks

C++ STL Documentation
