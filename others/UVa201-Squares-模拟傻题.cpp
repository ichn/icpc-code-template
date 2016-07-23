#include <bits/stdc++.h>
using namespace std;

int n, m;

char gchar() {
	char r = getchar();
	while (r == ' ' || r == '\n' || r == '\r')
		r = getchar();
	return r;
}

set<pair<int, int> > rd;

int id(int i, int j) {
	return n * (i - 1) + j;
}

int cnt[10];

int chk(int sz, int x, int y) {
	for (int i = 1; i <= sz; ++i) {
		if (rd.find(make_pair(id(x + i - 1, y), id(x + i, y))) == rd.end())
			return 0;
		if (rd.find(make_pair(id(x + i - 1, y + sz), id(x + i, y + sz))) == rd.end())
			return 0;
		if (rd.find(make_pair(id(x, y + i - 1), id(x, y + i))) == rd.end())
			return 0;
		if (rd.find(make_pair(id(x + sz, y + i - 1), id(x + sz, y + i))) == rd.end())
			return 0;

	}
	return 1;
}

int main() {

#ifdef LOCAL_PC
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tCase = 0;
	while (scanf("%d", &n) != EOF) {
		if (tCase != 0) {
			puts("");
			puts("**********************************");
			puts("");
		}
		scanf("%d", &m);
		rd.clear();
		while (m--) {
			int u, v;
			if (gchar() == 'H') {
				scanf("%d%d", &u, &v);
				rd.insert(make_pair(id(u, v), id(u, v+1)));
			} else {
				scanf("%d%d", &u, &v);
				swap(u, v);
				rd.insert(make_pair(id(u, v), id(u+1, v)));
			}
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					cnt[i] += chk(i, j, k);

		}
		printf("Problem #%d\n\n", ++tCase);
		bool flag = false;
		for (int i = 1; i <= n; ++i)
			if (cnt[i] != 0) {
				printf("%d square (s) of size %d\n", cnt[i], i);
				flag = true;
			}
		if (!flag) {
			printf("No completed squares can be found.\n");
		}
	}
	
	return 0;
}
