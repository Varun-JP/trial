class Solution {
public:
    vector<vector<int>> ans;
    void permute( vector<int>& nums , int index){
        int n = nums.size();
        if(index == n ){
            ans.push_back(nums) ;
            return;
        }
        unordered_set<int>used;

        for(int i = index ; i < n ; i++){
            if(used.find(nums[i]) !=used.end())  continue;
            used.insert(nums[i]);
            swap(nums[index] , nums[i]);
            permute(nums , index+1);
            swap(nums[index], nums[i]);
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {     
        permute(nums , 0);
        return ans;
    }
};