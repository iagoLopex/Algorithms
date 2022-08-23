#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>vec;

void unir(int p, int r, int mid){
	
	int pAux = p;
	vector<int>mer;
	int q = mid+1;
	
	while(p<=mid && q<=r){

		if(vec[p] < vec[q]){
			mer.push_back(vec[p]);
			p++;
		}
		else{
			mer.push_back(vec[q]);
			q++;
		}
	}
	
	//insiro o restante no meu vetor auxiliar
	while(p<=mid){
		mer.push_back(vec[p]);
		p++;
	}
	while(q<=r){
		mer.push_back(vec[q]);
		q++;
	}
	
	//pego os valores do vetor auxiliar e insiro no vetor a ser ordenado
	for(int i=pAux; i<=r; i++){
		vec[i] = mer[i-pAux];
	}
}

void mergesort(int p, int r){
	
	//enquanto o p for menor do que r eu continuo criando a arvore
	if(p < r){
		int mid = (p+r)>>1;
		mergesort(p, mid);
		mergesort(mid+1, r);
		unir(p, r, mid);
		cout << "saiu\n";
	}
}

int main(){
	
	cin >> n;
	int a;
	for(int i=0; i<n; i++){
		cin >> a;
		vec.push_back(a);
	}
	cout << endl;
	mergesort(0, (n-1));
	for(int i=0; i<n; i++){
		cout << vec[i] << " ";
	}
}
