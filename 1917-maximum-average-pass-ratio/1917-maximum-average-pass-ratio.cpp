class Solution {
public:
    double calculate(int pass, int total){
        return double(pass+1)/(total+1)-(double)pass/total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue<pair<double,pair<int,int>>> maxHeap;
       for(auto clas:classes)
       {
        maxHeap.push({calculate(clas[0],clas[1]),{clas[0],clas[1]}});
       }  
       while(extraStudents--){
        auto topele=maxHeap.top();
        maxHeap.pop();
        int pass= topele.second.first;
        int total=topele.second.second;
        maxHeap.push({calculate(pass+1,total+1),{pass+1,total+1}});
       }
       double totalPassRatio=0;
       while(!maxHeap.empty()){
        auto topele=maxHeap.top();
        maxHeap.pop();
         totalPassRatio+=(double)topele.second.first/topele.second.second;
       }
       return totalPassRatio/classes.size();
    }
};