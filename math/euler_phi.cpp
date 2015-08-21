#include <bits/stdc++.h>
/*
euler phi is multiplicative, so if n=pa^a pb ^b... phi(n)=phi(pa^a) * phi(pb^b)... 
phi(pa^a)=pa^a - pa^(a-1) ******* 
 */
const int N=4000002;
int phi[N];

void sieve() {
	for(int i=1;i<N;i++)phi[i]=i;
	for(int i=2;i<N;i++)
		if(phi[i]==i)
			for(int j=i;j<N;j+=i)
				phi[j]-=phi[j]/i;
}
