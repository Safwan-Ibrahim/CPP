// Created on: 2025-09-07 19:41
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];
bool Done[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> Swt, Swo; // segment with two, segment with one
    int prev = -1;
    bool two = false;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) {
            if (prev != -1) {
                if (two) {
                    Swt.push_back({prev, i - 1});
                }
                else Swo.push_back({prev, i - 1});
            }
            prev = -1;
            two = false;
        }
        else if (A[i] == 1) {
            if (prev == -1) prev = i;
        }
        else {
            two = true;
            if (prev == -1) prev = i;
        }
    }

    if (A[n] != 0) {
        if (two) Swt.push_back({prev, n});
        else Swo.push_back({prev, n});
    }

    for (auto [l, r] : Swt) {
        Done[l - 1] = Done[r + 1] = true; 
    }

    for (auto [l, r] : Swo) {
        if (!Done[l - 1] && l != 1) Done[l - 1] = true;
        else if (!Done[r + 1]) Done[r + 1] = true;
    }

    int ans = Swt.size() + Swo.size();

    for (int i = 1; i <= n; i++) {
        ans += A[i] == 0 && !Done[i];
    }

    cout << ans << endl;
    
    return 0;
} 