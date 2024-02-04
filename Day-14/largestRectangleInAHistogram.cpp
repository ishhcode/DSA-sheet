//largest area rectangle in a histogram
class Solution {
public:
void prevSmaller(vector<int>&heights,vector<int>&left){
   stack<int> st;
   int n = heights.size();
   for(int i=0;i<n;i++){
     while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
     if(!st.empty()){
       left[i] = st.top();
     }
     st.push(i);
   }
 }
 void nextSmaller(vector<int>&heights,vector<int>&right){
   stack<int> st;
   int n = heights.size();
   for(int i=n-1;i>=0;i--){
     while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
     if(!st.empty()){
       right[i] = st.top();
     }
     st.push(i);
   }
 }
 
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
   vector<int>left(n,-1);
   vector<int> right(n,-1);

   prevSmaller(heights, left);
   nextSmaller(heights,right);
   int ans = -1;

   for(int i=0;i<n;i++){
      int l = heights[i];
      if(right[i]==-1){
        right[i]=n;
      }
      int b = right[i]-left[i]-1;
      int newArea=l*b;
      ans=max(ans,newArea);
   }
   return ans;
        
    }
};