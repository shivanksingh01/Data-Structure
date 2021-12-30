//  [2,7,11,15], target = 9


vector<int> twoSum(vector<int> & nums, int target){
    unordered_map<int, int> umap;
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        umap[target-nums[i]] = i;
    }
    for(int i=0;i<nums.size();i++){
        if(umap.find(target-nums[i]) != umap.end()){
            auto it = umap.find(target-nums[i]);
            res.push_back(i);
            res.push_back(it.second);
        }
    }
    // for(int i=0;i<nums.size();i++){
    //     if(umap.find(target-nums[i]) != umap.end()){
    //         res.push_back( umap[target-nums[i]]);
    //         re.push_back(i);
    //     }
        // umap[nums[i]] = i;
    }
    return res;
}