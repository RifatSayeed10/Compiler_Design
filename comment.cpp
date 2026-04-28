#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input.txt");
    char c, n;

    bool single = 0, multi = 0;

    cout << "Comments:\n";
    string code = "";

    while (f.get(c)) {

        // detect comment start
        if (!single && !multi && c == '/' && f.get(n)) {
            if (n == '/') {
                single = 1;
                cout << "//";
            }
            else if (n == '*') {
                multi = 1;
                cout << "/*";
            }
            else {
                code += c;
                f.unget();
            }
        }

        // single line comment
        else if (single) {
            cout << c;
            if (c == '\n') single = 0;
        }

        // multi line comment
        else if (multi) {
            cout << c;
            if (c == '*' && f.get(n)) {
                cout << n;
                if (n == '/') multi = 0;
                else f.unget();
            }
        }

        // normal code
        else {
            code += c;
        }
    }

    cout << "\n\nCode without comments:\n";
    cout << code;

    return 0;
}
