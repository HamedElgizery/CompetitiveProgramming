#include <bits/stdc++.h>

using namespace std;


void solve() {
	int N;
	string S;
	cin >> N >> S;
	
	map<int, int> freq;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum++;
		sum -= S[i] - '0';
		freq[sum]++;
	}

	long long ans = 0;
	sum = 0;
	for (int i = 0; i < N; i++) {
		ans += freq[sum];
		sum++;
		sum -= S[i] - '0';
		freq[sum]--;
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
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
	return 0;
}