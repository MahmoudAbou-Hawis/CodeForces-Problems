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
   // Created By Sofar
   int n;
   cin>>n;
   vector<long double>v(n);
   map<long double , int>m;
    for(auto &i : v)
    {
        scanf("%LF",&i);
        m[i]++;
        if((ll)(i)%2 == 0)
        if(m.find(i/2)==m.end())
            m[i/2] = 0;
        if(m.find(i*3)==m.end())    
        m[i*3] = 0;
    }
    long double start;
    for(auto &i :v)
    {
        if((ll)i % 2 ==0 )
        {
            if(!m[i/2] && !m[i*3])
            {
                start = i ;
                break;
            }
        }
        else
        {
        
             if(!m[i*3])
            {
                start = i ;
                break;
            }
        }
    }
    vector<long double>ans;
    ans.pb(start);
    int counter = 0;
    while(counter < n)
    {
        if(m[ans[counter]*2])
        {
            ans.push_back(ans[counter]*2);
            m[ans[counter]*2]--;
        }
        if(m[ans[counter]/3])
        {
             ans.push_back(ans[counter]/3);
            m[ans[counter]/3]--;
        }
        counter++;
    }
    for(auto &i:ans)
    {
        printf("%0.0LF ",i);
    }
    return 0;
}


