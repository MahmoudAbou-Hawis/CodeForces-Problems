#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Sofar cout.tie(0);
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
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;   

pair<ll,ll> solve(ll x)
{
    if(x == 0) return {1,0};
    ll counts = 0;
    ll sum = 0;
    while (x != 0)
    {
        sum += (x%10);
        x /= 10;
        counts++;
    }
    return {counts,sum};
}

int main()
{
    Created By Sofar
    string str;
    cin >> str;
    ll TotalSumOfNumber = 0;
    ll n = 0;
    for(int i = 0 ; i < str.size() ; i++)
    {
        TotalSumOfNumber += (str[i]-'0');
    }
    if(str.size() > 1)n++;
    pair<ll,ll> r = solve(TotalSumOfNumber);
    while (r.first != 1)
    {
        n++;
        TotalSumOfNumber = r.second;
        r = solve(TotalSumOfNumber);
    }
    cout << n;
    
    return 0;
}


