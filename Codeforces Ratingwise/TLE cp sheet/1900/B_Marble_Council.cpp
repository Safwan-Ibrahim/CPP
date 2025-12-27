// Created on: 2025-12-17 22:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5000 + 17, mod = 998244353;

#define db(x, ...) _db(x, #x, ##__VA_ARGS__)

template<typename T>
void _db(T val, const char* name) {
    cerr.write(name, strcspn(name,"[")) << " = " << val << endl;
}

template<typename T, typename... Args>
void _db(T val, const char* name, Args... args) {
    cerr.write(name, strcspn(name,"[")); 
    ((cerr << "[" << args << "]"), ...);
    cerr << " = " << val << endl;
}

void Try() {
    int n; cin >> n;
    vector<int> Cnt(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Cnt[x]++;
    }

    vector<int> A = {0};
    for (int i = 1; i <= n; i++) {
        if (Cnt[i]) A.push_back(Cnt[i]);
    }

    sort(A.begin() + 1, A.end());
    int m = A.size() - 1;

    db(m);

    vector<int> Msc(n + 1, 0); // multiset count
    auto Prev = Msc;

    for (int i = m; i >= 1; i--) {

        for (int sum = n; sum >= 0; sum--) {
            int ans = 0; 
            // taking as mx
            if (sum >= A[i]) { // when we need A[i] as mx // calculating now
                ans += 1;
            }
            // else added 0
            if (i < m) {
                ans += Prev[sum];
                ans %= mod;
            }

            // taking as sum
            if (sum + A[i] <= n) { // validity check
                ans += A[i]; // when we need A[i] contribution in sum // calculating now
                ans %= mod;

                if (i < m) {
                    ans += 1LL * A[i] * Prev[sum + A[i]] % mod;
                    ans %= mod;
                }
            }

            Msc[sum] = ans;
        }
        cerr << i << "-> \n";
        for (int sum = 0; sum <= n; sum++) {
            db(Msc[sum], sum);
        }
        cerr << endl;
        Prev = Msc;
    }

    cout << Msc[0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 