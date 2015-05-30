// Time: O(n) Space: O(n)
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st; 
    for (const auto &num : nums) {
      if (st.find(num) == st.end()) st.insert(num);
      else return true;
    }   
    return false;
  }
};

// Time: O(nlogn) Space: O(logn)
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) return true;
    }   
    return false;
  }
};
