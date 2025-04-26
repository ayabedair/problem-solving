#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define MOD 1000000007
#define int long long

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int sub(int a, int b, int m) {
    return ((a % m) - (b % m) + m) % m;
}

int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
// int n, k, mx = LONG_MAX;
vector<int> levels, vis;
vector<vector<int>> adj;
vector<int> nums;
string s;
const int X = 19, Y = 19;
int dp[1000000][9];
int rec(int i, int rem) {
    if (i == s.size()) return rem % 3 == 0;

    if (~dp[i][rem]) return dp[i][rem];

    int ch1 = rec(i + 1, (rem * 10 + (s[i] - '0')) % 3);
    int ch2 = rec(i + 1, (s[i] - '0') % 3) + (rem == 0);

    return dp[i][rem] = max(ch1, ch2);
}

void solve() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << rec(1, (s[0] - '0') % 3) << endl;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
