#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 3e4+10, OO = INT_MAX;
int N, M;
set<int> doges[mxN];
vector<pair<int, int>> adj[mxN];

int dijkstra(int st, int en) {
	vector<int> dist(mxN, OO);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, st});
	dist[st] = 0;

	while(pq.size()) {
		auto node = pq.top();
		pq.pop();

		if (node.first > dist[node.second])
			continue;

		for (auto it : adj[node.second]) {
			if (dist[it.second] > node.first + it.first) {
				dist[it.second] = node.first + it.first;
				pq.push({dist[it.second], it.second});
			}
		}
	}
	if (dist[en] == OO)
		dist[en] = -1;
	return dist[en];
}	

void solve() {
	cin >> N >> M;

	int stB, enB;
	for (int i = 0; i < M; i++) {
		int B, P;
		cin >> B >> P;
		if (!i) stB = B;
		if (!(i-1)) enB = B;
		doges[B].insert(P);
	}

	for (int i = 0; i < N; i++) {
		for (auto doge : doges[i]) {
			for (int to = i + doge, j = 1; to < N; to += doge, j++){
				adj[i].push_back({j, to});
				if (doges[to].count(doge)) break;
			}
			for (int to = i - doge, j = 1; to >= 0; to -= doge, j++){
				adj[i].push_back({j, to});
				if (doges[to].count(doge)) break;
			}
		}
	}
	cout << dijkstra(stB, enB);
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