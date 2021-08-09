#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<int, int> nxt;

void solve() {
	nxt.clear();

	int N, K;
	cin >> N >> K;
	vector<int> A(N); for (auto& a : A) cin >> a;

	for (int i = 0; i + 1 < N; i++)
		nxt[A[i]] = A[i+1];


	nxt[A.back()] = (int)-2e9;

	sort(A.begin(), A.end());

	int cnt = 1;
	for (int i = 0; i+1 < N; i++) {
		if (nxt[A[i]] == A[i+1])
			continue;
		cnt++;
	}

	cout << (cnt <= K ? "YES" : "NO");
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