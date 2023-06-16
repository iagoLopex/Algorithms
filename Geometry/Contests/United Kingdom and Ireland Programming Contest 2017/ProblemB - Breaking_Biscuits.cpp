#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;

struct pt {
  double x, y;
  pt(){x = 0, y = 0;}
	pt(double a, double b){x=a,y=b;}
};

class line{
public:
	double A, B, C;
	double a, b;
	double num, den;
	
	line(){A = a = B = b = C = 0; }
	line(double nume, double deno, pt &v){
		A = deno, B = -nume, C = -(deno * v.x) + (nume * v.y);
		a = (fabs(B)<eps ? 1.0 : -A/B), b = (fabs(B)<eps ? 0 : -C/B);
	}
	line(pt &u, pt &v){
		den = u.x - v.x;
		num = u.y - v.y;
		A = num, B = -den, C = -(num * u.x) + (den * u.y);
		den*=-1;
		a = (fabs(B)<eps ? 1.0 : -A/B), b = (fabs(B)<eps ? 0 : -C/B);
	}
};

double PointToLine(line &u, pt &v){
	return (fabs(u.A * v.x + u.B * v.y + u.C) / sqrtf(u.A*u.A + u.B*u.B));
}

double Dist(pt &u, pt &v){
	return (sqrt((u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y)));
}

pt Intersect(line &u, line &v){
	pt c;
	c.x = (v.b-u.b)/(u.a-v.a);
	c.y = (u.a*c.x + u.b);
	return c;
}

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convexHull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }
    
    a = st;
}

int main(){
	
	int n;
	cin>>n;
	vector<pt>hull(n), aux;
	for(int i=0; i<n; i++)
		cin>>hull[i].x>>hull[i].y;
		
	aux = hull;
	convexHull(hull);
	vector<line>lines;

	for(int i=0; i<(int)hull.size(); i++){
		pt a = hull[i], b = hull[(i+1)%(int)hull.size()];
		lines.push_back(line(a, b));
	}
	
	double ans = 1e9;
	for(int i=0; i<(int)lines.size(); i++){
		double h=0;
		for(int j=0; j<(int)hull.size(); j++){
			
			line x(lines[i].num, lines[i].den, hull[j]);
			pt k;
			if(lines[i].B == 0){
				k = pt(-(lines[i].C/lines[i].A), hull[j].y);
			}
			else{
				if(lines[i].A == 0){
					k = pt(hull[j].x, -(lines[i].C/lines[i].B));
				}
				else{
					k = Intersect(lines[i], x);
				}
			}
			h = max(h, Dist(k, hull[j]));
		}
		ans = min(ans, h);
	}
	cout << fixed << setprecision(7) << ans << endl;
}
