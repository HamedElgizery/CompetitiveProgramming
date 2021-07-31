#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1e5+10;
ll N, K;
ll A[mxN];
int freq[60];

void process(ll n) {
	for (int i = 0; i < 60; i++)
		freq[i]+=bool((1LL<<i)&n);
}

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		process(A[i]);
	}

	ll ans = 0;
	for (int i = 59; i >= 0; i--) {
		if (!((1LL<<i)&K))
			continue;

		if (freq[i] <= N/2) {
			ans |= (1LL << i);
		}
		else {
			K = (1LL << i)-1;
		}
	}

	ll FANS = 0;
	for (int i = 0; i < N; i++) {
		FANS += (ans^A[i]);
	}
	cout << FANS << '\n';
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
		memset(freq, 0, sizeof freq);
		solve();
	}
}