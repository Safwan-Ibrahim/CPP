// Created on: 2025-05-23 15:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, k; string A, B;
int need; ll mx;
vector<char>V;

void check(int st) {
    string S = A;
    set<char>Tmp;
    for (int k = 0; k < 10; k++) {
        if (st >> k & 1) Tmp.insert(V[k]);
    }

    for (int i = 0; i < S.size(); i++) {
        if (Tmp.find(S[i]) != Tmp.end()) S[i] = B[i];
    }

    int cnt = 0; ll ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == B[i]) cnt++;
        if (S[i] != B[i] || i + 1 == S.size()) {
            ans += 1LL * cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    mx = max(ans, mx);
}

void rec(int i, int st) {
    if (i == V.size()) {
        if (__builtin_popcount(st) == need) check(st);
        return;
    }
    rec(i + 1, st);
    st |= (1 << i);
    rec(i + 1, st);
}

void Try() {
    cin >> n >> k;
    cin >> A >> B;
    
    for (auto c : A) {
        V.push_back(c);
    }

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    need = min((int)V.size(), k);
    rec(0, 0);
    cout << mx << endl;

    mx = 0;
    V.clear();

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 