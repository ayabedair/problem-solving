#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

vector<ll>lucky;
void generate(ll n){
    if(n > 1e10) return;

    lucky.push_back(n);
    generate((n * 10) + 4);
    generate((n * 10) + 7);
}

int main()
{
    ll n; cin >> n;
    generate(0);
    sort(lucky.begin(), lucky.end());
    cout << (lower_bound(lucky.begin(), lucky.end(), n) - lucky.begin());

    return 0;
}
