#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 25, OO = 0x3f3f3f3f;
int d[N][N];

void solve() {
	for (int i = 2; i <= 19; i++) {
		int x;
		scanf("%d", &x);
		while(x--) {
			int v;
			scanf("%d", &v);
			d[i][v] = d[v][i] = 1;
		}
	}
	for (int k = 1; k <= 20; k++) {
		for (int i = 1; i <= 20; i++) {
			for (int j = 1; j <= 20; j++) {
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	int n;
	scanf("%d", &n);
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%2d to %2d: %d\n", a, b, d[a][b]);
	}
}	

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int tc = 0, x;
	while(scanf("%d", &x) != EOF) {
		memset(d, OO, sizeof d);
		while(x--) {
			int v;
			scanf("%d", &v);
			d[1][v] = d[v][1] =  1;

		}
		printf("Test Set #%d\n", ++tc);
		solve();
		puts("");
	}
}