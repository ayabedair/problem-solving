#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int main(){
    ll n; cin >> n;

    if(n <= 2)
        cout << n;
    else if(n % 2)
        cout << n * (n-1) * (n-2);
    else if(n % 3)
        cout << n * (n-1) * (n-3);
    else
        cout << (n-1) * (n-2) * (n-3);
}
