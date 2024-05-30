#include "BTreeKamus.h"


const char FileKamus[26] = "Kamus-Jawa-Indonesia.dat";

int CountNode(Address Tree)
{
    if(Tree == NULL)
        return 0;
    else
        return 1 + CountNode(Tree->Left) + CountNode(Tree->Right);
}

void PrintStatusProgram(Address Tree)
{
    int Height = height(Tree);
    int MaxHeight = ceil(log2(CountNode(Tree)))+1;
    if (Height == 0) MaxHeight = 0;
    printf("Jumlah tree saat ini : %d\n", CountNode(Tree));
    printf("Ketinggian maksimum tree saat ini harus : %d\n", MaxHeight);
    printf("Ketinggian tree saat ini : %d\n", Height);
    printf("Status : ");
    if(Height <= MaxHeight)
    {
        SuccMsg("Baik\n");
    }
    else
    {
        ErrorMsg("Buruk\n");
    }
}

void Execute(int Choice, Address *Tree, bool *Exit)
{
    switch (Choice)
    {
    case 1:
        // Menampilkan isi kamus Jawa secara traversal InOrder
        system("cls");
        HeaderKamus();
        ((*Tree) == NULL) ? ErrorMsg("Kamus tidak terdeteksi...\n") : PrintTree((*Tree));
        Pause();
        break;
    case 2:
        // Tambahkan kosakata baru kedalam kamus
        system("cls");
        InsertKata(&(*Tree));
        break;

    case 3:
        // Mencari string
        system("cls");
        if (isAVL((*Tree)))
        {
            PrintStatusProgram((*Tree));
        }
        else
        {
            PrintStatusProgram((*Tree));
            ErrorMsg("Perbaiki kecepatan?\n");
            if (Validasi())
            {
                BalancingTree(&(*Tree));
            }
            if(isAVL((*Tree)))
            PrintStatusProgram((*Tree));
        }
        SearchKata((*Tree));
        break;
    case 4:
        system("cls");
        EditTree(*Tree);
        break;

    case 5:
        // Menghapus kosakata
        system("cls");
        char InputUser[MAX_BUFFER];
        printf("Masukan kosakata yang akan dihapus dalam bahasa Jawa : ");
        scanf(" %[^\n]", InputUser);
        InputUser[0] = toupper(InputUser[0]);
        DeleteFromTree(&(*Tree), InputUser);
        SaveTreeToFile((*Tree), "Kamus-Jawa-Indonesia.dat");  
        Pause();
        break;
    case 6: 
        printTreeWithRoot(*Tree);
        Pause();
        break;
    case 7:
        PrintStatusProgram((*Tree));
        printf("Proses balancing...\n");
        BalancingTree(&(*Tree));
        PrintStatusProgram((*Tree));
        Pause();
        break;
    case 0:
        // Tambahkan kosakata baru kedalam kamus
        printf("Apakah anda yakin untuk keluar?\n");
        if (Validasi())
        {
            *Exit = true;
            /* End program */
            SaveTreeToFile((*Tree), "Kamus-Jawa-Indonesia.dat");
            ExitApps();
        }
        break;

    default:
        ErrorMsg("Fitur belum ada\n");
        break;
    }
}

