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
int main()
{
    Created By Sofar
    int k ; 
    cin>>k;
    map<ll,vector<pi>>m;
    int tst = 1;
    while(k--)
    {
        ll sum = 0;
        int n;
        cin>>n;
        vi arr(n);
        for(int i = 0 ; i < n ;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        vector<bool>freq(1e5,0);
        vector<bool>Nfreq(1e5,0);
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] >= 0)
            {
                if(!freq[arr[i]])
                {
                    m[sum-arr[i]].pb({tst,i+1});
                    freq[arr[i]] = true;
                }
            }
            else 
            {
                if(!Nfreq[-arr[i]])
                {
                    m[sum-arr[i]].pb({tst,i+1});
                    Nfreq[-arr[i]] = true;
                } 
            }
        }
        tst++;
    }
    for(auto &i :m)
    {
        if(sz(i.second)>=2)
        {
            cout<<"YES\n";
            cout<<i.second[0].f <<" " << i.second[0].second<<'\n';
            cout<<i.second[1].f <<" " << i.second[1].second<<'\n';
            return 0;
        }
    }
    cout<<"NO\n";

    return 0;
}


