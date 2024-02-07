//check whether two strings are anagram or not
class Solution {
public:
    bool isAnagram(string str1, string str2) {
        int arr[26]={0};
    for(int i=0;i<str1.length();i++){
        arr[str1[i]-'a']++;
    }

    for(int i=0;i<str2.length();i++){
        arr[str2[i]-'a']--;
    }
    for(int i=0;i<str1.length();i++){
        if(arr[str1[i]-'a'] !=0){
            return false;
        }
    }
    for(int i=0;i<str2.length();i++){
        if(arr[str2[i]-'a'] !=0){
            return false;
        }
    }
    return true;
        
    }
};