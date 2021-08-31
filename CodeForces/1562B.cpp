#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool prime[100];
string num;

bool ok(int n) {
	string target = to_string(n);
	int i = 0;
	for (int j = 0; j < num.size() && i < target.size(); j++) {
		if (target[i] == num[j]) {
			i++;
		}
	}
	return i == target.size();
}

void solve() {
	int len;
	cin >> len;
	cin >> num;
	for (int i = 1; i < 100; i++) {
		if (!prime[i]) {
			if (ok(i)) {
				cout << to_string(i).size() << '\n' << i;
				return;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(prime, 1, sizeof prime);
	prime[1] = 0;
	for (int i = 4; i < 100; i+=2) prime[i] = 0;
	for (int i = 3; i < 100; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < 100; j += i)
				prime[j] = 0;
		}
	}
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << '\n';
	}
}