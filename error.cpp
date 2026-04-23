#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,string>> tokens;

    cout << "Enter tokens (line token). END to stop:\n";

    int line;
    string tok;

    while (cin >> line >> tok && tok != "END") {
        tokens.push_back({line, tok});
    }

    // ---------- 1. Duplicate Identifier ----------
    cout << "\nDuplicate Identifier Detection:\n";

    set<string> used;
    set<string> keywords = {"int","float","double","if","else","return","void"};

    for (auto p : tokens) {
        string t = p.second;

        // identifier = letter দিয়ে শুরু + keyword না
        if (isalpha(t[0]) && !keywords.count(t)) {

            if (used.count(t)) {
                cout << "Duplicate identifier '" << t
                     << "' at line " << p.first << "\n";
            } else {
                used.insert(t);
            }
        }
    }

    // ---------- 2. Duplicate Token ----------
    cout << "\nDuplicate Token Detection:\n";

    for (int i = 1; i < tokens.size(); i++) {
        if (tokens[i].second == tokens[i - 1].second &&
            tokens[i].second != "{" && tokens[i].second != "}") {

            cout << "Duplicate token '" << tokens[i].second
                 << "' at line " << tokens[i].first << "\n";
        }
    }

    // ---------- 3. Unbalanced Braces ----------
    cout << "\nUnbalanced Braces Detection:\n";

    stack<int> st;

    for (auto p : tokens) {
        if (p.second == "{") st.push(p.first);

        else if (p.second == "}") {
            if (st.empty()) {
                cout << "Unmatched '}' at line " << p.first << "\n";
            } else {
                st.pop();
            }
        }
    }

    while (!st.empty()) {
        cout << "Unmatched '{' at line " << st.top() << "\n";
        st.pop();
    }

    return 0;
}
