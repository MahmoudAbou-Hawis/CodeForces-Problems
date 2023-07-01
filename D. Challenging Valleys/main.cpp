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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>v(n);
        for(auto &i:v)cin>>i;
        int l = 0 ; 
        int r = 0;
        int accepted = 0;
        while(r < n)
        {
          while(l > 0 && r < n && v[l-1] <= v[l])
          {
            l++;
            r = l;
          }
          if(l == n)break;
          while(r < n&&v[r+1] == v[r])
          {
                r++;
          }
            if((l == 0 && (r == n-1 || v[r+1] > v[r])) || (l!=0 &&  (r == n-1 || v[r+1] > v[r])) )
            {
                accepted++;
            }
            r++;
            l = r;
        }
        cout<<((accepted == 1)?"YES\n":"NO\n");
    }
    

    return 0;
}

