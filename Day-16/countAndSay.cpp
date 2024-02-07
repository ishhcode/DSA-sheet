//count and say problem 
//n =1 ans ="1"
//n-2 ans = "11"
//n=3 ans ="21"
//n=4 ans ="1211"
//n=5 ans = "111221"
class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
        return "1";
    }
    if(n==2){
        return "11";
    }
    string prev = countAndSay(n-1);
    string result = "";
    int count=1;
    for(int i=1;i<prev.length();i++){
    if(prev[i]!=prev[i-1]){
        result.push_back('0'+ count);
        result.push_back(prev[i-1]);
        count=1;
    }
    else{
        count++;
    }
    if(i==prev.size()-1){
        result.push_back('0'+ count);
        result.push_back(prev[i]);

    }
    }
    return result;
        
    }
};