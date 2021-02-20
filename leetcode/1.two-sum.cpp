/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx;
        map<int, int> table;
        for (auto i=nums.begin(); i!=nums.end(); i++) {
            auto t = table.find(target - *i);
            int pos = (int)(i - nums.begin());
            if (t != table.end()) {
                idx.push_back(pos);
                idx.push_back(t->second);
                break;
            } else {
                table.insert(pair<int, int>(*i, pos));
            }
        }

        return idx;
    }
};
// @lc code=end

