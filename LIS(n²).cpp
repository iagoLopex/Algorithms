#include <bits/stdc++.h>

using namespace std;

vector<int> lis(vector<int>&vec){
	int n = vec.size();
	vector<int>dp(n, 1), p(n, -1);
	
	int ans = -1, index = -1;
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(vec[j] < vec[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				p[i] = j;
				
				//pego o ultimo maior
				if(ans <= dp[i]){
					ans = dp[i];
					index = i;
				}
			}
		}
	}
	vector<int> subseq;
    while (index != -1) {
        subseq.push_back(vec[index]);
        index = p[index];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<int>vec;
	int n;
	while(cin>>n){
		vec.push_back(n);
	}
	vector<int>f = lis(vec);
	cout<< f.size() << "\n-\n";
	for(auto i : f)
		cout << i << endl;
}
