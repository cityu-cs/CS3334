#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
    int val;
    int step;
    Node(int v, int s) : val(v), step(s) {}
};

const int MAX_NUM = 9999;

class Solution {
private:
    bool vis[MAX_NUM + 1];
    int prime[MAX_NUM + 1];
    int primeCnt;

    int distance(int a, int b) {
        int cnt = 0;
        while (a && b) {
            if (a % 10 != b % 10) {
                cnt++;
            }
            a /= 10;
            b /= 10;
        }
        return cnt;
    }

public:
    Solution() {
        memset(vis, 0, sizeof(vis));
        primeCnt = 0;
        for (int i = 2; i <= MAX_NUM; i++) {
            if (!vis[i]) {
                if (i >= 1000) {
                    prime[primeCnt++] = i;
                }
                for (int j = i * i; j <= MAX_NUM; j += i) {
                    vis[j] = true;
                }
            }
        }
    }

    int primePath(int start, int end) {
        memset(vis, 0, sizeof(vis));
        queue<Node> q;
        q.push(Node(start, 0));
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            if (node.val == end) {
                return node.step;
            }
            for (int i = primeCnt - 1; i >= 0; i--) {
                if (!vis[prime[i]] && distance(node.val, prime[i]) == 1) {
                    vis[prime[i]] = true;
                    q.push(Node(prime[i], node.step + 1));
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    int t;
    cin >> t;
    while (t--) {
        int start, end;
        cin >> start >> end;
        int ans = s.primePath(start, end);
        if (ans == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}