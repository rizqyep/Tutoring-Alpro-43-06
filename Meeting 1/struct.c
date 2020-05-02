#include <stdio.h>
#include <string.h>

typedef struct
{
    int nilai;
    char nama[20];
} mahasiswa;

mahasiswa mhs[10]; // struct mhs dengan tipe mahasiswa ,10 data

int main()
{
    int n;
    printf("Masukkan jumlah data :");
    scanf("%d", &n); // integer

    for (int i = 0; i < n; i++)
    {
        fflush(stdin); // clean buffer
        printf("Data struct indeks ke %d \n", i);
        printf("Masukkan Nama : ");
        fgets(mhs[i].nama, 20, stdin);
        // format string dengan fgets -> "\n"
        strtok(mhs[i].nama, "\n"); // membuang \n dari string
        printf("Masukkan Nilai : ");
        fflush(stdin);
        scanf("%d", &mhs[i].nilai);
    }

    for (int i = 0; i < n; i++)
    {
        if (mhs[i].nilai > 80)
        {
            printf("%s %d \n", mhs[i].nama, mhs[i].nilai);
        }
    }
}