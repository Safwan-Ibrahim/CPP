#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+9;
int n,arr[N],brr[N];

void merge_sort_sp(int l, int r) 
{
    if (l >= r) {
        return;
    }

    int mid = (l+r)/2;
    merge_sort_sp(l,mid);
    merge_sort_sp(mid+1,r);

    int p1 = l, p2 = mid+1;
    for (int i = l; i <= r; i++) {
        if (p1 > mid) {
            brr[i] = arr[p2++];
        }
        else if (p2 > r) {
            brr[i] = arr[p1++];
        }
        else if (arr[p1] < arr[p2]) {
            brr[i] = arr[p1++];
        }
        else {
            brr[i] = arr[p2++];
        }
    }

    for (int i = l; i <= r; i++) {
        arr[i] = brr[i];
    }

}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    merge_sort_sp(1,n);

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    return 0;
} 