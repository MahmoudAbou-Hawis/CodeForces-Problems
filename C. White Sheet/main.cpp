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
ll intersection_area(int num_args ,...)
{
    va_list args;
    va_start(args,num_args);
    ll MIN_X2 = LOO, MAX_X1 = 0,MIN_Y2 = LOO,MAX_Y1 = 0;
    Rect curr{};
    for(int i = 0 ; i < num_args ;i++)
    {
        curr = va_arg(args,Rect);
        MIN_X2 = min(MIN_X2,curr.x2);
        MAX_X1 = max(MAX_X1,curr.x1);
        MIN_Y2 = min(MIN_Y2,curr.y2);
        MAX_Y1 = max(MAX_Y1,curr.y1);
    }
    return ((MIN_X2 - MAX_X1) * (MIN_Y2 - MAX_Y1 ));
}
bool Is_Intersection(int num_args ,...)
{
    va_list args;
    va_start(args,num_args);
    Rect curr{};
    ll x =LOO , y =LOO;
    for(int i = 0 ; i < num_args ; i++)
    {
        curr = va_arg(args,Rect);
        x = min(x,curr.x2 );
        y = min(y,curr.y2);
    }
    va_start(args,num_args);
    for(int i = 0 ; i < num_args ;i++)
    {
        curr = va_arg(args,Rect);
        if(!(x <= curr.x2 && y <= curr.y2 && curr.x1 < x && curr.y1 < y ))
            return false;
    }
    return true;
}

int main() {
    setIO("");
    Rect first{},second{},third{};
    cin>>first.x1>>first.y1 >> first.x2>>first.y2 >>second.x1>>second.y1 >> second.x2>>second.y2;
    cin>>third.x1>>third.y1 >> third.x2>>third.y2;
    ll result = first.area();  
    if(Is_Intersection(2,first,second))
    {
        result-= intersection_area(2,first,second);
    }
    if(Is_Intersection(2,first,third))
    {
        result-= intersection_area(2,first,third);
    }
    if(Is_Intersection(3,first,second,third))
    {
        result += intersection_area(3,first,second,third);
    }
   cout<< ((result > 0)?"YES":"NO");
    
    return 0;
}

