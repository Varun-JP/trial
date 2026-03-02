class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0 , len , n = nums.size() , sum = 0;
        unordered_map<int, int> mp ;
        mp[0] = -1;
        for(int i = 0 ; i< n; i++){
            if (nums[i]==0){
                nums[i] = -1;
            }
        }
        for(int i = 0 ; i< n ; i++){
            sum+= nums[i];
            if(mp.count(sum)){

                max_len = max(max_len, i - mp[sum]);
            }
            else{
                mp[sum] = i ;
            }   
        }
        return max_len;
    }
};