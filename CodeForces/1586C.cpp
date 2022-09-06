#include <bits/stdc++.h>

using namespace std;

void solve() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> A(N, vector<char>(M)); 
	for (auto &a : A) 
		for (auto &aa : a) 
			cin >> aa;

	vector<int> cum(M, 0);
	for (int j = 0; j + 1 < M; j++) {
		for (int i = 1; i < N; i++) {
			cum[j] += (A[i][j] == 'X' && A[i-1][j+1] == 'X');
		} 
	}

	for (int i = 1; i < M; i++)
		cum[i] += cum[i-1];


	int Q;
	cin >> Q;
	while(Q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		bool ans;
		if (l == r)
			ans = 1;
		else
			ans = !(cum[r-1] - (l ? cum[l-1] : 0));
		cout << (ans ? "YES" : "NO") << '\n';
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
	return 0;
}