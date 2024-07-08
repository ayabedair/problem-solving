#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ln '\n'

int main()
{
    string s; cin >> s;
    ll sum = 0;
    for(int i = 0 ; i < s.length() ; ++i){
        if(s[i] == '4' || s[i] == '7')
            sum++;
    }
    if(sum == 4 || sum == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}