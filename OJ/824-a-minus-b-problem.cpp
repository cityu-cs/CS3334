// 824: A = B Problem

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, c;
    while (cin >> n >> c) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        if (c < 0) c = -c;
        int i = 0, j = 1;
        while (i < n) {
            while (j < n && a[j] - a[i] < c) ++j;
            if (j < n && a[j] - a[i] == c) {
                int llen = 1, rlen = 1;
                while (i + 1 < n && a[i + 1] == a[i]) ++i, ++llen;
                while (j + 1 < n && a[j + 1] == a[j]) ++j, ++rlen;
                ans += 1ll * llen * rlen;
            }
            ++i;
        }
        cout << ans << endl;
    }
}