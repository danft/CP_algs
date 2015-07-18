#include <bits/stdc++.h>
#define N 1000011

using namespace std;

char str[N];

int n, z[N];
/*str[i..i+z[i]-1]=str[0..z[i]-1]*/

void zeta() {
	int l = 0, r = 0;
	z[0] = n;
	for( int i = 1 ; i<n ;i++ )
	{
		if( i > r )
		{
			l = r = i;
			while( r < n && str[r-l] == str[r] ) r++; 
			z[i] = r-l, r--;
		} 
		else
		{
			int k = i-l;
			if( z[k] < r-i+1 ) z[i] = z[k];
			else {
				l = i;
				while( r < n && str[r-l] == str[r] ) r++;
				z[i] = r-l;r--;
			}
		}
	}
}
