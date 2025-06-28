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

    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        int mn =  2e9, id = -1; // boro value
        for (int j = i ; j <= n; j++) {
            if (mn > A[j]) {
                mn = A[j];
                id = j;
            }
        }
        if (A[id] != A[i]) {
            swap(A[i], A[id]);
            cnt++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << cnt;
    cout << endl;
    return 0;
} 