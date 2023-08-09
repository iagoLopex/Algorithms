#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

int MxArea(vector<int>&hist){
	stack<int>stk;
	int left[n+2], right[n+2];
	hist[0]=hist[n+1]=-1;
	
	stk.push(0);
	for(int i=1; i<=n; i++){
		while(hist[stk.top()] >= hist[i])
			stk.pop();
		left[i] = i - stk.top();
		stk.push(i);
	}
	
	while(!stk.empty()) 
		stk.pop();
	
	stk.push(n+1);
	for(int i=n; i>=1; i--){
		while(hist[stk.top()] >= hist[i])
			stk.pop();
		right[i] = stk.top() - i;
		stk.push(i);
	}
	
	//~ for(int i=1; i<=n; i++){
		//~ cout << hist[left[i]] << " ";
	//~ }
	//~ cout << endl;
	//~ for(int i=1; i<=n; i++){
		//~ cout << hist[right[i]] << " ";
	//~ }
	//~ cout << endl;
	
	int ans=0;
	for(int i=1; i<=n; i++){
		int tam = right[i] + left[i] - 1;
		ans = max(ans, tam * hist[i]);
	}
	return ans;
}

signed main(){
	cin>>n;
	while(n){
		vector<int>hist(n+2);
		for(int i=1; i<=n; i++){
			cin>>hist[i];
		}
		cout << MxArea(hist) << '\n';
		cin>>n;
	}
}
