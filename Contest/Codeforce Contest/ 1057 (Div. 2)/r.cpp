// Created on: 2025-10-12 20:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll cost(vector<int> V) {
    sort(V.begin(), V.end());
    ll sum = 0;
    for (auto x : V) sum += x;
    return abs(sum - 1LL * V[1] * (ll) V.size());
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cout << cost({248215438, 785225899, 701092198});
    
    return 0;
} 