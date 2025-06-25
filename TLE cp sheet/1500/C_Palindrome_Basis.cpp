// Created on: 2025-05-07 07:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 4e4 + 8, mod = 1e9 + 7;
vector<int>V;
int Ans[505][nn];

int rev(int x) {
    int num = 0;
    while(x > 0) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return num;
}

void prec() {
    for (int i = 1; i <= nn; i++) {
        if (i == rev(i)) {
            V.push_back(i);
        }
    }
    memset(Ans, -1, sizeof Ans);
}

int way(int i, int sum) {
    if (i == V.size()) {
        return sum == 0;
    }
    int &ans = Ans[i][sum];
    if (ans != -1) {
        return ans;
    }
    ans = way(i + 1, sum);
    if (sum - V[i] >= 0) {
        ans += way(i, sum - V[i]);
    }
    return ans %= mod;
}

void Try() {
    int n; cin >> n;
    cout << way(0, n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec();
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 