void InsertKata(Address *Tree)
{
    // Input Kosa Kata Baru
    Kamus NewKamus;
    AddressNodeNR KamusJawa = NULL;
    bool ValidToContinou = true;
    int tingkatan;

    system("cls");
    printf("Saat ini anda akan menambahkan kosakata bahasa Jawa\n");
    InputKamus(&NewKamus.Jawa);

    // Lakukan pengecekan pada setiap kosakata yang ada di dalam kamus Jawa
    StringToList(&KamusJawa, NewKamus.Jawa);
    while (KamusJawa != NULL)
    {
        Address TempJawa = SearchTree((*Tree), KamusJawa->Info);
        if (TempJawa != NULL) // Ada yang sama
        {
            // Tidak bisa dilanjutkan karena sudah ada
            // Kalo mau edit aja kosakata yang lalu
            ErrorMsg("\nPeringatan!\n");
            printf("Kosakata ");
            ErrorMsg(KamusJawa->Info);
            printf(" sudah ada di dalam program, silahkan lakukan pengeditan menggunakan fitur edit kata jika ingin menambahkan sesuatu pada kosakata tersebut\n");
            Pause();
            free(NewKamus.Jawa);
            ValidToContinou = false;
            break;
        }
        KamusJawa = KamusJawa->Next;
    }

    if (ValidToContinou)
    {

        system("cls");
        printf("Saat ini anda akan menambahkan kosakata bahasa Indonesia\n");
        InputKamus(&NewKamus.Indonesia);

        system("cls");
        printf("Ingin menambahkan contohnya?\n");
        if (Validasi())
        {
            system("cls");
            printf("Saat ini anda akan menambahkan contoh penggunaan bahasa Jawa nya\n");
            InputKamus(&NewKamus.Contoh);
        }
        else
            NewKamus.Contoh = NULL;

        system("cls");
        printf("Ingin menambahkan tingkatan kata?\n");
        if (Validasi())
        {
            printf("1. Ngoko\n");
            printf("2. Inggil\n");
            printf("3. Madya\n");
            printf("Masukkan tingkatan kata: ");
            scanf(" %d", &tingkatan);
            switch (tingkatan)
            {
            case 1:
                NewKamus.Tingkatan = "Ngoko";
                break;
            case 2:
                NewKamus.Tingkatan = "Inggil";
                break;
            case 3:
                NewKamus.Tingkatan = "Madya";
                break;
            default:
                printf("Input tidak valid.");
                NewKamus.Tingkatan = " ";
                break;
            }
        }
        else
            NewKamus.Tingkatan = 0;

        // Insert To File
        InsertToFile(MergeKamus(NewKamus), "Kamus-Jawa-Indonesia.dat");
        InsertToTree(&(*Tree), NewKamus);
    }
    Pause();
}

void InputKamus(String *NewVocab)
{
    *NewVocab = AlokString(1);
    (*NewVocab)[0] = 0;
    while (true)
    {
        Input(&(*NewVocab));
        system("cls");
        printf("%s\n", *NewVocab);
        if ((*NewVocab) != NULL)
        {
            printf("\nTambahkan sinonim kata bahasa Jawanya?\n");
            if (!Validasi())
                break;
        }
    }
}

//InputKamus2
//-----------
void Input(String *NewVocab)
{
    char Buffer[MAX_BUFFER];
    unsigned int LenOfVocab = 0;

    printf("Masukan kata: ");

    /* Mulai melakukan penginputan kata */
    /* Mengambil input dari user */
    scanf(" %[^\n]", Buffer);

    LenOfVocab = strlen(Buffer);

    if (LenOfVocab != 0)
    {
        String Temp;
        Buffer[0] = toupper(Buffer[0]);
        /* Mengalokasikan memori yang cukup untuk menyimpan kosakata */
        (Temp) = AlokString(LenOfVocab + 2); // 2 untuk . dan \n

        /* Mengkopi input ke dalam memori yang baru dialokasikan */
        strcpy(Temp, Buffer);
        strcat(Temp, ".");
        (Temp)[LenOfVocab + 1] = 0;
        for (size_t i = 1; i < LenOfVocab; i++)
        {
            Buffer[i] = tolower(Buffer[i]);
        }
        unsigned int LenOfNewVocab = strlen(*NewVocab);
        LenOfVocab = strlen(Temp);
        (*NewVocab) = (String)realloc((*NewVocab), (LenOfNewVocab + LenOfVocab + 1) * sizeof(char));
        strcat((*NewVocab), Temp);
        (*NewVocab)[LenOfVocab + LenOfNewVocab] = 0;
    }
    fflush(stdin);
}

void InsertToFile(String NewVocab, String NamaFile)
{
    FILE *fp;

    fp = fopen(NamaFile, "a+");

    if (fp == NULL)
    {
        ErrorMsg("Gagal membuka file ");
        ErrorMsg(NamaFile);
        ErrorMsg("\n");
        fclose(fp);
    }
    else
    {
        /* Abi,Urang. '=' Saya,Gueh. (Abi jajan ka Bandung, Urang gelut jeung maneh.) */
        /* Abi,Urang.=Saya,Gueh.(Abi jajan ka Bandung,Urang gelut jeung maneh.) */
        fprintf(fp, "%s", NewVocab);
        fclose(fp);
        if (strcmp(NamaFile, FileKamus) == 0)
            SuccMsg("Berhasil menuliskan kosakata baru ke dalam file Kamus-Jawa-Indonesia.dat\n");
    }
}

