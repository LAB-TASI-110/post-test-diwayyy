#include <stdio.h>
#include <string.h>

int main() {
    
    int N;
    char nama[100][50];
    int stok[100];
    int kategori[100];
    int pilih;
    int total = 0;

    printf("Masukkan jumlah data barang: ");
    scanf("%d", &N);

    printf("\nKode Kategori:\n");
    printf("1 = Sembako\n");
    printf("2 = Pakaian\n");
    printf("3 = Aksesoris\n\n");

    // input data barang
    for(int i = 0; i < N; i++) {
        printf("Data barang ke-%d\n", i+1);

        printf("Nama barang : ");
        scanf("%s", nama[i]);

        printf("Jumlah stok : ");
        scanf("%d", &stok[i]);

        printf("Kode kategori : ");
        scanf("%d", &kategori[i]);

        printf("\n");
    }

    // memilih kategori
    printf("Masukkan kategori yang ingin dihitung: ");
    scanf("%d", &pilih);

    printf("\n===== STRUK STOK BARANG =====\n");

    // proses pencarian kategori
    for(int i = 0; i < N; i++) {
        if(kategori[i] == pilih) {
            printf("%s : %d pcs\n", nama[i], stok[i]);
            total += stok[i];
        }
    }

    printf("-----------------------------\n");
    printf("Total stok kategori %d : %d pcs\n", pilih, total);

    return 0;
}
