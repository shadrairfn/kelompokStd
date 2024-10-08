#include <iostream>
#include "kelompok.h"

using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address allocate(infotype x) {
    address p = new elmList;
    info(p) = x;
    p->next = NULL;

    return p;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}


void insertLast(List &L, address P) {
    address Q;
    if (L.first == NULL) {
        insertFirst(L,P);
    } else {
        Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (next(Prec) == NULL) {
        insertLast(L,P);
    } else {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else {
        if (next(L.first) == NULL) {
            P = next(L.first);
            L.first->next = NULL;
        } else {
            address Q = L.first;
            while (Q->next != NULL && Q->next->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

address searchBykodeFak(List L, std::string target) {
    address P = L.first;
    while (P != NULL) {
        if (info(P).kodeFak == target) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void sortBykodeFak(List &L) {
    if (L.first == NULL || L.first->next == NULL) {
        return; // Tidak perlu sorting jika list kosong atau hanya memiliki satu elemen
    }

    address sorted = NULL; // List sementara untuk menampung elemen yang sudah terurut
    address current = L.first;

    while (current != NULL) {
        address next = current->next;
        if (sorted == NULL || info(current).kodeFak < info(sorted).kodeFak) {
            current->next = sorted;
            sorted = current;
        } else {
            address temp = sorted;
            while (temp->next != NULL && info(temp->next).kodeFak < info(current).kodeFak) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    L.first = sorted;
}


address isFound(List L, address P, int urutanData) {
    for (int i = 1; i < urutanData; i++) {
        P = L.first;
    }
    return P;
}


std::ostream& operator<<(std::ostream &out, const Fakultas &f) {
    out << "Nama Fakultas: " << f.namaFak << ", "
        << "Jumlah Prodi: " << f.jumProdi << ", "
        << "Kode Fakultas: " << f.kodeFak;
    return out;
}

void printInfo(List L) {
    address p = L.first;
    while (p != NULL) {
        std::cout << info(p) << std::endl;
        p = p->next;
    }
    cout << endl;
}


