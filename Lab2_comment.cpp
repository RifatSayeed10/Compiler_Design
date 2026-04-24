#include<bits/stdc++.h>
using namespace std;

int main() {
    string code, line;
    cout << "Enter code (Ctrl+Z / Ctrl+D to end):\n";

    while(getline(cin, line)) {
        code += line + '\n';
    }

    int n = code.size();
    int lineNo = 1;
    bool found = false;

    for(int i = 0; i < n; i++) {
        if(code[i] == '\n') lineNo++;

        if(i + 1 < n && code[i] == '/' && code[i+1] == '/') {
            found = true;
            string comment = "";
            int startLine = lineNo;
            i += 2;

            while(i < n && code[i] != '\n') {
                comment += code[i];
                i++;
            }

            int letters = 0;
            for(char c : comment) {
                if(isalpha(c)) letters++;
            }

            cout << "\nComment found: //" << comment << "\n";
            cout << "Type: Single-line comment\n";
            cout << "Letters in comment: " << letters << "\n";
            cout << "Line number: " << startLine << "\n";
        }

        else if(i + 1 < n && code[i] == '/' && code[i+1] == '*') {
            found = true;
            string comment = "";
            int startLine = lineNo;
            i += 2;

            while(i + 1 < n && !(code[i] == '*' && code[i+1] == '/')) {
                if(code[i] == '\n') lineNo++;
                comment += code[i];
                i++;
            }

            int letters = 0;
            for(char c : comment) {
                if(isalpha(c)) letters++;
            }

            cout << "\nComment found: /*" << comment << "*/\n";
            cout << "Type: Multi-line comment\n";
            cout << "Letters in comment: " << letters << "\n";
            cout << "Line number: " << startLine << "\n";

            i++;
        }
    }

    if(!found) {
        cout << "\nNo comment found.\n";
    }

    return 0;
}
