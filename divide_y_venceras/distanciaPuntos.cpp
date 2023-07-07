#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

struct Point
{
    double x, y;
};

double calculateDistance(const Point &p1, const Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

double minDistance(const std::vector<Point> &s, double d)
{
    double minDistance = d;
    int n = s.size();

    std::sort(s.begin(), s.end(), [](Point &p1, Point &p2)
              { return p1.y < p2.y; });

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n && (s[j].y - s[i].y) < minDistance; ++j)
        {
            double distance = calculateDistance(s[i], s[j]);
            if (distance < minDistance)
            {
                minDistance = distance;
            }
        }
    }

    return minDistance;
}

double findMinDistance(const std::vector<Point> &points)
{
    int n = points.size();

    if (n <= 3)
    {
        double minDistance = std::numeric_limits<double>::max();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                double distance = calculateDistance(points[i], points[j]);
                if (distance < minDistance)
                {
                    minDistance = distance;
                }
            }
        }
        return minDistance;
    }

    int mid = n / 2;
    Point midPoint = points[mid];

    std::vector<Point> left(points.begin(), points.begin() + mid);
    std::vector<Point> right(points.begin() + mid, points.end());

    double dLeft = findMinDistance(left);
    double dRight = findMinDistance(right);

    double d = std::min(dLeft, dRight);

    std::vector<Point> s;
    for (const Point &point : points)
    {
        if (std::abs(point.x - midPoint.x) < d)
        {
            s.push_back(point);
        }
    }

    double ds = minDistance(s, d);

    return std::min(d, ds);
}

int main()
{
    std::vector<Point> points = {
        {0.0, 0.0},
        {1.0, 2.0},
        {3.5, 1.5},
        {4.0, 2.0},
        {2.0, 3.0}};

    double minDistance = findMinDistance(points);
    std::cout << "La distancia mínima entre dos puntos es: " << minDistance << std::endl;

    return 0;
}