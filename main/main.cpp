#include <iostream>
#include "kelompok.h"

using namespace std;

int main()
{
    List L;
    infotype Kampus;
    address pointer1, pointer2, pointer3, pointer4, pointer5, pointer6, P1, P2, Prec;

    createList(L);
    cout << "Masukan nama fakultas, jumlah prodi, dan kode fakultas: ";
    cin >> Kampus.namaFak >> Kampus.jumProdi >> Kampus.kodeFak;
    pointer1 = allocate(Kampus);
    insertFirst(L, pointer1);

    cout << "Masukan nama fakultas, jumlah prodi, dan kode fakultas: ";
    cin >> Kampus.namaFak >> Kampus.jumProdi >> Kampus.kodeFak;
    pointer2 = allocate(Kampus);
    insertLast(L, pointer2);

    cout << "Masukan nama fakultas, jumlah prodi, dan kode fakultas: ";
    cin >> Kampus.namaFak >> Kampus.jumProdi >> Kampus.kodeFak;
    pointer3 = allocate(Kampus);
    insertFirst(L, pointer3);

    cout << "Masukan nama fakultas, jumlah prodi, dan kode fakultas: ";
    cin >> Kampus.namaFak >> Kampus.jumProdi >> Kampus.kodeFak;
    pointer4 = allocate(Kampus);
    insertLast(L, pointer4);

    cout << "Masukan nama fakultas, jumlah prodi, dan kode fakultas: ";
    cin >> Kampus.namaFak >> Kampus.jumProdi >> Kampus.kodeFak;
    pointer5 = allocate(Kampus);
    insertAfter(L, pointer4, pointer5);

    cout << "Masukan nama fakultas, jumlah prodi, dan kode fakultas: ";
    cin >> Kampus.namaFak >> Kampus.jumProdi >> Kampus.kodeFak;
    pointer6 = allocate(Kampus);
    insertAfter(L, pointer4, pointer6);

    printInfo(L);

    std::string targetKodeFak = info(pointer1).kodeFak;
    Prec = searchBykodeFak(L, targetKodeFak);
    deleteAfter(L, Prec, P1);

    printInfo(L);

    targetKodeFak = info(pointer6).kodeFak;
    Prec = searchBykodeFak(L, targetKodeFak);
    if (Prec->next == NULL) {
        deleteLast(L, P2);
    } else if (L.first->next == NULL) {
        deleteFirst(L, P2);
    } else {
        targetKodeFak = info(pointer4).kodeFak;
        Prec = searchBykodeFak(L, targetKodeFak);
        deleteAfter(L, Prec, P2);
    }

    printInfo(L);

    sortBykodeFak(L);
    printInfo(L);
    return 0;
}
