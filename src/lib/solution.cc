#include "solution.h"
#include <numeric>
#include <queue>
using namespace std;

string Solution::PrintHelloWorld() { 
  return "**** Hello World ****"; 
}

vector<int> Solution::OddFilter(vector<int> vec) {//O(n)
  vector<int> res(5);
  auto it = copy_if(vec.begin(), vec.end(), res.begin(), [](const int i){return i % 2 == 0;});
  res.resize(distance(res.begin(), it));
  return res;
}

vector<int> Solution::SquareMap(vector<int> vec) {//O(n)
  vector<int> res(vec.size());
  transform(vec.begin(), vec.end(), res.begin(), [](const int i){return i * i;});
  return res;
}

int Solution::vectorSum(vector<int> vec) {//O(n)
  int res = accumulate(vec.begin(), vec.end(), 0);
  return res;
}

void Solution::heapSort(vector<int> &vec) {//O(nlog(n))
  priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i : vec) pq.push(i);
  for (int i = 0; i < vec.size(); i++) {
    vec[i] = pq.top();
    pq.pop();
  }
}

int Solution::kthLargest(vector<int> vec, int k) {//O(nlog(k))
  if (k <= 0 || vec.size() < k) return INT_MIN;
  priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i : vec) {
    pq.push(i);
    if (pq.size() > k) pq.pop();
  }
  return pq.top();
}


