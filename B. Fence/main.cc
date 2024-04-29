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
    ll n, k;
    cin >> n >> k;
    vector<unsigned long long int> v(n);
    vector<unsigned long long int> prefixsum_1(1,0);
    for(int i = 0;  i < n ; i++)
    {
        cin >> v[i];
        prefixsum_1.push_back(v[i] + prefixsum_1[i]);
    }
    unsigned long long int idx = -1;
    unsigned long long int smallestSum  = -1;
    long long int temp = 0;
    for(int i = 0 ; i <= n - k ; i++)
    {
        smallestSum = min(smallestSum,prefixsum_1[i + k] - prefixsum_1[i]);
        if(temp != smallestSum) idx = i;
        temp = smallestSum;
    }
    cout << idx + 1;
    return 0;
}