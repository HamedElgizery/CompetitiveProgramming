#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e2+10;
const double EPS = 1e-6;

int w, h;
char grid[N][N];

struct Vector {
    double x, y;
    Vector(double x = 0, double y = 0) : x(x), y(y) {}

    void rotate90() {
        double xx = x;
        double yy = y;
        x = yy;
        y = -xx;
    }
};

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
};

bool equal(double f, double s) {
    return abs(f-s) <= EPS;
}

point operator +(point p, Vector v) {
    point ret;
    ret.x = v.x + p.x;
    ret.y = v.y + p.y;
    return ret;
}

struct circle {
    point centre;
    double r;
    circle(point centre = point()) : centre(centre) {}
    bool inCircle(point p) {
        double xx = (p.x - centre.x);
        double yy = (p.y - centre.y);
        double dis = sqrt((xx*xx + yy*yy));
        return sqrt((xx*xx + yy*yy)) < r || equal(dis, r);
    }
} CIRCLE;


double length(point a, point b) {
    double xx = a.x - b.x;
    double yy = a.y - b.y;
    return sqrt(xx*xx + yy*yy);
}

double TriangleArea(point a, point b, point c) {
    return 0.5 * abs(a.x*(b.y-c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
}

struct square {
    point tl, tr, br, bl;
    double area, sideL;
    square(point tl = point(), point tr = point(), point bl = point(), point br = point()) {
        this->tl = tl;
        this->tr = tr;
        this->bl = bl;
        this->br = br;
        area = 0;
    }
    void build() {
        point mid = point((bl.x + tr.x)/2, (bl.y + tr.y)/2);
        Vector vec = {tr.x - mid.x, tr.y - mid.y};
        for (int i = 0; i < 4; i++) {

            if (i == 0)
                tr = mid + vec;
            if (i == 1) 
                br = mid + vec;
            if (i == 2) 
                bl = mid + vec;
            if (i == 3) 
                tl = mid + vec;
        
            vec.rotate90();
        }
        double xx = tl.x - tr.x;
        double yy = tl.y - tr.y;
        sideL = sqrt(xx*xx + yy*yy);
        area = sideL*sideL;
    }    

    bool inSquare(point p) {
        double sum = 0;
        sum += TriangleArea(tl, tr, p);
        sum += TriangleArea(tr, br, p);
        sum += TriangleArea(br, bl, p);
        sum += TriangleArea(bl, tl, p);
        return equal(sum, area);
    }
} SQUARE;



void solve() {
    cin >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            grid[i][j] = '.';

    cin >> CIRCLE.centre.x >> CIRCLE.centre.y >> CIRCLE.r;
    cin >> SQUARE.bl.x >> SQUARE.bl.y >> SQUARE.tr.x >> SQUARE.tr.y;
    SQUARE.build();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (SQUARE.inSquare(point(j, i)) || CIRCLE.inCircle(point(j, i)))
                grid[i][j] = '#';
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j];
        }
        cout << " \n"[i+1 != h];
    }
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}