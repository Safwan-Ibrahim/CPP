#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int power(int x, int n, int mod) { // O(mod)
    if (mod == 1) return 0;
    vector<int> a;
    vector<bool> vs(mod, false);
    a.push_back(1); // x^0
    vs[1] = true;
    int cur = 1, st = 0;
    while (true) {
        cur = 1LL * cur * x % mod;
        if (vs[cur]) {
            st = find(a.begin(), a.end(), cur) - a.begin();
            break;
        }
        vs[cur] = true;
        a.push_back(cur);
    }

    int len = (int)a.size() - st;
    if (n < st) {
        return a[n];
    }
    n -= st;
    return a[st + n % len];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x = 2, n = 9, m = 40;
    cout << power(x, n, m) << '\n';
    return 0;
}