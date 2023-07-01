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
    ll h,n;
    cin>>h>>n;
    vector<ll>sum(n);
    long double sumation = 0; 
    ll current;
    for(int i = 0 ; i < n ;i++)
    {
        cin>>current;
        (i==0)?sum[i] = current:sum[i] = current + sum[i-1]; 
        sumation+=current;
    }
    ll result = INT64_MAX;
    for(ll i = 0 ; i < n ; i++)
    {
        long double NowNumber = h + sum[i];
        if(NowNumber > 0 && sumation < 0)
        {
            result = min(result ,((ll)ceil(NowNumber / -sumation)*n +i+1) );
        }
        else if(NowNumber <= 0)
        {
            result = min(result,i+1);
        }
    }
    cout<<((result==INT64_MAX)?-1:result);
    return 0;
}


