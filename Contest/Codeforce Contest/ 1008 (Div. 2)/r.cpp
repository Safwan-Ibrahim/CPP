// Created on: 2025-03-10 22:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 4e5 + 8;
int A[N];

void Try() {
    int n; cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    ll sum1 = 0, sum2 = 0;
    set<int>H;
    set<int>F, S;
    for (int i = 1; i <= n; i++) {
        if (i <= n / 2) {
            sum1 += A[i];
            F.insert(A[i]);
        }
        else {
            sum2 += A[i];
            S.insert(A[i]);
        }
        H.insert(A[i]);
    }


    int first = -1, mainn = -1;
    ll ans = sum2 - sum1;
    for (int i = n; i >= 1; i--) {
        if (i <= n / 2) {
            ans += A[i];
            ll need = A[i] + ans;
            if (need > 0 && H.find(need) == H.end()) {
                first = A[i];
                mainn = need;
                cout << A[i] << " ";
                auto it1 = S.begin();
                auto it2 = F.begin();
                F.erase(A[i]);
                F.insert(mainn);
                for (int i = 1; i <= n / 2; i++) {
                    cout << *it1++ << " ";
                    cout << *it2++ << " ";
                }
                cout << endl;
                return;
            }

        }
        // else {
        //     ans -= A[i];
        //     ll need = A[i] - ans;
        //     if (need > 0 && Have.find(need) == Have.end()) {
        //         first = A[i];
        //         mainn = need;
        //         cout << A[i] << " ";
        //         auto it1 = S.begin();
        //         auto it2 = F.begin();
        //         S.erase(A[i]);
        //         S.insert(mainn);
        //         for (int i = 1; i <= n / 2; i++) {
        //             cout << *it1++ << " ";
        //             cout << *it2++ << " ";
        //         }
        //         cout << endl;
        //         return;
        //     }
        //     ans += A[i];
        // }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 