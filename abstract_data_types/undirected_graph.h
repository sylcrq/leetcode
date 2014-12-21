#include <vector>

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// create and init a undirected graph
UndirectedGraphNode* init_undirected_graph(std::vector<std::vector<int> >& nodes);
// print a undirected graph
void print_undirected_graph(UndirectedGraphNode* node);
