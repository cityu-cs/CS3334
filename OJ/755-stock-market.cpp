// 755: Stock Market

#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int MAXN = 100000 + 3;

typedef long long ll;

int n;

ll p[MAXN];

ll solve();

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        cout << solve() << endl;
    }
}

struct Node {
    ll height, weight;
    ll area() {
        return height * weight;
    }
    // string toString() {
    //     return "(" + to_string(height) + ", " + to_string(weight) + ")";
    // }
};

ll solve() {
    stack<Node> s;
    ll ans = 0, weight = 0;
    Node tmp;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && s.top().height >= p[i]) {
            tmp = s.top();
            s.pop();
            weight += tmp.weight;
            ans = max(ans, tmp.height * weight);
            // cout << "pop" << tmp.toString() << ", weight = " << weight << ", area = " << tmp.height * weight << endl;
        }
        s.push({p[i], weight + 1});
        weight = 0;
    }
    weight = 0;
    while (!s.empty()) {
        tmp = s.top();
        s.pop();
        weight += tmp.weight;
        ans = max(ans, tmp.height * weight);
        // cout << "pop" << tmp.toString() << ", weight = " << weight << ", area = " << tmp.height * weight << endl;
    }
    return ans;
}