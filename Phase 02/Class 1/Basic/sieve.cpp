#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9;
bool gone[N];
 
int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int>primes;
    for (int i = 2; i * i <= n; i++) {
        if (!gone[i]) {
            for (int j = i * i; j <= n; j += i) {
                gone[j] = true;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!gone[i]) {
            primes.push_back(i);
        }
    }

    cout << primes.size() << endl;
    
    return 0;
} 