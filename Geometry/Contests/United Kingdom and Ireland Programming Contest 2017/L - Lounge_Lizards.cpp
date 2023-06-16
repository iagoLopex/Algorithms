#include <bits/stdc++.h>
#define f first
#define s second
#define sz(vec) (int) vec.size()

using namespace std;

const double eps = 1e-12;

int lis(vector<pair<double,int>> const& a) {
	int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i].s) - d.begin();
        if (d[l-1] < a[i].s && a[i].s < d[l])
            d[l] = a[i].s;
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}

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

double dist(const pt &a, const pt &b){
	return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int h;
	pt t;
	cin>>t.x>>t.y;
	
	map<pair<double,double>, array<vector<pair<double,int>>, 2> >mp;
	map<pair<double, double>, int>coef;
	map<double, array<vector<pair<double,int>>, 2>>ver, hor;
	
	int n; cin>>n;
	for(int i=0; i<n; i++){
		pt c;
		cin>>c.x>>c.y>>h;

		line k(t, c);
		
		if(k.A && k.B){
			if(!coef[{k.a, k.b}]){
				
				coef[{k.a, k.b}]=1;
				
				if(c.x >= t.x){
					mp[{k.a, k.b}][0].push_back({dist(c, t), h});
				}
				else{
					mp[{k.a, k.b}][1].push_back({dist(c, t), h});
				}
			}
			else{//se ja tem a equacao de reta
				
				if(c.x >= t.x){//se o x for maior ele ta pra cima 
					mp[{k.a, k.b}][0].push_back({dist(c, t), h});
				}
				else{//senao ele ta pra baixo
					mp[{k.a, k.b}][1].push_back({dist(c, t), h});
				}
			}
		}
		else{
			if(!k.B){//reta vertical (olho somente y)
				if(c.y >= t.y){
					hor[c.x][0].push_back({dist(c, t), h});
				}
				else{
					hor[c.x][1].push_back({dist(c, t), h});
				}
			}
			else{//reta horizontal (olho somente x)
				if(c.x >= t.x){
					ver[c.y][0].push_back({dist(c, t), h});
				}
				else{
					ver[c.y][1].push_back({dist(c, t), h});
				}
			}
		}
	}
	int ans=0;
	
	for(auto [a, b]: mp){
		for(int i=0; i<2; i++){
			sort(b[i].begin(), b[i].end());
			ans+=lis(b[i]);
		}
	}
	for(auto [a, b]: ver){
		for(int i=0; i<2; i++){
			sort(b[i].begin(), b[i].end());
			ans+=lis(b[i]);
		}
	}
	for(auto [a, b]: hor){
		for(int i=0; i<2; i++){
			sort(b[i].begin(), b[i].end());
			ans+=lis(b[i]);
		}
	}
	cout << ans << endl;
}
