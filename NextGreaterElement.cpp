#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

vector<int> NextGreater(const vector<int>& nums) {
	stack<pair<int,int>> stk;
	vector<int> result(nums.size(), -1);
	
	for (int i = 0; i < (int)nums.size(); i++){
		while (!stk.empty() && nums[i] > stk.top().f) {
			result[stk.top().s] = nums[i];
			stk.pop();
		}
		stk.push({nums[i], i});
	}
	return result;
}

int main(){
	
	vector<int> nums = {4, 5, 2, 25, 7, 18};
	vector<int> ans = NextGreater(nums);
	
	for(auto k: ans)
		cout << k << ' ';
}
