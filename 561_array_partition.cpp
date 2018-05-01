#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an array of 2n integers, 
 * your task is to group these integers into 
 * n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) 
 * which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 *
 * Solution is simply to sort the vector and sum-up
 * values at even indices.
 * Sketch of proof is as follows: 
 * suppose we have the following array (ordering is irrelevant for the problem):
 *
 *      nums = {1,2,3,4,5,6}
 *
 * and assume that the optimal solution does not contain the pair (5,6).
 * Specifically, suppose the pairs are (5,a[i]) and (6,a[j]).
 * Then, try to modify the optimal solution by pairing (5,6) and (a[i],a[j]).
 * The value then changes as follows:
 *
 *   [min(5,6) + min(a[i],a[j])] - [min(5,a[i]) + min(6,a[j])]
 *     =  5 + min(a[i],a[j]) - a[i] - a[j] 
 *     >= max(a[i],a[j]) + min(a[i],a[j]) - a[i] - a[j]
 *     >= 0
 *
 * Therefore, an optimal solution can always be found by pairing
 * the two biggest elements. The solution proposed here
 * is just an implementation of this greedy strategy.
 */
int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    long long sum = 0;
    for (int i=0; i<nums.size(); i+=2) {
        sum+=(long)(nums[i]);
    }
    return (int)sum;
}

int main() {
  vector<int> v = {1,4,3,2};
  cout << arrayPairSum(v) << endl;
  return 0;
}
