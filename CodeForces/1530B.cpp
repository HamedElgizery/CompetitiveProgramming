#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 25;

int di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dj[] = {0, -1, 0, 1, -1, 1, -1, 1};

int ans[N][N];
int h, w;

bool valid(int i, int j) {
	return !(0 <= i && i < h && 0 <= j && j < w) || !ans[i][j];
}
void solve() {
	memset(ans, 0, sizeof ans);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i > 0 && i+1 < h && j > 0 && j+1 < w)
				continue;
			bool ok = 1;
			for (int d = 0; d < 8; d++) {
				int ni = di[d] + i;
				int nj = dj[d] + j;
				ok &= valid(ni, nj);
			}
			if (ok)
				ans[i][j] = 1;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}