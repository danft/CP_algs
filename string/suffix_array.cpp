#include <bits/stdc++.h>
#define For(i,b) for(int (i)=(0);(i) < (b); ++(i))
using namespace std;

namespace suffix_array {

	const int N=2e5+1;
	char *str;
	int len,gap;
	int sa[N], rank[N], tmp[N], lcp[N];

	bool cmp(int i, int j) {
		if (rank[i]!=rank[j])
			return rank[i]<rank[j];
		i+=gap;
		j+=gap;
		return (i<len && j<len)?rank[i]<rank[j]:i>j;
	}

	void build() {
		len=strlen(str);
		For(i,len) sa[i]=i,rank[i]=str[i];
		for(gap=1;;gap*=2) {
			sort(sa, sa+len, cmp);
			For(i, len-1) tmp[i+1]=tmp[i]+cmp(sa[i], sa[i+1]);
			For(i, len) rank[sa[i]]=tmp[i];
			if (tmp[len-1]==len-1) break;
		}
	}

	void build_lcp() {
		for (int i=0,k=0;i<len;++i)if(rank[i]!=len-1) {
			for(int j=sa[rank[i] + 1]; str[i+k]==str[j+k];)
				++k;
			lcp[rank[i]] = k;
			if (k)--k;
		}
	}
}
