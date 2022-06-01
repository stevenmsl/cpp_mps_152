#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol152;

/*
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/

tuple<vector<int>, int>
testFixture1()
{
  auto input = vector<int>{2, 3, -2, 4};
  return make_tuple(input, 6);
}

/*
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

tuple<vector<int>, int>
testFixture2()
{
  auto input = vector<int>{-2, 0, -1};
  return make_tuple(input, 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.maxProduct(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.maxProduct(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}