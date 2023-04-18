#include <bits/stdc++.h>

using namespace std;

void kmp(string &s, int p[]){
	//     menor
	int k=0;
	for(int i=1; i<(int)s.size(); i++){
		while(k>0 && s[i] != s[k]){
			k = p[k-1];
		}
		if(s[i] == s[k])
			k++;
		
		p[i]=k;
	}
}

void match(string &t, string &s, int p[], bool &ok){
	//      menor       maior
	int k=0;
	for(int i=0; i<(int)s.size(); i++){
		while(k>0 && s[i] != t[k]){
			k=p[k-1];
		}
		if(s[i]==t[k])
			k++;
		if(k == (int)t.size()){
			ok=true;
			continue;
		}
	}
}

int main(){
	int n,a;
	string s, t;
	cin>>n;
	while(n--){
		
		cin>>s; 
		cin>>a;
		int p[s.size()];
		p[0]=0;
		while(a--){
			cin>>t;
			kmp(t, p);
			bool ok=false;
			match(t, s, p, ok);
			if(ok) cout << "y\n";
			else cout << "n\n";
		}
	}
}
