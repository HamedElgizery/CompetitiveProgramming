#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
bool inter(pair<int, int> f, pair<int, int> s) {
	if (f.first > s.first) swap(f, s);
	return f.second > s.first && f.second < s.second;
}

void solve() {
	cin >> N >> K;

	vector<pair<int, int>> chords;
	vector<bool> unused(2*N+1, 1);
	vector<int> avi;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		chords.push_back({a, b});
		unused[a] = unused[b] = 0;
	}

	for (int i = 1; i <= 2*N; i++)
		if (unused[i]) avi.push_back(i);

	for (int i = 0; i < N-K; i++)
		chords.push_back({avi[i], avi[i+N-K]});

	assert(chords.size() == N);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ans += inter(chords[i], chords[j]);
		}
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
}