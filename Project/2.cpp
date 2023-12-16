// Solution 2: Hash Table

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000;

int arr[MAXN], ans[MAXN];

int mod(int a, int b) { // handle negative numbers
    return (a % b + b) % b;
}

class Hash {
private:
    static const int TABLE_SIZE = 20011;
    int val[TABLE_SIZE];
    int cnt[TABLE_SIZE];

public:
    Hash() {
        memset(cnt, 0, sizeof(cnt));
        memset(val, 0, sizeof(val));
    }

    int locate(int x) {
        int base_idx = mod(x, TABLE_SIZE);
        int i = 0;
        int idx = base_idx;
        while (cnt[idx] > 0 && val[idx] != x) {
            i++;
            idx = mod(base_idx + i * i, TABLE_SIZE); // quadratic probing
        }
        return idx;
    }

    void insert(int x) {
        int idx = locate(x);
        if (cnt[idx] == 0) {
            val[idx] = x;
            cnt[idx] = 1;
        } else {
            cnt[idx]++;
        }
    }

    int get(int x) {
        return cnt[locate(x)];
    }

    void set(int x, int c) {
        int idx = locate(x);
        if (cnt[idx] == 0) {
            val[idx] = x;
            cnt[idx] = c;
        } else {
            cnt[idx] = c;
        }
    }
};

class Solution {
public:
    int solve(int arr[], int n, int ans[]) {
        Hash hash;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            hash.insert(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (hash.get(arr[i]) > 1) {
                ans[cnt++] = arr[i];
                hash.set(arr[i], 0);
            }
        }
        return cnt;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = 0;
        int i = 0;
        while (i < line.length()) {
            int sign = 1;
            if (line[i] == '-') {
                sign = -1;
                i++;
            }
            int num = 0;
            while (i < line.length() && line[i] >= '0' && line[i] <= '9') {
                num = num * 10 + (line[i] - '0');
                i++;
            }
            arr[n++] = sign * num;
            i++;
        }

        int cnt = Solution().solve(arr, n, ans);
        if (cnt > 0) {
            printf("%d", ans[0]);
            for (int i = 1; i < cnt; i++) {
                printf(" %d", ans[i]);
            }
            printf("\n");
        }
    }
}
