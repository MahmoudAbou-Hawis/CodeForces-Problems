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
bool isGood(ll mid , vector<ll>&v ,ll tar, ll days )
{
    ll sum = 0;
    ll len = sz(v)-1;
    for(int i = 0 ; i <= min(mid,len) ; i ++)
    {
        sum += (((days -1 - i)/(mid+1))+1)*v[i]; 
    }
    return (sum >= tar);
}  
int main()
{
    Created By Sofar
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c,d;
        cin>>n>>c>>d;
        vector<ll>arr(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<int>());
        if(arr[0] * d < c )
        {
            cout<<"Impossible\n";
            continue;
        }
        ll start = 0; 
        ll end = d-1;
        ll mid;
        ll ans;
        while(start <= end)
        {
            mid = (start + end)/2;
            if(isGood(mid,arr ,c ,d))
            {
                ans = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        if(ans == d -1)
        {
            cout << "Infinity\n"; 
        }
        else
        {
            cout<< ans <<'\n';
        }
    }
    return 0;
}

