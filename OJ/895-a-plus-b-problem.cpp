// 895: A + B Problem

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 3;

char a[MAXN], b[MAXN], c[MAXN];

void solve();

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        solve();
    }
}

void solve() {
    int lenA = strlen(a), lenB = strlen(b);
    int carry = 0;
    int lenC = max(lenA, lenB);
    for (int i = 0; i < lenC; i++) {
        c[i] = carry;
        if (i < lenA) {
            c[i] += a[lenA - i - 1] - '0';
        }
        if (i < lenB) {
            c[i] += b[lenB - i - 1] - '0';
        }
        if (c[i] >= 10) {
            c[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    if (carry) {
        c[lenC++] = 1;
    }
    for (int i = lenC - 1; i >= 0; i--) {
        cout << (int) c[i];
    }
    cout << endl;
}