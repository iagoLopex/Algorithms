//exercice 706D codeforces

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define endl '\n'
#define pb push_back
#define int unsigned long long
#define sz(vec) (int)vec.size()
#define fin  freopen("int", "r", stdin)
#define fout freopen("out", "w", stdout)
#define FORr(vec) for(int i = 0; i < sz(vec); i++) cin >> vec[i];
#define FORw(vec) for(int i = 0; i < sz(vec); i++) cout << vec[i] << " \n"[i==sz(vec)-1];
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

/*-------------------------------------------------------------------------------------------*/

struct node{
  node*left;
  node*right;
  int cnt;
  bool leaf;
  
  node(){ leaf=false; cnt=0; left=nullptr; right=nullptr; }
};

class trie{
public:
	node* root;
	vector<string>ans;
	
	trie(){ root = new node; insert(0); }
	
	void insert(int x){
		node *aux = root;
		for(int i = (1<<30); i; i>>=1){
			if(x&i){//1 direita
				if(!(aux->right))
					aux->right = new node;
				aux = aux->right;
			}
			else{
				if(!(aux->left))
					aux->left = new node;
				aux = aux->left;
			}
			aux->cnt++;
		}
		aux->leaf=true;
	}
	
	void delet(int x){
		node *aux = root;
		for(int i = (1<<30); i; i>>=1){
			if(x&i)//1 direita
				aux = aux->right;
			else
				aux = aux->left;
				
			aux->cnt--;
		}
	}
	
	int mXor(int x){
		
		int ans=0;
		node *aux = root;
		for(int i = (1<<30); i; i>>=1){
			
			if(aux->right && aux->left){//se ambos os nodes existem
				
				if(aux->right->cnt && aux->left->cnt){//se tenho ambos
					
					if(x&i) aux = aux->left; //prioridade 0, se é 1
					else aux = aux->right;
					
					//~ cout << "i: " << i << endl;
					ans = ans + i;
					//~ cout << "ans " << ans << endl;
				}
				else{
					if(aux->right->cnt){//só posso ir pra direita
						aux = aux->right;
						
						if(!(x&i)) // se é o sinal contrario, soma
							ans = ans + i;
					}
					else{
						aux = aux->left;
						
						if(x&i) // se é o sinal contrario, soma
							ans = ans + i;
					}
				}
			}
			else{
				
				if(aux->right){//so existe direita
					aux = aux->right;
					
					if(!(x&i)) // se é o sinal contrario, soma
						ans = ans + i;
				}
				else{
					aux = aux->left;
					
					if(x&i) // se é o sinal contrario, soma
						ans = ans + i;
				}
			}
		}
		return max(x, ans);
	}
	
	void print(){
		cout << "------------------------------\n";
		auto dfs = [&](auto dfs, node*t, string path) -> void{
			if(t->leaf){ cout << "path " << path << endl; }
			if(t->right) dfs(dfs, t->right, path+"1");
			if(t->left) dfs(dfs, t->left, path+"0");
		};
		dfs(dfs, root, "");
		cout << "------------------------------\n";
	}
};

signed main(){
	
	trie a;
	
	int q, v;
	char op;
	cin>>q;
	while(q--){
		cin>>op>>v;
		if(op=='+'){
			a.insert(v);
		}
		else{
			if(op=='-'){
				a.delet(v);
			}
			else{
				cout << a.mXor(v) << endl;
			}
		}
	}
}
