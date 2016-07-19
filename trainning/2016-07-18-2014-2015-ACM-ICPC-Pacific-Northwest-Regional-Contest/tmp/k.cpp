#include <bits/stdc++.h>
using namespace std;
namespace my_zone {
#define rep(_i, _k, _j) for(int _i = _k; _i < _j; ++_i)
#define rgo(_i, _k, _j) for(int _i = _k; _i <= _j; ++_i)
#define foreach(_i, _s) for(typeof(_s.begin()) _i = _s.begin(); _i != _s.end(); ++_i)
#define pb push_back
#define mp make_pair
#define clr(t) memset(t, 0, sizeof t);
#define clo(t, v) memcpy(t, v, sizeof t);
#define cls(t, v) memset(t,v,sizeof t);
#define pc(c) putchar(c)
#define gc() getchar()
	typedef pair<int, int> ipir;
	typedef vector<int> ivec;
	typedef set<int> iset;
	const int INF = 0x3f3f3f3f;
	typedef long long LL;
	typedef double DB;
	inline char gchar(char r=gc()) {
		for(;r==' '||r=='\n'||r=='\r';
				r=gc());return r;}
	template<class T> inline void fr(T&r) {
		char c=gc();
		for(;c<'0'||'9'<c;c=gc());
		for(r=0;'0'<=c&&c<='9';c=getchar())
			r=r*10+c-'0';
	}
	template<class T> inline void fr(T&a,T&b) {
		fr(a), fr(b);
	}
	template<class T> inline void fr(T&a,T&b,T&c) {
		fr(a), fr(b), fr(c);
	}
	int fr() {
		int r=0;char c=gc();
		for(;c<'0'||'9'<c;c=gc());
		for(r=0;'0'<=c&&c<='9';c=getchar())
			r=r*10+c-'0';
		return r;
	}
	const int maxE = 10000, maxV = 10000;
	struct Edge {
		int e, h[maxV], to[maxE], nxt[maxE];
		void init() {
			cls(h,-1);
			e=0;
		}
		void addEdge(int u,int v) {
			to[e] = v, nxt[e] = h[u], h[u] = e++;
		}
	};
};
using namespace my_zone;


int n;

char p[10][10];

vector<pair<int, vector<int> > > per;
vector<int> t;

int calc(vector<int> s) {
	int r = 0, m = 0;
	foreach(i, s) {
		if ((*i) > m) {
			++r;
			m = (*i);
		}
	}
	return m;
}

int main() {
#ifdef lol
	freopen("k.in", "r", stdin);
	freopen("k.out", "w", stdout);
#endif

	int tCase = fr();
	while (tCase--) {
		n = fr();
		rgo(i, 0, n+1)
			rgo(j, 0, n+1)
				p[i][j] = gchar();
		t.clear();
		per.clear();
		rgo(i, 1, n) t.pb(i);
		sort(t.begin(), t.end());
		do {
			per.pb(mp(calc(t), t));
		} while (next_permutation(t.begin(), t.end()));
	//	cout << per.size() << endl;
		sort(per.begin(), per.end());
	}
		

	return 0;
}
