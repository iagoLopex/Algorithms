#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vi p, vec;

void printLis(int i){
    if(p[i]==-1){
        cout << vec[i] << endl;
        return;
    }
    printLis(p[i]);
    cout << vec[i] << endl;
}

void LIS(int x){
    
    int k=0, lis_end=0;
    vi L(x, 0), L_id(x, 0);
    p.assign(x, -1);
    
    for(int i=0; i<x; i++){
        
        int pos = lower_bound(L.begin(), L.begin()+k, vec[i]) - L.begin();
        
        L[pos] = vec[i];                //store the value
        L_id[pos] = i;                  //store the index
        p[i] = pos ? L_id[pos-1] : -1;  //take de predecessor value
        
        if(pos == k){
            k=pos+1;
            lis_end=i;
        }
    }
    cout << k << "\n-\n";
    printLis(lis_end);
}

int main(){
    
    int n;
    while(cin>>n)
        vec.push_back(n);
    
    LIS((int)vec.size());
}
