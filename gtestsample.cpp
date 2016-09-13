#include "gtest/gtest.h"
#include "insertSort.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <ostream>


using SortAlgorithm::insert_sort;
using SortAlgorithm::merge;
using SortAlgorithm::merge_sort;


TEST(test_insert_sort, test_C_array)
{
    int data1[10]={1,2,3,4,5,6,7,8,9,10};
    int data2[10]={10,9,8,7,6,5,4,3,2,1};
    int data3[10]={5,5,5,5,5,4,4,4,4,4};
    int data4[1]={5};
    int comparedata1[10]={1,2,3,4,5,6,7,8,9,10};
    int comparedata2[10]={10,9,8,7,6,5,4,3,2,1};
    int comparedata3[10]={5,5,5,5,5,4,4,4,4,4};
    int comparedata4[1]={5};

    std::sort(comparedata1,comparedata1+10);
    insert_sort(data1+0,data1+10);
    std::sort(comparedata2,comparedata2+10);
    insert_sort(data2+0,data2+10);
    std::sort(comparedata3,comparedata3+10);
    insert_sort(data3+0,data3+10);
    std::sort(comparedata4,comparedata4+1);
    insert_sort(data4+0,data4+1);
    EXPECT_EQ(std::vector<int>(data1,data1+10),std::vector<int>(comparedata1,comparedata1+10));
    EXPECT_EQ(std::vector<int>(data2,data2+10),std::vector<int>(comparedata2,comparedata2+10));
    EXPECT_EQ(std::vector<int>(data3,data3+10),std::vector<int>(comparedata3,comparedata3+10));
    EXPECT_EQ(std::vector<int>(data4,data4+1),std::vector<int>(comparedata4,comparedata4+1));
}

TEST(test_merge_sort, test_C_array)
{
    int data1[10]={1,2,3,4,5,6,7,8,9,10};
    int data2[10]={10,9,8,7,6,5,4,3,2,1};
    int data3[10]={5,5,5,5,5,4,4,4,4,4};
    int data4[1]={5};
    int comparedata1[10]={1,2,3,4,5,6,7,8,9,10};
    int comparedata2[10]={10,9,8,7,6,5,4,3,2,1};
    int comparedata3[10]={5,5,5,5,5,4,4,4,4,4};
    int comparedata4[1]={5};
    std::sort(comparedata1,comparedata1+10);
    merge_sort(data1+0,data1+10);
    std::sort(comparedata2,comparedata2+10);
    merge_sort(data2+0,data2+10);
    std::sort(comparedata3,comparedata3+10);
    merge_sort(data3+0,data3+10);
    std::sort(comparedata4,comparedata4+1);
    merge_sort(data4+0,data4+1);
    EXPECT_EQ(std::vector<int>(data1,data1+10),std::vector<int>(comparedata1,comparedata1+10));
    EXPECT_EQ(std::vector<int>(data2,data2+10),std::vector<int>(comparedata2,comparedata2+10));
    EXPECT_EQ(std::vector<int>(data3,data3+10),std::vector<int>(comparedata3,comparedata3+10));
    EXPECT_EQ(std::vector<int>(data4,data4+1),std::vector<int>(comparedata4,comparedata4+1));
}

