#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
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
 
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
vector<pair<pair<int,int>,char>> points;
vector<vector<char>> graph;
 
bool result = false;
 
void check(vector<vector<char>> shape)
{
 
    if(!result)
    {
        if(shape.size() > points[0].f.f) return;
        map<char,int>c ;
        c['A'] = 0;
        c['B'] = 0;
        c['C'] = 0;
        for(int i = 0 ; i < points[0].f.f ; i++)
        {
            for(int j = 0 ; j < shape[i].size() ;j++)
            {
                c[shape[i][j]]++;
            }
        }
        if(c['A'] + c['B'] + c['C'] == (points[0].f.f * points[0].f.f))
        {
            result = true;
            graph = shape;
            return;
        }
    }
}
 
void bruteforce(int company, vector<vector<char>> shape)
{
    if(company == 3)
    {
        check(shape);
        return;
    }
    if(shape.size() > points[0].f.f) return;
 
    if(shape.size() < points[0].f.f)
    {
        vector<vector<char>> shape2 = shape;
        vector<char> x(points[company].first.second);
        int len = shape.size();
        for(int i = 0 ; i < points[company].first.first ; i++)
        {
            shape2.pb(x);
            for(int j = 0 ; j < points[company].f.s ; j++)
            {
                shape2[len][j] = points[company].s;
            }
            len++;
        }
        if(result) return;
        bruteforce(company+1 ,shape2);
 
        shape2 = shape;
        vector<char> x1(points[company].first.f);
        len = shape.size();
        for(int i = 0 ; i < points[company].first.s ; i++)
        {
            shape2.pb(x1);
            for(int j = 0 ; j < points[company].f.f ; j++)
            {
                shape2[len][j] = points[company].s;
            }
            len++;
        }
        if(result) return;
        bruteforce(company+1 ,shape2);
    }
 
    else
    {
        for(int i = 0 ; i < points[0].first.first ; i++)
        {
            while(shape[i].size() != points[0].first.first)
            {
                shape[i].pb(points[company].s);
            }
 
        }
       
        bruteforce(company+1,shape);
        if(result) return;
    }
}
 
int main()
{
    setIO("");

    int x,y;
    cin >> x >> y;
    int result = 0;
    int var;
    for(int i = 0 ; i < x ;i++)
    {
        cin >> var;
        result += (var > y)? 2:1;
    }
    cout << result;
    return 0;
}