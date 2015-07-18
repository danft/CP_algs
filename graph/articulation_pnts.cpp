#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define N 100

vi adj[N];
vi dfsnum, low, p;
int n,t;
set<int> res ;

void dfs( int u ) {

	dfsnum[ u ] = ++t;
	low[ u ] = dfsnum[u];

	int children = 0;
	for(int v:adj[u])
		if( dfsnum[ v ]==0 )
		{
			children++;
			p[v] = u;
			dfs( v );
			low[u] = min( low[u], low[v] );

			/*for bridges modify it a bit*/
			if( p[u] == -1 && children > 1 )
				res.insert( u ) ;
			else if( p[u] != -1 && low[v] >= dfsnum[u] )
				res.insert( u );
		}
		else if( v != p[u] )
			low[u]= min( low[u], dfsnum[v] );
}
