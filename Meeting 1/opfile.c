#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

int main()
{
    int angka;
    char nama[20];
    FILE *fpointer;
    //menulis ke file
    fpointer = fopen("file.txt", "w");
    printf("Masukkan Nama : ");
    fflush(stdin);
    scanf("%s", &nama);
    printf("Masukkan Angka : ");
    scanf("%d", &angka);
    fprintf(fpointer, "%s %d\n", nama, angka);
    fclose(fpointer);

    //menambahkan ke file
    fpointer = fopen("file.txt", "a");
    printf("Masukkan Nama : ");
    fflush(stdin);
    scanf("%s", &nama);
    printf("Masukkan Angka : ");
    scanf("%d", &angka);

    fprintf(fpointer, "%s %d\n", nama, angka);

    fclose(fpointer);

    //membaca dari file
    int i = 0;
    printf("Hasil pembacaan dari file :\n");
    fpointer = fopen("file.txt", "r");

    while (fscanf(fpointer, "%s %d", &nama, &angka) != EOF)
    {
        printf("%s %d\n", nama, angka);
    }

    fclose(fpointer);
}