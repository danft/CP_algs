#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define mod 1000000007
#define N 60001

ll sum( ll a, ll b ) {
	return ( a%mod + b%mod + mod) %mod;
}
/*
Euler Theorem about Integer partitions:
the number of partitions of n P(n)=P(n-1)+P(n-2)-P(n-5)-P(n-7)... 
*/
int main() {
	vi dp(N);
	dp[0] = 1;
	for( int i = 1; i<N; i++ )
	{
		dp[i] = 0;
		for( int j = 1; i-j*(3*j-1)/2 >= 0; j++ )
		{
			//cout <<"!"<< j << endl;
			dp[i] = sum( dp[i], dp[i-j*(3*j-1)/2] * ((j%2)?1:(-1)) );
			if( i - j*(3*j-1)/2 - j >= 0 )
			dp[i] = sum( dp[i], dp[i-j*(3*j-1)/2-j] * ((j%2)?1:(-1)) );
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		cout << dp[x] << "\n";
	}
}
