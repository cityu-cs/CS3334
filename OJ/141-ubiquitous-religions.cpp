// 141: Ubiquitous Religions

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50000 + 1;

class UnionFind {
public:
    int fa[MAXN];
    int rank[MAXN];
    int n;

    UnionFind(int n): n(n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            fa[x] = y;
        } else {
            fa[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

int main() {
    int n, m;
    int t = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            uf.unite(x - 1, y - 1);
        }
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(uf.find(i));
        }
        cout << "Case " << ++t << ": " << s.size() << endl;
    }
}
