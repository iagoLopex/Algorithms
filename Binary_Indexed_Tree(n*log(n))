#include <bits/stdc++.h>

using namespace std;

long long int bit[10000004];
int n;

void upd2(int, int);

void upd1(int l, int r, int v){
	upd2(l, v);
	upd2(r+1, -v);
}

void upd2(int ind, int v){
	for(;ind<=n; ind+= ind & -ind){
		bit[ind] += v;																								
	}
}

long long int query(int ind){
	long long int ans=0;
	for(;ind>0;ind-= ind & -ind)
		ans+=bit[ind];
	return ans;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int m, o, a, b, c;
	char f;
	cin >> n >> m >> o;
	upd1(1,n,o);
	while(m--){
		cin >> f;
		if(f == 'Q'){
			cin >> a;
			cout << query(a) << '\n';
		}
		else{
			cin>>a>>b>>c;
			upd1(a, b, c);
		}
	}
}
