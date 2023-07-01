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
    for(int i = 0 ; i < n; i++)
        matrix[i][i]=0;
    for(int k=0 ;k<n;k++)
        for(int u = 0 ; u <n;u++)
            for(int v=0;v<n;v++)
                matrix[u][v]=min(matrix[u][v],matrix[u][k]+matrix[k][v]);
}
int main(){
   Created By Tourists
    int n;
    cin>>n;
    vector<vector<int>>Matrix(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ;j++)
            cin>>Matrix[i][j];

   floyed(Matrix);

    int q;
    cin>>q;
    for(int i = 0 ; i < q ; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        --a,--b;
        Matrix[a][b] = Matrix[b][a] = min(Matrix[a][b] , c);
        for(int row = 0 ; row < n ; row++)
            for(int colum = 0 ; colum < n ;colum++)
                Matrix[row][colum] = min({ Matrix[row][colum] ,  Matrix[row][a] + Matrix[a][b] + Matrix[b][colum] , Matrix[row][b] + Matrix[a][b] + Matrix[a][colum] });

        ll sum = 0;
        for(int row = 0 ; row < n ; row++)
            for(int colum = row +1 ; colum < n ;colum++)
                sum+=Matrix[row][colum];

        cout<<sum<<" ";
        
    }
    return 0;
}

