// Created on: 2025-12-07 18:39
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

template<typename T>
void debug(const string &nm, T &&v, int f = -1) {
    if (f == -1) cerr << nm << " = " << v << "\n";
    else {
        string vn = nm.substr(0, nm.size() - 3);
        cerr << vn << "[" << f << "] = " << v << "\n";
    }
}

#define db(x) debug(#x, x)
#define ds(x, i) debug(#x, x, i)

vector<bool> pos_sum(vector<int>& A) {
    int n = accumulate(A.begin(), A.end(), 0);
    int mx = *max_element(A.begin(), A.end());

    vector<int> Cnt(mx + 1, 0);
    
    for (auto x : A) {
        Cnt[x]++;
    }
    
    vector<bool> Pos(n + 1, 0); Pos[0] = 1;

    for (int x = 1; x <= mx; x++) {
        if (!Cnt[x]) continue;

        vector<bool> Npos = Pos;

        int oc = Cnt[x];
        ds(Cnt[x], x);
        for (int len = 0; len < x; len++) {
            
            db(len);
            int sum = 0;
            for (int v = len, c = 0; v <= n; v += x, c++) {

                if (c > oc) {
                    sum -= Pos[v - c * x];
                    c--;
                }

                if (sum) {
                    db(sum);
                    db(v);
                }
                if (sum) Npos[v] = 1;
                sum += Pos[v];
            }

        }
        cerr << endl;
        swap(Npos, Pos);
    }

    return Pos;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<bool> Pos = pos_sum(A);
    for (int i = 1; i < Pos.size(); i++) {
        if (Pos[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
} 