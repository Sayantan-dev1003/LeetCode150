class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].size();
            int last = index + 1;

            while (last < n &&
                   totalChars + 1 + words[last].size() <= maxWidth) {
                totalChars += 1 + words[last].size();
                last++;
            }

            string line;
            int numWords = last - index;
            int numSpaces = maxWidth - totalChars + (numWords - 1);

            if (last == n || numWords == 1) {
                for (int i = index; i < last; i++) {
                    if (!line.empty())
                        line += " ";
                    line += words[i];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int spacesBetween = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int i = index; i < last; i++) {
                    if (!line.empty()) {
                        line += string(
                            spacesBetween + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0)
                            extraSpaces--;
                    }
                    line += words[i];
                }
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};
