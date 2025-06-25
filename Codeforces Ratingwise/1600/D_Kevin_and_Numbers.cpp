// Created on: 2025-06-11 02:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int pn, tn;
multiset<int>A, B;

bool have(int x) {
    if (x == 1) {
        if (A.find(x) != A.end()) {
            A.erase(A.find(x));
            return true;
        }
        return false;
    }
    if (A.find(x) != A.end()) {
        A.erase(A.find(x));
        return true;
    }
    return have(x / 2) && have((x + 1) / 2);
}

void Try() {
    cin >> pn >> tn;
    A.clear(), B.clear();
    for (int i = 1; i <= pn; i++) {
        int x; cin >> x;
        A.insert(x);
    }
    for (int i = 1; i <= tn; i++) {
        int x; cin >> x;
        B.insert(x);
    }

    bool yes = true;
    for (auto it = B.begin(); it != B.end(); it++) {
        if (!have(*it)) {
            cout << "No\n"; return;
        }
    }
    cout << (A.empty() ? "Yes\n" : "No\n");
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 