String MergeKamus(Kamus NewKamus)
{
bool HaveContoh = false;
    bool HaveTingkatan = false;
    String Result;
    if (NewKamus.Contoh != NULL)
        HaveContoh = true;
    if (NewKamus.Tingkatan != NULL)
        HaveTingkatan = true;

    if (HaveContoh && HaveTingkatan)
    {
        Result = AlokString(strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + strlen(NewKamus.Contoh) + strlen(NewKamus.Tingkatan) + 6);
        Result[strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + strlen(NewKamus.Contoh) + strlen(NewKamus.Tingkatan) + 5] = 0;
        ConvFromCharToChar(&NewKamus.Contoh, '.', ',');
        ConvFromCharToChar(&NewKamus.Tingkatan, '.', ',');
    }
    else if (HaveContoh)
    {
        Result = AlokString(strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + strlen(NewKamus.Contoh) + 5);
        Result[strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + strlen(NewKamus.Contoh) + 4] = 0;
        ConvFromCharToChar(&NewKamus.Contoh, '.', ',');
    }
    else if (HaveTingkatan)
    {
        Result = AlokString(strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + strlen(NewKamus.Tingkatan) + 4);
        Result[strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + strlen(NewKamus.Tingkatan) + 3] = 0;
        ConvFromCharToChar(&NewKamus.Tingkatan, '.', ',');
    }
    else
    {
        Result = AlokString(strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + 3);
        Result[strlen(NewKamus.Jawa) + strlen(NewKamus.Indonesia) + 2] = 0;
    }

    ConvFromCharToChar(&NewKamus.Jawa, '.', ',');
    ConvFromCharToChar(&NewKamus.Indonesia, '.', ',');

    /* 18 + 4 '=' "()" 0 "*/
    strcpy(Result, NewKamus.Jawa);
    strcat(Result, "=");
    strcat(Result, NewKamus.Indonesia);

    if (HaveContoh)
    {
        strcat(Result, "(");
        strcat(Result, NewKamus.Contoh);
        strcat(Result, ")");
    }

    if(HaveTingkatan)
    {
        strcat(Result, "*");
        strcat(Result, NewKamus.Tingkatan);
        strcat(Result, "*");
    }


    strcat(Result, "\n");
    return Result;
}

void ConvFromCharToChar(String *Vocab, char CharFrom, char CharThis)
{
    unsigned int LenOfVocab = strlen((*Vocab));
    for (unsigned int i = 0; i < LenOfVocab; i++)
    {
        if ((*Vocab)[i] == CharFrom && i != LenOfVocab - 1)
            (*Vocab)[i] = CharThis;
    }
}

void InsertToTree(Address *Tree, Kamus NewKamus)
{
    // Pisahkan kosakata bahasa Jawa ke dalam Linked List
    AddressNodeNR ListVocabJawa = NULL;
    StringToList(&ListVocabJawa, NewKamus.Jawa);
    while (ListVocabJawa != NULL)
    {
        InsertBinaryTree(&(*Tree), NewKamus, ListVocabJawa->Info, 1);
        ListVocabJawa = ListVocabJawa->Next;
    }
}

Address AlokTree()
{
    return (Address)malloc(sizeof(Binary));
}

Address CreateKamus(Kamus NewKamus, String VocabJawa, int Height)
{
    Address NewTree = AlokTree();
    if (NewTree != NULL)
    {
        NewTree->Height = Height;
        NewTree->Left = NULL;
        NewTree->Right = NULL;
        NewTree->Kamus.Jawa = VocabJawa;
        NewTree->Kamus.Indonesia = NewKamus.Indonesia;
        NewTree->Kamus.Contoh = NewKamus.Contoh;
        NewTree->Kamus.Tingkatan = NewKamus.Tingkatan;
    }
    else
    {
        ErrorMsg("Gagal memuat kosakata ke dalam aplikasi\n");
        Pause();
    }
    return NewTree;
}

