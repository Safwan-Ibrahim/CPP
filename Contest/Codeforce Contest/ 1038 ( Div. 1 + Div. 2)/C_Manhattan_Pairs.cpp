// Created on: 2025-07-19 21:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n; array<int, 3> A[nn];

bool cmp1(array<int, 3>a, array<int, 3>b) {
    return a[1] < b[1];
}

bool cmp2(array<int, 3>a, array<int, 3>b) {
    return a[1] > b[1];
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        A[i] = {x, y, i};
    }

    sort(A + 1, A + n + 1); sort(A + 1, A + n / 2 + 1, cmp1); sort(A + n / 2 + 1, A + n + 1, cmp2);
    for (int i = 1; i <= n / 2; i++) {
        cout << A[i][2] << " " << A[i + n / 2][2] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 