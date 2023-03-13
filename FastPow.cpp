int f11(int k, int n){
	if(n == 0) return 1;
	int x = f11(k, n / 2);
	if(n & 1) return x * x * k;
	return x * x;
}
