#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

ll solve(ll n, ll sum, vector<ll> &dp)
{
    if (sum > n)
        return 0;
    if (sum == n)
    {
        return 1;
    }
    if (dp[sum] != -1)
        return dp[sum];

    ll ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        ans += solve(n, sum + i, dp) % mod;
    }

    return dp[sum] = ans;
}

int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> dp(n + 1, -1);
    ll ans = solve(n, sum, dp) % mod;
    cout << ans << endl;
    return 0;
}