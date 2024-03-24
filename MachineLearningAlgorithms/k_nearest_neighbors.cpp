#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    Point(double x, double y, int label)
        : x{x}, y{y}, label{label} {}

    double x;
    double y;
    int label;
};

double euclidean_distance(const Point& point_1, const Point& point_2) {
    return std::sqrt(std::pow(point_1.x - point_2.x, 2) + std::pow(point_1.y - point_2.y, 2));
}

std::vector<int> knn(const std::vector<Point>& points, const Point& test_point, int k) {
    std::vector<std::pair<double, int>> distances; 

    for (int i = 0; i < points.size(); ++i) {
        double dist = euclidean_distance(points[i], test_point);
        distances.push_back({dist, i});
    }
    
    std::sort(distances.begin(), distances.end());

    std::vector<int> neighors;
    for (int i = 0; i < k; ++i) {
        neighors.push_back(points[distances[i].second].label);
    }
    return neighors;
}

int main() {
    // Usage of KNN
    std::vector<Point> points;
    points.push_back(Point{1, 2, 0}); 
    points.push_back(Point{2, 3, 1}); 
    points.push_back(Point{3, 4, 0}); 
    points.push_back(Point{4, 5, 1});

    Point test_point{2.5, 3.5, -1};
    int k = 4;

    std::vector<int> neighbors = knn(points, test_point, k);
    // Prints the labels of nearest k labels for test_point
    std::endl(std::cout << "Labels of the " << k << " nearest neighbours");
    for (int label : neighbors) {
        std::cout << label << " ";
    }

    return 0;
}