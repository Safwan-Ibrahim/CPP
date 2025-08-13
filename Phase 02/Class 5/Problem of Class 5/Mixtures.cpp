// Created on: 2025-04-02 09:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105, inf = 1e9;
int n, Pref[nn], Ans[nn][nn];

int min_cost(int l, int r) {
    if (l == r) {
        return 0;
    }
    int &ans = Ans[l][r];
    if (ans != -1) {
        return ans;
    }
    ans = inf;
    for (int i = l; i <= r - 1; i++) {
        int a = (Pref[i] - (l ? Pref[l - 1] : 0) + 100) % 100;
        int b = (Pref[r] - Pref[i] + 100) % 100;
        ans = min(ans, a * b + min_cost(l, i) + min_cost(i + 1, r));
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {  
            int x; cin >> x;
            sum += x;
            sum %= 100;
            Pref[i] = sum;
        }
    
        memset(Ans, -1, sizeof Ans);
        cout << min_cost(1, n) << endl;
    }
    
    return 0;
} 