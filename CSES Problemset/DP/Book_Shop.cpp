// Created on: 2025-07-08 16:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1007, inf = -1e8;
int n, x, Page[nn], Price[nn];

int get_max(int x) {
    // from i to n maximum page we can get at price x = Mx[i][x];
    vector<int>Mn_next(x + 3, 0), Mn_cur(x + 3, 0);
    for (int i = n; i >= 1; i--) {
        for (int sum = x; sum >= 0; sum--) {
            Mn_cur[sum] = Mn_next[sum];
            if (sum + Price[i] <= x) {
                Mn_cur[sum] = max(Mn_cur[sum], Page[i] + Mn_next[sum + Price[i]]);
            }
        }
        Mn_next = Mn_cur;
    }
    return Mn_next[0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> Price[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> Page[i];
    }
    cout << get_max(x) << endl;
    
    return 0;
} 