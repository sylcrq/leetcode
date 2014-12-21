#include "gtest/gtest.h"
#include "undirected_graph.h"
#include <vector>

using namespace std;

//UndirectedGraphNode* init_undirected_graph(vector<vector<int> >& nodes);
//void print_undirected_graph(UndirectedGraphNode* node);

TEST(UndirectedGraphTestCase, Normal)
{
    int node_1[3] = {0, 1, 2};
    int node_2[2] = {1, 2};
    int node_3[2] = {2, 2};

    vector<vector<int> > nodes;
    vector<int> node_1_(node_1, node_1+3);
    vector<int> node_2_(node_2, node_2+2);
    vector<int> node_3_(node_3, node_3+2);

    nodes.push_back(node_1_);
    nodes.push_back(node_2_);
    nodes.push_back(node_3_);

    UndirectedGraphNode* graph = init_undirected_graph(nodes);

    std::cout << "undirected graph:" << std::endl;
    print_undirected_graph(graph);
}
