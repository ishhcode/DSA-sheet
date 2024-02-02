// Immediate Smaller Element
/*For each element in the array, check whether the immediate right element of the array is smaller or not.
If the next element is smaller, update the current index to that element. If not, then -1. The last element does not
 have any elements on its right.*/

 void immediateSmaller(vector<int>& a)
{
	// Write your code here.
	int n = a.size();
	for(int i=0;i<n-1;i++){
         if(a[i] > a[i+1]){
			 a[i]= a[i+1];
		 }
		 else{
			 a[i]=-1;
		 }
	}
	a[n-1]=-1;
}
//Nearest Smaller Element
/*Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element
 has an index smaller than i.*/
 vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> G;
    stack<int> st;
    int n = A.size();
    for(int i=0;i<n;i++){
        
        while(!st.empty() && (st.top() >= A[i])){
            st.pop();
        }
        int res = (st.empty()?-1 : st.top());
        G.push_back(res);
        st.push(A[i]);
    }
    return G;
}
