// 742: Simple Quadtree

#include <iostream>

using namespace std;

const int MAXN = 1024;

int n;
char map[MAXN][MAXN];
int ans = 0;

int solve(int rowStart, int rowEnd, int colStart, int colEnd) {
    if (rowStart == rowEnd) {
        return map[rowStart][colStart] - '0';
    }
    int rowMid = (rowStart + rowEnd) / 2;
    int colMid = (colStart + colEnd) / 2;
    int a = solve(rowStart, rowMid, colStart, colMid);
    int b = solve(rowStart, rowMid, colMid + 1, colEnd);
    int c = solve(rowMid + 1, rowEnd, colStart, colMid);
    int d = solve(rowMid + 1, rowEnd, colMid + 1, colEnd);
    if (a == b && b == c && c == d && d == 0) {
        return 0;
    } else if (a == b && b == c && c == d && d == 1) {
        return 1;
    } else {
        ans += 4;
        return 2;
    }
}

int main() {
    while (cin >> n) {
        int size = 1 << n;
        for (int i = 0; i < size; ++i) {
            cin >> map[i];
        }
        solve(0, size - 1, 0, size - 1);
        cout << ans + 1 << endl;
        ans = 0;
    }
}