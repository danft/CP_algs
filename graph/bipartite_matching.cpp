#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

/*
 * para construir o min-vertex-cover
 * faca as arestas q sao do matching direcionadas da direita pra esquerda
 * e as outras da esq pra direita
 * faca um dfs dos vertices q nao estao no matching
 * o min-verttex-cover sao os vertices NAO visitados da esquerda e os visitados da direita
 * */
#define N 610

vi adj[N];
int n, m;
int mat[N], umat[N];
bool mark[N];

bool aug(int u) {
	if(mark[u]) return false;
	mark[u] = true;
	for(int v:adj[u])
		if( mat[v] == -1 || aug( mat[v] ) )
		{
			umat[u]=v;
			mat[v]=u;
			return true;
		}
	}
	return false;
}

int mcbm( ) {
	memset(mat,-1,sizeof mat);
	memset(umat,-1,sizeof umat);

	int ret=0;
	while( 1 ) {
		memset( mark, 0, sizeof( mark ));
		int rinc=0;
		for( int i = 0; i<n; i++) if( umat[i] == -1 && !mark[i] )
			rinc+=dfs(i);
		if(!rinc)break;
		ret+=rinc;
	}
	return ret;
}
