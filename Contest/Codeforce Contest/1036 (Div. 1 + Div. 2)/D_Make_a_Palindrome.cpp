// Created on: 2025-07-06 22:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k; 
vector<int>A, B;

bool pos() {
    int cut = n - (k - 1);
    map<int, int>Mp;
    for (int i = 0; i < cut; i++) {
        Mp[B[i]]++;
    }

    for (int i = 0, j = n - 1; i < j;) {
        if (A[i] == A[j]) {
            i++, j--;
        }
        else {
            if (Mp[max(A[i], A[j])] <= 0) return false;
            Mp[max(A[i], A[j])]--;
            if (A[i] > A[j]) i++;
            else j--;
        }
    }
    return true;
}

void Try() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A.push_back(x);
    }
    
    B = A;
    sort(B.rbegin(), B.rend());
    bool yes = pos();
    if (k != n) k++;
    yes |= pos();

    cout << (yes ? "YES\n" : "NO\n");
    A.clear(); B.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 