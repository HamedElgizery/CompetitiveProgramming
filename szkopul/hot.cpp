#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000 + 10 ;
 
int arr[MAX] ;
int N ;
 
vector< vector<int> >adj(MAX) ;
 
long long ans = 0 ;
int to[MAX] , cnt[MAX] , P[MAX] ;
 
queue<int>q[MAX] ;

void count(int centre) {

	for (auto& child : adj[centre]) {
		q[1].push(child);
		to[child] = child;
		cnt[child]=1;
		P[child] = centre;
	}

	for (int i = 1; i < N; ++i) {
		int sum1 = 0, sum2 = 0;
		for (auto& child : adj[centre])
			sum2 += cnt[child];
		for (auto& child : adj[centre]) {
			sum2 -= cnt[child];
			ans += 1LL * sum1 * cnt[child] * sum2; 
			sum1 += cnt[child];
		}
		for (auto& child : adj[centre])
			cnt[child] = 0;

		while(!q[i].empty()) {
			int node = q[i].front();
			q[i].pop();

			for (auto& child : adj[node]) {
				if (child == P[node])
					continue;
				q[i+1].push(child);
				to[child] = to[node];
				cnt[to[child]]++;
				P[child] = node;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d", &N);

	for (int i = 1; i < N; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
		count(i);
	printf("%lld\n", ans);
}