#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	vector<ll> S(N), T(N);
	for (auto& s : S) cin >> s;
	for (auto& t : T) cin >> t;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			T[j] = min(T[(j-1+N)%N] + S[(j-1+N)%N], T[j]);
		} 
	}

	for (auto& t : T) cout << t << '\n';
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