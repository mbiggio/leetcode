#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an unsorted array, return whether an 
 * increasing subsequence of length 3 exists or not in the array.
 * Formally the function should return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 <= i < j < k <= n-1, else return false.
 */

bool increasingTriplet(const vector<int>& nums) {
    if (nums.size() == 0) return false;
    
    /* STEP 1 - find an increasing pair */
    int min_idx = 0;
    int low_idx = -1;
    int high_idx = -1;
        
    int i = 1;
    while (i < nums.size()) {
        if (nums[i] > nums[min_idx]) {
            high_idx = i;
            low_idx = min_idx;
            break;
        }
        else {
            min_idx = i;
        }
        i++;
    }
    if (low_idx == -1) return false;

    /* STEP 2 - find an increasing triplet */
    for (int k=i; k<nums.size(); ++k) {
        if (nums[k] > nums[high_idx]) return true;
        else if (nums[k] < nums[high_idx]) {
            if (nums[k] > nums[min_idx]) {
                high_idx = k;
                low_idx = min_idx;
            }
            else {
                min_idx = k;
            }
        }
    }
    return false;
}

int main() {
  vector<int> v;

  /* test 1 */
  v = {1,2,3,4,5};
  cout << increasingTriplet(v) << endl;

  /* test 2 */
  v = {5,4,3,2,1};
  cout << increasingTriplet(v) << endl;
  return 0;
}
