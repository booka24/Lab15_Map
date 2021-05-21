
#include "TTreeMap.h"
#include <gtest.h>
#include <cassert>
#include <iostream>
using namespace std;

TEST(TreeMap, can_build_and_run_sample_test)
{
    cs540::Map<int, int> a;
    EXPECT_EQ(0, a.size());
}

TEST(TreeMap, can_add_item)
{
    cs540::Map<int, int> a;
    a.insert(pair<int, int>(0, 444));
    EXPECT_EQ(444, a[0]);
}

TEST(TreeMap, can_find_item)
{
    cs540::Map<int, int> a;
    a.insert(pair<int, int>(0, 444));
    a.insert(pair<int, int>(1, 111));
    a.insert(pair<int, int>(2, 34));
    EXPECT_EQ(34, a[2]);
}

TEST(TreeMap, can_delete_item)
{
    cs540::Map<int, int> a;
    a.insert(pair<int, int>(0, 444));
    a.insert(pair<int, int>(1, 111));
    a.insert(pair<int, int>(2, 34));
    a.erase(0);
    ASSERT_ANY_THROW(a.find(0));
}

TEST(TTreeMap, unexpected_indexation_wont_cause_error)
{
    cs540::Map<int, int> a;
    a.insert(pair<int, int>(0, 444));
    a.insert(pair<int, int>(1, 111));
    a.insert(pair<int, int>(2, 34));
    ASSERT_NO_THROW(a[3]);
}

TEST(TreeMap, can_iterate_object)
{
    cs540::Map<int, int> a;
    a.insert(pair<int, int>(0, 444));
    a.insert(pair<int, int>(1, 111));
    a.insert(pair<int, int>(2, 34));
    int sorted[3] = { 444, 111, 34 };
    int i = 0;
    for (auto iter = a.begin(); iter != a.end(); iter++) {
        EXPECT_EQ(sorted[i], (*iter).second);
        i++;
    }
}