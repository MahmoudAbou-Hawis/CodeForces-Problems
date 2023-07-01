#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Tourists cout.tie(0);
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
int n,q;
vector<ll>v;
int main(){
    Created By Tourists
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        v = vector<ll>(n);
        for(ll &i : v)cin>>i;
        sort(v.begin(),v.end(),greater<ll>());
        vector<ll>prefix;
        prefix.pb(v[0]);
        for(int i = 1 ; i < n ; i++)
        {
            prefix.pb(v[i]+prefix[i-1]);
        } 
        while (q--)
        {
          int x;
          cin>>x;
          int low = 1 ;
          int high = n;
          int ans = -1;
          while(low <= high)
          {
            int mid = (low + high ) /2;
            if(prefix[mid-1] >= x)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid +1;
            }
          }
          cout<<ans<<'\n'; 
        }
    }
        


    return 0;
}


