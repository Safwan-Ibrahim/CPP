// Created on: 2025-02-28 00:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 3e5 + 8;
int n, k, A[N];
char S[N];

bool ok(int x) {
    vector<int>B; 
    vector<char>C;
    for (int i = 1; i <= n; i++) {
        if (A[i] > x) {
            B.push_back(A[i]);
            C.push_back(S[i]);
        }
    } 

    int cnt = 0; bool blue = false;
    for (int i = 0; i < B.size(); i++) {
        if (C[i] == 'R') {
            if (blue) {
                cnt++;
            }
            blue = false;
        }
        else {
            blue = true;
        }
    }
    if (blue) {
        cnt++;
    }
    return cnt <= k;
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int lo = 0, hi = 1e9, ans;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        } 
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 