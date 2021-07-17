#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+20;

int n;
int a[N], aa[N];
int inDeg[N];
set<int> adj[N];
vector<set<int>> use;

void solve() {
	cin >> n;
	use.clear();
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	memset(inDeg, 0, sizeof(int) * (n+10));

	for (int i = 1; i <= n; i++) 
		cin >> a[i], aa[i] = a[i], adj[a[i]].insert(i), inDeg[a[i]]++;

	for (int i = 1; i <= n; i++) {
		if (inDeg[i] > 1)
			use.push_back(adj[i]);
	}
	int l = 0;
	for (int i = 1; i <= n; i++) {
		if (inDeg[i] == 0) {
			for (set<int>::iterator it = use[l].begin(); it != use[l].end(); it++) {
				if (*it != i) {
					a[*it] = i, use[l].erase(it);
					break;
				}
			}
			l += (use[l].size() == 1);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += (a[i] == aa[i]);
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
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