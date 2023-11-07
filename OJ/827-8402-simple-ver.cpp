// 827: 8402 (Simple version)

// Given an array of positive integers,
// each time you can perform one of the following operations:
// 1. Change an element to a smaller positive value
// 2. Replace two equal elements with one element equal to their sum
// Find the maximum element at any time during the operation.

// Greedy. Maintain a min heap. Each time, pop the smallest two elements,
// If x_1 <= 1/2 * x_2, x_1 is not useful, discard it. Put x_2 back to the heap.
// If x_1 > 1/2 * x_2, merge them as 2 * x_1, which > x_2.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000 + 1;

int arr[MAXN];

void generateArray(int* arr, int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 1; i <= n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        arr[i] = x % m + 1;
    }
}

int main() {
    int n, m, seed;
    scanf("%d %d %d", &n, &m, &seed);
    generateArray(arr, n, m, seed); // a[1...n]

    priority_queue<ll, vector<ll>, greater<ll> > pq; // min heap
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        pq.push(arr[i]);
        ans = max(ans, (ll)arr[i]);
    }

    while (pq.size() > 1) {
        ll x1 = pq.top();
        pq.pop();
        ll x2 = pq.top();
        pq.pop();
        if (x1 <= x2 / 2) {
            pq.push(x2);
        } else {
            ans = max(ans, x1 * 2);
            pq.push(x1 * 2);
        }
    }
    
    ans = max(ans, pq.top());
    printf("%lld\n", ans);
}
