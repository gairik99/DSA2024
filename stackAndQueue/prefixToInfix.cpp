#include <bits/stdc++.h>
using namespace std;
// problem link
// https://shorturl.at/8mm67

   bool isOperator(char ch) {
        if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
            return false;
        return true;
    }
  
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        for(int i=pre_exp.size()-1; i>=0; i--) {
            auto ch = pre_exp[i];
            if(isOperator(ch)) {
                
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push('(' + op1 + ch + op2 + ')');
            } else {
                st.push(string(1,ch));
            }
        }
        return st.top();
    }