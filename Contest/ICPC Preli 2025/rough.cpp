/*
 *   Copyright (c) 2025 Emon Thakur
 *   All rights reserved.
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll M = 1000000;
string s; 
deque<int> stk;
ll sum = 0;
bool shuja = true;

void push(int x)
{
    if(shuja) stk.push_front(x);
    else stk.push_back(x);
    sum += x;
}

void relax()
{
    while(stk.size()>M) 
    {
        if(shuja) sum -= stk.back(), stk.pop_back();
        else sum-= stk.front(), stk.pop_front();
    }
}

void pop()
{
    if(stk.size())
    {
        if(shuja) sum -= stk.front(), stk.pop_front();
        else sum -= stk.back(), stk.pop_back();
    }
}

void printt()
{
    if(stk.size())
    {
        if(shuja) cout<<stk.front()<<'\n';
        else cout<<stk.back()<<'\n';
    }
    else cout<<"-"<<'\n';
}

int main()
{
    //cout<<"Case "<<tc<<": ";
    //check N <= 2 cases 
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(cin >> s)
    {
        relax();
        if(s=="PUSH")
        {
            int x; cin >> x;
            push(x);
            relax();
        }
        else if(s=="POP")
        {
            pop();
        }
        else if(s=="PRINT")
        {
            printt();
        }
        else if(s=="SIZE")
        {
            cout<<stk.size()<<endl;
        }
        else if(s=="SUM")
        {
            cout<<sum<<endl;
        }
        else if(s=="REVERSE")
        {
            shuja ^= 1;
        }
        else if(s=="REPEAT")
        {
            int m; cin >> m;
            int n = stk.size();
            
            if (n == 0) continue;

            if (shuja) {
                int id = 0;
                for (int i = 1; i <= min(M - n, 1LL * n * m); i++) {
                    sum += stk[id];
                    stk.push_back(stk[id++]);
                }
            }
            else {
                int id = n - 1;
                for (int i = 1; i <= min(M - n, 1LL * n * m); i++) {
                    sum += stk[id];
                    stk.push_front(stk[id]);
                }
            }
        }
    }
}
