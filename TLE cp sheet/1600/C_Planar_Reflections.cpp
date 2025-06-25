// Created on: 2025-05-29 03:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7, nn = 1e3 + 18;
int n, k, Ans[2][nn][nn];

int it_dp(int starting_age, int obstacle) {
    vector<vector<int>>V(starting_age + 3, vector<int>(obstacle + 3, 0));
    vector<int>Pref(obstacle + 3, 0);

    for (int age = 2; age <= starting_age; age++) {
        for (int front = 1; front <= obstacle; front++) {
            V[age][front] = 1;
            int r = obstacle - front;
            V[age][front] += Pref[r];
            if (V[age][front] >= mod) V[age][front] -= mod;
        }

        int sum = 0;
        for (int i = 1; i <= obstacle; i++) {
            sum += V[age][i];
            if (sum >= mod) sum -= mod;
            Pref[i] = sum;
        }
    }

    int ans = 1;
    for (int i = 1; i <= obstacle; i++) {
        ans += V[starting_age][i];
        if (ans >= mod) ans -= mod;
    }
    return ans;
}

int total_set(bool right, int i, int age) {
    if (age == 1 || i == 1 && !right || i == n + 1) return 1;
    int &ans = Ans[right][i][age];
    if (ans != -1) return ans;
    if (right) {
        ans = total_set(right ^ 1, i, age - 1) + total_set(right, i + 1, age);
        if (ans >= mod) ans -= mod;
    }
    else {
        ans = total_set(right ^ 1, i, age - 1) + total_set(right, i - 1, age);
        if (ans >= mod) ans -= mod;
    }
    return ans;
}

void Try() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        for (int age = 1; age <= k; age++) {
            Ans[0][i][age] = -1;
            Ans[1][i][age] = -1;
        }
    }

    cout << total_set(1, 1, k) << endl;
    //cout << it_dp(k, n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 