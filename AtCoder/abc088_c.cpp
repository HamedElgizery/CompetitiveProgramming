#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int G[3][3];

void solve() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> G[i][j];

	bool ans = 1;
	//Check Rows
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 3; j++) {
			int diff = G[i][0] - G[j][0];
			for (int k = 1; k < 3; k++) {
				ans &= (G[i][k] - G[j][k] == diff);
			}
		}
	}
	//Check Cols
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 3; j++) {
			int diff = G[0][i] - G[0][j];
			for (int k = 1; k < 3; k++) {
				ans &= (G[k][i] - G[k][j] == diff);
			}
		}
	}

	cout << (ans ? "Yes" : "No") << '\n';
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