#include<bits/stdc++.h>
using namespace std;

bool isKey(string s) {
    string k[] = {"int","float","using","namespace","std","return","cout","if","else","while","for"};
    for(string x : k) if(x == s) return true;
    return false;
}

bool isOp(char c) {
    string op = "+-*/%=<>!";
    return op.find(c) != string::npos;
}

bool isSp(char c) {
    string sp = "(){}[];,";
    return sp.find(c) != string::npos;
}

int main() {
    string code, line;
    cout << "Enter code and end with ctrl+z:\n";

    while(getline(cin, line)) code += line + "\n";

    set<string> keywords, constants, identifiers, symbols, operators;
    string token = "";

    for(int i = 0; i < code.size(); i++) {
        char c = code[i];

        if(isalnum(c) || c == '_'|| c=='.') token += c;
        else {
            if(token != "") {
                if(isKey(token)) keywords.insert(token);
                else if(isdigit(token[0])) constants.insert(token);
                else identifiers.insert(token);
                token = "";
            }

            if(isOp(c)) {
                string op = string(1, c);
                if(i + 1 < code.size()) {
                    string two = op + code[i + 1];
                    if(two == "==" || two == "<=" || two == ">=" || two == "!=" || two == "++" || two == "--") {
                        operators.insert(two);
                        i++;
                        continue;
                    }
                }
                operators.insert(op);
            }
            else if(isSp(c)) {
                symbols.insert(string(1, c));
            }
        }
    }

    if(token != "") {
        if(isKey(token)) keywords.insert(token);
        else if(isdigit(token[0])) constants.insert(token);
        else identifiers.insert(token);
    }

    cout << "keywords: ";
    for(auto x : keywords) cout << x << " ";
    cout << "\nidentifiers: ";
    for(auto x : identifiers) cout << x << " ";
    cout << "\noperators: ";
    for(auto x : operators) cout << x << " ";
    cout << "\nconstants: ";
    for(auto x : constants) cout << x << " ";
    cout << "\nspecial symbols: ";
    for(auto x : symbols) cout << x << " ";
}
