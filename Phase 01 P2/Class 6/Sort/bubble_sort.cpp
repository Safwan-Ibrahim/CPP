// Created on: 2025-02-13 17:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// bubble sort : every time boro holei samne swap kore felbo // jar fole everytime shobcheye borota seshe chole jabe // 2nd max ta last er agey jabe I mean last value gulu thik jaygay boshbe everytime

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 2; j <= n; j++) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
            }
        }
    }

    cout << is_sorted(A + 1, A + n + 1);
    
    return 0;
} 