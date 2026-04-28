#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> code;
    string line;

    while (getline(cin, line)) {
        code.push_back(line);
    }

    stack<pair<char,int>> st;
    bool hasError = false;

    for (int i = 0; i < code.size(); i++) {
        string s = code[i];
        int lineNo = i + 1;

        // remove spaces
        string temp = s;
        temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());

        if (temp.empty()) continue;

        // 🔹 1. Semicolon check
        char last = temp.back();
        if (last != ';' && last != '{' && last != '}') {
            cout << "Syntax Error: Missing semicolon at line " << lineNo << endl;
            hasError = true;
        }

        // 🔹 2. Bracket check
        for (char c : s) {
            if (c == '(' || c == '{') {
                st.push({c, lineNo});
            }
            else if (c == ')' || c == '}') {
                if (st.empty()) {
                    cout << "Syntax Error: Unmatched parenthesis at line " << lineNo << endl;
                    hasError = true;
                } else {
                    char top = st.top().first;
                    int topLine = st.top().second;
                    st.pop();

                    if ((c == ')' && top != '(') || (c == '}' && top != '{')) {
                        cout << "Syntax Error: Mismatched parenthesis at line " << lineNo << endl;
                        hasError = true;
                    }
                }
            }
        }
    }

    // 🔹 leftover opening brackets
    while (!st.empty()) {
        cout << "Syntax Error: Unmatched parenthesis at line " << st.top().second << endl;
        st.pop();
        hasError = true;
    }

    if (!hasError) {
        cout << "No Syntax Errors Found" << endl;
    }

    return 0;
}
