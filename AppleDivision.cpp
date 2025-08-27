#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll i, vector<ll> &v, ll sum, ll totSum)
{
    if (i >= v.size())
    {
        return abs(totSum - 2 * sum);
    }

    ll ans = 0;
    sum += v[i];
    ans = solve(i + 1, v, sum, totSum);
    sum -= v[i];
    ans = min(ans, solve(i + 1, v, sum, totSum));

    return ans;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    ll total_sum = 0;
    for (auto &it : v)
    {
        cin >> it;
        total_sum += it;
    }

    cout << solve(0, v, 0, total_sum);
    return 0;
}
