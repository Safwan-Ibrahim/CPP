// Created on: 2024-09-30 22:41
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+9;
ll D[N];
int A[N], L[N], R[N];

bool cmp(pair<int,int>a, pair<int,int>b) {
    return a.first > b.first;
}

int32_t main() {   
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1, greater<int>());

    for (int i = 1; i <= q; i++) {
        cin >> L[i] >> R[i];
        D[L[i]]++;
        D[R[i]+1]--;
    }    

    pair<int,int> Mp[n+5];
    for (int i = 1; i <= n; i++) {
        D[i] += D[i - 1];
        Mp[i].first = D[i];
        Mp[i].second = i;
    }

    sort(Mp + 1, Mp + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        D[Mp[i].second] = A[i];
    }

    for (int i = 1; i <= n; i++) {
        D[i] += D[i - 1];
    }

    ll sum = 0;
    for (int i = 1; i <= q; i++) {
        sum += D[R[i]] - D[L[i] - 1];
    }

    cout << sum << endl;

    return 0;
} 