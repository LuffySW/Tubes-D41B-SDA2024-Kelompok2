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

    Koor(2,2);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    Koor(3,2);  printf("%c                                            %c\n", 186, 186);
    Koor(4,2);  printf("%c                   Menu:                    %c\n", 186, 186);
    Koor(5,2);  printf("%c 1. Tampilkan isi kamus Jawa - Indonesia    %c\n", 186, 186);
    Koor(6,2);  printf("%c 2. Tambah kosakata kamus                   %c\n", 186, 186);
    Koor(7,2);  printf("%c 3. Mencari kosakata bahasa Jawa            %c\n", 186, 186);
    Koor(8,2);  printf("%c 4. Edit kosakata                           %c\n", 186, 186);
    Koor(9,2);  printf("%c 5. Hapus kosakata                          %c\n", 186, 186);
    Koor(10,2); printf("%c 6. Tampilkan Ilustrasi Binary Search Tree  %c\n", 186, 186);
    Koor(11,2); printf("%c 7. Perbaiki performa program (Balancing)   %c\n", 186, 186);
    Koor(12,2); printf("%c 0. Keluar                                  %c\n", 186, 186);
    Koor(13,2); printf("%c                                            %c\n", 186, 186);
    Koor(14,2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    Koor(15,2);  printf("Masukan pilihan anda: ");
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
Koor(0, 4); printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c %c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c  %c%c%c   %c%c%c%c%c%c%c %c%c%c%c%c%c%c          %c%c%c%c%c%c%c %c%c%c  %c%c%c\n", 219,219,187,  219,219,187,219,219,219,219,219,219,219,187,219,219,187,      219,219,219,219,219,219,187, 219,219,219,187,   219,219,219,187,219,219,219,219,219,219,187,  219,219,219,219,219,219,187, 219,219,187,  219,219,187,     219,219,219,219,219,219,187, 219,219,219,219,219,219,187,         219,219,219,219,219,219,187, 219,219,187,  219,219,187);
Koor(1, 4); printf("%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c%c%c          %c%c%c%c%c%c%c%c%c%c%c  %c%c%c\n", 219,219,186, 219,219,201,188,219,219,201,205,205,205,205,188,219,219,186,     219,219,201,205,205,205,219,219,187,219,219,219,219,187, 219,219,219,219,186,219,219,201,205,205,219,219,187, 219,219,201,205,205,205,219,219,187,219,219,186, 219,219,201,188,   219,219,201,205,205,219,219,187, 200,205,205,219,219,186,         219,219,201,205,205,219,219,187,219,219,186,  219,219,186);
Koor(2, 4); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c  %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c%c  %c%c%c  %c%c%c%c%c%c%c%c%c%c%c\n", 219,219,219,219,219,201,188, 219,219,219,219,219,187,  219,219,186,     219,219,186,   219,219,186,219,219,201,219,219,219,219,201,219,219,186,219,219,219,219,219,219,201,188,219,219,186,   219,219,186,219,219,219,219,219,201,188,    219,219,219,219,219,219,205,188,  219,219,201,205,188,  219,219,219,219,219,187,  219,219,186,  219,219,186,219,219,219,219,219,219,219,186);
Koor(3, 4); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c  %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c   %c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c  %c%c%c  %c%c%c%c%c%c%c%c%c%c%c\n", 219,219,201,205,219,219,187, 219,219,201,205,205,188,  219,219,186,     219,219,186,   219,219,186,219,219,186,200,219,219,201,188,219,219,186,219,219,201,205,205,205,188, 219,219,186,   219,219,186,219,219,201,205,219,219,187,     219,219,201,205,205,219,219,187,219,219,201,205,188,  200,205,205,205,205,188,  219,219,186,  219,219,186,200,205,205,205,205,219,219,186);
Koor(4, 4); printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c %c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c%c     %c%c%c\n", 219,219,186,  219,219,187,219,219,219,219,219,219,219,187,219,219,219,219,219,219,219,187,200,219,219,219,219,219,219,201,188, 219,219,186, 200,205,188,219,219,186,     219,219,186,200,219,219,219,219,219,219,201,188,219,219,186, 219,219,187,     219,219,219,219,219,219,201,188,219,219,219,219,219,219,187,              219,219,219,219,219,219,201,188,     219,219,186);
Koor(5, 4); printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c     %c%c%c%c%c%c      %c%c%c%c%c%c%c %c%c%c  %c%c%c   %c%c%c%c%c%c%c %c%c%c%c%c%c%c          %c%c%c%c%c%c%c      %c%c%c\n", 200,205,188,  200,205,188,200,205,205,205,205,205,205,188,200,205,205,205,205,205,205,188, 200,205,205,205,205,205,188, 200,205,188,     200,205,188,200,205,188,      200,205,205,205,205,205,188, 200,205,188,  200,205,188,   200,205,205,205,205,205,188, 200,205,205,205,205,205,188,          200,205,205,205,205,205,188,      200,205,188);
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
Koor(17,37);  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
Koor(18,25);  printf("      https://github.com/LuffySW/Tubes-D41B-SDA2024-Kelompok2.git\n");
}