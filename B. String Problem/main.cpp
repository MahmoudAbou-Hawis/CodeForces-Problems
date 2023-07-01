#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Tourists cout.tie(0);
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
const ll N =27;
void floyed(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i = 0 ; i < N ; i++)
        matrix[i][i]=0;
    for(int k=0 ;k<n;k++)
        for(int u = 0 ; u <n;u++)
            for(int v=0;v<n;v++)
                matrix[u][v]=min(matrix[u][v],matrix[u][k]+matrix[k][v]);
}
int main(){
    Created By Tourists
    vector<vector<int>>Matrix(27,vector<int>(27,OO));
    string firstString,secondString;
    cin>>firstString>>secondString;
    if(firstString.size()!=secondString.size()) {
        cout << "-1";
        return 0;
    }
    int query;
    cin>>query;
    for(int i = 0 ; i < query ;i++)
    {
        char from,to;
        int cost;
        cin>>from>>to>>cost;
        Matrix[from-'a'][to-'a'] = min(Matrix[from-'a'][to-'a'], cost);
    }
    floyed(Matrix);
    int cost = 0;
    string result;
    int n = firstString.size();
    for(int i = 0 ; i < n ; i++)
    {
        int mnCharCost =OO;
        char cheapestChar;
        for (int w = 0; w < 26; w++)
        {
            if(Matrix[firstString[i]-'a'][w] != OO && Matrix[secondString[i]-'a'][w] != OO)
            {
                if(Matrix[firstString[i]-'a'][w] + Matrix[secondString[i]-'a'][w] < mnCharCost)
                {
                    mnCharCost=Matrix[firstString[i]-'a'][w] + Matrix[secondString[i]-'a'][w];
                    cheapestChar = w+'a';
                }
            }
        }
        if(mnCharCost==OO)
        {
            cost =-1;
            break;
        }
        cost+=mnCharCost;
        result+=cheapestChar;
    }
    cout<<cost<<'\n';
    if(cost!=-1)
    cout<<result;

    return 0;
}
