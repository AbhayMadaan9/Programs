//https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875
void insertBottom(int ele, stack<int>& st) {
    if (st.empty()) {
        st.push(ele);
        return;
    }
    int topEle = st.top();
    st.pop();
    insertBottom(ele, st);
    st.push(topEle);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int topEle = st.top();
    st.pop();
    reverseStack(st);
    insertBottom(topEle, st);
}
