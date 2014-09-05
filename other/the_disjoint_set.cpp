#include <iostream>
#include <vector>

using namespace std;

//并查集
//The Disjoint Set ADT
class DisjointSet
{
public:
    //初始化一个并查集
    DisjointSet(int n);
    //返回元素x所在的集合(根节点)
    int find_set(int x);
    //合并两个元素所在的集合
    void union_sets(int x, int y);

private:
    vector<int> disjoint_set_;
};


//初始化一个并查集, O(N)
DisjointSet::DisjointSet(int n)
{
    disjoint_set_.resize(n);

    for(int i=0; i<n; i++)
    {
        disjoint_set_[i] = i + 1;
    }
}

//返回元素x所在的集合(根节点), 平均O(1)
int DisjointSet::find_set(int x)
{
    if(x <= 0 || x > disjoint_set_.size())
        return -1;
    
    int ret = x;

    while(disjoint_set_[ret-1] != ret)
        ret = disjoint_set_[ret-1];

    //路径压缩
    if(ret != x)
    {
        disjoint_set_[x-1] = ret;
    }

    return ret;
}

//合并两个元素所在的集合, O(1)
void DisjointSet::union_sets(int x, int y)
{
    int set_x = find_set(x);
    int set_y = find_set(y);

    if(set_x < 0 || set_y < 0) return;

    if(set_x != set_y)
    {
        disjoint_set_[set_y-1] = set_x;
    }
}

