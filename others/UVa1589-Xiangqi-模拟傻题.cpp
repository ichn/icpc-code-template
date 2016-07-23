#include <assert.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char gchar() {
	char r = getchar();
	while (r == ' ' || r == '\n' || r == '\r')
		r = getchar();
	return r;
}

int n, board[12][12];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool chk_G(int x, int y) {
	for (int i = x - 1; 0 < i; --i)
		if (board[i][y] == 'K')
			return true;
		else if (board[i][y] != 0)
			return false;
	return false;
}

bool chk_R(int x, int y) {
	for (int i = x - 1; 0 < i; --i)
		if (board[i][y] == 'K')
			return true;
		else if (board[i][y] != 0)
			return false;

	for (int i = x + 1; i < 11; ++i)
		if (board[i][y] == 'K')
			return true;
		else if (board[i][y] != 0)
			return false;

	for (int i = y - 1; 0 < i; --i)
		if (board[x][i] == 'K')
			return true;
		else if (board[x][i] != 0)
			return false;

	for (int i = y + 1; i < 10; ++i)
		if (board[x][i] == 'K')
			return true;
		else if (board[x][i] != 0)
			return false;
	return false;
}

bool chk_C(int x, int y) {
	bool mark = false;
	for (int i = x - 1; 0 < i; --i)
		if (board[i][y] == 0)
			continue;
		else if (board[i][y] != 'K') {
			if (mark)
				return false;
			mark = true;
		}
		else if (board[i][y] == 'K') {
			if (mark)
				return true;
			return false;
		}

	mark = false;
	for (int i = x + 1; i < 11; ++i)
		if (board[i][y] == 0)
			continue;
		else if (board[i][y] != 'K') {
			if (mark) return false;
			mark = true;
		}
		else if (board[i][y] == 'K') {
			if (mark)
				return true;
			return false;
		}

	mark = false;
	for (int i = y - 1; 0 < i; --i)
		if (board[x][i] == 0)
			continue;
		else if (board[x][i] != 'K') {
			if (mark) return false;
			mark = true;
		}
		else if (board[x][i] == 'K') {
			if (mark)
				return true;
			return false;
		}

	mark = false;
	for (int i = y + 1; i < 10; ++i)
		if (board[x][i] == 0)
			continue;
		else if (board[x][i] != 'K') {
			if (mark) return false;
			mark = true;
		}
		else if (board[x][i] == 'K') {
			if (mark)
				return true;
			return false;
		}

	return false;
}

int hx[] = {1, -1, 2, -2, 1, -1, 2, -2};
int hy[] = {2, 2, -1, -1, -2, -2, 1, 1};

bool chk_H(int x, int y) {
	
	for (int i = 0; i < 8; ++i) {
		int tx = x + hx[i];
		int ty = y + hy[i];
		if (!(0 < tx && tx < 4))
			continue;
		if (!(3 < ty && ty < 7))
			continue;
		if (board[tx][ty] != 'K')
			continue;
		if (hx[i] == 2) {
			if (board[x+1][y] != 0)
				continue;
			else return true;
		}
		if (hx[i] == -2) {
			if (board[x-1][y] != 0)
				continue;
			else return true;
		}
		if (hy[i] == 2) {
			if (board[x][y+1] != 0)
				continue;
			else return true;
		}
		if (hy[i] == -2) {
			if (board[x][y-1] != 0)
				continue;
			else return true;
		}
	}
	return false;
}


bool chk_ok() {
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (board[i][j] == 'G' && chk_G(i, j))
				return false;
			else if (board[i][j] == 'R' && chk_R(i, j))
				return false;
			else if (board[i][j] == 'H' && chk_H(i, j))
				return false;
			else if (board[i][j] == 'C' && chk_C(i, j))
				return false;
		}
	}
	return true;
}


int x, y;

void solve() {
	int rec[12][12];

	memcpy(rec, board, sizeof board);
	/*
	for (int i = 1; i <= 11; ++i) {
		for (int j = 1; j < 10; ++j)
			printf("%d ", rec[i][j]);
		puts("");
	}
	*/
	for (int i = 0; i < 4; ++i) {
		memcpy(board, rec, sizeof board);
		int tx, ty;
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx < 1 || tx > 3) continue;
		if (ty < 4 || ty > 6) continue;
		board[tx][ty] = 'K';
		board[x][y] = 0;
		if (chk_ok()) {
			puts("NO");
			return ;
		}
	}
	puts("YES");
}

int main() {

#ifdef LOCAL_PC
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	while (scanf("%d%d%d", &n, &x, &y)) {
		if (x == 0 && x == 0 && y == 0)
			break;
		assert(0 < x && x < 4);
		assert(3 < y && x < 7);
		memset(board, 0, sizeof board);
		board[x][y] = 'K';
		for (int i = 0; i < n; ++i) {
			int r = gchar(), u, v;
			scanf("%d%d", &u, &v);
			board[u][v] = r;
		}
		solve();
	}

	return 0;
}



