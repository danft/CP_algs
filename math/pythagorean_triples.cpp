#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+10;

void prep() {
	for(ll p=1;p*p < N;++p) {
		for(ll q=p+1;1;++q) {
			if(p*p + q*q >=N )break;
			for(ll i=1; i*(p*p+q*q)<N; i++)
			{
				/*our pyt triple is: (2pq, p*p-q*q, p*p+q*q)*/
				//ispt[i*p*p+i*q*q]=1;
			//	cout<<i*p*p+i*q*q<< "@\n";
			}
		}
	}
}
