// Created on: 2025-05-31 20:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17, mod = 998244353;
int n, A[nn], B[nn], Mx_A[nn], Mx_B[nn];

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

void Try() {
    cin >> n; int mx = 0, id = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (mx <= A[i]) {
            mx = A[i];
            id = i;
        }
        Mx_A[i] = id;
    }
    
    mx = 0; id = 0;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        if (mx <= B[i]) {
            mx = B[i];
            id = i;
        }
        Mx_B[i] = id;
    }

    for (int i = 0; i < n; i++) {
        int get_a = Mx_A[i], get_b = Mx_B[i];
        if (A[get_a] > B[get_b]) {
            cout << (1LL * power(2, A[get_a], mod) + power(2, B[i - get_a], mod)) % mod << " ";
        }
        else if (A[get_a] < B[get_b]) {
            cout << (1LL *  power(2, B[get_b], mod) + power(2, A[i - get_b], mod)) % mod << " ";
        }
        else {
            if (A[i - get_b] >= B[i - get_a]) {
                cout << (1LL *  power(2, B[get_b], mod) + power(2, A[i - get_b], mod)) % mod << " ";
            }
            else {
                cout << (1LL * power(2, A[get_a], mod) + power(2, B[i - get_a], mod)) % mod << " ";
            }
        }
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