// Created on: 2025-07-01 22:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], Cnt[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Cnt[A[i]]++;
    }

    vector<int>Dif(n + 5, 0);
    for (int i = 0; i <= n; i++) {
        if (i == 0 || Cnt[i - 1] > 0) {
            Dif[i]++;
            Dif[n - Cnt[i] + 1]--;
        }
        else break;
    }
    
    vector<int>Ans;
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += Dif[i];
        Ans.push_back(sum);
    }

    reverse(Ans.begin(), Ans.end());
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    for (int i = 1; i <= n; i++) {
        Cnt[A[i]] = 0;
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