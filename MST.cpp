#include <bits/stdc++.h>

using namespace std;

struct UF{
    vector<int> pai,r;
    UF(int n){
        pai.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            pai[i]=i;
            r[i]=1;            
        }
    }
    UF(){}
    int acha(int x){
        if(pai[x]==x) 
            return x;
        return pai[x]=acha(pai[x]);
    }
    void unir(int x, int y){
        x=acha(x);
        y=acha(y);
        if(r[x]>r[y]){
            pai[y]=x;
            r[x]+=r[y];
        }
        else{
            pai[x]=y;
            r[y]+=r[x];
        }
    }
    bool mesmoConjunto(int x,int y){
        return acha(x)==acha(y);
    }
};
int main(){
    int n,m,x; cin >> n >> m >> x;
    vector<pair<int,pair<int,int> > >arestas;
    for(int i=0;i<m;i++){
        int a,b,p;
        cin >> a >> b >> p;
        arestas.push_back({p,{a,b}});
    }
    sort(arestas.begin(),arestas.end());
    UF arvore(n+1);
    for(int i=0;i<arestas.size();i++){
        int peso=arestas[i].first;
        int a=arestas[i].second.first;
        int b=arestas[i].second.second;
        if(!arvore.mesmoConjunto(a,b)){
            arvore.unir(a,b);
        }
    }
}

