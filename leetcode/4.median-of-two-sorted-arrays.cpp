#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m{static_cast<int>(nums1.size())};
        int n{static_cast<int>(nums2.size())};
        bool odd{static_cast<bool>((n + m) % 2)};
        int med_pos{(n + m) / 2};
        // Special case.
        if (m == 0 && n == 0)
            return 0.0;
        else if (m == 0)
            return odd ? nums2[med_pos]
                       : (nums2[med_pos] + nums2[med_pos - 1]) / 2.0;
        else if (n == 0)
            return odd ? nums1[med_pos]
                       : (nums1[med_pos] + nums1[med_pos - 1]) / 2.0;

        if (nums1[m - 1] <= nums2[0]) {
            if (m - 1 >= med_pos)
                return odd ? nums1[med_pos]
                           : (nums1[med_pos] + nums1[med_pos - 1]) / 2.0;
            else {
                if (odd)
                    return nums2[med_pos - m];
                else
                    return m - 1 == med_pos - 1
                        ? (nums1[m - 1] + nums2[0]) / 2.0
                        : (nums2[med_pos - 1 - m] + nums2[med_pos - m]) / 2.0;
            }
        }
        if (nums1[0] >= nums2[n - 1]) {
            if (n - 1 >= med_pos)
                return odd ? nums2[med_pos]
                           : (nums2[med_pos] + nums2[med_pos - 1]) / 2.0;
            else {
                if (odd)
                    return nums1[med_pos - n];
                else
                    return n - 1 == med_pos - 1
                        ? (nums2[n - 1] + nums1[0]) / 2.0
                        : (nums1[med_pos - 1 - n] + nums1[med_pos - n]) / 2.0;
            }
        }

        // General case. Do binary search.
        int i{0}, curr_pos{-1}, prev_pos{-1}, start{0}, end{m - 1};
        int mid{-1};
        for (;; ++i) {
            while (start <= end) {
                mid = (start + end) / 2;
                if (nums1[mid] > nums2[i])
                    end = mid - 1;
                else if (nums1[mid] == nums2[i])
                    break;
                else
                    start = mid + 1;
            }
            prev_pos = curr_pos;
            if (nums1[mid] >= nums2[i])
                curr_pos = mid;
            else
                curr_pos = mid + 1;
            end = m - 1;
            start = curr_pos;
            if (i + curr_pos >= med_pos)
                break;
            if (i == n - 1)
                break;
        }

        // Combine and return answer.
        if (odd) {
            if (i + curr_pos < med_pos)
                return nums1[med_pos - i - 1];
            else
                return (i + curr_pos == med_pos) ? nums2[i]
                                                 : nums1[med_pos - i];
        } else {
            if (i + curr_pos == med_pos)
                return prev_pos == curr_pos
                    ? (nums2[i] + nums2[i - 1]) / 2.0
                    : (nums2[i] + nums1[curr_pos - 1]) / 2.0;
            else if (i + curr_pos < med_pos)
                return (curr_pos == med_pos - i - 1)
                    ? (nums1[med_pos - i - 1] + nums2[i]) / 2.0
                    : (nums1[med_pos - i - 1] + nums1[med_pos - i - 2]) / 2.0;
            else
                return (prev_pos == med_pos - i)
                    ? (nums1[med_pos - i] + nums2[i - 1]) / 2.0
                    : (nums1[med_pos - i] + nums1[med_pos - i - 1]) / 2.0;
        }

        return -1;
    }
};

int main() {
    vector<int> num1{1, 3, 4, 5};
    vector<int> num2{2};
    Solution a;
    double b(a.findMedianSortedArrays(num1, num2));
    cout << b << endl;
    return 0;
}