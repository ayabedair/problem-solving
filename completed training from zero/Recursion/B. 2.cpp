#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

vector<ll>lucky;
ll r, l;
void generate(ll n){
    if(n > 1e10) return;

    if(n >= l) lucky.push_back(n);
    generate((n * 10) + 4);
    generate((n * 10) + 7);
}

int main()
{
    cin >> l >> r;
    generate(0);
    ll sum = 0;
    sort(lucky.begin(), lucky.end());
    while(l <= r){
        auto it = lower_bound(lucky.begin(), lucky.end(), l);
        sum += (min(r, *it) - l + 1) * *it;
        l = *it + 1;
    }

    cout << sum;

    return 0;
}
