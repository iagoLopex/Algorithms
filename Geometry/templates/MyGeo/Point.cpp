#include <bits/stdc++.h>
using namespace std;

#define ld long double

const long double EPS = 1e-7;


//-----------------------------------------------start----------------------------------------------------------//

template<class F>
struct Point{
	F x, y;
	Point(): x(0), y(0){};
	Point(F a, F b): x(a), y(b){};
	
	bool operator < (const Point &u) const{ if(fabs(x-u.x) < EPS){ return y < u.y; }else{ return x < u.x; } }
	bool operator > (const Point &u) const{ if(fabs(x-u.x) < EPS){ return y > u.y; }else{ return x > u.x; } }
	bool operator == (const Point &u) const{ return (fabs(x-u.x) < EPS && fabs(y-u.y) < EPS); }
	Point operator - (const Point& b) const { return Point{x - b.x, y - b.y}; }
        F operator ^(const Point& b) const { return x*b.y - y*b.x; } //neg(direita) , pos(esquerda), 0(colinear), usa um vetor base(p1 - p2) ^ (pn - pn+1); 
    
        F dist(Point b) { return sqrt((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y)); }
    
	friend istream & operator >>(istream &in, Point &u){ return in >> u.x >> u.y; }
	friend ostream & operator <<(ostream &out, Point &u){ return out << " P(" << u.x << "," << u.y << ") "; }
};

//-----------------------------------------------finish----------------------------------------------------------//


int main() {
}
