// 752: Task Manager

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 3;

int n, r[MAXN], w[MAXN], p[MAXN], ans[MAXN];

struct Node {
    int id, arriveTime, processTime;
    bool operator < (const Node &other) const {
        return (arriveTime == other.arriveTime) ? (id < other.id) : (arriveTime < other.arriveTime);
    }
};

void solve();

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> r[i] >> w[i] >> p[i];
        }
        solve();
        for (int i = 1; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << ans[n] << endl;
    }
}

void solve() {
    queue<Node> q[2];
    int curTime = r[1];
    int idx = 1;
    Node todo;
    q[p[1]].push({1, r[1], w[1]});
    while (idx <= n) {
        while (idx < n && r[idx + 1] <= curTime) {
            idx++;
            q[p[idx]].push({idx, r[idx], w[idx]});
        }
        if (q[0].empty() && !q[1].empty()) {
            todo = q[1].front();
            q[1].pop();
        } else if (!q[0].empty()) {
            todo = q[0].front();
            q[0].pop();
        } else {
            idx++;
            curTime = r[idx];
            q[p[idx]].push({idx, r[idx], w[idx]});
            continue;
        }
        ans[todo.id] = curTime + todo.processTime;
        curTime = ans[todo.id];
    }
}