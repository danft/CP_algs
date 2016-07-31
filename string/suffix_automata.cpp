#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

using namespace std;

class suffix_automata_t {
	struct node_t {
		int link, len; 
		map <char,int> next;
		bool fin;
		node_t (): link(-1), len(0), fin(0) {}
		node_t& operator=(const node_t &u) {
			link = u.link; len = u.len; next = u.next; fin = u.fin;
			return *this;
		}
	};

	public:
	static const int N = 2 * 50010; /*50010 is max length of the string*/
	node_t st[N];
	int size, p;

	suffix_automata_t() {
		size = 0;
	}
	void build (const char *str) {
		for (int i=0; i<size; ++i) {
			st[i].next.clear(); st[i].fin = false;
		}
		st[0] = node_t();
		p = 0;
		size = 1;
		for (int i = 0; str[i] != '\0'; i++)
			addchar (str[i]);
		for (int p = size-1; p > 0; p = st[p].link)
			st[p].fin = true;
	}
	void addchar (char c) {
		int curr = size++;
		st[curr].len = st[p].len + 1;
		for ( ; p != -1 && !st[p].next.count (c); p = st[p].link)
			st[p].next[c] = curr;
		if (p == -1) 
			st[curr].link = 0;
		else {
			int q = st[p].next[c];
			if (st[p].len +1 == st[q].len)
				st[curr].link = q;
			else { 
				int cl = size++;
				st[cl] = st[q];
				st[cl].len = st[p].len + 1;
				for (;p != -1 && st[p].next.count(c) && st[p].next[c] == q; p = st[p].link)
					st[p].next[c] = cl;
				st[curr].link = st[q].link = cl;
			}
		}
		p = curr;
	}
};
