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

void insertFirst(List_parent &L, address_parent P)
{
    address_parent Q;
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    if (first(L) == NULL){
        insertFirst(L,P);
    }
    else if (next(Prec) == first(L)){
        insertLast(L,P);
    }
    else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertLast(List_parent &L, address_parent P)
{
    address_parent Q;
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void deleteFirst(List_parent &L, address_parent &P)
{
    address_parent Q;
    if (first(L) != NULL)
    {
        P = first(L);
        if(next(P) == NULL)
        {
            first(L) = NULL;
        }
        else
        {
            Q = first(L);
            while (next(Q) != first(L))
            {
                Q=next(Q);
            }
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
            next(Q) = first(L);
            //dealokasi(P);
        }
    }
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
{
    if (next(Prec) == first(L))
    {
        P = first(L);
        first(L) = next(P);
        next(Prec) = first(L);
        next(P) = NULL;
    } else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(List_parent &L, address_parent &P)
{
    address_parent Q;

    if (first(L) != NULL)
    {
        P = first(L);
        if (next(P) == NULL)
        {
            first(L) = NULL;
        } else
        {
            Q = first(L);
            while (next(next(Q)) != first(L))
            {
                Q =next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
            next(P) = NULL;
            //dealokasi(P);
        }
    }
}

void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<"NIM (ID)       : "<<info(P).NIM<<endl;
            cout<<"Name           : "<<info(P).account_name<<endl;
            cout<<"Address        : "<<info(P).address<<endl;
            cout<<"Phone Number   : "<<info(P).contact_no<<endl;
            //cout<<"<------ JOINED GROUP ------>"<<endl;
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
