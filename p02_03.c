#include <stdio.h>

int main(){

    int antrian = 1;

    printf("====================================\n");
    printf("        SISTEM KAFETARIA IT DEL\n");
    printf("====================================\n");

    printf("Nomor Antrian Anda : %d\n\n", antrian);

    // menu
    char makanan[3][30] = {"Nasi Goreng","Ayam Geprek","Mie Goreng"};
    char minuman[3][30] = {"Es Teh","Kopi","Jus Alpukat"};
    char snack[3][30] = {"Kentang Goreng","Roti Bakar","Pisang Goreng"};

    int harga_makanan[3] = {15000,18000,13000};
    int harga_minuman[3] = {5000,7000,10000};
    int harga_snack[3] = {12000,10000,8000};

    int stok_makanan[3] = {10,10,10};
    int stok_minuman[3] = {15,15,15};
    int stok_snack[3] = {10,10,10};

    // menyimpan pesanan
    int pesanan_makanan[3] = {0};
    int pesanan_minuman[3] = {0};
    int pesanan_snack[3] = {0};

    int kategori,menu,jumlah;
    int lagi = 1;
    int total = 0;

    while(lagi==1){

        printf("\n========== KATEGORI MENU ==========\n");
        printf("1. Makanan\n");
        printf("2. Minuman\n");
        printf("3. Snack\n");

        printf("Pilih kategori : ");
        scanf("%d",&kategori);

        if(kategori==1){

            printf("\n------ MENU MAKANAN ------\n");
            for(int i=0;i<3;i++){
                printf("%d. %s - Rp%d (stok:%d)\n",i+1,makanan[i],harga_makanan[i],stok_makanan[i]);
            }

            printf("Pilih menu : ");
            scanf("%d",&menu);

            printf("Jumlah : ");
            scanf("%d",&jumlah);

            if(jumlah > stok_makanan[menu-1]){
                printf("Maaf stok habis!\n");
            }
            else{
                pesanan_makanan[menu-1] += jumlah;
                stok_makanan[menu-1] -= jumlah;
                total += harga_makanan[menu-1]*jumlah;
                printf("Pesanan ditambahkan\n");
            }
        }

        else if(kategori==2){

            printf("\n------ MENU MINUMAN ------\n");
            for(int i=0;i<3;i++){
                printf("%d. %s - Rp%d (stok:%d)\n",i+1,minuman[i],harga_minuman[i],stok_minuman[i]);
            }

            printf("Pilih menu : ");
            scanf("%d",&menu);

            printf("Jumlah : ");
            scanf("%d",&jumlah);

            if(jumlah > stok_minuman[menu-1]){
                printf("Maaf stok habis!\n");
            }
            else{
                pesanan_minuman[menu-1] += jumlah;
                stok_minuman[menu-1] -= jumlah;
                total += harga_minuman[menu-1]*jumlah;
                printf("Pesanan ditambahkan\n");
            }
        }

        else if(kategori==3){

            printf("\n------ MENU SNACK ------\n");
            for(int i=0;i<3;i++){
                printf("%d. %s - Rp%d (stok:%d)\n",i+1,snack[i],harga_snack[i],stok_snack[i]);
            }

            printf("Pilih menu : ");
            scanf("%d",&menu);

            printf("Jumlah : ");
            scanf("%d",&jumlah);

            if(jumlah > stok_snack[menu-1]){
                printf("Maaf stok habis!\n");
            }
            else{
                pesanan_snack[menu-1] += jumlah;
                stok_snack[menu-1] -= jumlah;
                total += harga_snack[menu-1]*jumlah;
                printf("Pesanan ditambahkan\n");
            }
        }

        printf("\nTambah pesanan lagi? (1=ya / 0=tidak): ");
        scanf("%d",&lagi);
    }

    printf("\n====================================\n");
    printf("           STRUK PEMESANAN\n");
    printf("        KAFETARIA IT DEL\n");
    printf("====================================\n");

    printf("Nomor Antrian : %d\n",antrian);

    printf("\nDaftar Pesanan:\n");

    for(int i=0;i<3;i++){
        if(pesanan_makanan[i]>0){
            printf("%s x%d = Rp%d\n",
            makanan[i],
            pesanan_makanan[i],
            pesanan_makanan[i]*harga_makanan[i]);
        }
    }

    for(int i=0;i<3;i++){
        if(pesanan_minuman[i]>0){
            printf("%s x%d = Rp%d\n",
            minuman[i],
            pesanan_minuman[i],
            pesanan_minuman[i]*harga_minuman[i]);
        }
    }

    for(int i=0;i<3;i++){
        if(pesanan_snack[i]>0){
            printf("%s x%d = Rp%d\n",
            snack[i],
            pesanan_snack[i],
            pesanan_snack[i]*harga_snack[i]);
        }
    }

    printf("------------------------------------\n");
    printf("Total Bayar : Rp%d\n",total);

    int bayar;

    printf("Masukkan uang : ");
    scanf("%d",&bayar);

    if(bayar < total){
        printf("Uang tidak cukup\n");
    }
    else{
        printf("Kembalian : Rp%d\n",bayar-total);
    }

    printf("\nSilahkan tunggu nomor antrian dipanggil\n");
    printf("Terima kasih telah menggunakan Kafetaria IT Del\n");

    return 0;
}