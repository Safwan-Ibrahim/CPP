#include <bits/stdc++.h>
using namespace std;

const int N = 3001;
double dp[N][N], p[N];
bool vis[N][N];
int n;

double rec(int i, int head, int tail) {
    if (i == n + 1) {
        if (head > tail) { 
            return 1;
        }
        else {
            return 0;
        }
    }
    if (vis[i][head]) {
        return dp[i][head];
    }
    vis[i][head] = true;
    double ans = p[i] * rec(i + 1, head + 1, tail);
    ans += (1 - p[i]) * rec(i + 1, head, tail + 1);
    return dp[i][head] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << fixed << setprecision(10) << rec(1, 0, 0) << '\n';

    return 0;
}