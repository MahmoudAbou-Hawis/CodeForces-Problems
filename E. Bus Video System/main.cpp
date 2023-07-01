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
long n ,w;
vi arr;
void solve()
{
    int start  = 0;
    int end = 0;
    int counter = 0;
    int h = 0; 
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i]<0)
        {
            h += (-arr[i]);
        }
        else
        {
            if(h-arr[i] < 0)
            {
                end +=abs(h-arr[i]);
                h=0;
            }else
            {
                h-=arr[i];
            }
        }
        if(counter + arr[i] < 0)
        {
            start += abs(counter+arr[i]);
            counter = 0;
        }
        else
        {
            counter+=arr[i];
        }
    }
    if(start <0 || (w-end < 0) || start > (w-end) )
    {
        cout<<0<<'\n';
        return;
    }
 cout<<(w-end-start+1)<<'\n';;
}

int main()
{
    Created By Sofar
    cin>>n>>w;
    arr = vi(n);
    for(auto&i : arr)
    {
        cin>>i;
    }
    solve();
    return 0;
}


