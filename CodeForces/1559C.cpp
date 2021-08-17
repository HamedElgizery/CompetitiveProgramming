#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> A;
int N;
bool valid(int i) {
	if (i)
		if (A[i-1] == 1) return 0;
	if (i < N) 
		if (A[i] == 0) return 0;
	return 1;
}

void solve() {
	cin >> N;
	A.resize(N);
	for (auto& a : A) cin >> a;

	for (int i = 0; i <= N; i++) {
		if (valid(i)) {
			if (i == 0) 
				cout << N+1 << ' ';
			for (int j = 1; j <= N; j++) {
				cout << j << ' ';
				if (i == j)
					cout << N+1 << ' ';
			}
			return;
		}
	}

	cout << -1;
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