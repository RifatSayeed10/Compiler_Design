#include<bits/stdc++.h>
using namespace std;
int step = 1;

int precedence(char op){
    if(op=='+'||op=='-')
    return 1;
    if(op=='/'||op=='*')
    return 2;
 return 0;
}

string infixtopostfix(string infix){
    stack<char>st;
    string postfix="";

    for(char c:infix){
        if(isalnum(c)){
            postfix+=c;
        }else if(c=='('){
            st.push(c);
        }else if(c==')'){
            while(!st.empty()&& st.top()!='('){
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }else{
           while(!st.empty() && precedence(st.top()) >= precedence(c)){
                postfix+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}

string generateTAC(string postfix){
    stack<string>st;
    int tempcount=1;
    for(char c:postfix){
        if(isalnum(c)){
            st.push(string(1,c));
        }else{
            string op2=st.top();
            st.pop();
            string op1=st.top();
            st.pop();

            string temp="t"+to_string(tempcount++);
            cout<<step++ << ". "<<temp<< " = "<<op1<<" "<<c<<" "<<op2<<endl;
            st.push(temp);
        }

    }
    return st.top();
}
int main(){
    string input;
    cout<<"Enter expression: ";
    getline(cin,input);

    input.erase(remove(input.begin(),input.end(),' '),input.end());

    int pos=input.find('=');
    string lhs=input.substr(0,pos);
    string rhs=input.substr(pos+1);

    string postfix=infixtopostfix(rhs);
    cout<<"Postfix: "<<postfix<<endl;
    cout<<"\nThree Address code: "<<endl;

    string finaltemp=generateTAC(postfix);

    cout<<step++<< ". "<<lhs<<" = "<<finaltemp<<endl;
    return 0;
}
