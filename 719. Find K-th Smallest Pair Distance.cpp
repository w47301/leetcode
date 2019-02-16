/*
题意：给定n个数，则会有n*(n-1)/2个距离（绝对值），求第k大的距离值
思路：
    二分搜索第k大的距离值
    先将数组排序，则可以以O（nlogn）的复杂度求值cnt(mid)——不大于mid的距离值个数，进而二分搜索第一个不小于k的cnt(mid)值
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = nums[n-1]-nums[0];
        while (l <= r) {
            int mid = (l+r)/2, cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += upper_bound(nums.begin(), nums.end(), nums[i]+mid)-nums.begin()-i-1;
            if (cnt >= k) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};