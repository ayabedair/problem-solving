#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
int n;
vector<int>v(16);
bool solve(int sum, int q){
    if(sum % 360 == 0 && q == n) return true;
    else if(q == n) return false;

    return solve(sum + v[q], q + 1) || solve(sum - v[q], q + 1);
}

int main() {
   cin >> n;
   for(int i = 0 ; i < n ; ++i) cin >> v[i];
   if(solve(0, 0)) cout << "YES";
   else cout << "NO";

    return 0;
}