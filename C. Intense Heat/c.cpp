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
     
int main(){
   // Created By Tourists
    ll n,k;
    scanf("%lld%lld",&n,&k);
    vector<ll> PrefixSum(n+1,0);
    ll number;
    for(ll i = 1 ; i  <= n ; ++i)
    {
        cin>>number;
        PrefixSum[i] = number + PrefixSum[i-1];
    }
    long double result = 0;
    for(int i  = 1 ; i <= n; i++)
    {
        for(int j = i + (k-1) ; j <= n ; j++)
        {
            long double total = PrefixSum[j] - PrefixSum[i-1];
            long double temp = total / (long double)(j-i+1);
            result = max(temp,result);
        }
    }
    printf("%0.15LF",result);

    return 0;
}


