#include "gtest/gtest.h"
#include "LRU_cache.h"

TEST(LRUCacheTestCase, First)
{
    LRUCache* cache = new LRUCache(10);
    cache->set(7, 28);
    cache->set(7, 1);
    cache->set(8, 15);
    EXPECT_EQ(-1, cache->get(6));

    cache->set(10, 27);
    cache->set(8, 10);
    EXPECT_EQ(10, cache->get(8));

    cache->set(6, 29);
    cache->set(1, 9);
    EXPECT_EQ(29, cache->get(6));

    cache->set(10, 7);
    EXPECT_EQ(9, cache->get(1));
    EXPECT_EQ(-1, cache->get(2));
    EXPECT_EQ(-1, cache->get(13));

    cache->set(8, 30);
    cache->set(1, 5);
    EXPECT_EQ(5, cache->get(1));

    cache->set(13, 2);
    EXPECT_EQ(-1, cache->get(12));

    cache->print_list();
}

TEST(LRUCacheTestCase, Second)
{
    LRUCache* cache = new LRUCache(2);
    cache->set(2, 1);
    cache->set(1, 1);
    EXPECT_EQ(1, cache->get(2));

    cache->set(4, 1);
    EXPECT_EQ(-1, cache->get(1));
    EXPECT_EQ(1, cache->get(2));
}

TEST(LRUCacheTestCase, Third)
{
    LRUCache* cache = new LRUCache(3);
    cache->set(1, 1);
    cache->set(2, 2);
    cache->set(3, 3);
    cache->set(4, 4);
    EXPECT_EQ(4, cache->get(4));
    EXPECT_EQ(3, cache->get(3));
    EXPECT_EQ(2, cache->get(2));
    EXPECT_EQ(-1, cache->get(1));

    cache->set(5, 5);
    EXPECT_EQ(-1, cache->get(1));
    EXPECT_EQ(2, cache->get(2));
    EXPECT_EQ(3, cache->get(3));
    EXPECT_EQ(-1, cache->get(4));
    EXPECT_EQ(5, cache->get(5));
}

