#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const ld pi = acos(-1.0);
const ld EPS = 1e-7;

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

double dist(const Point<double> &a, const Point<double> &b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double PointAng(const Point<double> &a, const Point<double> &b, const Point<double> &c){//BAO
	double d1, d2, d3;
	d1=dist(a, b); d2=dist(a, c); d3=dist(b, c);
	double h = ((d1*d1)+(d2*d2)-(d3*d3))/(2*d1*d2);
 	double k = acos(h);
	return k;
}

double VectorAng(const Point<double> &a, const Point<double> &b){
	double ang = ((a.x*b.x +a.y*b.y) /  ( sqrt(a.x*a.x + a.y*a.y) * sqrt(b.x*b.x + b.y*b.y)));
	cout << "ang " << ang << '\n';
	return acos(ang);
}

signed main() {
	
	
	
}
