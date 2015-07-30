#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define N 26*26 + 10

const int INF=0x3f3f3f3f;
vector< ii > adj[N];
int dist[N][N];

void karp(int n){
    for(int i = 0;i<n;++i)
    	if(!adj[i].empty())
        	adj[n].push_back(make_pair(i,0));
    ++n;
    
    for(int i = 0;i<n;++i)
        fill(dist[i],dist[i]+(n+1),INF);
    
    dist[n-1][0] = 0;
    
    for (int k = 1;k<=n;++k) for (int u = 0;u<n;++u){
        if(dist[u][k-1]==INF) continue;
        
        for(int i = adj[u].size()-1;i>=0;--i)
	{
		int v=adj[u][i].first;
            dist[adj[u][i].first][k] = min(dist[v][k],dist[u][k-1]+adj[u][i].second);
	}
    }
    bool hascyc=false;
    
    for(int i = 0;i<n ;++i)
        if(dist[i][n]!=INF)
            hascyc= true;
    
    if(!hascyc){
        //graph is acyclic
        printf("No solution.\n");
        return;
    }
    
    double ans = 1e15;
    
    for(int u = 0;u+1<n;++u){
        if(dist[u][n]==INF) continue;
        double W = -1e15;
        
        for(int k = 0;k<n;++k)
            if(dist[u][k]!=INF)
                W = max(W,(double)(dist[u][n]-dist[u][k])/(n-k));
        
        ans = min(ans,W);
    }
        
    printf("%.2lf\n",-ans);
}
