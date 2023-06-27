#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  //encontro o tamanho do ciclo de swaps pra reposicionar o numero
  //e somo (tamanho do ciclo-1) na minha resposta
  
	int n;
	while(cin>>n){
		vector<int>vec(n);
		map<int,int>mp;
		vector<vector<int>>adj(n);

		for(int i=0; i<n; i++){
			cin>>vec[i];
		}
		vector<int>aux = vec;
		sort(begin(aux), end(aux));
		for(int i=0; i<n; i++){
			mp[aux[i]]=i;
		}

		for(int i=0; i<n; i++){
			adj[i].push_back(mp[vec[i]]);
		}

		int cont;
		vector<bool>vis(n, false);
		auto dfs = [&](auto dfs, int v) ->void{
			cont++;
			vis[v]=true;
			for(auto k: adj[v])
				if(!vis[k])
					dfs(dfs, k);
		};
		int ans=0;
		for(int i=0; i<n; i++){
			cont=0;
			dfs(dfs, i);
			ans+=(cont-1);
		}
		cout << ans << endl;
	}
}
