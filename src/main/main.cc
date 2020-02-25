#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/bst.h"
using namespace std;

int main()
{
    Solution solution ;
    std::cout << solution.PrintHelloWorld() << std::endl;

    vector<int> vec = {1,2,3,4,5};
    vector<int> res = solution.OddFilter(vec);
    for (int i : res) cout << i << " ";
    cout << endl;

    BST bst;
    bst.push(1);
    bst.push(2);
    cout << bst.find(1) << endl;
    cout << bst.find(2) << endl;

    vector<int> vec1 = {3,1,5,2,4};
    BST bst1(vec1);
    vector<int> res1 = bst1.levelTraversal();
    for (int i : res1) cout << i << " ";
    cout << endl;

    return EXIT_SUCCESS;
}