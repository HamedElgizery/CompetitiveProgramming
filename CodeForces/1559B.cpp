#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	for (int i = 1; i < N; i++) {
		if (S[i] == '?') {
			if (S[i-1] == 'R') S[i] = 'B';
			if (S[i-1] == 'B') S[i] = 'R';
		}
	}
	for (int i = N-1; i >= 0; i--) {
		if (S[i] == '?') {
			if (S[i+1] == 'R') S[i] = 'B';
			if (S[i+1] == 'B') S[i] = 'R';
		}
	}
	if (S[0] == '?') {
		for (int i = 0; i < N; i++) {
			if (i & 1) S[i] = 'R';
			else S[i] = 'B';
		}
	}
	cout << S;
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