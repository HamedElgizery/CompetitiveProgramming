#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a;

	ll ans = 0, r = 0;
	ll sum = A[0], XOR = A[0];

	for (int l = 0; l < N && r < N; l++) {
		while(sum == XOR && r < N) {
			ans += r - l + 1;
			r++;
			if (r >= N)
				break;
			sum += A[r];
			XOR ^= A[r];
		}
		sum -= A[l];
		XOR ^= A[l];
	}

	cout << ans;
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