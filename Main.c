#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 10

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    //Sol ve sağ dizi değişkenleri
    int sol_dizi = m - l + 1;
    int sag_dizi =  r - m;
  
    //Geçici diziler
    int L[sol_dizi], R[sag_dizi];
  
    for (i = 0; i < sol_dizi; i++)
        L[i] = arr[l + i];
    for (j = 0; j < sag_dizi; j++)
        R[j] = arr[m + 1+ j];
  
    //sıfırlama
    i = 0; 
    j = 0;
    k = l;
 
    while (i < sol_dizi && j < sag_dizi)
    {
        /*Eğer sol dizinin i. indisindeki eleman, sağ dizinin j. indisindeki elemandan küçük eşitse 
        yeni oluşturulacak dizinin ilk elemanı sol dizinin ilk elemanı oluyor.*/
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        //Yok değilse sağ dizinin ilk elemanı yeni dizimizin ilk elemanı oluyor.
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < sol_dizi)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < sag_dizi)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        //dizinin ortası hesaplanıyor. 
        int m = l+(r-l)/2;
  
         
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
         
        //Esas  fonksiyona dizimizi, sol indisi, orta indisi ve sağ indisi parametre olarak yolluyoruz.
        merge(arr, l, m, r);
    }
}

void dosya_yazma(char isim[50],int siralanmamis_liste[],int siralanmis[]){
    FILE *dosya;
    dosya = fopen(isim,"w");
    
    for(int i = 0 ; i<SIZE ; i++){
        fprintf(dosya,"%d. Girilen Sayi : %d \n",i+1,siralanmamis_liste[i]);

    }
    
    fprintf(dosya,"--------MERGESORT SİRALAMASİ------\n");
    for(int i = 0 ; i<SIZE ; i++){
        
        fprintf(dosya,"%d. Siradaki Sayi :%d\n",i+1,siralanmis[i]);
    }
    fclose(dosya);



}
int main(){
    while(true){
        printf("Mergesort ile siralama programi\n");
        char txt_ismi[50];
        int liste[SIZE];
        int girilen[SIZE];
        int siralanmis[SIZE];
        printf("Yazilacak dosyanin ismi : "); //yazilacak dosya ismini kullanıcıdan aliyorum.
        scanf("%s",&txt_ismi);
        for(int i = 0 ; i<SIZE ; i++){
            printf("%d. Elemani girin :",i+1);
            int girdi;
            scanf("%d",&girdi);
            liste[i] = girdi;
        }
        for(int i = 0 ; i<SIZE ; i++){
            girilen[i] = liste[i]; //girilen sirasiz listeyi kaybetmemek icin bir listeye attim.
        }
        mergeSort(liste,0,SIZE);
        for(int i = 0 ; i<SIZE ;i++){
            siralanmis[i] = liste[i];
        }
        dosya_yazma(txt_ismi,girilen,siralanmis); //olusturdugum fonksiyon sayesinde listeleri parametre olarak vermek yeterli oluyor.
        printf("Dosyaniz %s isminde olusturuldu. Cikis icin '0', bastan baslamak icin '1' :",txt_ismi);
        int son_girdi;
        scanf("%d",&son_girdi);
        if(son_girdi == 0){
            printf("Cikis yapiliyor..");
            break;
        }
        else if(son_girdi == 1){
            continue;
        }
    }
}
