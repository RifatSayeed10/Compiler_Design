#include<bits/stdc++.h>
using namespace std;

vector<string> keywords = {
    "int", "float", "double", "char", "bool", "void", "if", "else", "then",
    "endif", "while", "for", "do", "switch", "case", "static", "print", "return"
};

bool isKeyword(const string &s){
    return find(keywords.begin(), keywords.end(), s) != keywords.end();
}

bool isOperator(char c){
    string ops = "+-*/%=><!";
    return ops.find(c) != string::npos;
}

bool isSpecial(char c){
    string specials = "(){},;[]";
    return specials.find(c) != string::npos;
}

bool isIdentifierStart(char c){
    return isalpha(c) || c == '_' || c == '$';
}

bool isIdentifierChar(char c){
    return isalnum(c) || c == '_' || c == '$';
}

int main(){

    string code, line;

    cout << "Enter code (type END to finish):\n";

    // multi-line input
    while(getline(cin, line)){
        if(line == "END") break;
        code += line + "\n";
    }

    // remove comments
    regex blockComment(R"(/\*[\s\S]*?\*/)");
    code = regex_replace(code, blockComment, "");

    regex singleComment(R"(//.*)");
    code = regex_replace(code, singleComment, "");

    vector<string> identifiers, constants, keywordlist;
    vector<char> operators, specials;

    int n = code.size();

    for(int i = 0; i < n; i++){
        char c = code[i];

        if(isspace(c)) continue;

        // Identifier or keyword
        if(isIdentifierStart(c)){
            string word = "";
            while(i < n && isIdentifierChar(code[i])){
                word += code[i];
                i++;
            }
            i--;

            if(isKeyword(word))
                keywordlist.push_back(word);
            else
                identifiers.push_back(word);
        }

        // Constant
        else if(isdigit(c)){
            string num = "";
            while(i < n && isdigit(code[i])){
                num += code[i];
                i++;
            }
            i--;
            constants.push_back(num);
        }

        // Operator
        else if(isOperator(c)){
            operators.push_back(c);
        }

        // Special symbol
        else if(isSpecial(c)){
            specials.push_back(c);
        }
    }

    // Output
    cout << "\n=== Lexical Analysis Result ===\n";

    cout << "Keywords: ";
    for(auto &k : keywordlist) cout << k << " ";

    cout << "\nIdentifiers: ";
    for(auto &id : identifiers) cout << id << " ";

    cout << "\nConstants: ";
    for(auto &c : constants) cout << c << " ";

    cout << "\nOperators: ";
    for(auto &op : operators) cout << op << " ";

    cout << "\nSpecial Symbols: ";
    for(auto &sp : specials) cout << sp << " ";

    cout << "\n";

    return 0;
}
