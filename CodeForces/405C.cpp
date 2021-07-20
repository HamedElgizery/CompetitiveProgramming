#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1000;
int n, q;
int col[N], row[N], p;
int ans[N][2][2];
int grid[N][N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
			p+=(i==j)*(grid[i][j]);
		}
	}

	

	scanf("%d", &q);
	while(q--) {
		int type;
		scanf("%d", &type);
		if (type == 3) {
			printf("%d", p%2);
			continue;
		}
		int i; scanf("%d", &i);
		p -= grid[i][i];
		grid[i][i] = !grid[i][i];
		p+=grid[i][i];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
}
