// Created on: 2025-06-25 19:22
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int q; cin >> q;
    deque<int>N, R;
    bool rev = false;
    ll normal = 0, reverse = 0, sum = 0;
    int type;
    while(q--) {
        cin >> type;
        if (type == 3) {
            int x; cin >> x; sum += x;
            if (rev) {
                R.push_back(x);
                N.push_front(x);
                normal += sum;
                reverse += 1LL * R.size() * R.back();
            }
            else {
                N.push_back(x);
                R.push_front(x);
                reverse += sum;
                normal += 1LL * N.size() * N.back();
            }
        }
        else if (type == 2) {
            rev ^= 1;
        }
        else {
            if (rev) {
                reverse += sum;
                reverse -= 1LL * R.size() * R.back();
                int el = R.back(); R.pop_back(); R.push_front(el);
                normal -= sum;
                normal += 1LL * N.size() * N.front();
                el = N.front(); N.pop_front(); N.push_back(el);
            }
            else {
                normal += sum;
                normal -= 1LL * N.size() * N.back();
                int el = N.back(); N.pop_back(); N.push_front(el);
                reverse -= sum;
                reverse += 1LL * R.size() * R.front();
                el = R.front(); R.pop_front(); R.push_back(el);
            }
        }
        cout << (rev ? reverse : normal) << endl;
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