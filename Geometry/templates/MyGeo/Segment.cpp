template<class F>
struct segment{
	line<F> k;
	Point<F> u, v;
	
	segment(){}
	segment(Point<F> &x, Point<F> &y){ k=line<F>(x, y); u=x; v=y; }
};
