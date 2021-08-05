#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2e5+10;
int N, K, R;

void solve() {
	cin >> N >> K >> R;
	vector<int> DNA(N), need(K, INT_MAX);

	for (auto& dna : DNA) 
		cin >> dna;

	for (int i = 0; i < R; i++) {
		int B, Q;
		cin >> B >> Q;
		need[B] = Q; 
	}

	int ans = INT_MAX;
	int good = 0;
	
	for (int l = 0, r = 0; l < N; l++) {
		while(good < R && r < N)
			if (--need[DNA[r++]] == 0)
				++good;

		if (good == R)
			ans = min(ans, r - l);

		if (++need[DNA[l]] == 1)
			--good;
	}

	cout << (ans == INT_MAX ? "impossible" : to_string(ans));
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