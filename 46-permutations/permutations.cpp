class Solution {
public:
    vector<vector<int>> ans;
    void permute1( vector<int>& nums , int index){
        int n = nums.size();
        if(index == n){
            ans.push_back(nums) ;
            return;
        }

        for(int i = index ; i < n ; i++){
            swap(nums[index] , nums[i]);
            permute1(nums , index+1);
            swap(nums[index], nums[i]);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {     
        permute1(nums , 0);
        return ans;
    }
};