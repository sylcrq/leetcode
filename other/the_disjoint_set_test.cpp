#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

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

TEST(TheDisjointSetTestCase, Normal)
{
    DisjointSet myset(5);

    for(int i=1; i<=5; i++)
    {
        EXPECT_EQ(i, myset.find_set(i));
    }

    myset.union_sets(1, 2);
    EXPECT_EQ(1, myset.find_set(2));

    myset.union_sets(2, 3);
    EXPECT_EQ(1, myset.find_set(3));

    myset.union_sets(4, 5);
    EXPECT_EQ(4, myset.find_set(5));

    myset.union_sets(3, 5);
    EXPECT_EQ(1, myset.find_set(4));

    //for(int i=0; i<5; i++)
    //{
    //    cout << disjoint_set[i] << " - ";
    //}
    //cout << endl;
}
