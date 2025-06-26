// Created on: 2025-06-26 14:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 7;
vector<int>prm;
int n;

void prec() {
    vector<bool>gone(nn, false);
    for (int i = 2; i * i < nn; i++) {
        if (!gone[i]) {
            for (int j = i * i; j < nn; j += i) {
                gone[j] = true;
            }
        }
    }

    for (int i = 2; i < nn; i++) {
        if (!gone[i]) {
            prm.push_back(i);
        }
    }
}

vector<int> print(int x) {
    set<int>St;
    for (int i = 1; i <= n; i++) {
        St.insert(i);
    }
    vector<int>Ans; Ans.push_back(x);
    St.erase(x);
    for (int i = 1; i < x; i++) {
        if (St.find(x - i) != St.end()) {
            Ans.push_back(x - i);
            St.erase(x - i);
        }
        if (St.find(x + i) != St.end()) {
            Ans.push_back(x + i);
            St.erase(x + i);
        }
    }
    while(St.size()) {
        Ans.push_back(*St.begin()); St.erase(St.begin());
    }
    return Ans;
}

void Try() {
    cin >> n;
    int id = upper_bound(prm.begin(), prm.end(), n / 2) - prm.begin();
    int cnt = 0; ll sum = 0;
    vector<int> Ans = print(prm[id]);
    for (int i = 0; i < Ans.size(); i++) {
        sum += Ans[i];
        cnt += ((sum + i) / (i + 1)) == prm[id];
        cout << Ans[i] << " ";
    }
    cout << endl;
    assert(cnt >= n / 3 - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 