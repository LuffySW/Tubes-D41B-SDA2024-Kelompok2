#include "BTreeKamus.h"

void Koor(int Baris, int Kolom)
{
    HANDLE h;
    COORD c;
    c.Y = Baris;
    c.X = Kolom;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, c);
}

/* ============================================== */
void SetColor(int kode1, int kode2)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, kode1 | kode2);
}

void DefaultColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BG_BLACK | FG_WHITE);
}

void ErrorMsg(String ErrorMessage)
{
    SetColor(BG_RED, FG_BLACK);
    printf("%s", ErrorMessage);
    DefaultColor();
}

void SuccMsg(String SuccesMessage)
{
    SetColor(BG_GREEN, FG_BLACK);
    printf("%s", SuccesMessage);
    DefaultColor();
}

int Menu()
{

    int Choice;
    char ChoiceString[MAX_BUFFER];
    system("cls");

    Koor(2,37);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,187);
    Koor(3,37);  printf("%c                                                  %c\n", 003, 003);
    Koor(4,37);  printf("%c                      Menu:                       %c\n", 003, 003);
    Koor(5,37);  printf("%c    1. Tampilkan Isi Kamus Jawa - Indonesia       %c\n", 003, 003);
    Koor(6,37);  printf("%c    2. Tambah Kosakata Kamus                      %c\n", 003, 003);
    Koor(7,37);  printf("%c    3. Mencari Kosakata Bahasa Jawa               %c\n", 003, 003);
    Koor(8,37);  printf("%c    4. Edit Kosakata                              %c\n", 003, 003);
    Koor(9,37);  printf("%c    5. Hapus Kosakata                             %c\n", 003, 003);
    Koor(10,37); printf("%c    6. Tampilkan Ilustrasi Binary Search Tree     %c\n", 003, 003);
    Koor(11,37); printf("%c    7. Perbaiki Performa Program (Balancing)      %c\n", 003, 003);
    Koor(12,37); printf("%c    0. Keluar                                     %c\n", 003, 003);
    Koor(13,37); printf("%c                                                  %c\n", 003, 003);
    Koor(14,37); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,188);

    Koor(15,37);  printf("Masukan pilihan anda: ");
    scanf(" %[^\n]", ChoiceString);

    if (sscanf(ChoiceString, "%d", &Choice))
    {
        if (Choice >= 0 && Choice <= 7)
            return Choice;
    }

    ErrorMsg("Pilihan anda tidak ada...");
    sleep(1.5);
    return Choice = Menu();
    fflush(stdin);
}

void Pause()
{
    SetColor(BG_GREEN, FG_BLACK);
    printf("\nTekan tombol apapun untuk melanjutkan...\n");
    getch();
    DefaultColor();
    fflush(stdin);
}

bool Validasi()
{
    char Choice = ' ';
    printf("Tekan tombol ");
    SetColor(NONE, FG_GREEN);
    printf("[Y]");
    DefaultColor();
    printf(" jika iya...\n");

    printf("Tekan tombol ");
    SetColor(NONE, FG_RED);
    printf("[N]");
    DefaultColor();
    printf(" jika tidak...\n");

    while ((Choice != 'Y') && (Choice != 'N'))
    {
        Choice = toupper(getch());
    }
    fflush(stdin);
    return (Choice == 'Y');
}

void ExitApps()
{
    SetColor(BG_BLUE, FG_WHITE);
    remove("temp.txt");
    remove("TempFile.dat");
    printf("Terima kasih telah menggunakan aplikasi kami (^_^) \n");
    printf("Keluar aplikasi...");
    SetColor(FG_WHITE, BG_RED);
    sleep(1);
}

