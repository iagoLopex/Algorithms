#include <bits/stdc++.h>

using namespace std;
vector<int>vec;
vector<bool>vis(100);

void permutation(int n, int x, int q, int ini){
    
    if(x == n+1){
        for(int i=0; i<=q; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for(int i=ini; i<=n; i++){
            
            if(vis[i] == false){
                
                vis[i] = true;
                vec.push_back(i);
                permutation(n, x+1, q, ini);
                vis[i] = false;
                vec.pop_back();
            }    
        }
    }
}

int main(){
    int quant, ii, dd;
    cin >> ii >> dd;
    quant = dd-ii;
    permutation(dd, ii, quant, ii);
}
