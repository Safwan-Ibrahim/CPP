#include<bits/stdc++.h>
using namespace std;

long long __lcm(int a, int b) {
    return 1LL * a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(n), gcd(n);
    for (int &a : v) {
        cin >> a;
    }

    gcd[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        gcd[i] = __gcd(v[i], gcd[i + 1]);
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = __gcd(ans, __lcm(v[i], gcd[i + 1]));
    }
    cout << ans << endl;
}

// {1-2, 1-3, 1-4, 1-5, 2-3, 2-4, 2-5, 3-4, 3-5, 4-5}
// gcd of first n numbers = lcm(a[1], gcd(a[2]..a[n]))
// gcd of next n - 1 numbers = lcm(a[2], gcd(a[3]..a[n]))