/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        size_t N{s.length()};
        if (N == 0)
            return 0;
        size_t start{0};
        size_t length{1}, temp_length{0};

        for (size_t i{1}; i < N; i++)
        {
            temp_length = i - start;
            size_t pos{s.find(s[i], start)};
            if (pos - start < temp_length)
            {
                start = pos + 1;
                length = max(temp_length, length);
            }
        }

        return max(N - start, length);
    }
};
// @lc code=end
