#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 510;

bool change[N][N];
vector<pair<int, int>> ineq;
int freq[N], n, m, RANK[N];
int ffreq[N];

void solve() {
	cin >> n;
	memset(freq, 0, sizeof(freq));
	memset(ffreq, 0, sizeof(ffreq));
	memset(change, 0, sizeof(change));
	freq[0] = 1e9;
	ineq.clear();

	for (int i = 0; i < n; i++)
		cin >> RANK[i];

	cin >> m;
	for (int i = 0; i < m ; i++) {
		int a, b;
		cin >> a >> b;
		change[a][b] = change[b][a] = 1; 
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int a = RANK[i];
			int b = RANK[j];
			if (change[RANK[i]][RANK[j]])
				swap(a, b);
			ineq.push_back({a, b});
		}
	}

	for (auto it : ineq)
		freq[it.first]++;

	for (int i = 1; i <= n; i++) {
		if (ffreq[freq[i]]++) {
			cout << "IMPOSSIBLE";
			return;
		}
	}
	string blank = "";
	for (int i = 0, j = n-1; i < n; i++, j--) {
		cout << blank << find(freq, freq+n, j)-freq;
		blank = " ";
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