class matrix{
public:
	int n;
	V<V<double>>mat;
	
	matrix(V<V<double>>p) : mat(p) {};
	matrix(int x) : n(x), mat(n, V<double>(n)) {};
	matrix operator * (matrix const &p){
		matrix prod(n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					prod.mat[i][j] = (prod.mat[i][j] + (mat[i][k] * p.mat[k][j]));
				}
			}
		}
		return prod;
	}
};

matrix fexp(matrix p, int pot){
	matrix ID(p.n);
	for(int i=0; i<p.n; i++){ ID.mat[i][i]=1.0; }
	while(pot){
		if(pot&1) ID = ID * p;
		pot/=2, p = p * p;  
	}
	return ID;
}
