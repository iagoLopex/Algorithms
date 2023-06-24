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

double dist(const Point<double>&a, const Point<double>&b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

float ang(const Point<double> &a, const Point<double> &b, const Point<double> &c){
	double d1, d2, d3;
	d1=dist(a, b); d2=dist(a, c); d3=dist(b, c);
	float h = ((d1*d1)+(d2*d2)-(d3*d3))/(2*d1*d2);
 	float k = acos(h)*180/pi;
	return k;
}

template<class F>
struct segment{
	line<F> k;
	Point<F> u, v;
	
	segment(){}
	segment(Point<F> &x, Point<F> &y){ k=line<F>(x, y); u=x; v=y; }
};

void proj(line<double>k, Point<double> st, Point<double> &ans){
    
    line<double>h(k.num, k.den, st);
    if(k.A == 0){
        ans.x = st.x; ans.y = k.C;
    }
    else{
        if(k.B==0){
            ans.x = -(k.C/k.A); ans.y = st.y;
        }
        else{
            ans.x = (k.b-h.b)/(h.a-k.a);
            ans.y = h.a*ans.x+h.b;
        }
    }
}

int main(){
	
	//~ ios_base::sync_with_stdio(false);
  //~ cin.tie(NULL);
	freopen("out", "w", stdout);
	
	Point<double>start;
	double a, b;
	while(cin>>a>>b){
		
	    start = Point<double>(a, b);
		int n; cin>>n;
		vector<Point<double>>vec(n+1);
		vector<segment<double>>seg;
		cin>>vec[0];
		for(int i=1; i<n+1; i++){
			cin>>vec[i];
			seg.emplace_back(segment<double>(vec[i], vec[i-1]));
		}
		double ans = INT_MAX;
		Point<double>resp;
		for(int i=0; i<n; i++){
			
			Point<double>at;
			proj(seg[i].k, start, at);

			if((int)ang(at, seg[i].u, seg[i].v)==180){
			    if(ans > dist(at, start)){
			        ans = dist(at, start);
			        resp = at;
			    }
			}
			else{
			    if(ans > dist(start, seg[i].u)){
			        ans = dist(start, seg[i].u);
			        resp = seg[i].u;
			    }
			    if(ans > dist(start, seg[i].v)){
			        ans = dist(start, seg[i].v);
			        resp = seg[i].v;
			    }
			}
		}
		cout << fixed << setprecision(4);
		
		if(n==0){
			cout << vec[0].x << endl;
			cout << vec[0].y << endl;
		}
		else{
			cout << (!resp.x ? 0.0000 : resp.x) << endl;
			cout << (!resp.y ? 0.0000 : resp.y) << endl;
		}
	}
}
