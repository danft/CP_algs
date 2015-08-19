#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

/*testado no LA-3523*/
const int N=10010;

vi adj[N], mark, low, prv, ublock;
vector<vi> block;
vector<ii> st;
int n, m, cnt, block_cnt;

void dfs(int u) {
    mark[u]=low[u]=++cnt;


    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!mark[v]){
            st.push_back(ii(u,v));
            prv[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v] >= mark[u])/*u eh um ponto de articulacao*/
            {
                vi tmp;
                ++block_cnt;
                while(1)
                {
                    int w[2]={st.back().fi, st.back().se};
                    st.pop_back();
                    for(int k=0;k<2;k++)
                    if(ublock[w[k]]!=block_cnt) {
                        ublock[w[k]]=block_cnt;
                        tmp.pb(w[k]);
                    }
                    if(w[0]==u&&w[1]==v)break;
                }
                if(low[v]==mark[u]) /*se low[v] > mark[u], (u,v) eh bridge, temos q tratar separado*/
                    block.pb(tmp);
            }
        }else if(prv[u]!=v) /*grafo nao direcionado, preciso disso pra achar bridges*/
            low[u]=min(low[u],mark[v]);
    }

}
/*acha todas as componentes bi-connexas*/
void find_bcc() {
    mark=vi(n,0);
    low=vi(n,0);
    st.clear();
    prv=vi(n,-1);
    block.clear();
    ublock=vi(n,0);
    block_cnt=0;
    cnt=0;
    for(int u=0;u<n;u++) if(!mark[u])dfs(u);
}
