#include<bits/stdc++.h>
using namespace std;

string str;
int i=0, l;
bool f=false;
void X();
void A(){
    if(str[i] == 'a'){
        i++;
        X();
        if(f && i<l && str[i] =='d'){
            i++;
            f=true;
            return;
        }else{
            f=false;
            return;
        }
    }
}
void X(){
    if(i+1<l && str.substr(i,2) == "bb"){
        i+=2;
        f=true;
        X();
    }
    else if(i+1<l && str.substr(i,2) == "bc"){
        i+=2;
        f=true;
        X();
    }
    else{
        f=true;
        return;
    }
}
int main(){
    cout<<"Enter Input: ";
    cin>>str;
    l=str.length();

    A();
    if(f && i==l){
        cout<<"Input is valid.\n";
    } else{
        cout<<"String is Invalid.\n";
    }
    return 0;
}
