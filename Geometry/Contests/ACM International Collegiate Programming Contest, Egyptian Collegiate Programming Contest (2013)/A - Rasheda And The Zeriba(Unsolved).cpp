#include <bits/stdc++.h>
const long double pi = acos(-1.0);

using namespace std;

int n;
int vet[1005];

long double ang(long double R, long double l){//BAO
	long double h = ((2*R*R)-(l*l))/(2*R*R);
 	long double k = acos(h)*180.0/pi;
 	cout << "kkkkk " << k << "  h " << h << "  acos " << acos(h) << endl;
	return k;
}

long double calc(long double R, long double l){
	long double angulo = ang(R, l);
	//~ cout << "angulo " << angulo << endl;
	long double arco = (angulo * pi * R)/180.0;
	cout << "arco " << arco << endl;
	return arco;
}

bool ok(double r){
	
	cout << "\ntest Raio " << r << endl;
	double Total = pi*r*r;
	double Peri = 0;
	for(int i=0; i<n; i++){
		Peri += calc(vet[i], r);
	}
	cout << "soma " << Peri << "    Total " << Total << endl;
	return (Peri < Total);
}

int main(){
	
	//~ double a, b;
	//~ cin>>a>>b;
	//~ double x = ang(4.1231, 4.2426);
	//~ cout << x << endl;
	//~ cout << calc(4.1231, 4.2426) << endl;
	
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>vet[i];
	
	double l=1, r=1e6;
	while(l<r){
		double mid = (l+r)/2.0;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
		cout << l << " " << r << endl;
	}
}
