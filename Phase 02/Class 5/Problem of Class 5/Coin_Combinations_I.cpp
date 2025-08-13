// Created on: 2025-03-29 01:30
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105, M = 1e9 + 7, LM = 1e6 + 8;
int n, A[nn], Ans[LM];

int ways(int sum) {
    if (sum == 0) {
        return 1;
    }
    if (sum < 0) {
        return 0;
    }
    int &ans = Ans[sum];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += ways(sum - A[i]); ans %= M;
    }
    return ans;
}

int ways_it(int sum) {
    vector<int>Ways(sum + 5, 0);
    Ways[0] = 1;
    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - A[j] >= 0) {
                Ways[i] += Ways[i - A[j]]; 
                Ways[i] %= M;
            }
        }
    }

    return Ways[sum];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int x; cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    memset(Ans, -1, sizeof Ans);
    cout << ways(x) << endl;
    //cout << ways_it(x) << endl;
    
    return 0;
} 