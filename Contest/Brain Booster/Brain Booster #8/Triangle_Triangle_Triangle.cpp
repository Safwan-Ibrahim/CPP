// Created on: 2025-02-17 20:31
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    set<int>St;
    vector<int>A;
    for (int i = 1; i <= 3; i++) {
        int x; cin >> x;
        A.push_back(x);
        St.insert(x);
    }

    int sz = St.size();
    sort(A.begin(), A.end());
    if (A[0] + A[1] <= A[2]) {
        cout << "Not a triangle\n";
    }
    else if (sz == 3) {
        cout << "Scalene\n";
    }
    else if (sz == 2) {
        cout << "Isosceles\n";
    }
    else {
        cout << "Equilateral\n";
    }
    
    return 0;
} 