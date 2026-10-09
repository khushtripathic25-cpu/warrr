#include <iostream>
#include <stack>
using namespace std;

void reverse(string s) {
    stack<char> st;
    for (char ch : s) st.push(ch);
    cout << "Original: " << s << "\nReversed: ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

void palindrome(string s) {
    stack<char> st;
    for (char ch : s) st.push(ch);
    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    cout << (s == rev ? "Palindrome" : "Not Palindrome");
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    reverse(s);
    palindrome(s);
}