// 821: Distance

// Diameter of a tree

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100000 + 1;

vector<int> adj[N];
vector<ll> weight[N];
int n, farthest;
ll dist[N];

void dfs(int cur, int pre) {
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == pre) continue;
        dist[nxt] = dist[cur] + weight[cur][i];
        if (dist[nxt] > dist[farthest]) {
            farthest = nxt;
        }
        dfs(nxt, cur);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; ll w;
        scanf("%d%d%lld", &u, &v, &w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }

    dist[1] = 0;
    dfs(1, 0);

    dist[farthest] = 0;
    dfs(farthest, 0);

    printf("%lld\n", dist[farthest]);
}