#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L,address_child P){
    if (first(L) == NULL){
        last(L) = P;
        first(L) = P;
    }
    else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(List_child &L,address_child Prec,address_child P){
    if (first(L) == NULL){
        insertFirst(L,P);
    }
    else if (Prec == last(L)){
        insertLast(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void deleteFirst(List_child &L,address_child &P){
    if (first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    }
    else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteLast(List_child &L,address_child &P){
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = NULL;
}

void deleteAfter(List_child &L,address_child Prec,address_child &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"    Group ID     : "<<info(P).group_id<<endl;
        cout<<"    Group Name   : "<<info(P).group_name<<endl<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).group_id==x.group_id) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
