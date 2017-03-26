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
const int N = 100010;

/*
Persistent segment tree 
 */

struct node{
	int l, r, v;
	node (): l(-1), r(-1), v(0) {}
	node (int l, int r, int v): l(l), r(r), v(v) {}
};

int n, k, vec[N], v[N];
node tree[20*4*N];
int tree_size;

// p is the tree index
int build(int l, int r) {
	if (l == r) {
		tree[tree_size] = node(-1, -1, v[l]);
		return tree_size++; 
	}

	int mi = (l+r)/2;

	int u = tree_size++;
	tree[u] = node();

	tree[u].l = build(l, mi);
	tree[u].r = build(mi+1, r);
	tree[u].v = tree[tree[u].l].v + tree[tree[u].r].v;

	return u;
}

// point update
// returns the new root index
int update(int p, int l, int r, int ux) {
	if (l==r) {
		tree[tree_size] = node(-1, -1, v[l]);
		return tree_size++;
	}

	int mi = (l+r)/2;
	int u = tree_size++;
	tree[u] = tree[p];

	if (ux > mi)
		tree[u].r = update(tree[u].r, mi+1, r, ux);
	else 
		tree[u].l = update(tree[u].l, l, mi, ux);

	tree[u].v = tree[tree[u].l].v + tree[tree[u].r].v;

	return u;
}

// query

int que(int p, int l, int r, int x) {
	if (l==r) {
		return tree[p].v > x ? -1 : l;
	}

	int mi = (l+r)/2;
	int ret = mi;
	if (tree[tree[p].l].v <= x)
		ret = max(ret, que(tree[p].r, mi+1, r, x - tree[tree[p].l].v));
	else ret = que(tree[p].l, l, mi, x);

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;
	vi nxt(n+1, n), prv(n+1, -1);

	For (i,0,n) {
		cin >> vec[i];

		if (prv[vec[i]] != -1) {
			nxt[prv[vec[i]]] = i;
		}
		else
			v[i] = 1;

		prv[vec[i]] = i;
	}

	vi root(n);
	root[0] = build (0, n-1);

	for (int i = 0; i<n-1; ++i) {
		v[i] = 0;
		root[i+1] = update(root[i], 0, n-1, i);

		if (nxt[i] < n) {
			v[nxt[i]] = 1;
			root[i+1] = update(root[i+1], 0, n-1, nxt[i]);
		}
	}

	for (int i = 1; i<=n; i++) {
		int l = 0, ans = 0;	
		//cout << i <<":\n";
		while (l < n) {
			//cout << l << "# ";
			l = que(root[l], 0, n-1, i) + 1;
			++ans;
		}
		cout << ans << " ";
	}
	cout << '\n';

	
	
	return 0;
}
