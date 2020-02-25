#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(HelloWorldShould, ReturnHelloWorld) {
  Solution solution;
  std::string actual = solution.PrintHelloWorld();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}

TEST(OddFilter, OddFilterTest) {
  Solution solution;
  vector<int> vec = {1,2,3,4,5};
  vector<int> res = solution.OddFilter(vec);
  vector<int> expect = {2,4};
  for (int i = 0; i < res.size(); i++) {
    EXPECT_EQ(res[i], expect[i]);
  }
}

TEST(SquareMap, SquareMapTest) {
  Solution solution;
  vector<int> vec = {1,2,3,4,5};
  vector<int> res = solution.SquareMap(vec);
  vector<int> expect = {1,4,9,16,25};
  for (int i = 0; i < res.size(); i++) {
    EXPECT_EQ(res[i], expect[i]);
  }
}

TEST(VectorSum, VectorSumTest) {
  Solution solution;
  vector<int> vec = {1,2,3,4,5};
  int sum = solution.vectorSum(vec);
  EXPECT_EQ(15, sum);
}

TEST(VectorSum, EmptyVectorSumTest) {
  Solution solution;
  vector<int> vec = {};
  int sum = solution.vectorSum(vec);
  EXPECT_EQ(0, sum);
}

TEST(HeapSortTest, HeapSortTest) {
  Solution solution;
  vector<int> vec = {9,3,12,2,3,1,0,-1,19};
  solution.heapSort(vec);
  vector<int> expectedRes = {-1,0,1,2,3,3,9,12,19};
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec[i], expectedRes[i]);
  }
}

TEST(KthLargetTest, KthLargetTest) {
  Solution solution;
  vector<int> vec = {9,3,12,2,3,1,0,-1,19}; //After sorting: {-1,0,1,2,3,3,9,12,19}
  int res = solution.kthLargest(vec, 2);
  EXPECT_EQ(12, res);
  res = solution.kthLargest(vec, 1);
  EXPECT_EQ(19, res);
  res = solution.kthLargest(vec, 0);
  EXPECT_EQ(INT_MIN, res);
  res = solution.kthLargest(vec, 11);
  EXPECT_EQ(INT_MIN, res);
}