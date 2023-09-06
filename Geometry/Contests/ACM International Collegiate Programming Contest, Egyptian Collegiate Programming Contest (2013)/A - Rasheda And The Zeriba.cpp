#include <bits/stdc++.h>
const long double pi = acos(-1.0);

using namespace std;

/*
 * Testa pro raio R qual a soma em radianos do poligono atual(usando lei dos cossenos),
 * se for menor que 2*pi diminui R, senao aumenta R
 * Nunca converta o angulo pra graus
 */

int n;
vector<int>vet(1005);

double ang(double R, double l){
	double h = acos(1 - ((l*l)/(2*R*R)));
	return h;
}

bool ok(double r){
	double Total = 2*pi;
	double Peri = 0;
	for(int i=0; i<n; i++){
		Peri += ang(r, vet[i]);
	}
	return (Peri < Total);
}

int main(){
	freopen("zeriba.in", "r", stdin);
	int tt, cnt=1;
	cin>>tt;
	while(tt--){
		
		int mx = -1, sum=0;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>vet[i];
			mx = max(mx, vet[i]);
			sum+=vet[i];
		}
		
		if(sum-mx <= mx){
			cout << "Case " << cnt++ << ": can't form a convex polygon\n";
			continue;
		}
		
		double l=1, r=1e12;
		while(r - l > 1e-6){
			
			double mid = (l+r)/2.0;
			if(ok(mid))
				r = mid;
			else
				l = mid;
		}
		cout << fixed << setprecision(4);
		cout << "Case " << cnt++ << ": " << l << '\n';
	}
}
