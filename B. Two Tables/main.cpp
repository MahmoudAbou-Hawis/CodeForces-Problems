#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
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
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
struct Rect
{
    ll x1,y1,x2,y2;
    ll area()
    {
        return (x2-x1) * (y2-y1);
    }
};

int main() 
{
    setIO("");
    int t;
    cin>>t;
    while(t--)
    {
        int W,H;
        cin>>W>>H;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int w,h;
        cin>>w>>h;
        int leftSide , rightSide , upSide, buttomSide;
        leftSide  = (max(0,w-x1));
        leftSide  = ((leftSide > 0 && x2+leftSide > W)?OO:leftSide);
        rightSide = (max(0,x2-(W - w)));
        rightSide = ((rightSide > 0 &&x1 -rightSide < 0 )?OO:rightSide);
        buttomSide = max(0,h -y1);
        buttomSide = ((buttomSide > 0 &&buttomSide + y2 > H) ?OO:buttomSide);
        upSide = max(0,y2-(H-h));
        upSide = (( upSide > 0 && y1 - upSide < 0)? OO:upSide );
        int result = min({leftSide , rightSide , upSide, buttomSide});
        cout<< ((result==OO)?-1:result)<<'\n';

    }

    return 0;
}