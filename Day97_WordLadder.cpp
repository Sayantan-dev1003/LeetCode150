class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if (temp == endWord) {
                        return length + 1;
                    }

                    if (wordSet.count(temp)) {
                        q.push({temp, length + 1});
                        wordSet.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};
