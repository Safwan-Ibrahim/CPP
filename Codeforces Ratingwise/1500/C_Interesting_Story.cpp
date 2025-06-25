// Created on: 2025-04-24 06:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n;
string A[nn];

int max_take(int priority) {
    vector<int>V;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (auto x : A[i]) {
            if (x - 'a' == priority) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        V.push_back(cnt);
    }

    sort(V.rbegin(), V.rend());
    int ans = 0, sum = 0;
    for (auto x : V) {
        if (sum + x > 0) {
            sum += x;
            ans++;
        }
        else break;
    }
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, max_take(i));
    } 

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 