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
void  primeFactoraiztion(vector<int>&result,ll n)
{
   for(int i = 2 ; i * i <= n ;i++)
   {
        while((n%i)==0)
        {
            result.pb(i);
            n/=i;
        }
   }
   if(n!=1)result.pb(n);
}
int main()
{
    Created By Sofar
    int n ; 
    cin>>n;
    vector<int>result;
    primeFactoraiztion(result,n);
    int size =sz(result);
    for(int i = 0 ; i < size-1 ;i++ )
    {
        cout<<result[i]<<'*';
    }
    cout<<result[size-1];
    return 0;
}


