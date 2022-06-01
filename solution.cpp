#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol152;
using namespace std;

/*takeaways
  - if there are no negative numbers or zeros, then
    The product of the entire array is the max product
  - so the key is how to deal with negative numbers
    [2, 3, -2, 4]
    - up to the second element, the high and the low
      are both eqaul to 6 (2x3)
    - then comes the negative -2, which the high
      will change to -12 ,so will the low.
    - now comes the 4. The high and low are now -48
    - We will record the 6 as the max product
   - why we need to track high and low? because
     when we encouter a negative number, it will turn the high
     to low and low to high
     - let say (high, low) = (3,2)
     - after times -2, the high is -4, and the
       low is -6.
     - If we encouter yet another negative
       number, they will reverse again.
     - This is how we deal with negative numbers.
       - If the number of occurrences of the negative
         numbers are an even number, it will be the same
         as if the entire array only contains positive numbers

*/

int Solution::maxProduct(vector<int> &nums)
{
  auto high = nums[0], low = high, maxP = high;

  for (auto i = 1; i < nums.size(); i++)
  {
    high = nums[i] < 0 ? low * nums[i] : high * nums[i];
    low = nums[i] < 0 ? high * nums[i] : low * nums[i];
    maxP = max(maxP, high);
  }

  return maxP;
}
