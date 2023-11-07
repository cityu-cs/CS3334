// 892: Sliding Window

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void slidingWindow(int n, int windowSize, vector<int> arr);
};

int main() {
    int n, windowSize;
    cin >> n >> windowSize;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution solution;
    solution.slidingWindow(n, windowSize, arr);
}

void Solution::slidingWindow(int n, int windowSize, vector<int> arr) {
    vector<int> mins(n - windowSize + 1);
    vector<int> maxs(n - windowSize + 1);
    int currMin = INT_MAX, currMax = INT_MIN;
    int currMinIndex = -1, currMaxIndex = -1;
    for (int i = 0; i < windowSize; i++) {
        if (arr[i] < currMin) {
            currMin = arr[i];
            currMinIndex = i;
        }
        if (arr[i] > currMax) {
            currMax = arr[i];
            currMaxIndex = i;
        }
    }
    mins[0] = currMin;
    maxs[0] = currMax;
    for (int i = windowSize; i < n; i++) {
        if (currMinIndex == i - windowSize) {
            currMin = INT_MAX;
            for (int j = i - windowSize + 1; j <= i; j++) {
                if (arr[j] < currMin) {
                    currMin = arr[j];
                    currMinIndex = j;
                }
            }
        } else if (arr[i] < currMin) {
            currMin = arr[i];
            currMinIndex = i;
        }
        if (currMaxIndex == i - windowSize) {
            currMax = INT_MIN;
            for (int j = i - windowSize + 1; j <= i; j++) {
                if (arr[j] > currMax) {
                    currMax = arr[j];
                    currMaxIndex = j;
                }
            }
        } else if (arr[i] > currMax) {
            currMax = arr[i];
            currMaxIndex = i;
        }
        mins[i - windowSize + 1] = currMin;
        maxs[i - windowSize + 1] = currMax;
    }
    for (int i = 0; i < n - windowSize; i++)
        cout << mins[i] << " ";
    cout << mins[n - windowSize] << endl;
    for (int i = 0; i < n - windowSize; i++)
        cout << maxs[i] << " ";
    cout << maxs[n - windowSize] << endl;
}