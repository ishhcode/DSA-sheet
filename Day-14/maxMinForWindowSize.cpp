//maximum of minimum for every window size
void prevSmaller(vector<int>&a,int n ,vector<int> &left){
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(!st.empty()){
      left[i] = st.top();
        }
        st.push(i);
    }
}
void nextSmaller(vector<int>&a,int n ,vector<int> &right){
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) {
      right[i] = st.top();
        }
        st.push(i);
    }
}
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> result(n, INT_MIN);
    vector<int> left(n, -1);
    vector<int> right(n, n);

    prevSmaller(a, n, left);
    nextSmaller(a, n, right);

    for (int i = 0; i < n; i++) {
        int windowSize = right[i] - left[i] - 1;  // Corrected calculation
        result[windowSize - 1] = max(result[windowSize - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        result[i] = max(result[i], result[i + 1]);
    }

    return result;
}