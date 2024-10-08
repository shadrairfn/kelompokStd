#ifndef KELOMPOK_H_INCLUDED
#define KELOMPOK_H_INCLUDED

#include <string>

#define first(L) L.first
#define info(P) P->info

struct Fakultas{
    std::string namaFak;
    int jumProdi;
    std::string kodeFak;
};

typedef Fakultas infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
    address SL;
};

void createList(List &L);
address allocate(infotype x);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void printInfo(List L);
void sortBykodeFak(List &L);
address isFound(List L, address P, int urutanData);
address searchBykodeFak(List L, std::string target);

std::ostream& operator<<(std::ostream &out, const Fakultas &f);

#endif // KELOMPOK_H_INCLUDED
