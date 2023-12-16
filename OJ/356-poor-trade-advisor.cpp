// 356: Poor Trade Advisor

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500 + 1;

class uniteFind {
public:
    int fa[MAXN];
    int height[MAXN];
    int size[MAXN];
    int max_size;

    uniteFind(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            height[i] = 0;
            size[i] = 1;
        }
        max_size = 1;
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (height[x] > height[y]) {
            fa[y] = x;
            size[x] += size[y];
            max_size = max(max_size, size[x]);
        } else {
            fa[x] = y;
            size[y] += size[x];
            if (height[x] == height[y]) height[y]++;
            max_size = max(max_size, size[y]);
        }
    }
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        uniteFind uf(n);
        vector<Edge> edges;
        int max_w = INT_MIN;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
            max_w = max(max_w, w);
        }

        for (int i = 0; i < m; i++) {
            if (edges[i].w == max_w) {
                uf.unite(edges[i].u, edges[i].v);
            }
        }

        cout << uf.max_size << endl;
    }
}