void InsertBinaryTree(Address *Tree, Kamus NewKamus, String VocabJawa, int Height)
{
    if ((*Tree) == NULL)
        (*Tree) = CreateKamus(NewKamus, VocabJawa, Height);
    else if (strcmp(VocabJawa, (*Tree)->Kamus.Jawa) < 0) // Jika Kamus Jawa yang baru lebih kecil dari kamus yang lama
        InsertBinaryTree(&(*Tree)->Left, NewKamus, VocabJawa, Height + 1);
    else
        InsertBinaryTree(&(*Tree)->Right, NewKamus, VocabJawa, Height + 1);
}

void PrintTree(Address Root)
{
    if (Root != NULL)
    {
        PrintTree(Root->Left);
        PrintKamus(Root->Kamus);
        PrintTree(Root->Right);
    }
}

void PrintKamus(Kamus Kamus)
{
    SetColor(NONE, FG_GREEN);
    if (Kamus.Jawa != NULL)
        printf("%s\t", Kamus.Jawa);

    SetColor(NONE, FG_YELLOW);
    printf(" = \t");

    SetColor(NONE, FG_CYAN);
    if (Kamus.Indonesia != NULL)
        printf("%s", Kamus.Indonesia);

    SetColor(NONE, FG_WHITE);
    printf("\n");
    (Kamus.Contoh != NULL) ? printf("Contoh: %s\n\n", Kamus.Contoh) : printf("Tidak ada contoh kalimat yang tersedia\n\n");
    SetColor(NONE, FG_YELLOW);
    printf("===========================\n");

    DefaultColor();
}

void HeaderKamus()
{
    SetColor(NONE, FG_GREEN);
    printf("Jawa \t\t");
    SetColor(NONE, FG_CYAN);
    printf("Indonesia\n");
    SetColor(NONE, FG_WHITE);
    printf("Contoh \n");
    SetColor(NONE, FG_YELLOW);
    printf("===========================\n");
    DefaultColor();
}

bool HasChar(String Check, char Contain)
{
    int Len = strlen(Check);
    for (int i = 0; i < Len; i++)
    {
        if (Check[i] == Contain)
            return true;
    }
    return false;
}

void LoadDataKamus(Address *Tree)
{
    FILE *fp;
    fp = fopen(FileKamus, "r");
    if (fp == NULL)
    {
        ErrorMsg("Gagal memuat data pada file Kamus-Jawa-Indonesia.dat\n");
    }
    else
    {
        Kamus TempKamus;
        char Buffer[MAX_BUFFER * 3];
        // AddressNodeNR ListVocabJawa = NULL;
        while (fscanf(fp, "%[^\n]\n", Buffer) == 1)
        {
            StringToKamus(&TempKamus, Buffer);
            InsertToTree(&(*Tree), TempKamus);
        }
        SuccMsg("Berhasil memuat data kamus pada file Kamus-Jawa-Indonesia.dat\n");
    }
    fclose(fp);
    Pause();
}

int IsFileValid()
{
    FILE *fp;
    fp = fopen(FileKamus, "r");
    if (fp == NULL)
    {
        ErrorMsg("Gagal melakukan proses pengecekan file Kamus-Jawa-Indonesia.dat mungkin file tidak ada.");
        fclose(fp);
        Pause();
        return false;
    }
    else
    {
        char Buffer[MAX_BUFFER];
        int Row = 0;
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0)
        {
            fclose(fp);
            return -1;
        }

        rewind(fp);
        while (fscanf(fp, "%[^\n]\n", Buffer) == 1)
        {
            Row++;
            if(HasChar(Buffer, '(') || HasChar(Buffer, ')'))
            {
                if (CountChar(Buffer, '.') < 2 || CountChar(Buffer, '=') != 1 || CountChar(Buffer, '(') != 1 || CountChar(Buffer, ')') != 1)
                {
                    fclose(fp);
                    return Row;
                }
            }
            else
            {
                if (CountChar(Buffer, '.') < 2 || CountChar(Buffer, '=') != 1 || CountChar(Buffer, '(') > 1 || CountChar(Buffer, ')') > 1)
                {
                    fclose(fp);
                    return Row;
                }
            }
        }
    }
    return 0;
}

int CountChar(String StrCheck, char CharCheck)
{
    size_t Len = strlen(StrCheck);
    int Count = 0;
    for (size_t i = 0; i < Len; i++)
    {
        if (StrCheck[i] == CharCheck)
            Count++;
    }
    return Count;
}

