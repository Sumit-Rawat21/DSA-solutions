class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
      vector<int> ans(n,0);
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];

            ans[y]++;
        }
        int cnt=0;
        int champ;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0) 
            {champ=i;cnt++;}
        }

        if(cnt>1) return -1;
        return champ;
    }
};