class Solution {
private:
    void backtrack(int index, const string& digits, string& current,
                   vector<string>& result, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(index + 1, digits, current, result, mapping);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> result;
        string current;

        vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtrack(0, digits, current, result, mapping);
        return result;
    }
};
