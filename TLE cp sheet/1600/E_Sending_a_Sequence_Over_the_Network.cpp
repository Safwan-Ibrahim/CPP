// Created on: 2025-05-23 22:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn];
bool VR[nn], VL[nn], AR[nn], AL[nn];
map<int, vector<int>>L, R;

// bool left_ok(int i) {
//     if (i <= 0) {
//         return i == 0;
//     }
//     if (VL[i]) return AL[i];
//     VL[i] = true;
//     bool &ans = AL[i];
//     int next = i - A[i] - 1;
//     ans = left_ok(next);
//     for (auto x : R[i]) {
//         ans |= left_ok(x - 1);
//     }
//     return ans;
// }

// bool right_ok(int i) {
//     if (i > n) {
//         return i == n + 1;
//     }
//     if (VR[i]) return AR[i];
//     VR[i] = true;
//     bool &ans = AR[i];
//     int next = i + A[i] + 1;
//     ans = right_ok(next);
//     for (auto x : L[i]) {
//         ans |= right_ok(x + 1);
//     }
//     return ans;
// }

bool better_dp() {
    vector<bool>Pref_ok(n + 1, false);
    Pref_ok[0] = true;
    for (int i = 1; i <= n; i++) {
        if (i + A[i] <= n && Pref_ok[i - 1]) {
            Pref_ok[i + A[i]] = true;
        }
        if (i - A[i] - 1 >= 0 && Pref_ok[i - A[i] - 1]) {
            Pref_ok[i] = true;
        }
    }
    return Pref_ok[n];
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     int left = i - A[i];
    //     int right = i + A[i];
    //     if (left >= 0) L[left].push_back(i);
    //     if (right <= n + 1) R[right].push_back(i);
    // }

    // bool yes = false;
    // for (int i = 0; i <= n; i++) {
    //     yes |= left_ok(i) & right_ok(i + 1);
    // }
    // cout << (yes ? "YES\n" : "NO\n");

    // for (int i = 1; i <= n; i++) {
    //     VL[i] = VR[i] = false;
    // }
    // L.clear(); R.clear();

    bool ok = better_dp();
    cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 