#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;
	set<int> st;
	map<int, vector<int>> mp;
	for (int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		mp[l].push_back(r);
		st.insert(l);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	st.insert(2e9);
	int i = *st.begin();
	bool ans = 1;
	while(i <= 1e9) {
		for (auto& it : mp[i]) pq.push(it);
		pq.pop();
		if (!pq.empty()) {
			if (pq.top() <= i) {
				ans = 0;
				break;
			}
			i++;
		}
		else i = *st.lower_bound(i+1);
	}

	if (!pq.empty()) ans = 0;
	cout << (ans ? "Yes" : "No");
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