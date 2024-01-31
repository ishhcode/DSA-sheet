//sort a stack
#include <bits/stdc++.h> 
void sortedInsert(stack<int> &st,int x){
	
	// Base case: If the stack is empty or the top element is less than x, push x
    if (st.empty() || st.top() < x) {
        st.push(x);
        return;
    }

    // If the top element is greater than x, pop it and make a recursive call
    int n = st.top();
    st.pop();
    sortedInsert(st, x);

    // Push the popped element back to the stack
    st.push(n);

}
void sortStack(stack<int> &st)
{
	// Write your code here
	//base case
	if(st.empty())return ;
	// Pop the top element and make a recursive call to sort the remaining stack
    int x = st.top();
    st.pop();
    sortStack(st);

    // Insert the popped element into the sorted stack
    sortedInsert(st, x)


}