#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 101, OO = 0x3f3f3f3f;
int d[mxN][mxN], path[(int)1e6+10], N, M;
void solve() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			d[i][j] = OO;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char c;
			cin >> c;
			if (c - '0' == 1)
				d[i][j] = 1;
		}
		d[i][i] = 0;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++)
				if (d[i][k] != OO && d[k][j] != OO)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> path[i];

	vector<int> ans;
	
	ans.push_back(1);
	for (int l = 2; l <= M; l++) {
		while(d[path[ans.back()]][path[l]] != l - ans.back())
			ans.push_back(l-1);
	}
	ans.push_back(M);
	
	cout << ans.size() << endl;
	for (auto it : ans)
		cout << path[it] << ' ';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}
