#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = INT_MAX;
bitset<N>bs; // vector bool has the same space complexity as bitset // but bool array has 8 times more hence (1 byte = 8 bit)

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q,a,b;ll s; cin >> q >> s >> a >> b;
    ll sum = 0;
    while(q--) {
        if(s & 1) {
            sum += s / 2;
            bs.set(s/2);
        }
        else {
            if (bs[s / 2] == 1) {
                bs[s / 2] = 0;
                sum -= s / 2;
            }
        }
        s = (a * s + b) % (1LL << 32);
    }
    cout << sum << endl;
    
    return 0;
} 