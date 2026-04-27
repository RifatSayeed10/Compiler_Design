#include<bits/stdc++.h>
using namespace std;

string str;
int i=0,l;
bool f = false;

void A();
void B();
void S(){
    if(str[i] =='b'){
        i++;
        f=true;
        return;
    } else{
        A();
        if(f){
            B();
            return;
        }
    }
}

void A(){
    if(str[i] == 'a'){
        i++;
        f=true;
    }else{
        f=false;
        return;
    }
    if(i<l-1){
        A();
    }
}
void B(){
    if(str[i] == 'b'){
        i++;
        f=true;
        return;
    }else{
        f=false;
        return;
    }
}
int main(){
    cout<<"Enter Input: ";
    cin>>str;
    l=str.length();
    S();
    if(f && i==l){
        cout<<"Input is Valid\n";
    }
    else{
        cout<<"string is invalid.\n";
    }
    return 0;
}
