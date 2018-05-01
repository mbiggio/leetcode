#include <iostream>
#include <vector>
using namespace std;

int strStr(const string &haystack, const string &needle) {
    if (needle.empty()) return 0;
    if (needle.size() > haystack.size()) return -1;
    for (int i=0; i<haystack.size()-needle.size()+1; ++i) {
        int idx = 0;
        while (idx < needle.size() && haystack[i+idx] == needle[idx]) {
            ++idx;
        }
        if (idx == needle.size()) return i;
    }
    return -1;
} 

int main() {
  /* test 1 */
  cout << strStr("hello", "ll") << endl;
  cout << strStr("aaaaa", "bba") << endl;
  return 0;
}
