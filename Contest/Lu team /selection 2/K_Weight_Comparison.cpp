// Created on: 2025-04-18 18:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>>A, B;
    pair<int, int> Ar[m + 1];

    set<int>S;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        Ar[i] = {x, y};
        S.insert(x);
        S.insert(y);
    }

    map<int, int>Mp, Ump;
    int id = 1;
    for (auto x : S) {
        Mp[x] = id;
        Ump[id] = x;
        id++;
    }
    for (int i = 1; i <= m; i++) {
        auto [x, y] = Ar[i];
        Ar[i] = {Mp[x], Mp[y]};
    }


    for (int i = 1; i <= m; i++) {
        auto [x, y] = Ar[i];
        if (abs(x - y) == 1) {
            A.push_back({x, y});
        }
        else {
            B.push_back({x, y});
        }
    }

    if (A.empty()) {
        sort(B.begin(), B.end());
        cout << B.size() << endl;
        for (auto [x, y] : B) {
            cout << Ump[x] << " " << Ump[y] << endl;
        }
        return;
    }

    sort(A.begin(), A.end());
    int last = A[0].second;
    int first = A[0].first;
    set<pair<int, int>>St;
    for (int i = 1; i < A.size(); i++) {
        if (A[i].first == last) {
            last = A[i].second;
            if (i == A.size() - 1) {
                St.insert({first, last});
            }
        }
        else {
            St.insert({first, last});
            first = A[i].first;
            last = A[i].second;
        }
    }

    for (auto [x, y] : B) {
        bool covered = false;
        for (auto [l, r] : St) {
            if (l <= x && r >= y || l >= y && r <= x) {
                covered = true;
                break;
            }
        }
        if (!covered) A.push_back({x, y});
        
    }

    sort(A.begin(), A.end());
    cout << A.size() << endl;
    for (auto [x, y] : A) {
        cout << Ump[x] << " " << Ump[y] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 