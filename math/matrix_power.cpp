void mu(ll a[][N], ll b[][N], ll c[][N]) {
	for(int i=0;i<x;i++)
		for(int j=0;j<x;j++) {
			c[i][j]=0;
			for(int h=0;h<x;h++) {
				c[i][j]+=(a[i][h]*b[h][j])%mod;
				c[i][j]%=mod;
			}
		}
}
/*returns ans=mat^b*/
void power(ll b) {
	for(int i=0;i<x;i++)
		ans[i][i]=1;
	while(b) {
		if(b&1) {
			mu(ans, mat, tmp);
			for(int i=0;i<x;i++)
				for(int j=0;j<x;j++)
					ans[i][j]=tmp[i][j];
		}
		mu(mat, mat, tmp);
		for(int i=0;i<x;i++)
			for(int j=0;j<x;j++)
				mat[i][j]=tmp[i][j];
		b>>=1;
	}
}

