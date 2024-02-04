int findCelebrity(int n) {
    stack<int> st;

    // Push all elements onto the stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Eliminate candidates until only one candidate remains
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (knows(a, b)) {
            // a knows b, so 'a' cannot be the celebrity
            st.push(b);
        } else {
            // a doesn't know b, so 'b' cannot be the celebrity
            st.push(a);
        }
    }

    // Potential celebrity candidate remaining
    int potentialCelebrity = st.empty() ? -1 : st.top();

    // Check if the potential celebrity is a valid celebrity
    for (int i = 0; i < n; i++) {
        if (i != potentialCelebrity && (knows(potentialCelebrity, i) || !knows(i, potentialCelebrity))) {
            return -1;  // Not a valid celebrity
        }
    }

    return potentialCelebrity;
}
