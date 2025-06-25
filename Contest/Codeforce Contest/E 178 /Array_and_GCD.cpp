// Created on: 2025-04-28 21:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 4e5 + 8, mm = 1e7 + 8;
int n, A[nn];
ll Pref[nn], Prime_sum[nn];
vector<int>Primes;
bool Done[mm];


void prec() {
    for (int i = 2; 1LL * i * i < mm; i++) {
        for (int j = i * i; j < mm; j += i) {
            Done[j] = true;
        }
    }

    for (int i = 2; i < mm - 2; i++) {
        if (!Done[i]) {
            Primes.push_back(i);
        }
    }

    ll sum = 0;
    for (int i = 0; i < nn - 2; i++) {
        sum += Primes[i];
        Prime_sum[i + 1] = sum;
    }

}

bool ok(int x) {
    ll have = Pref[x];
    ll need = Prime_sum[x];
    //cerr << x << " " << need << " " << have << endl;
    return have >= need;
}


void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1, greater<>());
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        Pref[i] = sum;
    }

    int lo = 1, hi = n, ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << n - ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 