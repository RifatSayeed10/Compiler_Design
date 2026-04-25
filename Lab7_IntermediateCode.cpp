#include <iostream>
#include <stack>
using namespace std;

int prec(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    string expr, post = "";
    cin >> expr;

    char lhs = expr[0];
    string rhs = expr.substr(2);

    stack<char> op;

    // infix → postfix
    for (char c : rhs)
    {
        if (isalnum(c))
            post += c;
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(')
            {
                post += op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while (!op.empty() && prec(op.top()) >= prec(c))
            {
                post += op.top();
                op.pop();
            }
            op.push(c);
        }
    }
    while (!op.empty())
    {
        post += op.top();
        op.pop();
    }

    // postfix → TAC
    stack<string> st;
    int t = 1;

    for (char c : post)
    {
        if (isalnum(c))
            st.push(string(1, c));
        else
        {
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();
            string temp = "t" + to_string(t++);
            cout << temp << " = " << a << " " << c << " " << b << endl;
            st.push(temp);
        }
    }

    cout << lhs << " = " << st.top();
}
