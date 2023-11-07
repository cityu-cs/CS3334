// 836: Smallest Natural Number

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000 + 1;

bool a[MAXN];

int main() {
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x < MAXN)
                a[x] = true;
        }
        for (int i = 0; i <= n; ++i)
            if (!a[i]) {
                ans = i;
                break;
            }
        cout << ans << endl;
    }
}