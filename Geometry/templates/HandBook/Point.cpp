#include <bits/stdc++.h>
#define eps 1e-9 

using namespace std;

struct pt {
	double x,y;
	
	pt(){x=y=0;}
	pt(double u, double v) : x(u), y(v){}
	bool operator ==(const pt v){ return (x-v.x<eps && y-v.y<eps); }
	bool operator !=(const pt v){ return (*this==v); }
	void operator =(const pt v){ x=v.x, y=v.y; }
	
	friend istream & operator >> (istream &in, pt &a){ return in>>a.x>>a.y; }
	friend ostream & operator << (ostream &out, pt &a){ return out<<"P("<<a.x<<","<<a.y<<")"; }
};

double sq(const pt &p) {return p.x*p.x + p.y*p.y;}
double abs(const pt &p) {return sqrt(sq(p));}
double dist(const pt &a, const pt &b){
	return sqrtf(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}

int main(){
}
