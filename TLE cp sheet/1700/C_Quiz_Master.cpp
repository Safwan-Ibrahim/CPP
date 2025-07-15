// Created on: 2025-07-03 11:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, m, A[nn], Cnt[nn];
vector<int> Divisors[nn];

void prec() {
    for (int i = 1; i < nn - 2; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                Divisors[i].push_back(j);
                if (i / j != j) Divisors[i].push_back(i / j);
            }
        }
        sort(Divisors[i].begin(), Divisors[i].end());
    }
}

bool ok(int x) {
    int cnt = 0;
    int right_ = 0;
    bool yes = false;
    for (int left_ = 1; left_ <= n; left_++) {
        while(right_ + 1 <= n && A[right_ + 1] - A[left_] <= x) {
            right_++;
            for (int j = 0; j < Divisors[A[right_]].size() && Divisors[A[right_]][j] <= m; j++) {
                int d = Divisors[A[right_]][j];
                if (Cnt[d] == 0) cnt++;
                Cnt[d]++;
            }
        }
        if (cnt == m) yes = true;
        for (int j = 0; j < Divisors[A[left_]].size() && Divisors[A[left_]][j] <= m; j++) {
            int d = Divisors[A[left_]][j];
            Cnt[d]--; 
            if (Cnt[d] == 0) cnt--;
        }
    }
    return yes;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i]; 
    }
    
    sort(A + 1, A + n + 1);
    int lo = 0, hi = A[n] - A[1], ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            ans = mid; hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 