//stock span problem
/*
The span of the stock's price today is defined as the maximum number of 
consecutive days(starting from today and going backward) for which the price of the stock was less than today's price.*/


vector<int> findStockSpans(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans;
    stack<pair<int,int>> st;//price ,span

    for (int i = 0; i < n; i++) {
        int span=1;
        while(!st.empty() && st.top().first < prices[i]){
            span += st.top().second;
            st.pop();

        }
        st.push({prices[i],span});
        ans.push_back(span);
    }
    return ans;
}