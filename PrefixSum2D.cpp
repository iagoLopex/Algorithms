#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

signed main(){
	int n, q, x1, y1, x2, y2;
	cin>>n>>q;
	char mat[n+1][n+1];
	int pref[n+1][n+1];
	memset(pref, 0, sizeof pref);
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>mat[i][j];
	
	pref[1][1] = (mat[1][1] == '*');
	
	for(int j=2; j<=n; j++)
		pref[1][j] = pref[1][j-1] + (mat[1][j] == '*');
	for(int i=2; i<=n; i++)
		pref[i][1] = pref[i-1][1] + (mat[i][1] == '*');
	
	for(int i=2; i<=n; i++)
		for(int j=2; j<=n; j++)
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (mat[i][j] == '*');
	
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		cout << pref[x2][y2] - pref[x1-1][y2] - (pref[x2][y1-1] - pref[x1-1][y1-1]) << '\n';
	}
}
