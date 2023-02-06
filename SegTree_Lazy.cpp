#include <bits/stdc++.h> 

using namespace std; 
  
#define int long long

const int MAX = 1e5 + 5;
  
int seg[4 * MAX], lazy[4 * MAX], vet[MAX]; 
  
void push(int t, int child){
    if(lazy[t]){
		
		seg[t]+= (child + 1)*lazy[t];
		
		if(child){ 
			lazy[2*t] += lazy[t];
			lazy[2*t+1] += lazy[t];
		}
		lazy[t] = 0;
    }
}
  
int build(int l, int r, int t){ 
 
	if(l == r){
	seg[t] = vet[l];
		return seg[t]; 
	} 
	int mid = (l+r)>>1;
	return seg[t]=build(l,mid,2*t)+build(mid+1,r,2*t+1);
} 
  
int query(int i, int j, int l, int r,int t){ 
	push(t, r-l);
	if(r<i||l>j)
		return 0;
	if(l>=i && r<=j)
		return seg[t]; 
	int mid=(l+r)>>1; 
	return (query(i,j,l,mid,2*t)+ query(i,j,mid+1,r,2*t+1));
}
  
int update(int i,int j, int valu, int l, int r,int t){ 
	push(t, r-l);
	if(r < i || l > j)
		return seg[t];
	if(l>=i && r<=j){
		lazy[t] += valu;
		push(t, r-l);
		return seg[t]; 
	} 
	int mid = (l+r)>>1; 
	return seg[t]=(update(i,j,valu,l,mid,2*t)+update(i,j,valu,mid+1,r,2*t+1));
}

signed main(){ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, a;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>vet[i];
	build(0, n-1, 1);
	while(m--){
		cin>>a,--a;
		update(0, a, -1, 0, n-1, 1);
	}
	int cont = 0;
	for(int i = 0; i < n; i++) {
		if(query(i, i, 0, n - 1, 1) <= 0) {
			cont++;
		}
	}
	cout << cont << '\n';
}
