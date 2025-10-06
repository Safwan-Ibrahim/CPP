// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, mx, A[nn]; 
ll ts, Ps[nn];

ll count_of_subseq(vector<int> &V, ll ts) {
    int n = V.size();
    map<ll, int> Mp;
    ll sum = 0, ans = 0;

    Mp[0]++;
    for (int i = 0; i < n; i++) {
        sum += V[i];
        ans += Mp[sum - ts];
        Mp[sum]++;
    }

    return ans;
}

ll count_of_seq(ll ts, int mx) {
    vector<int> V; ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] > mx) {
            if (V.size()) ans += count_of_subseq(V, ts);
            V.clear();
        }
        else {
            V.push_back(A[i]);
        }
    }

    if (V.size()) ans += count_of_subseq(V, ts);
    return ans;
}   

void Try() {
    cin >> n >> ts >> mx;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    cout << count_of_seq(ts, mx) - count_of_seq(ts, mx - 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 