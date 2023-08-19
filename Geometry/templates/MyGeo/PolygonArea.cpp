int area(const vector<pt>&vec){
	int ans=0, n = (int)vec.size();
	for(int i=0; i<n; i++){ ans += ((vec[i].x*vec[(i+1)%n].y) - (vec[(i+1)%n].x*vec[i].y)); }
	return abs(ans)/2;
}
