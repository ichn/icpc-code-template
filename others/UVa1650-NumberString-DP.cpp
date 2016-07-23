#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 100;
const int mod = 1e9 + 7;

char s[maxn];
int n;
int f[maxn][maxn];

inline void add(int &x, int y) {
	(x += y) %= mod;
}

int main() {

#ifdef LOCAL_PC
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif


	while (scanf("%s\n", s) != EOF) {
		n = strlen(s) + 1;
		memset(f, 0, sizeof f);
		f[1][1] = 1;
		for (int i = 2; i <= n; ++i) {
			if (s[i - 2] == 'D') {
				int sum = 0;
				for (int j = 2; j <= i; ++j) {
					add(sum, f[i - 1][j - 1]);
					add(f[i][j], sum);
				}
			} else if (s[i - 2] == 'I') {
				int sum = 0;
				for (int j = i - 1; 1 <= j; --j) {
					add(sum, f[i - 1][j]);
					add(f[i][j], sum);
				}
			} else {
				int sum = 0;
				for (int j = 2; j <= i; ++j) {
					add(sum, f[i - 1][j - 1]);
					add(f[i][j], sum);
				}
				sum = 0;
				for (int j = i - 1; 1 <= j; --j) {
					add(sum, f[i - 1][j]);
					add(f[i][j], sum);
				}

			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			add(ans, f[n][i]);
		printf("%d\n", ans);
	}

	return 0;
}


/*
 
   1A，棒！
   思路是hq的。大概是只关注排名而非具体的值。
   似乎是sdoi2010地精部落的原题，当年也是看到这道题去问的hq，然后被那个牲口秒了。

 */


