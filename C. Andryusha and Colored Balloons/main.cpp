#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define NO_TREES             0
#define ONE_NODE             1
struct Node
{
    int id = 0 ;
    vector<Node*>neighbors ={};
    int level = 0;
    int color = 0;
    int grandFather = 0;
    Node(int _id) : id(_id) {}
};

class graph
{
    protected:
    vector<Node*>_Nodes;
    int nodeNumber;
    int MostNodeHaveChildren = 0;
    Node * big;
    private:
    int NodeId = 1;
    void GraphInit()
    {
        _Nodes = vector<Node*>(nodeNumber);
        for(auto &node : _Nodes)
        {
            node = new Node(NodeId++);
        }
    }
    public:
    void AddNode(int FirstNode,int SecondNode)
    {
        _Nodes[FirstNode-1]->neighbors.push_back(_Nodes[SecondNode-1]);
        _Nodes[SecondNode-1]->neighbors.push_back(_Nodes[FirstNode-1]);
        MostNodeHaveChildren = max({MostNodeHaveChildren , ++_Nodes[FirstNode-1]->level+1
        ,++_Nodes[SecondNode-1]->level+1});
        
    }
    void GraphClear()
    {
        for(auto &node :_Nodes)
        {
            node->neighbors.clear();
        }
    }

    graph(int _nodesNumber ) : nodeNumber(_nodesNumber) 
    {
        GraphInit();
    }
};

class  Andryusha_and_Colored_Balloons  : public graph
{
    private:
    int color = 2;
    void SolveValera_and_Elections(Node * _Node)
    {      
        queue<Node*>q;
        q.push(_Node);
        while (!q.empty())
        {
            Node * currentNode = q.front();
            q.pop();
           for(auto &neighbour : currentNode->neighbors)
           {
                if(neighbour->color == 0)
                {
                    while(((neighbour->color == 0)||(neighbour->color == currentNode->grandFather)) || neighbour->color == currentNode->color )
                    {
                        if(color % MostNodeHaveChildren == 0)color = 1;
                        neighbour->color = color++;
                    }
                    neighbour->grandFather = currentNode->color;
                    q.push(neighbour);
                }
           }
        }
    }
    public:
    void PrintResult()
    {
        _Nodes[0]->color = 1;
        MostNodeHaveChildren++;
        SolveValera_and_Elections(_Nodes[0]);
        cout << MostNodeHaveChildren-1 <<'\n';
        for(auto &node :_Nodes)
        {
            cout << node->color << ' ';
        }
    }
    Andryusha_and_Colored_Balloons(int NumberOfNodes) :graph(NumberOfNodes){}
};
int main()
{
    Code By Abou_Hawis
    int n, u, v, w;
    cin>>n;
    Andryusha_and_Colored_Balloons andryusha_and_Colored_Balloons(n);
    for(int i = 0 ; i < n-1 ; i++)
    {
        cin >> u >> v;
        andryusha_and_Colored_Balloons.AddNode(u,v);
    }
    andryusha_and_Colored_Balloons.PrintResult();

    return 0;
}