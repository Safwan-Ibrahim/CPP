// Created on: 2025-04-30 01:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, m, A[nn];

int last_zero(int x) {
    int ans = 0;
    while(x > 0 && x % 10 == 0) {
        ans++;
        x /= 10;
    }
    return ans;
}

int number_of_digit(int x) {
    int ans = 0;
    while(x > 0) {
        ans++;
        x /= 10;
    }
    return ans;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<int>Zero;
    int digit = 0;
    for (int i = 1; i <= n; i++) {
        digit += number_of_digit(A[i]);
        int lz = last_zero(A[i]);
        if (lz > 0) {
            Zero.push_back(lz);
        }
    }

    sort(Zero.rbegin(), Zero.rend());
    for (int i = 0; i < Zero.size(); i += 2) {
        digit -= Zero[i];
    }

    if (digit > m) {
        cout << "Sasha\n";
    }
    else {
        cout << "Anna\n";
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