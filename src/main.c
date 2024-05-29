#include "BTreeKamus.h"

#include <stdio.h>

int main()
{
    /* Deklarasi variabel */
    Address RootKamus = NULL;
    bool Exit = false;
    
    /* Program utama */
    // Memuat data
    // remove("Kamus-Sunda-Indonesia.dat");
    CheckAndLoadFile(&RootKamus);

    // Melakukan balancing tree setelah memuat data
     BalancingTree(&RootKamus);

    /* Run */
    while(!Exit) Execute(Menu(), &RootKamus, &Exit);
    
    return 0;
}