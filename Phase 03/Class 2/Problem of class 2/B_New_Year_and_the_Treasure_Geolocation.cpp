// Created on: 2025-07-13 18:18
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 17;
int n; pair<int, int> A[nn], B[nn];

bool p(int x, int y) {
    for (int i = 1; i <= n; i++) {
        auto [a, b] = A[i];
        pair<int, int> need = {x - a, y - b};
        bool t = binary_search(B + 1, B + n + 1, need);
        if (!t) return false;
    }
    return true;
} 

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i].first >> B[i].second;
    }
    
    sort(B + 1, B + n + 1);
    for (int i = 1; i <= n; i++) {
        int x = A[i].first + B[1].first, y = A[i].second + B[1].second;
        if (p(x, y)) {
            cout << x << " " << y << endl;
            return 0;
        }
    }
    assert(0);
    return 0;
} 