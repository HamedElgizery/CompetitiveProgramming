#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	string S, SS;
	cin >> N >> S;
	SS = S;
	sort(SS.begin(), SS.end());
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += (S[i] != SS[i]);
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
}