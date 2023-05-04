#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node{
  map<char, node*>alf;
  int qnt;
  
  node(){ qnt=0; }
};

class trie{

public:
  node *root;
  
  trie(){ root=new node; }
  
  void insert(string str){
    node *aux = root;
    
    for(char k: str){
      
      //esse cara é um prefixo de algum outro 
      aux->qnt++;
        
      if(!aux->alf[k])
        aux->alf[k] = new node;
      aux = aux->alf[k];
    }
    aux->qnt++;
  }
  
  int QntPref(string str){
    node *aux = root;
    for(auto k: str){
      if(!aux->alf[k])
        return 0;
      aux = aux->alf[k];
    }
    return aux->qnt;
  }
};

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  trie a;
  string ss;
  int dicionary, query;
  cin>>dicionary>>query;
  for(int i=0; i<dicionary; i++){
    cin>>ss; a.insert(ss);
  }
  while(query--){
    cin>>ss;
    cout << a.QntPref(ss) << endl;
  }
}
