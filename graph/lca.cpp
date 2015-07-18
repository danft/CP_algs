#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define N 50010

int n,q,dp[N][22],p[N],niv[N];

void prep() {
	for( int i = 0; i<n; i++ ) dp[i][0] = p[i];
	for( int j = 1; (1<<j) < n; j++ )
		for( int i = 0; i<n; i++ )
			dp[i][j] = dp[dp[i][j-1]][j-1];
}

int lca(int u,int v) {
	if( niv[u] < niv[v] )swap(u,v);

	for( int j = 21; j>=0; j-- ) /*21 is more than enough*/
		if( niv[u] - (1<<j) >= niv[v] ) u = dp[u][j];

	if( u == v ) return u;

	for( int j = 21; j>=0; j-- )
		if(dp[u][j]!=dp[v][j])
			u=dp[u][j], v=dp[v][j];

	return dp[u][0];
}
