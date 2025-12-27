// Created on: 2025-11-06 22:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17, inf = 1e6 + 1;

vector<vector<int>> Ans; 
vector<int> L[30], A, B;
vector<vector<int>> Closest; 
char S[nn], T[nn];
int n, k;

void prec() {
    Closest.assign(30, vector<int>(n + 2, -1));
    for (int c = 0; c < 26; c++) {
        int s = (int)L[c].size();
        if (s == 0) continue;
        for (int mn = 1; mn <= n; mn++) {
            int lo = 0, hi = s - 1, p = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (L[c][mid] <= mn) {
                    p = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            Closest[c][mn] = p;
        }
    }
}

int min_op(int i, int mn) {
    if (i == 1) return 0;

    mn = max(1, min(mn, i));
    int offset = i - mn;  

    if (Ans[i][offset] != -1) return Ans[i][offset];

    int ans = inf;
    int need = T[i] - 'a';
    int s = (int)L[need].size();

    int p = -1;
    if (mn >= 1 && mn <= n) p = Closest[need][mn];

    while (p != -1 && p < s && i - L[need][p] <= k) {
        int next_mn = min(i - 1, L[need][p]);
        ans = min(ans, max(i - L[need][p], min_op(i - 1, next_mn)));
        p++;
    }

    return Ans[i][offset] = ans;
}


void get(int i, int mn) {
    if (i == 1) return;

    mn = max(1, min(mn, i));
    int offset = i - mn;
    int ans = Ans[i][offset];
    int need = T[i] - 'a';
    int s = (int)L[need].size();

    int p = -1;
    if (mn >= 1 && mn <= n) p = Closest[need][mn];
    int lp = p;

    while (p != -1 && p < s && i - L[need][p] <= k) {
        int next_mn = min(i - 1, L[need][p]);
        if (max(i - L[need][p], min_op(i - 1, next_mn)) == ans) {
            A.push_back(i);
            B.push_back(L[need][p]);
            get(i - 1, next_mn);
            return;
        }
        p++;
    }
}


void res() {
    for (int i = 0; i <= 27; i++) L[i].clear();
}


void Try() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> S[i];
    for (int i = 1; i <= n; i++) cin >> T[i];

    for (int i = n; i >= 1; i--) {
        L[S[i] - 'a'].push_back(i);
    }

    if (S[1] != T[1]) {
        cout << -1 << endl; 
        res(); 
        return;
    }

    Ans.assign(n + 2, vector<int>(k + 2, -1)); 
    prec();

    A.clear(); B.clear();
    int mn = min_op(n, n);
    if (mn > k) {
        cout << -1 << endl;
    } else {
        cout << mn << endl;
        get(n, n);

        for (int i = 1; i <= mn; i++) {
            for (int j = 0; j < A.size(); j++) {
                if (B[j] < A[j]) {
                    S[B[j] + 1] = S[B[j]];
                    B[j]++;
                }
            }
            for (int j = 1; j <= n; j++) cout << S[j];
            cout << endl;
        }
    }

    res();
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) Try();

    return 0;
}
