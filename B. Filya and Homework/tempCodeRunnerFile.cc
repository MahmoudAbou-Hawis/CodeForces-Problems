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
    int x;
    cin >> x;
    vector<ll>arr(x);
    for(int i = 0 ; i < x ; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    ll X  = ((-arr[x-1] + arr[0])/-2);
    ll X2 = arr[x-1] - arr[0];
    set<ll>result;
    set<ll> result2;
    ll target = arr[0] + X;
    ll target2 = arr[x-1] - X2;
    for(int i = 0 ; i < x; i++)
    {
        if(arr[i] < target)
        {
            result.insert(arr[i] + X);
        }
        else if(arr[i] == target)
        {
            result.insert(arr[i]);
        }
        else
        {
            result.insert(arr[i] - X);
        }
        if(arr[i] > arr[0])
        {
            result2.insert(arr[i]-X2);
        }
    }
    if(result.size() == 1 || result2.size() == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}


