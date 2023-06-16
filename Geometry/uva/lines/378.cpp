#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)
#define eps 1e-9

template<class F>
struct Point{
	F x, y;
	Point(): x(0), y(0){};
	Point(F a, F b): x(a), y(b){};
	~Point(){};
	
	bool operator < (const Point &u) const{ if(fabs(x-u.x) < eps){ return y < u.y; }else{ return x < u.x; } }
	bool operator > (const Point &u) const{ if(fabs(x-u.x) < eps){ return y > u.y; }else{ return x > u.x; } }
	bool operator == (const Point &u) const{ return (fabs(x-u.x) < eps && fabs(y-u.y) < eps); }
	
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
		a = (fabs(B)<eps ? 1.0 : -A/B), b = (fabs(B)<eps ? 0 : -C/B);
	}
	line(Point<F> &u, Point<F> &v){
		den = u.x - v.x;
		num = u.y - v.y;
		A = num, B = -den, C = -(num * u.x) + (den * u.y);
		den*=-1;
		a = (fabs(B)<eps ? 1.0 : -A/B), b = (fabs(B)<eps ? 0 : -C/B);
	}
	~line(){};
	friend ostream & operator <<(ostream &out, const line &u){ return out << u.a << "x " << u.b << "\n" << u.A << "x " << u.B << "y " << u.C << " = 0"; }
};

//-----------------------------------------------finish----------------------------------------------------------//

bool same(const line<double> &u, const line<double> &v){
	if(!u.B){//a parallel to y
		if(!v.B && (fabs(-u.C/u.A + v.C/v.A) < eps))
			return true;
		return false;
	}
	if(!v.B){//b parallel to y
		if(!u.B && (fabs(-u.C/u.A + v.C/v.A) < eps))
			return true;
		return false;
	}
	if(fabs(u.a-v.a)<eps && fabs(u.b-v.b)<eps)//coeficient angular equal and b equal
		return true;
	return false;
}

bool parallel(const line<double>&u, const line<double> &v){
	if(!u.B){//a parallel to y
		if(!v.B)
			return true;
		return false;
	}
	if(!v.B){//b parallel to y
		if(!u.B)
			return true;
		return false;
	}
	if(fabs(u.a-v.a)<eps)//coeficient angular equal
		return true;
	return false;
}

bool intersect(const line<double> &u, const line<double> &v, Point<double> &ans){
	if(parallel(u, v))
		return false;
	if((!u.B && !v.A) || (!v.B && !u.A)){//form a 90 ang
		if((!u.B && !v.A)){
			ans.x = (-u.C/u.A); ans.y = v.b; 
			return true;
		}
		else{
			ans.x = (-v.C/v.A); ans.y = u.b; 
			return true;
		}
	}
	if(u.B){//u angular
		if(!v.B){//v parallel to y
			ans.x = (-v.C/v.A); ans.y = u.a*(-v.C/v.A)+u.b;
			return true;
		}
		if(!v.A){//v parallel to x
			ans.x = (v.C-u.b/u.a); ans.y = v.C;
			return true;
		}
		double k = (v.b-u.b)/(u.a-v.a);
		ans.x = k; ans.y = u.a*k+u.b;
		return true;
	}
	//v angular
	if(!u.B){//u parallel to y
		ans.x = (-u.C/u.A); ans.y = v.a*(-u.C/u.A)+v.b;
		return true;
	}
	if(!u.A){//u parallel to x
		ans.x = (u.C-v.b/v.a); ans.y = u.C;
		return true;
	}
	double k = (u.b-v.b)/(v.a-u.a);
	ans.x = k; ans.y = v.a*k+v.b;
	return true;
}

int main(){
	//~ freopen("out", "w", stdout);
	int t;
	Point<double>a, b, c, d, e;
	cin>>t;
	cout << fixed << setprecision(2);
	cout << "INTERSECTING LINES OUTPUT\n";
	while(t--){
		cin>>a>>b>>c>>d;
		line<double>u(a, b), v(c, d);
		//~ cout << u << endl;
		//~ cout << v << endl;
		if(same(u, v)){
			cout << "LINE\n";
		}
		else{
			if(parallel(u, v)){
				cout << "NONE\n";
			}
			else{
				intersect(u, v, e);
				cout << "POINT " << e.x << " " << e.y << endl;
			}
		}
	}
	cout << "END OF OUTPUT\n";
}
