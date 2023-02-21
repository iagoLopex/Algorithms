#include <bits/stdc++.h> 

using namespace std; 
  
#define int long long

const int MAX = 1e5 + 5;
  
struct no{
	int Psum=0; //soma do produto total
	int sum=0;  //soma individual
};

no seg[4 * MAX];
int lazy[4 * MAX], vet[MAX]; 

no f(no a, no b){
	no c;
	c.Psum = a.Psum + b.Psum;
	c.sum = a.sum + b.sum;
	return c;
}

void push(int t, int child, int l, int r){
    if(lazy[t]){
		
		seg[t].sum += (child + 1)*lazy[t];                                    //soma dos individuais
		//                      a1               an                n       2
		seg[t].Psum += ( ((lazy[t]*(l+1)) + (lazy[t]*(r+1))) * (r-l+1)) / 2; //somatorio dos produtos
		
		if(child){ 
			lazy[2*t] += lazy[t];
			lazy[2*t+1] += lazy[t];
		}
		lazy[t] = 0;
    }
}
  
no build(int l, int r, int t){ 
 
	if(l == r){
		seg[t].Psum = vet[l]*(l+1);
		seg[t].sum = vet[l];
		return seg[t]; 
	}
	int mid = (l+r)>>1;
	return seg[t] = f(build(l,mid,2*t), build(mid+1,r,2*t+1));
} 
  
no query(int i, int j, int l, int r,int t){ 
	push(t, r-l, l, r);
	if(r<i||l>j)
		return {0};
	if(l>=i && r<=j)
		return seg[t]; 
	int mid=(l+r)>>1; 
	return f(query(i,j,l,mid,2*t), query(i,j,mid+1,r,2*t+1));
}
  
no update(int i,int j, int valu, int l, int r,int t){ 
	push(t, r-l, l, r);
	if(r < i || l > j)
		return seg[t];
	if(l>=i && r<=j){
		lazy[t] += valu;
		push(t, r-l, l, r);
		return seg[t];
	}
	int mid = (l+r)>>1; 
	return seg[t] = f(update(i,j,valu,l,mid,2*t), update(i,j,valu,mid+1,r,2*t+1));
}

void show(){
	cout << endl;
	for(int i=0; i<10; i++){
		cout << i << "   seg | Psum: " << seg[i].Psum << "    sum: " << seg[i].sum << endl;
	}
	cout << endl;
}

signed main(){ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>vet[i];
	build(0, n-1, 1);
	int q, a, b, c;
	no ans;
	while(m--){
		cin>>q;
		if(q == 2){
			cin>>a>>b, --a, --b;//qry
			
			ans = query(a, b, 0, n-1, 1);
			cout << ans.Psum - ( ans.sum * (a)) << endl;
		}
		else{
			cin>>a>>b>>c,--a,--b;//upd
			update(a, b, c, 0, n-1, 1);
		}
	}
}
