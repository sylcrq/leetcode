#include "undirected_graph.h"
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

UndirectedGraphNode* init_undirected_graph(vector<vector<int> >& nodes)
{
    if(nodes.empty())
        return NULL;

    UndirectedGraphNode* graph = NULL;
    map<int, UndirectedGraphNode*> hash_map;

    for(size_t i=0; i<nodes.size(); i++)
    {
        if(!(nodes[i].empty()))
        {
            UndirectedGraphNode* node = new UndirectedGraphNode(nodes[i][0]);
            hash_map.insert( std::pair<int, UndirectedGraphNode*>(nodes[i][0], node) );

            if(graph == NULL)
                graph = node;
        }
    }

    for(size_t i=0; i<nodes.size(); i++)
    {
        if(!(nodes[i].empty()))
        {
            UndirectedGraphNode* node = hash_map[nodes[i][0]];
            
            for(size_t j=1; j<nodes[i].size(); j++)
            {
                if(hash_map.find(nodes[i][j]) != hash_map.end())
                    (node->neighbors).push_back(hash_map[nodes[i][j]]);
            }
        }
    }

    return graph;
}

void print_undirected_graph(UndirectedGraphNode* node)
{
    if(!node)
        return;

    queue<UndirectedGraphNode*> my_queue;
    map<int, UndirectedGraphNode*> hash_map;
    my_queue.push(node);
    hash_map.insert( std::pair<int, UndirectedGraphNode*>(node->label, node) );

    while(!my_queue.empty())
    {
        UndirectedGraphNode* tmp = my_queue.front();
        my_queue.pop();

        std::cout << tmp->label << "[";

        for(size_t i=0; i<(tmp->neighbors).size(); i++)
        {
            std::cout << ((tmp->neighbors)[i])->label << ",";

            if(hash_map.find(((tmp->neighbors)[i])->label) == hash_map.end())
            {
                my_queue.push((tmp->neighbors)[i]);
                hash_map.insert( std::pair<int, UndirectedGraphNode*>(((tmp->neighbors)[i])->label, (tmp->neighbors)[i]) );
            }
        }

        std::cout << "]" << std::endl;
    }
}

