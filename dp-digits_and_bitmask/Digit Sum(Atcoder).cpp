#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define mod 1000000007
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
vector<vector<int>> grid;
vector<int> nums;
int d;
string s;

int dp[10001][3][101];

int rec(int i, bool can, int sum) {
    if (i == s.size()) {
        return sum % d == 0;
    }

    if (~dp[i][can][sum]) return dp[i][can][sum];

    int mx = can? 9: s[i] - '0';
    int ans = 0;
    for (int j = 0; j <= mx; j++) {
        ans = add(ans, rec(i + 1, can || (j != mx), add(sum, j, d)), mod);
    }
    return dp[i][can][sum] = ans;
}


void solve() {
    cin >> s >> d;
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, false, 0) - 1 + mod) % mod << "\n";
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
