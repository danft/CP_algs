#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;
const int INF=0x3f3f3f3f;
const int N=2210;

int so, si, cap[N][N], flow[N][N];
int prv[N];

vi adj[N];
int n, m, t;

void add_edge(int u, int v, int cc) {
	cap[u][v]=cc;
	adj[u].pb(v);
	adj[v].pb(u);
}
void init() {
	so=0,si=n+1; //si nem sempre eh no n+1
	For(i,0,N)adj[i].clear();
	memset(cap,0,sizeof cap);
	memset(flow,0,sizeof flow);
}
/*se precisar repartir os vertices (imo melhor maneira)*/
int inline inu(int u) {
	return u<<1;
}
int inline outu(int u) {
	return u<<1|1;
}

bool bfs() {
	queue<int> q;
	memset(prv, -1, sizeof prv);
	prv[so]=-2;
	q.push(so);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u==si)return true;
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(prv[v]==-1 && cap[u][v] - flow[u][v] > 0 )
			{
				prv[v]=u;
				q.push(v);
			}
		}
	}
	return false;
}
int aug() {
	int mf=INF;
	for(int v=si;v!=so;v=prv[v])
		mf=min(mf, cap[prv[v]][v] - flow[prv[v]][v]);
	for(int v=si;v!=so;v=prv[v])
	{
		flow[prv[v]][v]+=mf;
		flow[v][prv[v]]-=mf;
	}
	return mf;
}

int maxflow() {
	int r=0;
	while(bfs())
		r+=aug();
	return r;
}
