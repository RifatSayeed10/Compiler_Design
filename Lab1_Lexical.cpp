#include <bits/stdc++.h>
using namespace std;

int main() {

    string code, line;
    cout << "Enter code (type END to finish):\n";

    while(getline(cin, line)) {
        //if(line == "END") break;
        code += line + " ";
    }

    vector<string> keywords = {"int","float","if","else","for","while","return"};

    vector<string> ids, cons, keys;
    vector<char> ops, sp;

    string temp = "";

    for(int i = 0; i < code.size(); i++) {
        char c = code[i];

        // word (identifier / keyword)
        if(isalnum(c)) {
            temp += c;
        }
        else {
            if(temp != "") {
                // check keyword
                if(find(keywords.begin(), keywords.end(), temp) != keywords.end())
                    keys.push_back(temp);
                else if(isdigit(temp[0]))
                    cons.push_back(temp);
                else
                    ids.push_back(temp);

                temp = "";
            }

            // operator
            if(c=='+'||c=='-'||c=='*'||c=='/'||c=='=')
                ops.push_back(c);

            // special symbol
            if(c=='('||c==')'||c=='{'||c=='}'||c==';'||c==',')
                sp.push_back(c);
        }
    }

    cout << "\nKeywords: ";
    for(auto x: keys) cout << x << " ";

    cout << "\nIdentifiers: ";
    for(auto x: ids) cout << x << " ";

    cout << "\nConstants: ";
    for(auto x: cons) cout << x << " ";

    cout << "\nOperators: ";
    for(auto x: ops) cout << x << " ";

    cout << "\nSpecial Symbols: ";
    for(auto x: sp) cout << x << " ";

    cout << endl;

    return 0;
}