void StringToList(AddressNodeNR *List, String Vocab)
{
    unsigned int LenOfTemp = 0;
    unsigned int LenOfJawa = 0;
    while (LenOfJawa != strlen(Vocab) && Vocab[LenOfJawa] != '=')
    {
        String Temp = AlokString(strlen(Vocab));
        Temp[strlen(Vocab)] = 0;
        while (Vocab[LenOfJawa] != '.' && Vocab[LenOfJawa] != ',')
        {
            Temp[LenOfTemp] = Vocab[LenOfJawa];
            LenOfTemp++;
            LenOfJawa++;
        }
        Temp[LenOfTemp] = 0;
        LenOfTemp = 0;
        LenOfJawa++;
        InsertNR(&(*List), Temp);
    }
}

int RefactorFile()
{
    FILE *fp;
    fp = fopen(FileKamus, "r+");
    remove("TempFile.dat");

    if (fp == NULL)
    {
        ErrorMsg("Gagal memuat data pada file Kamus-Jawa-Indonesia.dat\n");
        fclose(fp);
        return 0;
    }
    else
    {
        Kamus TempKamus;
        char Buffer[MAX_BUFFER * 3];
        while (fscanf(fp, "%[^\n]\n", Buffer) == 1)
        {

            int LenOfVocab = strlen(Buffer);
            for (int i = 0; i < LenOfVocab; i++)
            {
                if (i == 0)
                    (Buffer)[0] = toupper((Buffer)[0]);
                if ((Buffer)[i] == ',' || (Buffer)[i] == '.' || (Buffer)[i] == '=' || (Buffer)[i] == '(')
                    (Buffer)[i + 1] = toupper((Buffer)[i + 1]);
            }
            StringToKamus(&TempKamus, Buffer);
            InsertToFile(MergeKamus(TempKamus), "TempFile.dat");
        }
        fclose(fp);
        remove("Kamus-Jawa-Indonesia.dat");
        rename("TempFile.dat", "Kamus-Jawa-Indonesia.dat");
    }
    return 1;
}

void StringToKamus(Kamus *NewKamus, String Vocab)
{
    char Jawa[MAX_BUFFER];
    char Indonesia[MAX_BUFFER];
    char Contoh[MAX_BUFFER];
    /* Variabel sementara Kamus */
    sscanf(Vocab, "%[^=]=%[^(](%[^)])", Jawa, Indonesia, Contoh);
    (*NewKamus).Jawa = AlokString(strlen(Jawa) + 1);
    (*NewKamus).Indonesia = AlokString(strlen(Indonesia) + 1);
    (*NewKamus).Contoh = NULL;
    strcpy((*NewKamus).Jawa, Jawa);
    (*NewKamus).Jawa[0] = toupper((*NewKamus).Jawa[0]);
    (*NewKamus).Jawa[strlen(Jawa)] = 0;
    strcpy((*NewKamus).Indonesia, Indonesia);
    (*NewKamus).Indonesia[strlen(Indonesia)] = 0;
    if (HasChar(Vocab, '('))
    {
        (*NewKamus).Contoh = AlokString(strlen(Contoh) + 1);
        (*NewKamus).Contoh[strlen(Contoh)] = 0;
        strcpy((*NewKamus).Contoh, Contoh);
    }
}

void CheckAndLoadFile(Address *Tree)
{
    remove("TempFile.dat");
    bool Sukses;
    do
    {
        Sukses = false;
        system("cls");
        // Banner();
        Menu();
        SuccMsg("Sedang melakukan pengecekan file Kamus-Jawa-Indonesia.dat...\n");
        int Row = IsFileValid();
        SuccMsg("\nPengecekan sudah selesai...\n");
        if (Row == 0)
        {
            SuccMsg("\nMelakukan penulisan ulang data pada file...\n");
            RefactorFile();
            SuccMsg("File tidak bermasalah...\n");
            SuccMsg("Memuat data...\n");
            sleep(2);
            LoadDataKamus(&(*Tree));
            Sukses = true;
        }
        else if (Row == -1)
        {
            ErrorMsg("Tidak dapat memuat apapun, file masih kosong\n");
        }
        // else if (Row == -2) // Bug
        // { // Harus melakukan refactor terhadap- file
        //     ErrorMsg("Ada kesalahan huruf kapital kosakata pada file Kamus-Jawa-Indonesia.dat\n");
        //     SuccMsg("Sedang melakukan penulisan ulang...\n");
        //     if (RefactorFile())
        //         SuccMsg("Berhasil melakukan penulisan ulang...\n");
        //     else
        //         ErrorMsg("Gagal melakukan penulisan ulang...\n");
        // }
        else
        {
            char Str[10];
            sprintf(Str, "%d", Row);
            ErrorMsg("Ada kesalahan format teks pada file Kamus-Jawa-Indonesia.dat\n");
            ErrorMsg("Silahkan perbaiki format teks pada file tersebut pada Baris ke ");
            ErrorMsg(Str);
            printf("\n");
        }
        if (!Sukses)
        {
            ErrorMsg("Muat ulang file?\n");
            if (!Validasi())
                Sukses = true;
        }
    } while (!Sukses);
}

