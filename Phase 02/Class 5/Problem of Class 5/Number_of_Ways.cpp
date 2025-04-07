// Created on: 2025-04-07 06:59
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 5e5 + 8;
int n, A[N];
ll Pref[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    ll sum = 0;
    map<ll, int>Mp;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
        Pref[i] = sum;
        Mp[sum]++;
    }
    Mp[sum]--;

    if (sum % 3 != 0) {
        cout << 0 << endl; return 0;
    }

    ll need = sum / 3;
    ll ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        Mp[Pref[i]]--;
        if (Pref[i] == need) {
            ans += Mp[2 * need];
        }
    }
    
    cout << ans << endl;
    return 0;
} 