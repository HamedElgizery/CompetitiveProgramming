#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 1e9+7;
const int mxN = 1e5+10;

int freq[mxN];

void solve() {
	int N;
	cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a, freq[a]++;

	bool ok = 1;

	if (N&1) {
		ok &= (freq[0] == 1);
		for (int i = 2; i <= N; i+=2) {
			ok &= (freq[i] == 2);
		}
		for (int i = 1; i <= N; i+=2) {
			ok &= !(freq[i]);
		}
	}
	else {
		for (int i = 1; i <= N; i+=2) {
			ok &= (freq[i] == 2);
		}
		for (int i = 2; i <= N; i+=2) {
			ok &= !(freq[i]);
		}
	}

	if (!ok) {
		cout << 0;
		return;
	}

	set<int> st;
	for (auto a : A) {
		if (a)
			st.insert(a);
	}

	ll ans = 1;
	for (int i = 0; i < st.size(); i++) {
		ans *= 2;
		ans %= M;
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