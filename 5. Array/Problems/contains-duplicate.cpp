class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // :approach 1: T.C:O(n^2)
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size();++j)
        //         if(nums[i]==nums[j])return true;
        // }
        // return false;

        
        // :apparocah 2: [Using sort algo] || T.C: O(n logn))
        sort(nums.begin(),nums.end());
        for(int i=0; i < nums.size()-1; ++i){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
        
        // approcah 3 [Using set DS] T.C: O(n) && S.C: 0(n);
        // set<int> st;
        // for(int i=0; i<nums.size(); ++i){
        //     if(st.find(nums[i]) != st.end()) // already have i'th element
        //         return true;
        //     else
        //         st.insert(nums[i]);
        // }
        // return false;
    }
};

// Leetcode : https://leetcode.com/problems/contains-duplicate/
