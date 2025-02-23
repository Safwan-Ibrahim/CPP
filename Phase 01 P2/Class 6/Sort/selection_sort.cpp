// Created on: 2025-02-13 17:38
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// selection sort, everytime smallest value first e niye asha; then swap korlei shobcheye suto ta first e chole ashbe

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int mn =  INT_MAX, id = -1;
        for (int j = i ; j <= n; j++) {
            if (mn > A[j]) {
                mn = A[j];
                id = j;
            }
        }
        swap(A[i], A[id]);
    }

    cout << is_sorted(A + 1, A + n + 1);

    return 0;
} 