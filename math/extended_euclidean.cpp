#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> ii;
/*
Chinese Remainder Theorem:
let N=n0.n1.n2....nm /*ni is the ith moduli, which are all pairwise coprime*/
for each i, let yi=N/ni
for each i, let zi be the inverse of yi mod ni (could be done with gcdEx)
x = sum ai.yi.zi i from 0 to m
*/
ii extended_euclidean(ll a, ll b, ll &g) {
	ll y=0, x=1;
	ll yy=1, xx=0;
	
	while(b)
	{
		ll xn=x-(a/b)*xx, yn=y-(a/b)*yy;
		x=xx;y=yy;
		xx=xn;yy=yn;
		a%=b;
		swap(a,b);
	}
	g=a;
	return ii(x,y);
}
