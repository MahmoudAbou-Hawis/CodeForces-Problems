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


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int>arr(n);
    for(auto &i : arr)
    {
        cin >> i;
    }
    int st  = -1;
    int end = -1;
    for(int  i = 0 ; i < n - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            if(st == -1)
            {
                st = i;
                end = i+1;
            }
            else
            {
                end = i +1;
            }
        }
        else 
        {
            if(st != -1) break;
        }
    }
    if(st != -1)
    {
        reverse(arr.begin()+st,arr.begin()+end +1);
    }
    else
    {
        st = end = 0;
    }
    bool accepted  = true;
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] < arr[i-1])
        {
            accepted = false;
            break;
        }
    }
    if(accepted)
    {
        cout << "yes\n";
        cout << st+1 << " " << end+1;
    }
    else
    {
        cout << "no";
    }
    return 0;
}