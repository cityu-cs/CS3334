// 741: Coin Flipping Easy Game

#include <iostream>

using namespace std;

const int MAXN = 100 + 2;

int n, m, ans;
int a[MAXN];

int popcount(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

void calc() { // allow row flip, calculate current ans
    int cur = 0;
    for (int row = 0; row < n; row++) {
        cur += max(popcount(a[row]), m - popcount(a[row]));
    }
    if (cur > ans) {
        ans = cur;
    }
}

void solveCol(int col) { // allow col flip
    for (int row = 0; row < n; row++) {
        a[row] ^= 1 << col;
    }
    calc();
    for (int nextCol = col + 1; nextCol < m; nextCol++) {
        solveCol(nextCol);
    }
}

int main() {
    while (cin >> n >> m) {
        ans = 0;
        for (int row = 0; row < n; row++) {
            string s;
            cin >> s;
            int dec = 0;
            for (int col = 0; col < m; col++) {
                if (s[col] == '1') {
                    dec ^= 1 << (m - col - 1);
                }
            }
            a[row] = dec;
        }
        for (int col = 0; col < m; col++) {
            solveCol(col);
        }
        cout << ans << endl;
    }
}

// Time: O(2^m * n * m)
