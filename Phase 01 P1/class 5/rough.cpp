#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void sw(int* a, int* b) {
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

int32_t main()
{   
    int n = 8;
    cout << *(&n) << endl;

    int* p= &n;
    cout << *p << endl;

    *p = 5;
    cout << n << endl; 

    *(&n) = 10;
    cout << n << endl;

    int a = 20, b = 30;
    sw(&a,&b);

    cout << a << " " << b << endl;
 
    cout << &n << " " << &n+1 << endl;
}