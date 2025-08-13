// Created on: 2025-07-31 23:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int query1(int l, int r) {
    vector<int>Ans;
    for (int i = l; i <= r; i++) {
        Ans.push_back(i);
    }
    for (int i = l; i <= r; i++) {
        Ans.push_back(i);
    }
    cout << '?' << " " << Ans.size() << " ";
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    cout.flush();
    int ans; cin >> ans; return ans;
}

int query2(int l, int r, int i, int j) {
    cout << "? 6 " << l << " " << j << " " << r << " " << j << " " << i << " " << j << endl;
    cout.flush();
    int ans; cin >> ans; return ans;
}

void Try() {
    int n; cin >> n;
    int lo = 1, hi = n;
    int a, b, c; 
    while(hi - lo > 1) {
        int mid = (hi + lo) / 2;
        a = query1(lo, mid); 
        if (a > 0) {
            hi = mid; continue;
        }
        b = query1(mid + 1, hi);
        if (b > 0) {
            lo = mid + 1; continue;
        }
        c = query1(mid, mid + 1);
        lo = mid, hi = mid + 1;
    }

    cout << "? 3 " << lo << " " << hi << " " << hi << endl;
    cout.flush();
    int not_swap; cin >> not_swap;
    if (!not_swap) {
        swap(lo, hi);
    }

    bool od = false;
    if (n & 1) {
        od = true; n--;
    }
    string S = "";
    for (int i = 1; i + 1 <= n; i += 2) {
        int ans = query2(i, i + 1, lo, hi);
        if (ans == 2) {
            S += "()";
        }
        else if (ans == 3) {
            S += ")(";
        }
        else if (ans == 6) {
            S += "((";
        }
        else if (ans == 1) {
            S += "))";
        }
        else {
            cout << "! afds" << endl; return; 
        }
    }

    if (od) {
        int ans = query2(n, n + 1, lo, hi);
        if (ans == 1 || ans == 2) {
            S += ")";
        }
        else S += "(";
    }

    cout << "! " << S << endl;
    cout.flush();
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 