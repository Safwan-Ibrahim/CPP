// Created on: 2025-06-02 15:13
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2006;
int n, k;
string S;

void Try() {
    cin >> n >> k;
    cin >> S;
    string Need = "";
    for (int i = 1; i <= k - 1; i++) {
        Need += "()";
    }
    int rest = n - ((k - 1) * 2);
    Need += string(rest/ 2, '(');
    Need += string(rest/ 2, ')');

    vector<int>Wrong_left, Wrong_right;
    for (int i = 0; i < n; i++) {
        if (S[i] != Need[i]) {
            if (S[i] == '(') Wrong_left.push_back(i);
            else Wrong_right.push_back(i);
        }
    }

    
    vector<pair<int, int>>Ans;
    for (int i = 0; i < Wrong_left.size(); i++) {
        int a = Wrong_left[i], b = Wrong_right[i];
        if (a > b) swap(a, b);
        Ans.push_back({a, b});
        if (b - a > 1) Ans.push_back({a + 1, b - 1});
        swap(S[a], S[b]);
    }

    cout << Ans.size() << endl;
    for (auto [x, y] : Ans) {
        cout << x + 1 << " " << y + 1 << endl;
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