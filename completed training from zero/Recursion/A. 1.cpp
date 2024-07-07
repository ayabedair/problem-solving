#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int c = 0;
void count(ll n, ll res){
    if(res > n) return;

    count(n, res * 10);
    count(n, (res * 10) + 1);
    c++;
}

int main()
{
    ll n; cin >> n;
    count(n, 1);
    cout << c;
    return 0;
}
