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

    int ans = 0;
    set<int> St;
    for (int i = 1; i <= n; i++) {
        if (Cnt[i]) {
            St.insert(Cnt[i]);
        }
    }

    vector<int> Cmx(n + 1, 0); // compressed mx
    vector<int> Rmx(St.size() + 1, 0); // real mx
    int id = 0;
    for (auto x : St) {
        Cmx[x] = ++id;
        Rmx[id] = x;
    }

    vector<int> A = {0};
    for (int i = 1; i <= n; i++) {
        if (Cnt[i]) A.push_back(Cnt[i]);
    }

    sort(A.begin() + 1, A.end());
    int m = A.size() - 1;

    vector<vector<int>> Msc(id + 1, vector<int> (n + 1, 0)); // multiset count
    auto Prev = Msc;

    for (int i = m + 1; i >= 1; i--) {
        for (int sum = n; sum >= 0; sum--) {

            for (int mx = id; mx >= 0; mx--) {
                if (i == m + 1) {
                    Msc[mx][sum] = (sum >= Rmx[mx]); 
                    continue;
                }
                int ans = 0;
                if (sum + A[i] <= n) {
                    ans += 1LL * Prev[mx][sum + A[i]] * A[i] % mod;
                    ans %= mod;
                }
                ans += Prev[Cmx[A[i]]][sum];
                ans %= mod;
                Msc[mx][sum] = ans;
            }
        }
        Prev = Msc;
        cerr << i << "-->\n";
        for (int sum = n; sum >= 0; sum--) {
    
            for (int mx = id; mx >= 0; mx--) {
                db(Msc[mx][sum], Rmx[mx], sum);
            }
        }
    }
    
    ans += Msc[0][0];
    ans %= mod;

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 