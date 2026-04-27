// <Exp>   → <Term> + <Term> | <Term> - <Term> | <Term>
// <Term>  → <Factor> * <Factor> | <Factor> / <Factor> | <Factor>
// <Factor>→ ( <Exp> ) | ID | NUM
// ID      → a|b|c|d|e
// NUM     → 0|1|2|…|9
#include <bits/stdc++.h>
using namespace std;

string str;
int i = 0, l;
bool f = false;

void Exp();
void Term();
void Factor();

bool isID(char c) {
    return (c >= 'a' && c <= 'e');
}

bool isNUM(char c) {
    return (c >= '0' && c <= '9');
}

void Exp() {
    Term();
    if (f && i < l && (str[i] == '+' || str[i] == '-')) {
        i++;
        Term();
    }
}

void Term() {
    Factor();
    if (f && i < l && (str[i] == '*' || str[i] == '/')) {
        i++;
        Factor();
    }
}

void Factor() {
    if (i < l && str[i] == '(') {
        i++;
        Exp();
        if (f && i < l && str[i] == ')') {
            i++;
            f = true;
            return;
        } else {
            f = false;
            return;
        }
    }
    else if (i < l && isID(str[i])) {
        i++;
        f = true;
        return;
    }
    else if (i < l && isNUM(str[i])) {
        i++;
        f = true;
        return;
    }
    else {
        f = false;
        return;
    }
}

int main() {
    cout << "Enter Expression: ";
    cin >> str;
    l = str.length();
    i = 0;

    Exp();

    if (f && i == l) {
        cout << "Input is Valid\n";
    } else {
        cout << "Expression is Invalid\n";
    }
    return 0;
}
