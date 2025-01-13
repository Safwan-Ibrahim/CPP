#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sum = 0;
    // O(2^n * 31)
    for (int i = 0; i < (1 << n); i++) {
        ll cur = 0;
        for (int b = 0; b < 31; b++) {
            if (i >> b & 1) {
                cur ^= a[b];
            }
        }
        sum += cur;
    }

    cout << sum << endl; 
    sum = 0;
    vector<int>cnt(31,0);
    // O(n * 31)
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < 31; b++) {
            if (a[i] >> b & 1) {
                cnt[b]++;
            }
        }
    }

    for (int b = 0; b < 31; b++) {
        if (cnt[b] > 0) {
            int cnt_zero = n - cnt[b];
            ll con = (1LL << (cnt[b] + cnt_zero - 1)); // cnt[b] + cnt_zero = n; so solution o (1 << (n - 1)) 
            sum += (con << b);
        }
    }

    cout << sum << endl;
    sum = 0;
    for (int k = 0; k < 31; k++) {
        int cnt_zero = n - cnt[k];
        ll con = (1 << cnt_zero) * (cnt[k] * (cnt[k] / 2) + (cnt[k] & 1));
        sum += (con << k);
    }

    cout << sum << endl;
    return 0;
} 