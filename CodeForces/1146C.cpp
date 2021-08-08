#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int N;
	cin >> N;

	int ans = 0;
	for (int i = 0; i < 7; i++) {
		vector<int> A, B;
		for (int j = 1; j <= N; j++) {
			if (j&(1<<i))
				A.push_back(j);
			else
				B.push_back(j);
		}
		if (!A.size() || !B.size())
			continue;
		cout << A.size() << ' ' << B.size() << ' ';
		for (auto it : A) 
			cout << it << ' ';
		for (auto it : B) 
			cout << it << ' ';
		cout << endl;
		int tmp;
		cin >> tmp;
		ans = max(ans, tmp);
	}

	cout << -1 << ' ' << ans << endl;
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
	while(t--)
		solve();
}