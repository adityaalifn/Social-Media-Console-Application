#include "list_parent.h"

void createList(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertAfter(List_parent &L,address_parent Prec,address_parent P){
    if (first(L) == NULL){
        insertFirst(L,P);
    }
    else if (info(first(L)).NIM == info(Prec).NIM){
        insertLast(L,P);
    }
    else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(List_parent &L,address_parent P){
    address_parent Q = first(L);
    if (first(L) == NULL){
        insertFirst(L,P);
    }
    else{
        do{
            next(Q);
        }while (info(Q).NIM != info(first(L)).NIM);
        next(P) = first(L);
        next(Q) = P;
    }
}

void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P).NIM<<endl;
            printInfo(child(P));
            P = next(P);
        } while(info(P).NIM != info(first(L)).NIM);
    }
}

address_parent findElm(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    if ( first(L) == NULL){
        return NULL;
    }
    else{
        do {
            if(info(P).NIM == x.NIM) {
                return P;
            }
            P = next(P);
        } while(P != first(L));
    }
    return NULL;
}
