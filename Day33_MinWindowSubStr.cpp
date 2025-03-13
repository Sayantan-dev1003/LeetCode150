class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> target_freq, window_freq;
        for (char c : t)
            target_freq[c]++;

        int left = 0, right = 0, min_len = INT_MAX, min_start = 0;
        int required = target_freq.size();
        int formed = 0;

        while (right < s.size()) {
            char c = s[right];
            window_freq[c]++;

            if (target_freq.count(c) && window_freq[c] == target_freq[c]) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                char left_char = s[left];
                window_freq[left_char]--;
                if (target_freq.count(left_char) &&
                    window_freq[left_char] < target_freq[left_char]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
