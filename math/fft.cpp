#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const double PI=acos(-1);

typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n=(int) a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit=n>>1;
		for (;j>=bit;bit>>=1)
			j-=bit;
		j+=bit;
		if(i<j)
			swap(a[i],a[j]);
	}
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w(1);
			for (int j=0; j<len/2; ++j) {
				base u=a[i+j], v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if (invert)
		for(int i=0;i<n;++i)
			a[i]/=n;
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n=1;
	while (n<max(a.size(),b.size())) n<<=1;
	n<<=1;
	fa.resize(n),fb.resize(n);
	fft (fa,false);  fft(fb,false);
	for (size_t i=0; i<n; ++i)
		fa[i]*=fb[i];
	fft (fa, true);
	res.resize (n);
	for(size_t i=0; i<n; ++i)
		res[i]=int(fa[i].real() + 0.5);
}

int main() {

	int t,n;
	vector<int> a, b, c;
	char numa[300010], numb[300010];
	char ans[700010];

	scanf("%d", &t);
	while(t--) {
		scanf("%s %s", numa, numb);
		int na=strlen(numa), nb=strlen(numb);
		a.clear();b.clear();
		for(int i=na-1;i>=0;i--)
			a.pb(numa[i]-'0');
		for(int i=nb-1;i>=0;i--)
			b.pb(numb[i]-'0');
		multiply(a, b, c);

		int j=0;
		while(c.size()&&c.back()==0)c.pop_back();
		if(c.empty())c.pb(0);
		for(int i=0;i<c.size();i++) {
			if(i==c.size()-1 && c[i]>9) 
				c.pb(0);
			if(i<c.size()-1) 
				c[i+1]+=c[i]/10;
			c[i]%=10;
			ans[j++]='0'+(c[i]);
		}
		ans[j]='\0';
		reverse(ans,ans+j);
		puts(ans);
	}
	return 0;
}
