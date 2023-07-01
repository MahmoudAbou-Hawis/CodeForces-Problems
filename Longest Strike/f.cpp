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
    Created By Tourists
    int t;
    cin>>t;
    while(t--)
    {
        int n , k;
        cin>>n>>k;
        map<int,int>freq;
        vector<int>v;
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin>>x;
            freq[x]++;
            if(freq[x]==1)
            {
                v.pb(x);
            }
        }
        sort(v.begin(),v.end());
        int l = 0, h = 0;
        int low  = -1;
        int high = -1;
        int sz = v.size();
        long long result = -1;
        while( h != sz )
        {
            if(freq[v[h]] >= k )
            {
                if((h-l+1) > result)
                {
                    result = h-l+1;
                    low = v[l];
                    high = v[h] ;
                }
                if( h+1 <sz &&v[h+1] - v[h] ==1)
                {
                        h++;
                }
                else
                {
                    h++;
                    l=h;
                }
            }
            else
            {
                h++;
                l=h;
            }

        }
        if(result==-1)
        {
            cout<<-1<<'\n';
        }
        else{
            cout<<low<<" "<<high<<'\n';
        }
    }


    return 0;
}


