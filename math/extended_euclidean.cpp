#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> ii;

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
