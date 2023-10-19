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

template<class F>
double dist(const Point<F> &a, const Point<F> &b){
	return sqrt((double)(a.x-b.x)*(double)(a.x-b.x) + (double)(a.y-b.y)*(double)(a.y-b.y));
}

template<class F>
double PointAng(const Point<F> &a, const Point<F> &b, const Point<F> &c){//BAO
	double d1, d2, d3;
	d1=dist(a, b); d2=dist(a, c); d3=dist(b, c);
	double h = ((double)(d1*d1)+(double)(d2*d2)-(double)(d3*d3))/(double)(2.0*d1*d2);
	double k = acos(h);
	return k;
}

template<class F>
double VectorAng(const Point<F> &a, const Point<F> &b){
	double ang = ((double)(a.x*b.x +a.y*b.y) /  (double)( sqrt(a.x*a.x + a.y*a.y) * sqrt(b.x*b.x + b.y*b.y)));
	//~ cout << "ang " << (acos(ang)*180/pi) << '\n';
	return acos(ang);
}

signed main() {
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	/*
	Point<double> a(5, 0);
	Point<double> fa(4, 0);
	
	Point<double> b(1, 1);
	Point<double> fb(3, 2);
	
	cout << VectorAng(a - fa, b - fb);  //em graus vai dar erro de precisao
	*/
	
	int n;
	cin>>n;
	vector<Point<double>>vec(n);
	for(int i=0; i<n; i++){
		cin>>vec[i];
	}
	for(int i=0; i<2*n; i++){
		vec.push_back(vec[i]);
	}
	
	double fix = pi/2.0;
	
	for(int i=0; i<n; i++){
		ld sum = dist(vec[i], vec[i+1]);
		int j = i+1;
		//~ cout << "\nvetor atual :  i+1 " << vec[i+1] << "  i " << vec[i] << '\n';
		while(VectorAng(vec[i+1] - vec[i], vec[j+1] - vec[j]) < fix){
			//~ cout << "j+1 " << vec[j+1] << "  j " << vec[j] << "      dist " << dist(vec[j], vec[j+1]) << '\n';
			sum += dist(vec[j], vec[j+1]);
			j++;
		}
		cout << fixed << setprecision(9);
		cout << sum << endl;
	}
	return 0;
}
