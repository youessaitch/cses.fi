#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    sort(a.begin(), a.end()); // applicants sorted

    multiset<ll> ms;
    for (auto &x : b)
        ms.insert(x); // apartments

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        // find smallest apartment >= a[i] - k
        // basically : a[i]-k<=b[j]<=a[i]+k;
        auto it = ms.lower_bound(a[i] - k);
        if (it != ms.end() && *it <= a[i] + k)
        {
            ans++;
            ms.erase(it);
        }
    }

    cout << ans;
    return 0;
}
