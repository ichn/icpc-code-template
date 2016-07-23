#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 100;
const int mod = 10007;

char str[maxn];
int z[maxn];
int n;

bool chk() {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < z[i]; ++j)
			if (str[j] != str[i + j])
				return false;
		if (str[z[i]] == str[i + z[i]])
			return false;
	}
	return true;
}

int main() {
#ifdef LOCAL_PC
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tCase;
	scanf("%d\n", &tCase);
	while (tCase--) {
		scanf("%d\n", &n);
		scanf("%s", str);
		n = strlen(str);

		int L = 0, R = 0;
		memset(z, 0, sizeof z);
		for (int i = 1; i < n; ++i) {
			if (R < i) {
				L = R = i;
				while (R < n && str[R - L] == str[R]) ++R;
				z[i] = R - L;
				--R;
			} else {
				int k = i - L;
				if (z[k] < R-i+1) z[i] = z[k];
				else {
					L = i;
					while (R < n && str[R-L] == str[R]) ++R;
					z[i] = R-L;
					--R;
				}
			}
		}
	//	for (int i = 0; i < n; ++i)
	//		printf("%d ", z[i]);
	//	puts("");
	
		int ans = n;
		for (int i = 1; i < n; ++i) {
			ans += z[i];
			ans %= mod;
		}
		printf("%d\n", ans % mod);
	}

	return 0;
}
