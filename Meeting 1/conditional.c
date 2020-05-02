#include <stdio.h>

int main()
{
    int pilihan;
    int angka = 10;
    char nama[20] = "Bryan ";
    printf("1.Tampilkan Nama \n");
    printf("2.Tampilkan Angka \n");
    printf("0. Keluar \n");
    printf("Masukkan pilihan : ");
    scanf("%d", &pilihan);

    //evaluasi kondisi dengan switch-case
    switch (pilihan)
    {
    case 1:
        printf("%s", nama);
        break;
    case 2:
        printf("%d", angka);
        break;
    case 0:
        return 0;
    default:
        printf("Menu tidak ada");
    }

    //evaluasi kondisi dengan if-elseif-else
    if (pilihan == 1)
    {
        printf("%s", nama);
    }
    else if (pilihan == 2)
    {
        printf("%d", angka);
    }
    else if (pilihan == 0)
    {
        return 0;
    }
    else
    {
        printf("Menu tidak ada");
    }
}