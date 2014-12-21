#include "undirected_graph.h"
#include <iostream>
#include <map>
#include <queue>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
{
    if(!node)
        return NULL;

    queue<UndirectedGraphNode*> my_queue;
    map<UndirectedGraphNode*, UndirectedGraphNode*> hash_map;

    my_queue.push(node);
    UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
    //hash_map.insert( std::pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, copy) );
    hash_map[node] = copy;

    while(!my_queue.empty())
    {
        UndirectedGraphNode* tmp = my_queue.front();
        my_queue.pop();

        for(vector<UndirectedGraphNode*>::iterator it=(tmp->neighbors).begin(); it != (tmp->neighbors).end(); it++)
        {
            if(hash_map.find(*it) != hash_map.end())
            {
                (hash_map[tmp]->neighbors).push_back(hash_map[*it]);
            }
            else
            {
                UndirectedGraphNode* new_node = new UndirectedGraphNode((*it)->label);
                my_queue.push(*it);
                //hash_map.insert( std::pair<UndirectedGraphNode*, UndirectedGraphNode*>(*it, new_node) );
                hash_map[*it] = new_node;
                (hash_map[tmp]->neighbors).push_back(new_node);
            }
        }
    }

    return copy;
}

