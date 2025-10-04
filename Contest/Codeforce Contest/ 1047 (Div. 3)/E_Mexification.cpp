// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, A[nn], Cnt[nn];

vector<int> get(vector<int> &V) {
    for (auto x : V) {
        Cnt[x]++;
    }

    int mex = 0;
    while (Cnt[mex]) mex++;
    
    vector<int> Ans(n);
    for (int i = 0; i < n; i++) {
        if (Cnt[V[i]] == 1 && mex >= V[i]) {
            Ans[i] = V[i];      
        }
        else Ans[i] = mex;
    }

    for (auto x : V) {
        Cnt[x]--;
    }

    return Ans;
} 

void Try() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<int> Ans[6];
    Ans[0] = vector<int> (A + 1, A + n + 1);

    for (int i = 1; i < 6; i++) {
        Ans[i] = get(Ans[i - 1]);
    }

    k = (k <= 5 ? k : 4 + k % 2);
    ll ans = accumulate(Ans[k].begin(), Ans[k].end(), 0LL);

    cout << ans << endl;   
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 