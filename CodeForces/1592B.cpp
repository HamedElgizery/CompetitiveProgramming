#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N, X;
	cin >> N >> X;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i] = A[i];
	}

	if (N >= 2 * X) return void(cout << "YES");

	sort(A.begin(), A.end());
	for (int i = N - X; i < X; i++)
		if (A[i] != B[i]) return void(cout << "NO");


	cout << "YES";
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