// Solution 1: Brute Force

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000;

int arr[MAXN], ans[MAXN];
bool vis[MAXN];

class Solution {
public:
    int solve(int arr[], int n, int ans[]) {
        memset(vis, false, sizeof(vis));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            if (vis[i])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    vis[j] = true;
                    flag = true;
                }
            }
            if (flag) {
                ans[cnt++] = arr[i];
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
