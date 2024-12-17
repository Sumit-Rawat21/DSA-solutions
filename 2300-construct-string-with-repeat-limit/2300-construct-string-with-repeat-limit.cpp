class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        priority_queue<pair<char,int>> q;
        string res="";
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int j=0;j<26;j++)
        {
            if(freq[j]>0)
            {
                q.push({'a'+j,freq[j]});
            }
        }

        while(!q.empty())
        {
            auto ele=q.top();
            q.pop();
            int count=min(ele.second,repeatLimit);
            ele.second-=count;
            res.append(count,ele.first);

            if(ele.second>0)
            {
                if(q.empty()) break;
                auto temp=q.top();
                q.pop();
                res.append(1,temp.first);
                temp.second--; 
                if(temp.second>0)
                q.push({temp.first,temp.second});
                q.push({ele.first,ele.second});              
            }


        }

        return res;
    }
};