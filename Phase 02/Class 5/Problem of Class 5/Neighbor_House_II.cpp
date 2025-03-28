// Created on: 2025-03-28 05:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005;
int n, A[N];
int Ans[N][2];

int max_sell(int id, bool taken) {
    if (id == n) {
        if (taken) {
            return 0;
        }
        else {
            return A[n];
        }
    }
    else if (id >= n) {
        return 0;
    }
 
    int &ans = Ans[id][taken];
    if (ans != -1) {
        return ans;
    }
    return ans = A[id] + max(max_sell(id + 2, taken), max_sell(id + 3, taken));
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }   
    memset(Ans, -1, sizeof Ans);
    cout << max({max_sell(1, 1), max_sell(2, 0), max_sell(3, 0)}) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 