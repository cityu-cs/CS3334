// 746: Fast Food Restaurant

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 2;

struct Customer {
    int arriveTime;
    int orderTime;
    int queueLength;
};

int main() {
    int n;
    while(cin >> n) {
        queue <Customer> q;
        int a, o, l;
        int curTime = 0;
        for (int i = 0; i < n; i++) {
            cin >> a >> o >> l;
            while (!q.empty() && max(curTime, q.front().arriveTime) + q.front().orderTime <= a) {
                curTime = max(curTime, q.front().arriveTime) + q.front().orderTime;
                q.pop();
            }
            if (q.size() > l) {
                if (i == n - 1) {
                    cout << -1 << endl;
                }
                continue;
            } else {
                q.push({a, o, l});
                if (i == n - 1) {
                    // while (q.size() > 1) {
                    //     curTime = max(curTime, q.front().arriveTime) + q.front().orderTime;
                    //     q.pop();
                    // }
                    // cout << max(curTime, q.front().arriveTime) << endl;
                    while(!q.empty()) {
                        curTime = max(curTime, q.front().arriveTime) + q.front().orderTime;
                        q.pop();
                    }
                    cout << curTime - o << endl;
                }
            }
        }
    }
}