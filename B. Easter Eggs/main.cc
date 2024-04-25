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
    cin >> n;
    string PeriodString = "ROYGBIV"; 
    int idx = 3;
    int idx2 = 0;
    for(int i = 0 ; i < (n - (n%7)) ; i++)
    {
        if(idx2 == 7) idx2 = 0;
        cout << PeriodString[idx2++];
    }
    for(int i = 0 ; i < (n %7) ;i++)
    {
        if(idx == 7)
        {
            idx = 3;
        }
        cout << PeriodString[idx++];
    }
    return 0;
}


