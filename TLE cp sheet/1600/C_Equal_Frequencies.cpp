// Created on: 2025-05-22 15:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n; string S;

int get_mn(int x, bool print) {
    vector<int>Fr(26, 0), Ex;
    for (auto x : S) {
        Fr[x - 'a']++;
    }

    set<int>St;
    vector<pair<int, int>>V;
    for (int i = 0; i < 26; i++) {
        if (Fr[i]) V.push_back({Fr[i], i});
        else St.insert(i);
    }

    sort(V.rbegin(), V.rend());
    int sz = V.size();
    if (sz < n / x) {
        for (int i = 1; i <= n / x - sz; i++) {
            V.push_back({0, *St.begin()});
            St.erase(St.begin());
        }
    }
    else if (sz > n / x) {
        for (int i = n / x; i < sz; i++) {
            for (int j = 1; j <= V[i].first; j++) {
                Ex.push_back(V[i].second);
            }
        }
        V.resize(n / x);
    }

    for (int i = 0; i < V.size(); i++) {
        int &cnt = V[i].first;
        int &id = V[i].second;
        if (cnt > x) {
            for (int j = 1; j <= cnt - x; j++) {
                Ex.push_back(id);
            }
            cnt = x;
        }
    }

    if (print) {
        vector<stack<int>>A(26, stack<int>{});
        for (int i = 0; i < V.size(); i++) {
            if (V[i].first < x) {
                for (int j = 1; j <= x - V[i].first; j++) {
                    int id = Ex.back();
                    A[id].push(V[i].second);
                    Ex.pop_back();
                }
            }
        }

        for (int i = 0; i < S.size(); i++) {
            if (!A[S[i] - 'a'].empty()) {
                char c = A[S[i] - 'a'].top() + 'a';
                A[S[i] - 'a'].pop();
                cout << c;
            }
            else cout << S[i];
        }
        cout << endl;

    }

    return Ex.size();

}

void Try() {
    cin >> n;
    cin >> S; 
    int mn = n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && n / i <= 26) mn = min(get_mn(i, 0), mn);
    }

    cout << mn << endl;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && n / i <= 26 && get_mn(i, 0) == mn) {
            get_mn(i, 1); break;
        }
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