#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 101;
int ans[mxN];

void solve() {
	int K, N;
	cin >> K >> N;

	for (int i = 1; i < N; i++) {
		cout << i << endl;
		K -= i;
	}
	cout << K << endl;
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