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
    int n;
    cin>>n;
    vi v(n);
    bool flag = true;
    int counter = 0;
    for(auto &i:v)
    {
        cin>>i;
        if(i==1 && flag)counter++;
        else
            flag = false;
    }
    int l = 0;
    int h = 0;
    int result = 0;
    while(h < n)
    {
        if(v[h] == 0 || h == n-1)
        {
            if(v[h] == 0)
            result=max(result, h-l);
            else{
                int i = 0;
                if(h-l+1 ==n)counter = 0;
                result = max(result,h-l+1+counter);
                break;
            }
            h++;
            l = h;
            continue;
        }
        if(v[h] == 1)h++;
    }

    cout<<result;

    return 0;
}