void Banner()
{
/*

ASCII code 219 = █

ASCII code 220 = ▄

ASCII code 223 = ▀

ASCII code 200 = ╚

ASCII code 201 = ╔

ASCII code 202 = ╩

ASCII code 203 = ╦

ASCII code 204 = ╠

ASCII code 205 = ═

ASCII code 206 = ╬

ASCII code 185 = ╣

ASCII code 186 = ║

ASCII code 187 = ╗

ASCII code 188 = ╝


██╗  ██╗ ███████╗ ██╗       ██████╗  ███╗   ███╗ ██████╗   ██████╗  ██╗  ██╗    ██████╗  ██████╗              ██████╗  ██╗  ██╗   
██║ ██╔╝ ██╔════╝ ██║      ██╔═══██╗ ████╗ ████║ ██╔══██╗ ██╔═══██╗ ██║ ██╔╝    ██╔══██╗  ╚══██║              ██╔══██╗ ██║  ██║   
█████╔╝  █████╗   ██║      ██║   ██║ ██╔████╔██║ ██████╔╝ ██║   ██║ █████╔╝     ██████═╝   ██╔═╝    █████╗    ██║  ██║ ███████║   
██╔═██╗  ██╔══╝   ██║      ██║   ██║ ██║╚██╔╝██║ ██╔═══╝  ██║   ██║ ██╔═██╗     ██╔══██╗ ██╔═╝      ╚════╝    ██║  ██║ ╚════██║   
██║  ██╗ ███████╗ ███████╗ ╚██████╔╝ ██║ ╚═╝ ██║ ██║      ╚██████╔╝ ██║  ██╗    ██████╔╝ ██████╗              ██████╔╝      ██║     
╚═╝  ╚═╝ ╚══════╝ ╚══════╝  ╚═════╝  ╚═╝     ╚═╝ ╚═╝       ╚═════╝  ╚═╝  ╚═╝    ╚═════╝  ╚═════╝              ╚═════╝       ╚═╝  
                                                                                                                   

*/
SetColor(NONE, FG_CYAN);
Koor(1, 4); printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c %c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c  %c%c%c   %c%c%c%c%c%c%c %c%c%c%c%c%c%c          %c%c%c%c%c%c%c %c%c%c  %c%c%c\n", 219,219,187,  219,219,187,219,219,219,219,219,219,219,187,219,219,187,      219,219,219,219,219,219,187, 219,219,219,187,   219,219,219,187,219,219,219,219,219,219,187,  219,219,219,219,219,219,187, 219,219,187,  219,219,187,     219,219,219,219,219,219,187, 219,219,219,219,219,219,187,         219,219,219,219,219,219,187, 219,219,187,  219,219,187);
Koor(2, 4); printf("%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c%c%c          %c%c%c%c%c%c%c%c%c%c%c  %c%c%c\n", 219,219,186, 219,219,201,188,219,219,201,205,205,205,205,188,219,219,186,     219,219,201,205,205,205,219,219,187,219,219,219,219,187, 219,219,219,219,186,219,219,201,205,205,219,219,187, 219,219,201,205,205,205,219,219,187,219,219,186, 219,219,201,188,   219,219,201,205,205,219,219,187, 200,205,205,219,219,186,         219,219,201,205,205,219,219,187,219,219,186,  219,219,186);
Koor(3, 4); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c  %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c%c  %c%c%c  %c%c%c%c%c%c%c%c%c%c%c\n", 219,219,219,219,219,201,188, 219,219,219,219,219,187,  219,219,186,     219,219,186,   219,219,186,219,219,201,219,219,219,219,201,219,219,186,219,219,219,219,219,219,201,188,219,219,186,   219,219,186,219,219,219,219,219,201,188,    219,219,219,219,219,219,205,188,  219,219,201,205,188,  219,219,219,219,219,187,  219,219,186,  219,219,186,219,219,219,219,219,219,219,186);
Koor(4, 4); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c  %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c   %c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c  %c%c%c  %c%c%c%c%c%c%c%c%c%c%c\n", 219,219,201,205,219,219,187, 219,219,201,205,205,188,  219,219,186,     219,219,186,   219,219,186,219,219,186,200,219,219,201,188,219,219,186,219,219,201,205,205,205,188, 219,219,186,   219,219,186,219,219,201,205,219,219,187,     219,219,201,205,205,219,219,187,219,219,201,205,188,  200,205,205,205,205,188,  219,219,186,  219,219,186,200,205,205,205,205,219,219,186);
Koor(5, 4); printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c %c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c     %c%c%c\n", 219,219,186,  219,219,187,219,219,219,219,219,219,219,187,219,219,219,219,219,219,219,187,200,219,219,219,219,219,219,201,188, 219,219,186, 200,205,188,219,219,186,     219,219,186,200,219,219,219,219,219,219,201,188,219,219,186, 219,219,187,     219,219,219,219,219,219,201,188,219,219,219,219,219,219,187,              219,219,219,219,219,219,201,188,     219,219,186);
Koor(6, 4); printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c     %c%c%c%c%c%c      %c%c%c%c%c%c%c %c%c%c  %c%c%c   %c%c%c%c%c%c%c %c%c%c%c%c%c%c          %c%c%c%c%c%c%c      %c%c%c\n", 200,205,188,  200,205,188,200,205,205,205,205,205,205,188,200,205,205,205,205,205,205,188, 200,205,205,205,205,205,188, 200,205,188,     200,205,188,200,205,188,      200,205,205,205,205,205,188, 200,205,188,  200,205,188,   200,205,205,205,205,205,188, 200,205,205,205,205,205,188,          200,205,205,205,205,205,188,      200,205,188);
DefaultColor();

Koor(7,40); printf("Selamat Datang Di Aplikasi Kamus Bahasa\n");
Koor(8,50); printf("Jawa - Indonesia\n\n\n");

Koor(10,37);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
Koor(11,37);  printf("%c                                            %c\n", 186, 186);
Koor(12,37);  printf("%c                   Credit:                  %c\n", 186, 186);
Koor(13,37);  printf("%c 1. Astria Rizka Latifahsary    (231524037) %c\n", 186, 186);
Koor(14,37);  printf("%c 2. Luthfi Satrio Wicaksono     (231524049) %c\n", 186, 186);
Koor(15,37);  printf("%c 3. Tirta Rifky Fauzan          (231524063) %c\n", 186, 186);
Koor(16,37);  printf("%c                                            %c\n", 186, 186);
Koor(17,37);  printf("%c           Developer Sebelumnya :           %c\n", 186, 186);
Koor(18,37);  printf("%c 1. Roy Aziz Barera             (221524030) %c\n", 186, 186);
Koor(19,37);  printf("%c 2. Naila Saniyyah Nur'Aini     (221524024) %c\n", 186, 186);
Koor(20,37);  printf("%c 3. Retryanzani Dwi Fauzan      (221524028) %c\n", 186, 186);
Koor(21,37);  printf("%c                                            %c\n", 186, 186);
Koor(22,37);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
Koor(23,25);  printf("      https://github.com/LuffySW/Tubes-D41B-SDA2024-Kelompok2.git\n");
}

