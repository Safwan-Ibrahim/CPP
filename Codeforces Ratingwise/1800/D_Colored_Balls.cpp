// Created on: 2025-12-08 23:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e3 + 17, mod = 998244353;
int n, s, A[nn];

void another_way() {
    
    sort(A + 1, A + n + 1);
    vector<int> Cost(s + 1, 0);
    vector<int> Pcost = Cost;

    for (int i = n; i >= 1; i--) {

        for (int sum = s; sum >= 0; sum--) {

            Cost[sum] = 0; // take and need of A[i] as max
            if (sum >= A[i]) {
                Cost[sum] = (sum + A[i] + 1) / 2;
            }
            else Cost[sum] = A[i];
            
            // we would need to know if A[i] is the mx, but now we don't need because we calculated this already
            if (i != n) {
                // don't take
                Cost[sum] += Pcost[sum]; 
                Cost[sum] %= mod;
                // take and don't need of A[i] as max
                if (sum + A[i] <= s) {
                    Cost[sum] += Pcost[sum + A[i]];
                    Cost[sum] %= mod;
                }
            }
        }

        Pcost = Cost;
    }

    cout << Cost[0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        s += A[i];
    }

    another_way(); return 0;

    vector<int> Pcnt(s + 1, 0); // prev count of subset sum
    vector<int> Cnt(s + 1, 0); // count of subset sum
    Pcnt[0] = Cnt[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int ss = A[i]; ss <= s; ss++) {
            Cnt[ss] += Pcnt[ss - A[i]];
            Cnt[ss] %= mod;
        }
        Pcnt = Cnt;
    }

    int ans = 0;
    for (int ss = 1; ss <= s; ss++) {
        ans += (1LL * (ss + 1) / 2 * Cnt[ss]) % mod;
        ans %= mod;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int ss = 0; ss < A[i] && ss + A[i] <= s; ss++) {
            ans += 1LL * Cnt[ss] * (A[i] - (ss + A[i] + 1) / 2) % mod;
            ans %= mod;
        }
    }

    cout << ans << endl;
    return 0;
} 