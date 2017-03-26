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
	int u = tree_size++;
	if (l==r) {
		tree[u] = node(-1, -1, v[l]);
		return u;
	}

	int mi = (l+r)/2;
	tree[u] = tree[p];

	if (ux > mi)
		tree[u].r = update(tree[u].r, mi+1, r, ux);
	else 
		tree[u].l = update(tree[u].l, l, mi, ux);

	tree[u].v = tree[tree[u].l].v + tree[tree[u].r].v;

	return u;
}

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