void Tingkatan()
{

Koor(10,12);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
Koor(11,12);  printf("%c                   Selamat Datang di Aplikasi Kamus Bahasa                   %c\n", 186,       186);
Koor(12,12);  printf("%c                               Indonesia - Jawa                              %c\n", 186,       186);
Koor(13,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(14,12);  printf("%c        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c       %c\n", 186,              220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,       186);
Koor(15,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(16,12);  printf("%c                         Bahasa Jawa dan Tingkatannya                        %c\n", 186,       186);
Koor(17,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(18,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(19,12);  printf("%c        Bahasa Jawa Ngoko : Bahasa ini lebih santai dan tidak formal.        %c\n", 186,       186);
Koor(20,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(21,12);  printf("%c        Bahasa Jawa Krama Madya: Bahasa ini digunakan dalam situasi          %c\n", 186,       186);
Koor(22,12);  printf("%c        yang setengah formal, di mana kesopanan tetap dijaga                 %c\n", 186,       186);
Koor(23,12);  printf("%c        tetapi tidak seformal Bahasa Krama.                                  %c\n", 186,       186);
Koor(24,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(25,12);  printf("%c        Bahasa Jawa Krama Inggil : Bahasa ini sangat formal dan sopan.       %c\n", 186,       186);
Koor(26,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(27,12);  printf("%c        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c       %c\n", 186,              223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,       186);
Koor(28,12);  printf("%c                                                                             %c\n", 186,       186);
Koor(29,12);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}


