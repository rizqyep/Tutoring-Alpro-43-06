#include <stdio.h>
#include <string.h>
//deklarasi struktur sayur

typedef struct
{
    char nama[10], golongan[10];
    int banyak, kualitas, harga, total;
} sayur;

sayur struct_sayur[100];

int main()
{
    int n, totalsayuran = 0, cacahsayuran = 0;

    printf("Masukkan jumlah data : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Nama sayuran : ");
        scanf("%s", &struct_sayur[i].nama);
        printf("Golongan : ");
        scanf("%s", &struct_sayur[i].golongan);
        fflush(stdin);
        printf("Jumlah : ");
        scanf("%d", &struct_sayur[i].banyak);
        printf("Kualitas : ");
        scanf("%d", &struct_sayur[i].kualitas);

        if (strcmp(struct_sayur[i].golongan, "hijau") == 0)
        {

            switch (struct_sayur[i].kualitas)
            {
            case 1:
                struct_sayur[i].harga = 1000;

                break;
            case 2:
                struct_sayur[i].harga = 1500;

                break;
            }
        }
        else if (strcmp(struct_sayur[i].golongan, "lain") == 0)
        {

            switch (struct_sayur[i].kualitas)
            {
            case 1:
                struct_sayur[i].harga = 2500;
                break;
            case 2:
                struct_sayur[i].harga = 3000;
                break;
            default:
                struct_sayur[i].harga = 3200;
                break;
            }
        }

        struct_sayur[i].total = struct_sayur[i].banyak * struct_sayur[i].harga;
        totalsayuran += struct_sayur[i].total;
        cacahsayuran += struct_sayur[i].banyak;
    }

    //menampilkan data sayuran
    printf("Data Sayuran : \n");
    printf("%-10s %-10s Kualitas Banyak Harga Total\n", "Nama", "Golongan");
    for (int i = 0; i < n; i++)
    {
        printf("%-10s %-10s %-8d %-6d %-5d %-5d\n",
               struct_sayur[i].nama, struct_sayur[i].golongan, struct_sayur[i].kualitas, struct_sayur[i].banyak, struct_sayur[i].harga,
               struct_sayur[i].total);
    }
    //menghitung rata-rata dan menampilkan
    float rata;
    rata = (float)totalsayuran / cacahsayuran;
    printf("Rata-rata harga : Rp. %.2f\n", rata);

    sayur temp;
    int pertukaran = 0;
    for (int i = 0; i < n; i++)
    {
        pertukaran = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (strcmp(struct_sayur[j].golongan, struct_sayur[j + 1].golongan) > 0)
            {
                temp = struct_sayur[j];
                struct_sayur[j] = struct_sayur[j + 1];
                struct_sayur[j + 1] = temp;
                pertukaran += 1;
            }
        }
        if (pertukaran == 0)
        {
            break;
        }
    }

    FILE *fpointer;
    fpointer = fopen("file.txt", "a");
    printf("Data Sayuran Terurut: \n");
    printf("%-10s %-10s Kualitas Banyak Harga Total\n", "Nama", "Golongan");
    for (int i = 0; i < n; i++)
    {
        printf("%-10s %-10s %-8d %-6d %-5d %-5d\n",
               struct_sayur[i].nama, struct_sayur[i].golongan, struct_sayur[i].kualitas, struct_sayur[i].banyak, struct_sayur[i].harga,
               struct_sayur[i].total);
        fprintf(fpointer, "%s %s %d %d %d %d\n",
                struct_sayur[i].nama, struct_sayur[i].golongan, struct_sayur[i].kualitas, struct_sayur[i].banyak, struct_sayur[i].harga,
                struct_sayur[i].total);
    }
    fclose(fpointer);

    //membaca dari file
    printf("\nHasil pembacaan dari file : \n");
    printf("%-10s %-10s Kualitas Banyak Harga Total\n", "Nama", "Golongan");
    int i = 0;
    int jumlah_data = 0;
    fpointer = fopen("file.txt", "r");
    while (fscanf(fpointer, "%s %s %d %d %d %d\n",
                  &struct_sayur[i].nama, &struct_sayur[i].golongan, &struct_sayur[i].kualitas, &struct_sayur[i].banyak, &struct_sayur[i].harga,
                  &struct_sayur[i].total) != EOF)
    {
        printf("%-10s %-10s %-8d %-6d %-5d %-5d\n",
               struct_sayur[i].nama, struct_sayur[i].golongan, struct_sayur[i].kualitas, struct_sayur[i].banyak, struct_sayur[i].harga,
               struct_sayur[i].total);
        i++;
        jumlah_data++;
    }

    //selection sort
    int min;

    for (i = 0; i < jumlah_data; i++)
    {
        for (int j = i; j < jumlah_data; j++)
        {
            min = struct_sayur[i].kualitas;
            if (min > struct_sayur[j].kualitas)
            {
                temp = struct_sayur[i];
                struct_sayur[i] = struct_sayur[j];
                struct_sayur[j] = temp;
            }
        }
    }
    printf("Data Sayuran Terurut: \n");
    printf("%-10s %-10s Kualitas Banyak Harga Total\n", "Nama", "Golongan");
    for (i = 0; i < jumlah_data; i++)
    {
        printf("%-10s %-10s %-8d %-6d %-5d %-5d\n",
               struct_sayur[i].nama, struct_sayur[i].golongan, struct_sayur[i].kualitas, struct_sayur[i].banyak, struct_sayur[i].harga,
               struct_sayur[i].total);
    }
}