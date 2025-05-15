class Solution {
public:
    bool isOneMutationAway(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < 8; ++i) {
            if (a[i] != b[i])
                ++diff;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());
        if (geneBank.find(endGene) == geneBank.end())
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        vector<char> mutations = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == endGene)
                return steps;

            for (int i = 0; i < 8; ++i) {
                char originalChar = current[i];
                for (char ch : mutations) {
                    if (ch == originalChar)
                        continue;
                    current[i] = ch;
                    if (geneBank.count(current) && !visited.count(current)) {
                        visited.insert(current);
                        q.push({current, steps + 1});
                    }
                }
                current[i] = originalChar;
            }
        }

        return -1;
    }
};
