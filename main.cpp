#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

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

int countUser,countGroup,countPost,countJoinGroup;

void mainMenu();
void clrscr();
void registerAccount();
void loginAccount();
void loginAdmin();
void deleteUser();
void menuUser(List_parent &L,address_parent &P);
void postStatus(List_parent &L,address_parent &P);
void Timeline(List_parent &L,address_parent &P);
void menuAdmin();
void createGroup(List_parent &L, address_parent &P);
void menuGroup(List_parent &L, address_parent &P);
void editGroup(List_parent &L,address_parent &P);
void joinGroup(List_parent &L,address_parent &P);
void exitGroup(List_parent &L,address_parent &P);
void sortByID(List_parent &L1);
void sortChild (List_relasi &L,address_parent P);
//void sortByID (List_relasi &L1);

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
    cout<<endl<<endl<<"   *******************************************************************"<<endl;
    cout<<"   *              WELCOME TO TELKOM UNIVERSITY SOCIAL MEDIA         *"<<endl;
    cout<<"   *******************************************************************"<<endl;
    cout<<"    |  1. Register an account                                       |"<<endl;
    cout<<"    |  2. Login                                                     |"<<endl;
    cout<<"    |  3. ADMIN                                                     |"<<endl;
    cout<<"   -------------------------------------------------------------------"<<endl;
    cout<<"    |  99. Exit                                                     |"<<endl;
    cout<<"   -------------------------------------------------------------------"<<endl;
    cout<<"     Select: "; cin>>pil;
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
    cout<<endl<<endl<<"   ***************************************************************"<<endl;
    cout<<"*                        REGISTER AN ACCOUNT                     *"<<endl;
    cout<<"   ***************************************************************"<<endl;
    cout<<"   NIM (ID)      : "; cin>>x.NIM;
    if (findElm(LP,x) != NULL){
        cout<<"NIM already exist."<<endl;
        getch();
        mainMenu();
    }
    else{
        cout<<"   Password      : "; cin>>x.password;
        cout<<"   Name          : "; cin>>x.account_name;
        cout<<"   Address       : "; cin>>x.address;
        cout<<"   Phone Number  : "; cin>>x.contact_no;
        for (int i=0; i<10; i++){
            x.post[i] = " ";
        }
        address_parent Q = first(LP);
        address_parent tempP = first(LP);
        address_parent P = alokasi(x);
        countUser++;
        if (first(LP) == NULL){
            insertFirst(LP,P);
        }
        else{
            while (next(Q) != first(LP)){
                /*if (next(Q) == first(LP)){
                    insertLast(LP,P);
                }*/
                if (info(next(Q)).NIM < x.NIM){
                    //cout<<"A"<<x.NIM;
                    tempP = next(tempP);
                }
                Q = next(Q);
            }
            insertAfter(LP,tempP,P);
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
    cout<<endl<<endl<<"   ***************************************************************"<<endl;
    cout<<"*                     LOGIN INTO YOUR ACCOUNT                    *"<<endl;
    cout<<"   ***************************************************************"<<endl;
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
    cout<<endl<<endl<<"   ***************************************************************"<<endl;
    cout<<"   *   H O M E     H O M E     H O M E     H O M E     H O M E   *"<<endl;
    cout<<"   ***************************************************************"<<endl;
    cout<<"    |  Welcome back, "<<info(P).account_name<<" ("<<info(P).NIM<<")!"<<endl;
    cout<<"    |  What will you do?                                            |"<<endl;
    cout<<"    |  1. Timeline                                                  |"<<endl;
    cout<<"    |  2. Post status                                               | "<<endl;
    cout<<"    |  3. Group Menu                                                |"<<endl;
    cout<<"    |  4. Friend Menu                                               |"<<endl;
    cout<<"    |  5. Edit Profile                                              |"<<endl;
    cout<<"    |  9. Logout                                                    |"<<endl;
    cout<<"   -------------------------------------------------------------------"<<endl;
    cout<<"      Select: "; cin>>pil;
    switch (pil){
    case 1:
        Timeline(LP,P);
        break;
    case 2:
        postStatus(LP,P);
        break;
    case 3:
        menuGroup(LP,P);
        break;
    case 4:
        cout<<"    Coming Soon! Please follow my GitHub:)\n    github.com/adityaalifn"<<endl;
        getch();
        menuUser(L,P);
        break;
    case 5:
        cout<<"<<----------------- EDIT YOUR PROFILE ---------------->>"<<endl;
        cout<<"   Name: "; cin>>info(P).account_name;
        cout<<"   Password: "; cin>>info(P).password;
        cout<<"   Address: "; cin>>info(P).address;
        cout<<"   Phone Number: "; cin>>info(P).contact_no;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"   Edit Profile successful!"<<endl;
        getch();
        menuUser(L,P);
        break;
    case 9:
        mainMenu();
        break;
    }
}

void Timeline(List_parent &L,address_parent &P){
    clrscr();
    cout<<"*****************************************************"<<endl;
    cout<<"*                      TIMELINE                     *"<<endl;
    cout<<"*****************************************************"<<endl;
    int i = 0;
    address_parent Q = first(LP);
    //if (first(LP) != NULL){
        /*do{
            cout<<info(tempP).account_name<<endl;
            while ((i < 10) && (info(AP).post[i] != " ")){
                cout<<info(tempP).post[i]<<endl;
                i++;
            }
            tempP = next(tempP);
        }while (tempP != first(LP));*/
    //}
    if(first(L)!=NULL) {
        do {
            if (info(Q).post[0] != " "){
                i = 0;
                cout<<endl<<"Name: "<<info(Q).account_name<<endl;
                //cout<<"Status   : "<<endl;
                //cout<<"--> "<<info(Q).post[0];
                while ((info(Q).post[i] != " ") && (i<10)){
                    cout<<"--> "<<info(Q).post[i]<<endl;
                    i++;
                }
            }
            Q = next(Q);
        } while(info(Q).NIM != info(first(LP)).NIM);
    }
    getch();
    menuUser(LP,P);
}

void postStatus(List_parent &L,address_parent &P){
    clrscr();
    infotype_parent x;
    int i=0;
    while ((i < 10) && (info(P).post[i] != " ")){
        i++;
    }
    cout<<"********************************************"<<endl;
    cout<<"*               POST  STATUS               *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"What are you thinking now?"<<endl;
    cout<<"-> "; cin>>x.post[i];
    info(P).post[i] = x.post[i];
    countPost++;
    cout<<"Success! Your mind has been posted."<<endl;
    cout<<"Your mind is '"<<info(P).post[i]<<"'."<<endl;
    getch();
    menuUser(LP,P);
}

void loginAdmin(){
    clrscr();
    string username,pass;
    cout<<"***************************************************************"<<endl;
    cout<<"*                        ADMIN NOT GOD                        *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   Username  : "; cin>>username;
    cout<<"   Password  : "; cin>>pass;
    if (username == "aditbaik"){
        if (pass == "defajahat"){
            cout<<"   Hello! Sok kamu mau ngapain"<<endl;
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
    clrscr();
    int pil;
    cout<<"***************************************************************"<<endl;
    cout<<"*                    M E N U    A D M I N                     *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   1. View User"<<endl;
    cout<<"   2. Delete User"<<endl;
    cout<<"   3. View Summary"<<endl;
    cout<<"   9. Logout"<<endl;
    cout<<"--------------------------------------------------------------*"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch(pil){
    case 1:
        printInfo(LP);
        //sortByID(LP,LC);
        getch();
        menuAdmin();
        break;
    case 2:
        deleteUser();
        break;
    case 3:
        cout<<"<< ------------- VIEW APPLICATION SUMMARY ------------ >>"<<endl;
        cout<<"    Number of User Registered    : "<<countUser<<endl;
        cout<<"    Number of Group Created      : "<<countGroup<<endl;
        cout<<"    Number of Status Posted      : "<<countPost<<endl;
        cout<<"    Number of Member Join Group  : "<<countJoinGroup<<endl;
        getch();
        menuAdmin();
        break;
    case 9:
        mainMenu();
        break;
    }
}

void deleteUser(){
    infotype_parent x;
    cout<<endl<<"--------------------- DELETE USER ----------------------*"<<endl;
    if (first(LP) == NULL){
        cout<<"   No user registered!"<<endl;
        getch();
        menuAdmin();
    }
    else{
        printInfo(LP);
        cout<<"Input User ID: "; cin>>x.NIM;
        address_parent tempP = first(LP);
        if (findElm(LP,x) == NULL){
            cout<<"User ID not exist"<<endl;
            getch();
            menuAdmin();
        }
        else{
            address_parent P = findElm(LP,x);
            if (P == first(LP)){
                deleteFirst(LP,P);
            }
            else if (next(P) == first(LP)){
                deleteLast(LP,P);
            }
            else{
                do{
                    if (next(tempP) == P){
                        deleteAfter(LP,tempP,P);
                    }
                    tempP = next(tempP);
                }while (P != first(LP));
            }
            cout<<"User ID successfully deleted!"<<endl;
            getch();
            menuAdmin();
        }
    }
}

void menuGroup(List_parent &L,address_parent &P){
    clrscr();
    int pil;
    infotype_child XC;
    //address_child C;
    cout<<"***************************************************************"<<endl;
    cout<<"*                       GROUP  MENU                           *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   1. Create Group"<<endl;
    cout<<"   2. Edit Group"<<endl;
    cout<<"   3. Join Group"<<endl;
    cout<<"   4. Exit Group"<<endl;
    cout<<"   5. View Group"<<endl;
    cout<<"   9. Back"<<endl;
    cout<<"   Select: "; cin>>pil;
    switch(pil){
    case 1:
        createGroup(LP,P);
        break;
    case 2:
        editGroup(LP,P);
        break;
    case 3:
        joinGroup(LP,P);
        break;
    case 4:
        exitGroup(L,P);
        break;
    case 5:
        //sortChild(child(P),P);
        printInfo(child(P));
        getch();
        menuGroup(L,P);
        break;
    case 9:
        menuUser(L,P);
        break;
    }
}

void createGroup(List_parent &L, address_parent &P){
    clrscr();
    infotype_child x;
    cout<<"***************************************************************"<<endl;
    cout<<"*                     REGISTER AN GROUP                       *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"   Group ID         : "; cin>>x.group_id;
    if (findElm(LC,x) != NULL){
        cout<<"    Group ID already exist."<<endl;
        getch();
        menuGroup(L,P);
    }
    else{
        cout<<"   Group Name        : "; cin>>x.group_name;
        cout<<"   Group Description : "; cin>>x.group_desc;
        cout<<info(P).NIM;
        x.group_admin = info(P).NIM;
        for (int i=0; i<10; i++){
            x.group_post[i] = " ";
        }
        countGroup++;
        address_child Q = first(LC);
        address_child tempC = first(LC);
        address_child C = alokasi(x);
        address_relasi R = alokasi(C);
        insertFirst(child(P),R);
        if (first(LC) == NULL){
            insertFirst(LC,C);
        }
        else{
            while (Q != last(LC)){
                //cout<<"A";
                if (first(LC) == last(LC)){
                    if (info(first(LC)).group_id > x.group_id){
                        insertLast(LC,C);
                    }
                    else if (info(first(LC)).group_id < x.group_id){
                        insertFirst(LC,C);
                    }
                }
                else if(info(next(Q)).group_id < x.group_id){
                    tempC = next(tempC);
                    //cout<<"A";
                }
                Q = next(Q);
            }
            insertAfter(LC,tempC,C);
        }
        cout<<"You've been created group."<<endl;
        getch();
        menuGroup(LP,P);
    }
}

void editGroup(List_parent &L,address_parent &P){
    clrscr();
    if (first(child(P)) == NULL){
        cout<<"Group doesn't exist!"<<endl;
        getch();
        menuGroup(L,P);
    }
    else{
        printInfo(child(P));
        cout<<"Input Group ID: "; cin>>XC.group_id;
        cout<<"<<------------------------ EDIT GROUP ----------------------->>"<<endl;
        address_child C = findElm(LC,XC);
        address_relasi R = findElm(child(P),C);
        if (info(P).NIM != info(info(R)).group_admin){
            cout<<"    You are not admin on this group!"<<endl;
            getch();
            menuGroup(L,P);
        }
        else{
            cout<<"    Group Name           : "; cin>>info(C).group_name;
            cout<<"    Group Description    : "; cin>>info(C).group_desc;
            cout<<"    Edit successful!"<<endl;
            getch();
            menuGroup(L,P);
        }
    }
    getch();
    menuGroup(L,P);
}

void joinGroup(List_parent &L,address_parent &P){
    address_child C;
    infotype_child x;
    address_relasi R;
    cout<<"<<------------------- AVAILABLE GROUP TO JOIN --------------------->>"<<endl;
    printInfo(LC);
    if (first(LC) == NULL){
        cout<<"    NO USER HAS CREATED A GROUP"<<endl;
        getch();
        menuUser(L,P);
    }
    cout<<"Input Group ID: "; cin>>x.group_id;
    C = findElm(LC,x);
    if (C == NULL){
        cout<<"     GROUP NOT AVAILABLE"<<endl;
        getch();
        menuGroup(L,P);
    }
    else{
        if (findElm(child(P),C) != NULL){
            cout<<"   You already joined this group"<<endl;
            getch();
            menuGroup(L,P);
        }
        else{
            cout<<"--------------------------------------------------------------------"<<endl;
            R = alokasi(C);
            insertFirst(child(P),R);
            countJoinGroup++;
            cout<<"   Successful Joined the Group!"<<endl;
            getch();
            menuGroup(L,P);
        }
    }
}

void exitGroup(List_parent &L,address_parent &P){
    infotype_child x;
    cout<<"<<------------------- LEAVE GROUP --------------------->>"<<endl;
    printInfo(child(P));
    if (first(child(P)) == NULL){
        cout<<"    YOU ARE NOT IN A GROUP!"<<endl;
        getch();
        menuGroup(L,P);
    }
    else{
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"   Select Group ID: "; cin>>x.group_id;
        address_child C = findElm(LC,x);
        address_child permC = C;
        address_relasi R = findElm(child(P),C);
        if (R == NULL){
            cout<<"    Group ID doesn't exist."<<endl;
            getch();
            menuUser(L,P);
        }
        else{
            //cout<<"A";
            address_child tempC;
            if (info(C).group_admin == info(P).NIM){
                address_parent PP = first(LP);
                address_relasi tempR;
                do{
                    address_relasi RR = findElm(child(PP),permC);
                    //cout<<"E";
                    tempR = first(child(PP));
                    if (first(child(PP)) == RR){
                        //cout<<"F";
                        deleteFirst(child(PP),RR);
                    }
                    else if (next(RR) == NULL){
                        deleteLast(child(PP),RR);
                    }
                    else{
                        while (tempR != NULL){
                            if (next(tempR) == RR){
                                deleteAfter(child(PP),tempR,RR);
                            }
                        tempR = next(tempR);
                        }
                    }
                PP = next(PP);
                }while (PP != first(LP));

                if (C == first(LC)){
                    deleteFirst(LC,C);
                    //cout<<"B";
                }
                else if (C == last(LC)){
                    deleteLast(LC,C);
                    //cout<<"C";
                }
                else{
                    while (tempC != last(LC)){
                        if (next(tempC) == C){
                            deleteAfter(LC,tempC,C);
                            //cout<<"D";
                        }
                    tempC = next(tempC);
                    }
                }
                cout<<"You're admin of this group. So, this group will be deleted"<<endl;
            }
            else{
                address_relasi tempR = first(child(P));
                if (first(child(P)) == R){
                    deleteFirst(child(P),R);
                }
                else if (next(R) == NULL){
                    deleteLast(child(P),R);
                }
                else{
                    while(tempR != NULL) {
                        if(next(tempR) == R){
                            deleteAfter(child(P),tempR,R);
                        }
                    tempR = next(tempR);
                    }
                }
            }
            cout<<"   Leave successful! Good bye my friend:("<<endl;
            getch();
            menuGroup(L,P);
        }
    }
}

/*void sortRelasi(List_relasi &L){
    address_relasi P = first(L);
    address_relasi iMin,Q;
    while (next(P) != NULL){
        iMin = P;
        if (next(P) != NULL){
            Q = next(P);
        }
        while (Q != NULL){
            if (info(Q).group_id < info(iMin).group_id){
                iMin = Q;
            }

        }
    }
}*/

/*void sortByID (List_relasi &L1,)
{
    address_parent P = first(L1);
    address_parent iMin;
    address_parent Q;
    while (next(P) != first(L1))
    {
        iMin = P;
        if (P -> next != first(L1)) {
            Q = P -> next;
        }
        while (next(Q) != first(L1))
        {
            if ((Q -> info).NIM < (iMin -> info).NIM)
            {
                iMin = Q;
            }
            Q = next(Q);
        }
        if ((iMin -> info).NIM < (P -> info).NIM)
        {
            swap(P -> info,iMin -> info);
            swap(child(P),child(iMin));
        }
        if (Q -> next != first(L1)) {
            Q = Q -> next;
        }
    }
    printInfo(LP);
}*/

/*void sortChild (List_relasi &L,address_parent P){
    address_child Q,C;
    C = first(L);
    while (C != NULL){
        Q = C;
        while ((next(Q) != NULL) && (Q != NULL) && (info(prev(Q)).group_id > info(Q).group_id)){
            swap(info(prev(Q)),info(Q));
            //swap(prev(child(Q)),child(Q));
            Q = prev(Q);
        }
        C = next(C);
    }
    C = NULL;
    Q = NULL;
    printInfo(child(P));
}
*/
