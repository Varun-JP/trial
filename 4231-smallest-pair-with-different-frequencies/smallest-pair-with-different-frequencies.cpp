class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> value; // - 1, -1
        int n = nums.size();
        unordered_map<int, int> hash;
        int max= 0;

        for(int x: nums){
            hash[x]++;
        }

        for(auto& p : hash){
            value.push_back(p.first); //to only record unique values 
        }
        sort(value.begin() , value.end());

        int m = value.size(); //only for unqiue values we return 

        for(int i=0; i< m ; i++){
            for(int j=i+1; j< m ; j++){
                if(hash[value[i]] != hash[value[j]] ){ 
                    //if two are unequal then we return 
                      return {value[i] , value[j]};
                }
            
            }
        }
        return {-1,-1}; 
    }
};