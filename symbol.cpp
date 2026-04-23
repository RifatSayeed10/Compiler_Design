#include<bits/stdc++.h>
using namespace std;

struct symbol {
    string id,type,scope;
};


class symbolTable {
    public:
    vector<symbol>table;

    void insert (string id , string type ,string scope ) {
        table.push_back({id,type,scope});

    }


    void deleteid(string id){

        for (auto it=table.begin(); it!=table.end(); it++){
        if(it->id==id){ table.erase(it);return;}
        }
        cout<<id <<"Not found "<<endl;
    }


    void lookup(string id) {
        for (auto &s : table){
            if(s.id==id){
                cout<<s.id<<"     |         "<<s.type<< "    |    "<<s.scope<<endl;
                return;
            }
        }
         cout<<id <<"Not found "<<endl;
    }
    void display () {

cout <<"Identifier\tType\tScope" <<endl;

  for (auto &s : table){
            
                cout<<s.id<<"     |          "<<s.type<< "     |    "<<s.scope<<endl;
         
            
    }
}


};

int main () {

    symbolTable s;
    string id , type , scope;


    int ch;

    while (ch!=5) {
        cout<<"Enter your choice : "<<endl;
        cout<<"1.Insert 2.display 3.delete 4.lookup : " <<endl;
        cin>>ch;
        switch (ch)
        {  
        case 1: 
            cout<<"Enter ID , type and scope :";
            cin>>id>>type>>scope;
            s.insert(id,type,scope);
            cout<<endl;
            break;
        case 2:
            s.display();
            break;
        case 3: 
            cout<<"Enter id to delete : " ; cin>>id;
            s.deleteid(id);
            break;
        case 4:
             cout<<"Enter id to lookup : " ; cin>>id;
            s.lookup(id);
            
            break;
        
        default: cout<<"Null";
            break;
        }
        
    }


}
