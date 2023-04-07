#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
//gerekli kütüphaneler include edildi.
int main() {
    int boyut;
    int eleman;
    //girilecek dizinin boyut bilgisi alındı.
    int *dizi;
    int hedef;
    printf("karsilastirilacak sayiyi giriniz.\n");
    scanf("%d", &hedef);
    printf("dizinin boyutunu giriniz.\n");
    scanf("%d", &boyut);
    printf("%d", boyut);
    dizi = (int *) malloc(boyut * sizeof(int));
    //pointer ile dizinin boyutu kullanıcının girdiği boyut değişkeni ile değiştirildi.
    
    for (int i = 0; i < boyut; i++){
        printf("dizinin %d. indexini giriniz.\n", i);
        scanf("%d", &eleman);
        dizi[i] = eleman;
    }
    //bu döngüde kullanıcıdan dizinin elemanları alındı.
    for (int j = 0; j < boyut; j ++){
        printf("dizinin %d. elamani = %d\n", j,dizi[j]);
    }
    //alınan elemanlar ekrana yazdırıldı.
    printf("karsilastirilacak sayi %d\n", hedef);
    en_yakin_toplam(dizi, boyut, hedef);
    return 0;
}

void en_yakin_toplam(int dizi[], int n, int hedef) {
    int en_i, en_j, en_k;
    int en_uzak = INT_MAX;
    int i, j, k;
    //3 tane değer arandığı için ilk döngü dizinin boyutu -2 kadar 2. döngü dizinin boyutu -1 kadar ve 3. döngü dizinin boyutu kadar döndürülmüştür.
    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                int toplam = dizi[i] + dizi[j] + dizi[k];
                int fark = abs(hedef - toplam); 
                 //hedef ve toplamın farkını alıp mutlak değer olarak fark değişkenine atandı. 
                if (fark < en_uzak)  { //fark değişkeni en uzak değişkeninden küçük ise 
                    en_uzak = fark;
                    en_i = i;
                    en_j = j;
                    en_k = k;
                    //en uzak değişkeni fark değişkenine eşitlendi döngüdeki mevcut i,j,k değerleri kullanılacak değişkenlere atandı.
                }
            }
        }
    }
    printf("En yakın toplam: %d + %d + %d = %d\n", dizi[en_i], dizi[en_j], dizi[en_k], dizi[en_i]+dizi[en_j]+dizi[en_k]);
    //kullanıcıya bulunan değerler gösterilmiştir.
}
