// 784: Wonderful sub-array

#include <iostream>

using namespace std;

const int MAXN = 100000 + 2;

int a[MAXN];

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sums[2] = {0, 0};
        int ans = 0;
        int currentIdx = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == m) {
                if(sums[0] + sums[1] + m > ans) {
                    ans = sums[0] + sums[1] + m;
                }
                currentIdx ^= 1;
                sums[currentIdx] = 0;
            } else if (a[i] < m) {
                // terminate current sub-array
                if(sums[0] + sums[1] + m > ans) {
                    ans = sums[0] + sums[1] + m;
                }
                sums[0] = 0;
                sums[1] = 0;
            } else {
                sums[currentIdx] += a[i];
            }
        }
        if (sums[0] + sums[1] + m > ans) {
            ans = sums[0] + sums[1] + m;
        }
        cout << ans << endl;
    }
}