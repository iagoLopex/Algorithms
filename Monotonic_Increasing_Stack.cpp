#include <bits/stdc++.h>
using namespace std;

int n=6;
vector<int>arr={ 1, 4, 5, 3, 12, 10 };

void IncStk(){
	stack<int> stk;
	for (int i=0; i<n;i++) {
		//monotonic increasing
		while (!stk.empty() && stk.top() > arr[i]) {
			stk.pop();
		}
		stk.push(arr[i]);
	}
  int x=(int)stk.size(), j=x-1;
  vector<int>ans(x, 0);
  
	while (!stk.empty()) {
		ans[j] = stk.top();
		stk.pop();
		j--;
	}
}

int main(){
	IncStk();
	return 0;
}
