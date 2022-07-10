/*
 * Author: robot
 * Source : https://leetcode.cn/problems/implement-strstr/
 */
#include <iostream>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        while (i < haystack.size()) {
            int start = i;
            while (i < haystack.size() && j < needle.size() && haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == needle.size()) {
                return start;
            }
            j = 0;
            i = start;
            i++;
        }
        return -1;
    }
    
};