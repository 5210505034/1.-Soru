#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
int main() {
    int boyut;
    int eleman;
    int *dizi;
    int hedef;
    printf("karsilastirilacak sayiyi giriniz.\n");
    scanf("%d", &hedef);
    printf("dizinin boyutunu giriniz.\n");
    scanf("%d", &boyut);
    printf("%d", boyut);
    dizi = (int *) malloc(boyut * sizeof(int));
    
    for (int i = 0; i < boyut; i++){
        printf("dizinin %d. indexini giriniz.\n", i);
        scanf("%d", &eleman);
        dizi[i] = eleman;
    }
    
    for (int j = 0; j < boyut; j ++){
        printf("dizinin %d. elamani = %d\n", j,dizi[j]);
    }
    
    printf("karsilastirilacak sayi %d\n", hedef);
    en_yakin_toplam(dizi, boyut, hedef);
    return 0;
}

void en_yakin_toplam(int dizi[], int n, int hedef) {
    int en_i, en_j, en_k;
    int en_uzak = INT_MAX;
    int i, j, k;
 
    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                int toplam = dizi[i] + dizi[j] + dizi[k];
                int fark = abs(hedef - toplam); 
 
                if (fark < en_uzak) {
                    en_uzak = fark;
                    en_i = i;
                    en_j = j;
                    en_k = k;
                }
            }
        }
    }
    printf("En yakın toplam: %d + %d + %d = %d\n", dizi[en_i], dizi[en_j], dizi[en_k], dizi[en_i]+dizi[en_j]+dizi[en_k]);
}
