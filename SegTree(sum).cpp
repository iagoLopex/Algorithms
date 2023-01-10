#include <bits/stdc++.h>
using namespace std;

struct no{
    long long int v;
};

no seg[400020];
int vet[100005];

no f(no a, no b){
    no c;
    c.v = a.v + b.v;
    return c; 
}

no build(int l, int r, int t){

    if(l == r){
        seg[t].v = vet[l];
        return seg[t];
    }
    int mid = (l+r)>>1;
    return seg[t] = f(build(l, mid, 2*t), build(mid+1, r, 2*t+1));
}

no query(int i, int j, int l, int r, int t){
    if(r<i || l>j)
        return {0};
    if(l>=i && r<=j)
        return seg[t];
    int mid = (l+r)>>1;
    return f(query(i, j, l, mid, 2*t), query(i, j, mid+1, r, 2*t+1));
}

no update(int i, int value, int l, int r, int t){
    if(i<l || i>r) 
        return seg[t];
    if(i == l && r == i){
        vet[l]=value;
        seg[t].v = value;
        return seg[t];
    }
    int mid = (l+r)>>1;
    return seg[t] = f(update(i, value, l, mid, 2*t), update(i, value, mid+1, r, 2*t+1));
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>vet[i];
    }
    build(0, n-1, 1);
    int q,a,b;
    for(int i=0; i<m; i++){
        cin>>q>>a>>b;
        no c;
        if(q == 1){
            c = update(a, b, 0, n-1, 1);
        }
        else{
            c = query(a, b-1, 0, n-1, 1);
            cout<<c.v<<endl;
        }
    }
}
