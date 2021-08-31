#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
()()(()) 
1 1 1, 
1 1 1 1 2 2
1 3
) (
*/

void solve() {
	int N;
	cin >> N;
	vector<ll> A(N); for (auto& a : A) cin >> a;
	vector<ll> AA = A;

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (i&1) continue;
		ll open = 0;
		for (int j = i+1; j < N; j++) {
			if (j&1) {
				if (A[j] - open >= 0) {
					if (A[i] != AA[i] && open)
						ans++;
					ans += min(A[i], A[j] - open);
				}
				ll rem = min(open, A[j]);
				open -= rem;
				A[i] -= (A[j] - rem);
				if (A[i] < 0)
					break;
			}
			else open += A[j];
		}
	}
	cout << ans << endl;
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