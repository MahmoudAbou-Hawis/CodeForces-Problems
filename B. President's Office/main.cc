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


int main()
{
    setIO();
    int n,r;
    cin >> n >> r;
    char president;
    cin >> president;
    vector<vector<char>>room(n,vector<char>(r));
    unordered_map<char,int>visited;
    visited[president] = 1;
    visited['.'] = 1;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < r ;j++)
        {
            cin >> room[i][j];
        }
    }
    int count = 0;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < r; j++)
        {
            if(room[i][j] == president )
            {
                
                if(i > 0)
                {
                    count += ((visited[room[i-1][j]]++ == 0) ?1:0);
                }
                if(i < n-1)
                {
                    count += ((visited[room[i+1][j]]++ == 0) ?1:0);
                }
                if(j > 0)
                {
                    count += ((visited[room[i][j-1]]++ == 0) ?1:0);
                }
                if(j < r -1)
                {
                    count += ((visited[room[i][j+1]]++ == 0) ?1:0);
                }

            }
        }
    }
    cout << count;
    return 0;
}