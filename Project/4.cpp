// Solution 4: Quick Sort + Binary Search

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000;

int arr[MAXN], ans[MAXN];

struct Node {
    int val, idx;
};

bool cmp(Node a, Node b) {
    return (a.val == b.val) ? (a.idx < b.idx) : (a.val < b.val);
}

class Solution {
private:
    void swap(Node &a, Node &b) {
        Node tmp = a;
        a = b;
        b = tmp;
    }

    void quickSort(Node *arr, int l, int r) {
        if (l >= r) {
            return;
        }

        Node &pivot = arr[l];
        int i = l, j = r;
        while (i < j) {
            while (cmp(arr[i], pivot) && i < j) {
                i++;
            }
            while (!cmp(arr[j], pivot) && i < j) {
                j--;
            }
            swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[j]);

        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }

    int binarySearch(Node *arr, int l, int r, int target, int index) {
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (arr[mid].idx == index) {
                return mid;
            } else if (arr[mid].val < target || (arr[mid].val == target && arr[mid].idx < index)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

public:
    int solve(int arr[], int n, int ans[]) {
        Node *tmp = new Node[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            tmp[i].val = arr[i];
            tmp[i].idx = i;
        }
        quickSort(tmp, 0, n - 1);
        for (int i = 0; i < n; i++) {
            int j = binarySearch(tmp, 0, n - 1, arr[i], i);
            if ((j == 0 || tmp[j - 1].val != tmp[j].val) && (j < n - 1 && tmp[j + 1].val == tmp[j].val)) {
                ans[cnt++] = arr[i];
            }
        }
        delete[] tmp;
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
