//compare versions numbers
class Solution {
public:
    int compareVersion(string a, string b) {
         int n = a.length(), m = b.length();
    int i=0, j=0;
    while(i<n || j<m){
        long num1=0;
        long num2=0;
        while(i<n && a[i]!='.'){
            num1 = num1*10 + (a[i]-'0');
            i++;
        }
        while(j<m && b[j] !='.'){
            num2 = num2*10 + (b[j]-'0');
            j++;
        }
        if(num1>num2) return 1;
        else if(num1<num2) return -1;
        i++;
        j++;
    }
    return 0;
        
    }
};