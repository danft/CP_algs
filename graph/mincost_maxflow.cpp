#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int N = 320;
const int oo = 100000;

struct edge {
	int v, cost, cap, flow, back;
	edge(){}
	edge(int v, int cost, int cap, int back) :v(v), cost(cost), cap(cap), flow(0), back(back) {}
};

vector<edge> adj[N];
int so, si, n, m;
int prv[N], prv_edge[N], dist[N], phi[N];

void add_edge(int u, int v, int cost, int cap) {
	edge e1(v, cost, cap, adj[v].size());
	edge e2(u, -cost, 0, adj[u].size());
	adj[u].pb(e1);
	adj[v].pb(e2);
}

void init() {
	for(int i = 0; i<N; i++)
		adj[i].clear();
}

/*soh precisa se os pesos iniciais podem ser negativos*/
void bellman_ford() {
	for(int i =0;i<n;i++)
		phi[i]=oo;
	phi[so]=0; 
	for(int i=0; i<n-1; i++)
		for(int u=0;u<n;u++) if(phi[u]<oo)
			for(int j = 0;j <adj[u].size();j++) {
				int v=adj[u][j].v;
				if(phi[v]>phi[u]+adj[u][j].cost && adj[u][j].cap)
					phi[v]=phi[u]+adj[u][j].cost;
			}
}

bool dijkstra() {
	memset(prv,-1,sizeof(prv));
	memset(prv_edge,-1,sizeof prv_edge);
	fill(dist,dist+n,oo);

	priority_queue<ii,vector<ii>, greater<ii> > pq;
	dist[so]=0;
	pq.push(ii(0,so));

	bool ret=false;
	while(!pq.empty()) {
		int u=pq.top().second;
		int du=pq.top().first;
		pq.pop();
		if( u == si ){ ret=true;}

		if(du > dist[u])continue;
		for(int i = 0;i <adj[u].size();i++) {
			int v=adj[u][i].v;
			if(adj[u][i].cap-adj[u][i].flow <= 0)continue;
			if(dist[v] > dist[u]+phi[u]-phi[v]+adj[u][i].cost) {
				dist[v]=dist[u]+phi[u]-phi[v]+adj[u][i].cost;
				prv[v]=u;
				prv_edge[v]=i;
				pq.push(ii(dist[v],v));
			}
		}
	}

	for(int i = 0; i<N; i++)
		if(phi[i]<oo && dist[i]<oo)
			phi[i]+=dist[i];
	return ret;
}

int aug() {
	int mw=oo;
	for(int u=si; u!=so; u=prv[u]) 
		mw=min(mw,adj[prv[u]][prv_edge[u]].cap - adj[prv[u]][prv_edge[u]].flow);	
	int r=0;
	for(int u=si; u!=so; u=prv[u]) {
		adj[prv[u]][prv_edge[u]].flow += mw;
		adj[u][adj[prv[u]][prv_edge[u]].back].flow -= mw;
		/*depends maybe you need to multiply by the flow*/
		r += adj[prv[u]][prv_edge[u]].cost;
	}
	return r;
}

int min_const_max_flow() {

	int r=0;	
	bellman_ford();
	while(dijkstra()) {
		int rinc = aug();
		r+=rinc;
	}
	return r;
}
