#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 101;
int n, q, c;
int sky[N][N][11];

void solve() {
	cin >> n >> q >> c;
	for (int i = 0; i < n; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		sky[x][y][s]++;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 0; k < 11; k++) {
				sky[i][j][k] += sky[i][j-1][k] + sky[i-1][j][k] - sky[i-1][j-1][k];
			}
		}
	}

	int m = c+1;
	while(q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for (int k = 0; k < 11; k++) {
			int add = (k + t) % m;
			int cnt = (sky[x2][y2][k]+sky[x1-1][y1-1][k]-sky[x2][y1-1][k]-sky[x1-1][y2][k]);
			sum += cnt * add;
		}
		cout << sum << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}