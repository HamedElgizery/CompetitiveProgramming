//https://oj.uz/problem/view/BOI16_bosses

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 5e3+10;
vector<int> edges[mxN];

int N;

int bfs(int st) {
	queue<pair<int, int>> q;
	vector<int> VIS(N+1, 0);
	q.push({1, st});

	int ret = 0;

	while(q.size()) {
		auto node = q.front();
		q.pop();
		if (VIS[node.second])
			continue;
		VIS[node.second] = 1;
		ret += node.first;

		for (auto c : edges[node.second]) {
			if (!VIS[c])
				q.push({node.first+1, c});
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!VIS[i]) {
			ret = INT_MAX;
			break;
		}
	}
	return ret;
}

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int boss;
			cin >> boss;
			edges[boss].push_back(i);
		}
	}
	int ans = INT_MAX;
	for (int i = 1; i <= N; i++)
		ans = min(ans, bfs(i));


	if (ans == INT_MAX)
		ans = -1;
	cout << ans;
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