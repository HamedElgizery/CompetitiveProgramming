#include <bits/stdc++.h>

using namespace std;

void solve() {
	int N;
	cin >> N;
	vector<int> A(N); for (auto &a : A) cin >> a;

	bool ans1 = 1;
	int totalSub1 = 0;
	for (int i = N-2; i >= 0; --i) {
		if (A[i] - totalSub1 < 0) {
			ans1 = 0;
			break;
		}
		if (A[i] > A[i+1]) 
			totalSub1 += A[i] - A[i+1];
	}

	bool ans2 = 1;
	int totalSub2 = 0;
	for (int i = 1; i < N; ++i) {
		if (A[i] - totalSub2 < 0) {
			ans2 = 0;
			break;
		}
		if (A[i] > A[i-1]) 
			totalSub2 += A[i] - A[i-1];
	}

	cout << (ans1 || ans2 ? "YES" : "NO");
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
	return 0;
}
