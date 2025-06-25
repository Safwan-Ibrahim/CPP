// Created on: 2025-05-06 16:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n;
vector<int>A, B;

void Try() {
    cin >> n;
    A.resize(n + 5), B.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    vector<ll>Pref(n + 5, 0);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += B[i];
        Pref[i] = sum;
    }

    vector<ll>D(n + 5, 0), E(n + 5, 0); // D = difference, E = extra
    for (int i = 1; i <= n; i++) {
        int lo = i, hi = n, ans = i - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            ll v = Pref[mid] - Pref[i - 1];
            if (v <= A[i]) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        D[i]++;
        D[ans + 1]--;
        E[ans + 1] += A[i] - (Pref[ans] - Pref[i - 1]);
    }

    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += D[i];
        D[i] = sum;
    }

    for (int i = 1; i <= n; i++) {
        cout << D[i] * B[i] + E[i] << " ";
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