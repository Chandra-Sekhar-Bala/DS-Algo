class Solution {
public:
    int maxSubArray(vector<int>& num) {
        int mx=INT_MIN;
        int sum=0;
        for(int i=0; i<num.size(); i++)
        {
            sum+=num[i];
           mx = max(mx,sum); // mx = max so far[i] + nums[i+i]
            // if sum is less than 0 then it will reduce max sum :
            if(sum<0) 
                sum=0;
        }
        return mx;
        
    }
};

//Leetcode: https://leetcode.com/problems/maximum-subarray/
