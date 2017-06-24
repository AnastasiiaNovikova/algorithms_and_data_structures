/*
 
 Оболочка
 Имеется массив из N целочисленных точек на плоскости.
 Требуется найти периметр наименьшего охватывающего многоугольника, содержащего все точки.
 Input format
 5 ≤ N ≤ 500000
  - 10000 ≤ xi, yi ≤ 10000
 Output format
 Одно вещественное число — периметр требуемого многоугольника с двумя знаками после запятой.
 Examples
 Input	Output
 5
 2 1
 2 2
 2 3
 3 2
 1 2
 5.66

 */


// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
    coord_t x, y;
    
    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
    long n = P.size(), k = 0;
    vector<Point> H(2*n);
    
    // Sort points lexicographically
    sort(P.begin(), P.end());
    
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    
    // Build upper hull
    for (long i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    
    H.resize(k-1);
    return H;
}

double perimeter(vector <Point> &p){
    double per = 0.0;
    double l;
    double r;
    for (unsigned long i=0;i<p.size();i++){
        if (i+1==p.size()) {
            l=(p[i].x-p[0].x);
            r=(p[i].y-p[0].y);
            per=per+sqrt(l*l+r*r);
            break;
        }
        l=(p[i].x-p[i+1].x);
        r=(p[i].y-p[i+1].y);
        per=per+sqrt(l*l+r*r);
        
    }
    return per;
}



int main(){
    
    int N;
    scanf("%d",&N);
    double per;
    vector<Point> points(N);
    vector<Point> hool;
    for (int i=0;i<N;i++){
        int x, y;
        scanf("%d",&x);
        scanf("%d",&y);
        points[i].x=x;
        points[i].y=y;
        
    }
    
    hool=convex_hull(points);
    
    
    per= perimeter(hool);
    
    printf("%.2lf",per);
    
    
    
    
}
