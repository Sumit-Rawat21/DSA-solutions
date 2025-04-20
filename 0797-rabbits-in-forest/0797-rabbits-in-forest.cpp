class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        // unordered_map<int,int> mp;
        // for(auto ele:answers){
        //     mp[ele]++;
        // }
        // int res=0;
        // for(auto key: mp){
        //     double n= key.second/(key.first+1);
        //     if(n==0) n=1;
        //     res+= ceil(n)*(key.first+1);
        int res=0;
unordered_map <int,int> mpp;
        for (int i : answers) mpp[i]++;

        for (auto& p : mpp)
        res += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
            return res;
    }
};