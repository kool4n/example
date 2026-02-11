#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int v, w;
};
class Graph
{
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge: edges)
        {
            adjList[edge.v].push_back(edge.w);
            // adjList[edge.w].push_back(edge.v);
        }
    }
};
void printGraph(Graph const &graph, int n)
{
    cout << "Display in List: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int v: graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<Edge> edges =
    {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};
    int n = 6;
    Graph graph(edges, n);
    printGraph(graph, n);
 
    return 0;
}