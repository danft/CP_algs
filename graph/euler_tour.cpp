#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define INF 0x3f3f3f3f
#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define N 2002

vi adj[N];
vi ed[N];
vi euler_path;
int n, m;
int deg[N];
vector<bool>mark;
vector<bool>vis;
int vert[N];

void dfs1(int u) {
	mark[u] = 1;
	for( int i = 0; i<adj[u].size(); i++ )
		if( !mark[adj[u][i]] )
			dfs1(adj[u][i]);
}

bool isconected( int u ) {
	mark = vector<bool>( n, 0 );
	dfs1( u ); 
	for( int i =  0; i < n; i++ )
		if( !mark[i] && vert[i] ) return false;
	return true;
}

void dfs_euler( int u ) {

	while( !adj[u].empty() )
	{
		int v = adj[u].back();
		adj[u].pop_back();
		int edid = ed[u].back();
		ed[u].pop_back();

		if( vis[ edid ] ) /*is the edge marked*/
			continue;
		vis[ edid ] = 1;
		dfs_euler( v );
	}
	euler_path.pb( u );
}

bool even( ) {
	bool ok = true;
	for( int i = 0; i<100; i++ ) {
		ok &= deg[i]%2 == 0;
	}
	return ok;
}

int main(){

	return 0;
}
