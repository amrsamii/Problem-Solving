double getAngle_A_abB(double a, double b, double B) {
    return asin(a * sin(B) / b);
}

double getDistance(int x1, int x2, int y1, int y2) {

    return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

bool isInside(double x_point, double y_point, double top_left_x, double top_left_y, double bottom_right_x,
              double bottom_right_y) {
    return (x_point > top_left_x && x_point < bottom_right_x) && (y_point > bottom_right_y && y_point < top_left_y);
}

struct Point {
    double x;
    double y;
};

bool doOverlap(Point l1, Point r1, Point l2, Point r2) {

    if (l1.x >= r2.x || l2.x >= r1.x)
        return false;

    if (l2.y >= r1.y || l1.y >= r2.y)
        return false;

    return true;
}

pair<Point, Point> getIntersection(Point l1, Point r1, Point l2, Point r2) {

    Point l3, r3;
    l3.x = max(l1.x, l2.x);
    l3.y = max(l1.y, l2.y);
    r3.x = min(r1.x, r2.x);
    r3.y = min(r1.y, r2.y);
    return make_pair(l3, r3);

}

bool pointsEqual(Point p1, Point p2) {

    return (fabs(p1.x - p2.x) < 1e-6) && (fabs(p1.y - p2.y) < 1e-6);
}

map<char, int> values;

char findByValue(int x) {
    for (auto &y : values) {
        if (y.second == x)
            return y.first;
    }
    return '*';
}