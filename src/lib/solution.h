#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string PrintHelloWorld();
  vector<int> OddFilter(vector<int> vec);
  vector<int> SquareMap(vector<int> vec);
  int vectorSum(vector<int> vec);
  void heapSort(vector<int> &vec);
  int kthLargest(vector<int> vec, int k);
};

#endif