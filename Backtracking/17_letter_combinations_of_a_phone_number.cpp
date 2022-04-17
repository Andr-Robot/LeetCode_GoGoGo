/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   private:
    unordered_map<char, string> num_letter_map = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                                  {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string path;
    vector<string> res;
    void backtracking(const string &digits, int index) {
        if (digits.size() == path.size()) {
            res.push_back(path);
            return;
        }
        char num = digits[index];
        string letters = num_letter_map[num];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        path.clear();
        res.clear();
        if (0 == digits.size()) return res;
        backtracking(digits, 0);
        return res;
    }
};