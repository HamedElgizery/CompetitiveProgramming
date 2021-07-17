#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e5+1;
int n;
priority_queue<int> a, b;
void solve() {
	while(a.size())
		a.pop();
	while(b.size())
		b.pop();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push(x);
	}

	int currA = 0, currB = 0, ans = 0, nn = n;
	int take = n - (n/4);
	priority_queue<int, vector<int>, greater<int>> rem;
	for (int i = 0; i < take; i++) {
		currA += a.top();
		rem.push(a.top());
		currB += b.top();
		a.pop(), b.pop();
	}

	while(currA < currB) {
		ans++, nn++;
		int ntake = nn - (nn/4);
		for (int i = ntake; i > take; i--) {
			currA += 100;
			rem.push(100);
			if (b.size()) {
				currB += b.top();
				b.pop();
			}
		}
		if (ntake == take) {
			currA -= rem.top();
			rem.pop();
			rem.push(100);
			currA += 100;
		}
		take = ntake;
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