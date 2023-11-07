// 125: Graph Connectivity

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 26 + 1;

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
    int t;
    cin >> t;
    while (t--) {
        char n;
        cin >> n;
        int max_index = n - 'A' + 1;
        UnionFind uf(max_index);
        string s;
        getline(cin, s);
        while (getline(cin, s) && s != "") {
            uf.unite(s[0] - 'A', s[1] - 'A');
        }
        set<int> ans;
        for (int i = 0; i < max_index; i++) {
            ans.insert(uf.find(i));
        }
        cout << ans.size() << endl;
        if (t) {
            cout << endl;
        }
    }
}
