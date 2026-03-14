#include <stdio.h>
#include <string.h>

int main(){

    char kodeKota[4][5] = {"MDN","BLG","JKT","SBY"};
    char namaKota[4][20] = {"Medan","Balige","Jakarta","Surabaya"};
    int ongkir[4] = {8000,5000,12000,13000};
    char ket[4][20] = {"Dalam Pulau","Dalam Pulau","Luar Pulau","Luar Pulau"};

    char inputKode[10];
    float berat;
    float beratButet = 0, beratUcok = 0;
    float totalBerat = 0;
    float totalOngkir = 0;

    int i;
    int giliran = 0; //0 = Butet, 1 = Ucok
    char kotaTujuan[20];

    printf("===== DEL EXPRESS =====\n");

    while(1){

        scanf("%s", inputKode);

        if(strcmp(inputKode,"END")==0){
            break;
        }

        scanf("%f",&berat);

        for(i=0;i<4;i++){

            if(strcmp(inputKode,kodeKota[i])==0){

                strcpy(kotaTujuan,namaKota[i]);

                float biaya = berat * ongkir[i];

                totalBerat += berat;
                totalOngkir += biaya;

                if(giliran==0){
                    beratButet += berat;
                    giliran = 1;
                }
                else{
                    beratUcok += berat;
                    giliran = 0;
                }

                if(berat > 10){
                    totalOngkir -= 0.1 * biaya;
                }

                break;
            }
        }
    }

    printf("\n===== STRUK PEMBAYARAN =====\n");
    printf("Kota Tujuan        : %s\n", kotaTujuan);
    printf("Berat Paket Butet  : %.2f kg\n", beratButet);
    printf("Berat Paket Ucok   : %.2f kg\n", beratUcok);
    printf("Total Berat        : %.2f kg\n", totalBerat);
    printf("Total Ongkos Kirim : Rp %.0f\n", totalOngkir);

    printf("Promo              : ");

    if(totalBerat > 10){
        printf("Diskon 10%% ");
    }

    for(i=0;i<4;i++){
        if(strcmp(kotaTujuan,namaKota[i])==0){
            if(strcmp(ket[i],"Luar Pulau")==0){
                printf("+ Asuransi Gratis");
            }
        }
    }

    if(totalBerat <= 10){
        printf("Tidak ada promo");
    }

    printf("\n");

    return 0;
}
