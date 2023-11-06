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
double VectorAng(const Point<F> &a, const Point<F> &b){//melhor que o da lei dos cossenos(acima)
	double ang = ((double)(a.x*b.x +a.y*b.y) /  (double)( sqrt(a.x*a.x + a.y*a.y) * sqrt(b.x*b.x + b.y*b.y)));
	//~ cout << "ang " << (acos(ang)*180/pi) << '\n';
	return acos(ang);
}
