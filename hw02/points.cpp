#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

struct Point {
    long long x, y;
};

bool compareX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool compareY(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double stripClosest(vector<Point> &strip, int size, double d) {
    double minDist = d;
    if (size <= 1) {
        return minDist;
    }
    sort(strip.begin(), strip.end(), compareY); 

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j) {
            if (dist(strip[i], strip[j]) < minDist) {
                minDist = dist(strip[i], strip[j]);
            }
        }
    }

    return minDist;
}

double closestUtil(vector<Point> &P, int n) {
    if (n <= 3) {
        double minDist = numeric_limits<double>::max();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dist(P[i], P[j]) < minDist) {
                    minDist = dist(P[i], P[j]);
                }
            }
        }
        return minDist;
    }

    int mid = n / 2;
    Point midPoint = P[mid];
    vector<Point> P1(P.begin(), P.begin() + mid);
    vector<Point> P2(P.begin() + mid, P.end());
    double dl = closestUtil(P1, mid);
    double dr = closestUtil(P2, n - mid);

    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; ++i) {
        if (abs(P[i].x - midPoint.x) < d) {
            strip.push_back(P[i]);
        }
    }

    return min(d, stripClosest(strip, strip.size(), d));
}

int main() {
    int n;
    cin >> n;

    vector<Point> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i].x >> P[i].y;
    }

    sort(P.begin(), P.end(), compareX); 

    double minDistance = closestUtil(P, n);

    cout << fixed << setprecision(4) << minDistance << endl;

    return 0;
}