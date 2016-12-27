#include <bits/stdc++.h>

const int N = 4010001;
/*
TODO: add support for lazy propagation 
 */

/*
T must have an empty constructor
T must have an + operator implemented it should be assoc 
T must have a neutral element if we're taking max the neutral element is INT_MIN
 */
template <typename T>
class stree_t {
	private:
		T st[N];
		T I;
		int n;
		void upd (int p, int l, int r, int a, const T &val) {
			if (l > a || r < a) return;
			if (l==r) {
				st[p] = val;
				return ;
			}
			upd (p<<1, l, (l+r)/2, a, val);
			upd (p<<1|1, (l+r)/2+1, r, a, val);

			st[p] = st[p<<1] + st[p<<1|1];
		}
		T que (int p, int l, int r, int a, int b) const {
			if (l > b || r < a) 
				return  I;
			if (l >= a && r <= b)
				return st[p];
			T r1 = que (p<<1, l, (l+r)/2, a, b);
			T r2 = que (p<<1|1, (l+r)/2+1, r, a, b);
			return r1 + r2;
		}
	public:
		/*I is the identity element a + I = I + a = a*/
		stree_t (int n, T I) :n(n), I(I){
			for (int i = 0; i<=4*n; ++i)
				st[i] = I;
		}
		void clear (const T &x) {
			for (int i = 0; i<N; ++i)
				st[i] = x;
		}
		void upd (int a, const T &val) {
			upd (1, 1, n, a, val);
		}

		T que(int a, int b) const {
			return que (1, 1, n, a, b);
		}
};
