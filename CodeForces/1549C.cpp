#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> edBig(N+1, 0);
	edBig[0] = 1;
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		if (V < U)
			swap(U, V);
		edBig[U]++;
	}

	int ans = 0;
	for (auto it : edBig)
		ans += !(it);

	int Q;
	cin >> Q;
	while(Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int U, V;
			cin >> U >> V;
			if (V < U)
				swap(U, V);
			ans -= !edBig[U];
			edBig[U]++;
		}
		if (type == 2) {
			int U, V;
			cin >> U >> V;
			if (V < U)
				swap(U, V);
			edBig[U]--;
			ans += !edBig[U];
		}
		if (type == 3) {
			cout << ans << endl;
		}
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