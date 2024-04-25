#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define ABOU_HAWIS cout.tie(0);
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
    Created By ABOU_HAWIS
    unordered_map<ll,ll> m;
    int n;
    cin >> n;
    int num;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> num;
        m[num] = i;
    }
    ll vasya = 0, petya = 0;
    int len = n;
    cin >> n;
    for(int i = 0 ; i < n ;i++)
    {
        cin >> num;
        vasya += m[num] +1;
        petya += len - m[num];
    }
    cout << vasya << " " << petya;
    return 0;
}


