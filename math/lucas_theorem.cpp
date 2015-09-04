#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mk make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define mod 1000003

ll mul( ll a, ll b ) {
        return ( a%mod * b%mod )%mod;
}
ll sum( ll a, ll b ) {
        return (a%mod + b%mod )%mod;
}

ll gcd( ll a, ll b ) {
        return (b)?gcd(b,a%b):a;
}

void gcdEx( ll a, ll b, ll &x, ll &y, ll &g ) {
        if( !b ) { x=1,y=0,g=a;return;}
        gcdEx(b,a%b, x, y, g );
        ll x1 = y;
        ll y1 = x-(a/b)*y;
        x = x1;
        y = y1;
}

ll inverse( ll a ) {
        ll x,y,g;
        gcdEx(a,mod,x,y,g);
        return (x%mod + mod)%mod;
}

ll inv[2*mod], fat[2*mod];

void init() {
        inv[1] = 1;
        inv[0] = 0;
        for( int i = 2; i <= mod; ++i )
                inv[i] = (mod - (mod/i)*inv[mod%i]%mod)%mod;
        fat[0] = fat[1] = 1;
        for( int i = 2; i<=mod; i++ )
                fat[i] = mul(fat[i-1], i );
}

ll choose( ll n, ll k ) {
        if( k > n ) return 0;
        //cout << n << " " << k << endl;
        if( n >= mod || k >= mod)
        {
                ll ans = 1;
                while( n >0 )
                {
                        ans = mul(ans,choose( n%mod, k%mod ));
                        n /= mod;
                        k /= mod;
                }
                return ans;
        }
        ll num = fat[n];
        ll den = mul(fat[k],fat[n-k]);
        return mul(num,inv[den]);
}

int main(void) {
        return 0;
}
