#include <bits/stdc++.h>
#define eps 1e-9
#define pi acos(-1.0)

using namespace std;

template<class F>
struct Point{
	F x, y;
	Point(): x(0), y(0){};
	Point(F a, F b): x(a), y(b){};
	
	bool operator < (const Point &u) const{ if(fabs(x-u.x) < eps){ return y < u.y; }else{ return x < u.x; } }
	bool operator > (const Point &u) const{ if(fabs(x-u.x) < eps){ return y > u.y; }else{ return x > u.x; } }
	bool operator == (const Point &u) const{ return (fabs(x-u.x) < eps && fabs(y-u.y) < eps); }
	bool operator = (const Point &u){ x=u.x; y=u.y; return true; }
	
	friend istream & operator >>(istream &in, Point &u){ return in >> u.x >> u.y; }
	friend ostream & operator <<(ostream &out, Point &u){ return out << " P(" << u.x << "," << u.y << ") "; }
};

//-----------------------------------------------start----------------------------------------------------------//

/*
 * Note:
 * if A==0, parallel to x, passing to C
 * if B==0, parallel to y, passing to -(C/A)
 * if C==0, pass to Point(0,0)
 */

template<class F>
class line{
public:
	double A, B, C;
	double a, b;
	double num, den;
	
	line(){A = a = B = b = C = 0; }
	line(F nume, F deno, Point<F> &v){
		A = deno, B = -nume, C = -(deno * v.x) + (nume * v.y);
		a = (fabs(B)<EPS ? 1.0 : -A/B), b = (fabs(B)<EPS ? 0 : -C/B);
	}
	line(Point<F> &u, Point<F> &v){
		den = u.x - v.x;
		num = u.y - v.y;
		A = num, B = -den, C = -(num * u.x) + (den * u.y);
		den*=-1;
		a = (fabs(B)<EPS ? 1.0 : -A/B), b = (fabs(B)<EPS ? 0 : -C/B);
	}
	~line(){};
	
	bool isIn(const Point<F> &u){ return (A*u.x + B*u.y + C == 0); }
	
	friend ostream & operator <<(ostream &out, const line &u){ return out << u.a << "x " << u.b << "\n" << u.A << "x " << u.B << "y " << u.C << " = 0"; }
};

//-----------------------------------------------finish----------------------------------------------------------//

int main(){
}
