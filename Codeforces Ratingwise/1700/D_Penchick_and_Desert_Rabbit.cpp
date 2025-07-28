// Created on: 2025-07-24 22:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 17;
int n, A[nn], Pm[nn], Sm[nn], Vs[nn], Ans[nn];

int get_max(int i) {
    if (Ans[i] != -1) return Ans[i];
    int ans = A[Pm[i]];
    Vs[i] = true;
    int lo = i + 1, hi = n, go = i;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (Sm[mid] < A[i]) {
            go = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    if (Vs[go] == false || Ans[go] != -1) {
        ans = max(ans, get_max(go));
    } 
    if (Vs[Pm[i]] == false || Ans[Pm[i]] != -1) {
        ans = max(ans, get_max(Pm[i]));
    }
    return Ans[i] = ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int sm = A[n], id = n;
    for (int i = n; i >= 1; i--) {
        if (A[i] < sm) {
            sm = A[i];
        }
        Sm[i] = sm;
    }
    
    int pm = A[1]; id = 1;
    for (int i = 1; i <= n; i++) {
        if (A[i] > pm) {
            pm = A[i]; id = i;
        }
        Pm[i] = id;
        Vs[i] = false;
        Ans[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        cout << get_max(i) << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 