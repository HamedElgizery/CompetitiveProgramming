#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, t;
string s1, s2, ans;
stack<int> similar, different;

char diff(int idx) {
	for (char i = 'a'; i <= 'z'; i++) {
		if (i == s1[idx] || i == s2[idx])
			continue;
		return i;
	}
	return 'a';
}

void solve() {
	cin >> n >> t >> s1 >> s2;
	ans = string(n, '-');
	for (int i = 0; i < n; i++) {
		if (s1[i] == s2[i])
			similar.push(i);
		else
			different.push(i);
	}
	int st = n - t;
	while(st && similar.size()) {
		ans[similar.top()] = s1[similar.top()];
		similar.pop();
		st--;
	}
	if (st * 2 > different.size()) {
		cout << -1;
		return;
	}
	int stc = st;
	while(stc) {
		ans[different.top()] = s1[different.top()];
		different.pop();
		stc--;
	}
	while(st) {
		ans[different.top()] = s2[different.top()];
		different.pop();
		st--;
	}
	while(similar.size()) {
		ans[similar.top()] = diff(similar.top());
		similar.pop();
	}
	while(different.size()) {
		ans[different.top()] = diff(different.top());
		different.pop();
	}
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
}