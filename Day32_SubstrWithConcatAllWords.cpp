class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return result;

        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            unordered_map<string, int> windowMap;
            int count = 0;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordMap.count(word)) {
                    windowMap[word]++;
                    count++;

                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};
