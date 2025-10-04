// Created on: 2025-09-08 20:34
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int a, k;

int min_cost(int x, int y) {
    if (x == a) return 0;
    int ans = 1e9;
    if (x % 2 == 0) {
        ans = min(ans, 1 + min_cost(x / 2, y + x / 2));
    }
    if (y % 2 == 0) {
        ans = min(ans, 1 + min_cost(x + y / 2, y / 2));
    }
    return ans;
}

void print(int x, int y) {
    if (x == a) return;
    int l = 1e9, r = 1e9;
    int ans = l;
    if (x % 2 == 0) {
        l = min(ans, 1 + min_cost(x / 2, y + x / 2));
    }
    if (y % 2 == 0) {
        r = min(ans, 1 + min_cost(x + y / 2, y / 2));
    }
    if (l == r) {
        cout << "nope damn\n";
    }
    if (l < r) {
        cout << 1 << " ";
        print(x / 2, y + x / 2);
    }
    else {
        cout << 2 << " ";
        print(x + y / 2, y / 2);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> k >> a;
    cout << min_cost(1 << k, 1 << k);
    cout << endl;
    print(1 << k, 1 << k);

    cout << endl;

    for (int i = 30; i >= 0; i--) {
        if ((a >> i) & 1) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
} 