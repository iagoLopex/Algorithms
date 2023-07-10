#include <bits/stdc++.h>
#define eps 1e-9 
#define x real()
#define y imag()
#define pi acos(-1.0)

using namespace std;

struct vetor{
	complex<double> pt; //a+bi
	
	vetor(){}
	vetor(double a, double b){ pt={a, b}; }
	
	vetor operator+(vetor p) { return {pt.x+p.pt.x, pt.y+p.pt.y}; }
	vetor operator-(vetor p) { return {pt.x-p.pt.x, pt.y-p.pt.y}; }
	vetor operator*(double d){ return {pt.x*d, pt.y*d}; }
	vetor operator/(double d){ return {pt.x/d, pt.y/d}; }
	
	vetor operator+=(vetor p) { *this={pt.x+p.pt.x, pt.y+p.pt.y}; return *this; }
	vetor operator-=(vetor p) { *this={pt.x-p.pt.x, pt.y-p.pt.y}; return *this; }
	vetor operator*=(double d){ *this={pt.x*d, pt.y*d}; return *this; }
	vetor operator/=(double d){ *this={pt.x/d, pt.y/d}; return *this; }
	
	double tam(){ return sqrt((pt.x)*(pt.x)+(pt.y)*(pt.y)); } // r = sqrt(a*a+b*b)
	double ampl(){ return ((atan2(pt.y, pt.x))*180/pi); }     // Q1 Q2(0->180), Q3 Q4(0, -179)
	
	friend istream & operator >>(istream &in, vetor &a){double o, p; in>>o>>p; a={o,p}; return in;}
	friend ostream & operator <<(ostream &out, vetor &a){ return out<<"complex = "<<a.pt.x<<"+"<<a.pt.y<<"i";}
};

int main(){
}