/*================= Roy =======================*/

/*=======================Naila=====================*/

Address SearchTree(Address Root, String Input)
{
    if (Root == NULL || strcmp(Root->Kamus.Jawa, Input) == 0)

        return Root;

    else if (strcmp(Input, Root->Kamus.Jawa) < 0)

        return SearchTree(Root->Left, Input);

    else
        return SearchTree(Root->Right, Input);
}

void SearchKata(Address Tree)
{
    char InputUser[MAX_BUFFER];
    Address TempTree;
    printf("Masukan kosakata yang akan dicari dalam bahasa Jawa : ");
    scanf(" %[^\n]", InputUser);
    InputUser[0] = toupper(InputUser[0]);
    double start = ((double)clock()) / CLOCKS_PER_SEC;
    TempTree = SearchTree(Tree, InputUser);
    double end = ((double)clock()) / CLOCKS_PER_SEC;

    if (TempTree != NULL)
    {
        printf("Kecepatan pencarian : %f\n", end - start);
        HeaderKamus();
        PrintKamus(TempTree->Kamus); // kalo ditemukan dalam tree
    }
    else
    {
        ErrorMsg("Kata Tidak DItemukan!\n"); // kalo tidak ditemukan
    }
    Pause();
}

Address EditTree(Address Tree)
{
    char KataL[MAX_BUFFER], KataB[MAX_BUFFER], Jawa[MAX_BUFFER], Contoh[MAX_BUFFER];
    // char pilihan;
    // String A;
    // A = AlokString(strlen(KataL)+1);
    printf("Masukkan kata yang ingin diedit : ");
    scanf(" %[^\n]", KataL);
    KataL[0] = toupper(KataL[0]);

    Address Temp = SearchTree(Tree, KataL);
    if(Temp == NULL)
    {
        printf("Kata tidak ditemukan!");
        return NULL;
    }
    else
    {
        printf("Kamus sebelum diedit \n");
        PrintKamus(Temp->Kamus);

        printf("Apakah ingin mengedit kata bahasa Jawa, terjemahan dan contoh kalimatnya?\n");

        if (!Validasi())
        {
            printf("Masukkan kata terjemahan baru : ");
            scanf(" %[^\n]", KataB);
            free(Temp->Kamus.Indonesia);
            Temp->Kamus.Indonesia = AlokString(strlen(KataB) + 2);
            strcpy(Temp->Kamus.Indonesia, KataB);
            strcat(Temp->Kamus.Indonesia, ".");
        }
        else //jika memilih diubah Jawa dan contoh
        {
            printf("Masukkan kata terjemahan baru: ");
            scanf(" %[^\n]", KataB);
            free(Temp->Kamus.Indonesia);
            Temp->Kamus.Indonesia = AlokString(strlen(KataB) + 2);
            strcpy(Temp->Kamus.Indonesia, KataB);
            strcat(Temp->Kamus.Indonesia, ".");

            printf("Masukkan kata bahasa Jawa baru: ");
            scanf(" %[^\n]", Jawa);
            free(Temp->Kamus.Jawa);
            Temp->Kamus.Jawa = AlokString(strlen(Jawa) + 2);
            strcpy(Temp->Kamus.Jawa, Jawa);

            printf("Masukkan contoh kalimat baru: ");
            scanf(" %[^\n]", Contoh);
            free(Temp->Kamus.Contoh);
            Temp->Kamus.Contoh = AlokString(strlen(Contoh) + 2);
            strcpy(Temp->Kamus.Contoh, Contoh);
            strcat(Temp->Kamus.Contoh, ".");
        }
        system("cls");
        SuccMsg("Berhasil melakukan pengeditan!!\n");
        printf("Data kamus setelah diedit\n");
        PrintKamus(Temp->Kamus);
        Pause();
    }
    SaveTreeToFile(Tree,"Kamus-Jawa-Indonesia.dat");
    return Tree;
}

