// Created on: 2024-12-30 22:31
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll MAX = 1e18;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll>ans;
    ll p2 = 1;
    for (int i = 0; p2 < MAX; i++, p2 *= 2) {
        ll p3 = 1;

        for (int j = 0; p2 * p3 < MAX; j++, p3 *= 3) {
            ll p5 = 1;
            
            for (int k = 0; p2 * p3 * p5 < MAX; k++, p5 *= 5) {
                ans.push_back(p2 * p3 * p5);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << "The 1500'th ugly number is ";
    cout << ans[1499] << "." << endl;

    
    return 0;
} 