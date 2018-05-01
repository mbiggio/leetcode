#include <iostream>
#include <vector>
using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int cur_len = 1;
    int max_len = 1;
    for (int i=1; i<nums.size(); ++i) {
        if (nums[i] > nums[i-1]) {
            cur_len += 1;
        }
        else {
            cur_len = 1;
        }
        max_len = max(max_len,cur_len);
    }
    return max_len;
}

int main() {
  /* test 1 */
  vector<int> v;
  v = {1,3,5,4,7};
  cout << findLengthOfLCIS(v) << endl;
  v = {2,2,2,2,2};
  cout << findLengthOfLCIS(v) << endl;
  return 0;
}
