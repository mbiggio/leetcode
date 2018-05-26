#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<sstream>
#include<memory>
#include <boost/functional/hash.hpp>
using namespace std;

/**
 * My solution to topcoder Jewelry problem:
 * https://community.topcoder.com/stat?c=problem_statement&pm=1166
 * 
 * The algorithm I emply consists in solving two knapsack 
 * problems (one for the prefixes and one for the suffixes of the array)
 * and then combining the results for which the capacity 
 * of the knapsack are equal.
 * Special care has to be taken in handling duplicates correctly (with the right multiplicity)
 */

long long knapsack_tc (vector<int> &a) {

  sort(a.begin(),a.end());
  map<int,int> occurrences;
  for (int i : a) occurrences[i]++;
  long long K = 0;
  for (long long i=0; i<=a.size()-1; ++i) K+=a[i];

  /* first pass - left side */
  vector<vector<long long>> left(K+1, vector<long long>(a.size()+1));
  left[0][0]=1;
  for (long long h=1; h<=K; ++h) left[h][0] = 0;
  for (int i=1; i<=a.size(); ++i) {
    for (long long h=0; h<=K; ++h) {
      left[h][i] = left[h][i-1];
      if (h-a[i-1]>=0) 
        left[h][i] += left[h-a[i-1]][i-1];
    }
  }
  

  /* second pass - right side */
  long long counter = 0;
  long long num = 1;
  long long factor = 1;
  vector<vector<long long>> right(K+1, vector<long long>(a.size()+1));
  right[0][a.size()]=1;
  for (long long h=1; h<=K; ++h) right[h][a.size()] = 0;
  for (int i=a.size()-1; i>0; --i) {
    factor *= (occurrences[a[i]]-num+1); factor /= num;
    for (long long h=0; h<=K; ++h) {
      right[h][i] = right[h][i+1];
      if (h-a[i]>=0) {
        right[h][i] += right[h-a[i]][i+1];
        if (h>=num*a[i]) 
          counter += (right[h-num*a[i]][i+num])*(left[h][i])*(factor);
      }
    }
    if (a[i] == a[i-1]) {++num;}
    else {num = 1; factor = 1;}
  }

  return counter;
}

void test() {

  vector<int> v0 = {1,2,3,5,4,5};
  cout << knapsack_tc(v0) << endl;

  vector<int> v1 = {1000,1000,1000,1000,1000,1000,
                     1000,1000,1000,1000,1000,1000,
                     1000,1000,1000,1000,1000,1000,
                     1000,1000,1000,1000,1000,1000,
                     1000,1000,1000,1000,1000,1000};
  cout << knapsack_tc(v1) << endl;

  vector<int> v2 = {1,2,3,4,5};
  cout << knapsack_tc(v2) << endl;

  vector<int> v3 = {7,7,8,9,10,11,1,2,2,3,4,5,6};
  cout << knapsack_tc(v3) << endl;

  vector<int> v4 = {123,217,661,678,796,964,54,111,417,526,917,923};
  cout << knapsack_tc(v4) << endl;
}

int main() {
  test();
  return 0;
}

