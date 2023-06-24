float ang(const Point<double> &a, const Point<double> &b, const Point<double> &c){//BAO
	double d1, d2, d3;
	d1=dist(a, b); d2=dist(a, c); d3=dist(b, c);
	float h = ((d1*d1)+(d2*d2)-(d3*d3))/(2*d1*d2);
 	float k = acos(h)*180/pi;
	return k;
}
