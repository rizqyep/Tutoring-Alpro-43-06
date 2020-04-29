#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
char nama[20][20];
float nilai1[20],nilai2[20],nilai3[20],total,rata[20];
int n;

/*baris dibawah ini dinamakan function prototyping, tujuannya adalah mendeklarasikan fungsi
  agar dikenal oleh fungsi lainnya
*/
int menu();
void cari_data();
void sort_data();
void input();
void tampilkan_data();


int menu(){
    int pil;
    printf("Pilihan Menu :\n");
    printf("1.Input Data\n");
    printf("2.Cari Data\n");
    printf("3.Urutkan Data\n");
    printf("0.Keluar Program\n");
    printf("Pilihan anda : ");
    scanf("%d",&pil);

    switch(pil)
    {
        case 1 :
            input();
            break;
        case 2:
            cari_data();
            break;
        case 3 :
            sort_data();
            break;
        case 0 :
            system("cls");
            printf("Terima Kasih!");
            return 0;
        default :
            system("cls");
            printf("Inputan anda salah!");
            menu();
    }

}

void input(){
    printf("Masukkan jumlah data : ");
    scanf("%d",&n);
    for(int i = 0 ;i < n ;i++){
        printf("Data ke %d\n",i+1);
        fflush(stdin);
        printf("Masukkan nama siswa :");
        fgets(nama[i],20,stdin);
        strtok(nama[i],"\n");/*tujuan dari baris ini adalah untuk mengeluarkan \n
                               dari ujung string agar pada saat ditampilkan tidak ada enter */
        fflush(stdin);//membuang sisa inputan di buffer agar inputan selanjutnya tidak dilakukan oleh sisa input sebelumnya
        printf("Masukkan nilai 1 :");
        scanf("%f",&nilai1[i]);
        printf("Masukkan nilai 2 :");
        scanf("%f",&nilai2[i]);
        printf("Masukkan nilai 1 :");
        scanf("%f",&nilai3[i]);
        total = nilai1[i] + nilai2[i] + nilai3[i];
        rata[i] = total/3;
    }

    tampilkan_data();

    printf("Tekan enter untuk kembali ke menu");
    getch();
    system("cls");
    menu();
}
void cari_data(){
    char cari[20];
    fflush(stdin);
    printf("Masukkan Nama Mahasiswa Yang ingin di cari : ");
    fgets(cari,20,stdin);
    strtok(cari,"\n");
    fflush(stdin);
    int ketemu = -1;
    int pilih;
    //pencarian dengan linear search,karena data belum di urutkan
    for(int i = 0 ; i < n ; i++){
        if(strcmp(nama[i],cari)==0){
            ketemu = i; //artinya index data yang di cari berada pada urutan ke- i
        }
    }
    if(ketemu!=-1)
    {
    printf("Data yang di cari : \n");
    printf("%-20s Nilai1\t Nilai2\t Nilai3\t Rata-rata\n","Nama Mahasiswa");
    printf("%-20s %.2f\t %.2f\t %.2f\t %.2f\n",nama[ketemu],nilai1[ketemu],nilai2[ketemu],nilai3[ketemu],rata[ketemu]);
   }
    else
    {
        printf("Data tidak ditemukan\n");
    }
    printf("Masukkan 1 untuk mencari data yang lain, 0 untuk kembali ke menu :  ");
    scanf("%d",&pilih);
    switch(pilih)
    {
        case 1:
            system("cls");
            cari_data();
            break;
        case 2 :
            system("cls");
            menu();
            break;
    }

}

void tampilkan_data(){
    for(int i = 0 ; i < n ; i++)
    {
         printf("%-20s Nilai1\t Nilai2\t Nilai3\t Rata-rata\n","Nama Mahasiswa");
         printf("%-20s %.2f\t %.2f\t %.2f\t %.2f\n",nama[i],nilai1[i],nilai2[i],nilai3[i],rata[i]);
    }
}


void sort_data(){
    //sorting yang dilakukan menggunakan bubble sort
    printf("Data Sebelum Diurutkan (berdasarkan nilai rata-rata): \n");
    tampilkan_data();
    char temp_nama[20];
    float temp_nilai1,temp_nilai2,temp_nilai3,temp_rata;
    printf("\nData Setelah Diurutkan : \n");
    for(int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if(rata[j]<rata[j+1])
            {
                //menukar tempat nama
                strcpy(temp_nama,nama[j+1]);
                strcpy(nama[j+1], nama[j]);
                strcpy(nama[j], temp_nama);

                //menukar tempat nilai1,nilai2,nilai3
                temp_nilai1 = nilai1[j+1];
                nilai1[j+1] = nilai1[j];
                nilai1[j] = temp_nilai1;

                temp_nilai2 = nilai2[j+1];
                nilai2[j+1] = nilai2[j];
                nilai2[j] = temp_nilai2;

                temp_nilai3 = nilai3[j+1];
                nilai3[j+1] = nilai3[j];
                nilai3[j] = temp_nilai3;

                temp_rata = rata[j+1];
                rata[j+1] = rata[j];
                rata[j] = temp_rata;
            }
        }
    }
    tampilkan_data();

}


int main()
{
    menu();
}
