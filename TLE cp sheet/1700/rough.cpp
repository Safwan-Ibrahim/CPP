#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
int n, L, k;
int d[505], a[505];

map<tuple<int, int, int>, int> memo;

int solve(int i, int removed, int prev) {
    if (removed > k) return INF;
    if (i == n + 1) {
        return (L - d[prev]) * a[prev];
    }
    auto state = make_tuple(i, removed, prev);
    if (memo.count(state)) return memo[state];
    int keep = (d[i] - d[prev]) * a[prev] + solve(i + 1, removed, i);
    int remove = solve(i + 1, removed + 1, prev);
    return memo[state] = min(keep, remove);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> L >> k;
    for (int i = 0; i < n; ++i) cin >> d[i];
    d[n] = L;
    for (int i = 0; i < n; ++i) cin >> a[i];
    a[n] = 0;

    cout << solve(1, 0, 0) << '\n';
    return 0;
}
