#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

List_parent LP;
List_child LC;
List_relasi LR;
address_child AC;
address_parent AP;
address_relasi AR;
infotype_parent XP;
infotype_child XC;

void mainMenu();
void clrscr();
void registerAccount();
void loginAccount();
void loginAdmin();
void menuUser(List_parent &L,address_parent &P);
void postStatus(List_parent &L,address_parent &P);
void Timeline(List_parent &L,address_parent &P);
void menuAdmin();

int main()
{
    createList(LP);
    createList(LC);
    createList(LR);
    mainMenu();
    return 0;
}

void clrscr(){
    system("cls");
}

void mainMenu(){
    clrscr();
    int pil;
    cout<<"***************************************************************"<<endl;
    cout<<"*           WELCOME TO TELKOM UNIVERSITY SOCIAL MEDIA         *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   1. Register an account"<<endl;
    cout<<"   2. Login"<<endl;
    cout<<"   3. ADMIN"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"   99. Exit"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch (pil){
    case 1:
        registerAccount();
        break;
    case 2:
        loginAccount();
        break;
    case 3:
        loginAdmin();
        break;
    case 99:
        exit(99);
        break;
    }
    if (pil != 99){
        mainMenu();
    }
}

void registerAccount(){
    clrscr();
    infotype_parent x;
    cout<<"***************************************************************"<<endl;
    cout<<"*                     REGISTER AN ACCOUNT                     *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   NIM (ID)      : "; cin>>x.NIM;
    if (findElm(LP,x) != NULL){
        cout<<"NIM already exist."<<endl;
        getch();
        mainMenu();
    }
    else{
        cout<<"   Password      : "; cin>>x.password;
        /*cout<<"   Name          : "; cin>>x.account_name;
        cout<<"   Address       : "; cin>>x.address;
        cout<<"   Phone Number  : "; cin>>x.contact_no;*/
        for (int i=0; i<10; i++){
            x.post[i] = " ";
        }
        address_parent Q;
        address_parent P = alokasi(x);
        Q = first(LP);
        if (first(LP) == NULL){
            insertFirst(LP,P);
        }
        else{
            do{
                next(Q);
            }while ((info(Q).NIM > x.NIM) && (info(Q).NIM != info(first(LP)).NIM));
            insertAfter(LP,Q,P);
        }
        cout<<"Congratulations! You've been registered"<<endl;
        getch();
        mainMenu();
    }
}

void loginAccount(){
    clrscr();
    infotype_parent x;
    address_parent P;
    cout<<"***************************************************************"<<endl;
    cout<<"*                  LOGIN INTO YOUR ACCOUNT                    *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   NIM (ID)  : "; cin>>x.NIM;
    cout<<"   Password  : "; cin>>x.password;
    P = findElm(LP,x);
    if (P != NULL){
        if (info(P).password == x.password){
            menuUser(LP,P);
        }
        else{
            cout<<"Wrong password!"<<endl;
            getch();
            loginAccount();
        }
    }
    else{
        cout<<"Username is not registered!"<<endl;
        getch();
        mainMenu();
    }
}

void menuUser(List_parent &L,address_parent &P){
    int pil;
    //int j = 0;
    infotype_parent x;
    clrscr();
    cout<<"***************************************************************"<<endl;
    cout<<"*   H O M E     H O M E     H O M E     H O M E     H O M E   *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   Welcome back, "<<info(P).account_name<<" ("<<info(P).NIM<<")!"<<endl;
    cout<<"   What will you do?"<<endl;
    cout<<"   1. Timeline"<<endl;
    cout<<"   2. Post status"<<endl;
    cout<<"   3. Group Menu"<<endl;
    cout<<"   4. Friend Menu"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch (pil){
    case 1:
        Timeline(LP,P);
        break;
    case 2:
        postStatus(LP,P);
        break;
    }
}

void Timeline(List_parent &L,address_parent &P){
    int i;
    AP = first(LP);
    if (first(LP) != NULL){
        do{
            cout<<info(AP).account_name<<endl;
            while ((i < 10) && (info(AP).post[i] != " ")){
                cout<<info(AP).post[i]<<endl;
                i++;
            }
            next(AP);
        } while (info(AP).NIM != info(first(L)).NIM);
    }
    getch();
    menuUser(LP,P);
}

void postStatus(List_parent &L,address_parent &P){
    infotype_parent x;
    int i;
    cout<<"What are you thinking now?"<<endl;
    cout<<"-> "; cin>>x.post[0];
    while ((i < 10) && (info(P).post[i] != " ")){
        i++;
    }
    info(P).post[i] = x.post[0];
    cout<<"Success! Your mind has been posted."<<endl;
    cout<<"Your mind is '"<<info(P).post[i]<<"'."<<endl;
    getch();
    menuUser(LP,P);
}

void loginAdmin(){
    string username,pass;
    cout<<"***************************************************************"<<endl;
    cout<<"*                        ADMIN NOT GOD                        *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   Username  : "; cin>>username;
    cout<<"   Password  : "; cin>>pass;
    if (username == "aditbaik"){
        if (pass == "defajahat"){
            cout<<"Hello! Sok kamu mau ngapain"<<endl;
            getch();
            menuAdmin();
        }
    }
    else{
        cout<<"Sorry!"<<endl;
        getch();
        mainMenu();
    }
}

void menuAdmin(){
    int pil;
    cout<<"***************************************************************"<<endl;
    cout<<"*                    M E N U    A D M I N                     *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   1. View User"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch(pil){
    case 1:
        printInfo(LP);
        getch();
        menuAdmin();
        break;
    }
}
