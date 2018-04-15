//DFS for directed graph
//unweighted graph

#include <bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define print(a) printf("%d",a)
#define SZ 1000000

vector<int>adj[SZ+10];
//vector<int>parent;
int parent[SZ];
int visit[SZ];

void init()
{
    for(int i = 0 ; i  < SZ ; i++){
        parent[i] = -1;
        visit[i] = 0;
    }
}

void input_graph(int no_edges)
{
    for(int i = 0; i < no_edges ; i++)
    {
        int u,v;
        sc(u);
        sc(v);
        adj[u].push_back(v);
    }
}

void DFS_visit(int s)
{
    for(int i = 0 ; i < adj[s].size(); i++)
    {
        int v = adj[s][i];
//        print(v);
//        printf("\n");
        if(visit[v] == 0)
        {
            cout<<v<<endl;
            parent[v] = s;
            visit[v] =  1;
            DFS_visit(v);
        }
    }
}

void DFS(int no_vertex)
{
    int s;

    for(s = 0; s < no_vertex; s++)
    {
        if(visit[s] == 0 )
        {
            visit[s] = 1;
            cout<<s<<endl;
            DFS_visit(s);
        }
    }
}




int main()
{
    int no_vertex,no_edges;

    sc(no_vertex);
    sc(no_edges);

    init();

    input_graph(no_edges);

    DFS(no_vertex);

//    for(int i = 0 ; i < no_vertex; i++)
//    {
//        if(parent[i]!=0)
//        {
//            print(parent[i]);
//            printf(" ");
//        }
//    }

    printf("\n");

    return 0;

}

