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

int n;
unsigned countBits(unsigned int Number)
{
    return (int)log2(Number)+1;
}
void even()
{
    vector<int>v(n,0);
    int Number = n/2;
    int PNumber = ((1<<countBits(Number))|Number);
    int start = (Number*2)-1;
    v[start--] = Number;
    v[start--] = PNumber;
    for(int i = start ; i>= 0 ;i--)
    {
        v[i] = v[i+2]-1;
    }
    for(auto &i : v)
    {
        cout<<i<<' ';
    }
    cout<<'\n';
}
void odd()
{
    vector<int>v(n,0);
    int Number = n/2;
    int bits = countBits(Number);
    int PNumber = ((3<<countBits(Number))|Number);
    v[0] = ((2<<bits)|1);
    v[1] = 1;
    v[2] = ((1<<bits)|2);
    v[3] = 2;
    int start = (Number*2)-1;
    v[start--] = Number;
    v[start--] = PNumber;
      for(int i = start ; i>= 4 ;i--)
    {
        v[i] = v[i+2]-1;
    }
    for(auto &i : v)
    {
        cout<<i<<' ';
    }
    cout<<'\n';


}
int main()
{
    Created By Sofar
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n== 3)
        {
            for(int i = 1 ; i < 4 ;i++)cout<<i<<" ";
            cout<<'\n';
            continue;
        }
        if((n/2)%2 == 0)
        {
            even();
        }
        else
        {
            odd();
        }
    }
    return 0;
}

