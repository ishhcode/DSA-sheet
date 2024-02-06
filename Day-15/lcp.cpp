//longest common prefix 
//approach -1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int len = strs.size();
        string n=strs[0],m = strs[len-1];
        string ans=""; 
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){
                ans+=n[i];
            }
            else break;
        }
        return ans;

        
        
    }
};

//approach-2
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            bool match =true;
            for(int j=1;j < strs.size();j++){
                if(strs[j].size()<i || ch!= strs[j][i]){
                    match= false;
                    break;
                }
            }
            if(match==false)break;
            else ans.push_back(ch);
        }
        return ans;
        
    }
};