Address DeleteFromTree(Address *Root, String Input)
{
    Address TempTree;
    TempTree = SearchTree((*Root), Input);
    if (TempTree != NULL)
    {
        if ((*Root) == NULL)
        {
            return (*Root);
        }
        else if(strcmp(Input, (*Root)->Kamus.Jawa) < 0)
        {
            (*Root)->Left = DeleteFromTree(&(*Root)->Left, Input);
        }
        else if (strcmp(Input, (*Root)->Kamus.Jawa) > 0)
        {
            (*Root)->Right = DeleteFromTree(&(*Root)->Right, Input);
        }
        else
        {
            // Kasus 1: Leaf node
            if ((*Root)->Left == NULL && (*Root)->Right == NULL)
            {
                free((*Root));
                (*Root) = NULL;
            }
            // Kasus 2: Node memiliki satu anak
            else if ((*Root)->Left == NULL)
            {
                Address temp = (*Root);
                (*Root) = (*Root)->Right;
                free(temp);
            }
            else if ((*Root)->Right == NULL)
            {
                Address temp = (*Root);
                (*Root) = (*Root)->Left;
                free(temp);
            }
            // Kasus 3: Node memiliki dua anak
            else
            {
                Address temp = minValueTree((*Root)->Right);
                (*Root)->Kamus = temp->Kamus;
                (*Root)->Right = DeleteFromTree(&(*Root)->Right, temp->Kamus.Jawa);
            }
        }
        printf("Kata '%s' berhasil terhapus\n", Input);
        printf("Data kamus setelah dihapus\n");
        PrintTree(*Root);
        Pause();
        return (*Root);
    }
    else
    {
        ErrorMsg("Kata Tidak Ditemukan!\n"); // kalo tidak ditemukan
    }
    return *Root;
}

Address minValueTree(Address Root)
{
    Address current = Root;
    while (current->Left != NULL)
    {
        current = current->Left;
    }
    return current;
}

void printTreeGraph(Address Root, int level,int lastLevel) 
{
    if (Root != NULL) 
    {
        printTreeGraph(Root->Left, level + 1, lastLevel);
        int distance = 2 * (level - 1);
        if (level > lastLevel) {
            printf("\n");
            printDistance(distance);
            lastLevel = level;
        }
        printf("%s", Root->Kamus.Jawa);
        printTreeGraph(Root->Right, level + 1, lastLevel);
    }
}

void printTreeWithRoot(Address Root) 
{
    if (Root != NULL) {
        printf("%s\n", Root->Kamus.Jawa);
        int distance = 2 * (height(Root) - 1);
        if (distance != 0)  
        {
            printDistance(distance);
            printTreeGraph(Root->Left, 2, 1);
            printf("\n");
            printDistance(distance);
            printTreeGraph(Root->Right, 2, 1);
        }
    }
}

void printDistance(int distance) {
    for (int i = 0; i < distance; i++) {
        printf("-");
    }
}

void CopyTreeToFile(Address Tree, FILE *f) {
    if (Tree != NULL) {
        if (Tree->Kamus.Contoh == NULL)
        {
            fprintf(f, "%s.=%s*%s\n", Tree->Kamus.Jawa, Tree->Kamus.Indonesia, Tree->Kamus.Tingkatan);
        }
        else{
            fprintf(f, "%s.=%s(%s)*%s\n", Tree->Kamus.Jawa, Tree->Kamus.Indonesia, Tree->Kamus.Contoh, Tree->Kamus.Tingkatan);
        }
        CopyTreeToFile(Tree->Left, f);
        CopyTreeToFile(Tree->Right, f);
    }
}

void SaveTreeToFile(Address Tree, String file) {
    FILE *f = fopen(file, "w");
    if (f == NULL) {
        printf("File tidak dapat dibuka!\n");
        return;
    }

    CopyTreeToFile(Tree, f);

    fclose(f);
}
