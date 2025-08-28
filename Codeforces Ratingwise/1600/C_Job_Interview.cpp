// Created on: 2025-06-21 11:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, tn, P[nn], T[nn];

map<array<int, 4>, ll>Ans;

ll get_ans(int i, int cur_pn, int cur_tn, bool taken) {
    if (i == n + tn + 2) return 0;
    if (Ans.find({i, cur_pn, cur_tn, taken}) != Ans.end()) return Ans[{i, cur_pn, cur_tn, taken}];
    ll ans = 0;
    if (P[i] > T[i] && cur_pn || (!cur_tn && cur_pn)) {
        ans = P[i];
        if (taken) ans += get_ans(i + 1, cur_pn - 1, cur_tn, true);
        else ans += get_ans(i + 1, cur_pn, cur_tn, true);
    }
    else if (cur_tn) {
        ans = T[i];
        if (taken) ans += get_ans(i + 1, cur_pn, cur_tn - 1, true);
        else ans += get_ans(i + 1, cur_pn, cur_tn, true);
    }
    return Ans[{i, cur_pn, cur_tn, taken}] = ans;
}

void Try() {
    cin >> n >> tn;
    for (int i = 1; i <= n + tn + 1; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= n + tn + 1; i++) {
        cin >> T[i];
    }
    
    vector<ll>Normal(n + tn + 2, 0);
    vector<int>Rest_pn(n + tn + 2, 0), Rest_tn(n + tn + 2, 0);
    Rest_pn[0] = n, Rest_tn[0] = tn;
    vector<bool>Ip(n + tn + 2, false);
    int cur_pn = n, cur_tn = tn;
    for (int i = 1; i <= n + tn + 1; i++) {
        if (P[i] > T[i] && cur_pn || !cur_tn) {
            cur_pn--;
            Normal[i] = Normal[i - 1] + P[i];
            Rest_pn[i] = cur_pn;
            Rest_tn[i] = cur_tn;
            Ip[i] = true;
        } 
        else {
            cur_tn--; 
            Normal[i] = Normal[i - 1] + T[i];
            Rest_pn[i] = cur_pn;
            Rest_tn[i] = cur_tn;
        }
    }

    for (int i = 1; i <= n + tn; i++) {
        ll ans = Normal[i - 1] + get_ans(i, Rest_pn[i - 1], Rest_tn[i - 1], false);
        cout << ans - (Ip[i] ? P[i] : T[i]) << " ";
    }
    cout << Normal[n + tn] << " ";
    cout << endl;
    Ans.clear();

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 