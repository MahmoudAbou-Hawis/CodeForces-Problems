#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int main()
{
    setIO();
    ll n ;
    cin >> n;
    vector<ll> v(n);
    vector<ll> prefixsum_1(1,0);
    vector<ll> prefixsum_2(1,0);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
        prefixsum_1.push_back(prefixsum_1[i] + v[i]);
    }
    sort(all(v));
    for(int i = 0 ; i < n ; i++)
    {
        prefixsum_2.push_back(prefixsum_2[i] + v[i]);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int type,l,r;
        cin >> type >> l >> r;
        if(type == 1)
        {
            cout << prefixsum_1[r] - prefixsum_1[l - 1] << '\n';
        }
        else
        {
            cout << prefixsum_2[r] - prefixsum_2[l - 1] << '\n';
        }
    }

    
    return 0;
}