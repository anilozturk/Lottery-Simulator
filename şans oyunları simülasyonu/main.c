#include <stdio.h>
#include <stdlib.h>

int sayi_al(int,int);
void Ana_menu_goruntusu();
void Alt_menu_sans();
void bubble_sort(int *,int);
void sayisal_loto(int [],int *);
void super_loto(int [],int *);
void on_numara(int [],int *);
void sans_topu(int [],int [],int *);
int tahmin_bul(int *,int *,int,int);
void kabarcik_siralama(int [], int [], int);
void yer_degistir(int *, int *);

int main()
{
    int secim,secim2,i;
    int static genel_top_odul=0;
    static int sayisal_saydir[49]= {0};
    static int sans_saydir[34]={0};
    static int arti_sans_saydir[14]={0};
    static int on_saydir[80]={0};
    static int super_saydir[54]={0};
    int sayisal_saydir2[49]= {0},sans_saydir2[34]={0},arti_sans_saydir2[14]={0},on_saydir2[80]={0},super_saydir2[54]={0};
    static int arti_random_sans[14]={0};
    static int random_say[49]= {0};
    static int random_sans[49]={0};
    static int random_on[80]={0};
    static int random_super[54]={0};
    int random_say2[49]={0},random_sans2[49]={0},arti_random_sans2[14]={0},random_on2[80]={0},random_super2[54]={0};
    char cevap,cevap_sayisal,cevap_super,cevap_on,cevap_sans;
    unsigned besleme;

    printf("Beslemeyi girin:");
    scanf("%u",&besleme);
    srand(besleme);

    do
    {
        Ana_menu_goruntusu();
        secim=sayi_al(1,3);//secimin istenen aralikta olmasi isteniyor
        switch (secim)
        {
        case 1:
            do
            {
                Alt_menu_sans();
                printf("(Toplam odulunuz:%d puan) Seciminizi giriniz:",genel_top_odul);//butun oyunlarin toplam odulu
                secim2=sayi_al(1,5);

                switch (secim2)
                {
                case 1:
                    do
                    {
                        for (i=0;i<49;i++)
                            random_say[i]=i+1;//bilgisayarin sayisal loto oyunu icin secebilecegi sayilarin olusturdugu dizi
                        sayisal_loto(sayisal_saydir,&genel_top_odul);

                        do
                        {
                            printf("Yeniden oynamak ister misiniz?");
                            fflush(stdin);//tamponlanan bolgeyi siliyor
                            cevap_sayisal=getchar();
                        }
                        while (cevap_sayisal!='e' && cevap_sayisal!='E' && cevap_sayisal!='h' && cevap_sayisal!='H');/*cevabin istenen
                        kosullara uymasi saglaniyor*/
                    }
                    while (cevap_sayisal=='e' || cevap_sayisal=='E');//cevap evet oldugu surece tekrar oynatiyor

                    break;
                case 2:
                    do
                    {
                        for (i=0;i<34;i++)
                            random_sans[i]=i+1;//bilgisayarin sans topu oyunu icin secebilecegi 5 sayinin dizisi
                        for (i=0;i<14;i++)
                            arti_random_sans[i]=i+1;//bilgisayarin sans topu oyunu icin secebilecegi arti sayilarin dizisi
                        sans_topu(sans_saydir,arti_sans_saydir,&genel_top_odul);
                        do
                        {
                            printf("Yeniden oynamak ister misiniz?");
                            fflush(stdin);
                            cevap_sans=getchar();

                        }
                        while (cevap_sans!='e' && cevap_sans!='E' && cevap_sans!='h' && cevap_sans!='H');/*cevabin
                        istenen kosullara uymasi saglaniyor*/
                    }
                    while (cevap_sans=='e' || cevap_sans=='E');//cevap evet oldugu surece tekrar oynatiyor
                    break;
                case 3:
                    do
                    {
                        for (i=0;i<80;i++)
                            random_on[i]=i+1;//bilgisayarin on numara oyunu icin secebilecegi sayilarin olusturdugu dizi
                        on_numara(on_saydir,&genel_top_odul);
                        do
                        {
                            printf("Yeniden oynamak ister misiniz?");
                            fflush(stdin);
                            cevap_on=getchar();

                        }
                        while (cevap_on!='e' && cevap_on!='E' && cevap_on!='h' && cevap_on!='H');/*cevabin
                        istenen kosullara uymasi saglaniyor*/
                    }
                    while (cevap_on=='e' || cevap_on=='E');//cevap evet oldugu surece oynatiyor
                    break;
                case 4:
                    do
                    {
                        for (i=0;i<54;i++)
                            random_super[i]=i+1;//bilgisayarin super loto oyunu icin secebilecegi sayilarin olusturdugu dizi
                        super_loto(super_saydir,&genel_top_odul);
                        do
                        {
                            printf("Yeniden oynamak ister misiniz?");
                            fflush(stdin);
                            cevap_super=getchar();

                        }
                        while (cevap_super!='e' && cevap_super!='E' && cevap_super!='h' && cevap_super!='H');/*cevabin
                        istenen kosullara uymasi saglaniyor*/
                    }
                    while (cevap_super=='e' || cevap_super=='E');//cevap evet oldugu surece oynatiyor
                    break;
                case 5:
                    break;

                }
                if (secim2==5)//alt menuden ana menuye donme kosulu
                    break;
            }
            while (cevap_sayisal!='h' || cevap_sayisal!='H' || cevap_super!='h' || cevap_super!='H' || cevap_on!='h' || cevap_on!='H' || cevap_sans!='h' || cevap_sans!='H');
            /*cevap hayir olmadigi surece eger evetse o oyunu tekrar oynatir istenmeyen veri girisinde soruyu tekrar sorar,
            eger hayirsa alt menuye doner*/
            break;
        case 2:
            printf("\nSAYISAL\n");

            for (i=0;i<49;i++)
            {
                sayisal_saydir2[i]=sayisal_saydir[i];/*2 adet frekans dizisi secilir cunku bir frekans siralama fonksiyonuna adres olarak
                gonderilir ve orda degeri degisiklige ugrar,bu durumdan kurtulmak icin 2 adet frekans dizisi secilip biri digerine atanir*/
                random_say2[i]=random_say[i];/*2 adet sansli sayi dizisi secilir cunku bir sansli sayi dizisi siralama fonksiyonuna adres olarak
                gonderilir ve orda degeri degisiklige ugrar,bu durumdan kurtulmak icin 2 adet sansli sayi dizisi secilip biri digerine atanir*/
            }

            kabarcik_siralama(sayisal_saydir2,random_say2,49);//sansli sayi ve frekansi siralama fonksiyonuna gonderilir

            for (i=0;i<6;i++)//en cok cikan 6 sayi istendigi icin 6 kez doner
                printf("%d sayisi %d kez cikti\n",random_say2[i],sayisal_saydir2[i]);
            for (i=6;i<49;i++){//listelenen son sayi ile ayni miktarda cikmis diger sayilarin olup olmadigini kontrol edip yazdirir
                if (sayisal_saydir2[i]==sayisal_saydir2[5])
                    printf("%d sayisi %d kez cikti\n",random_say2[i],sayisal_saydir2[i]);
            }

            printf("\nSANS TOPU\n");

            for (i=0;i<34;i++)
            {
                sans_saydir2[i]=sans_saydir[i];
                random_sans2[i]=random_sans[i];
            }

            kabarcik_siralama(sans_saydir2,random_sans2,34);//sansli sayi ve frekansi siralama fonksiyonuna gonderilir

            for (i=0;i<5;i++)//en cok cikan 5 sayi istendigi icin 5 kez doner
                printf("%d sayisi %d kez cikti\n",random_sans2[i],sans_saydir2[i]);

            for (i=5;i<34;i++){//listelenen son sayi ile ayni miktarda cikmis diger sayilarin olup olmadigini kontrol edip yazdirir
                if (sans_saydir2[i]==sans_saydir2[4])
                    printf("%d sayisi %d kez cikti\n",random_sans2[i],sans_saydir2[i]);
            }

            printf("\n+\n");

            for (i=0;i<14;i++)
            {
                arti_sans_saydir2[i]=arti_sans_saydir[i];
                arti_random_sans2[i]=arti_random_sans[i];
            }

            kabarcik_siralama(arti_sans_saydir2,arti_random_sans2,14);//sansli sayi ve frekansi siralama fonksiyonuna gonderilir

            for (i=0;i<1;i++)// en cok cikan + sayi istendigi icin 1 kez doner
                printf("%d sayisi %d kez cikti\n",arti_random_sans2[i],arti_sans_saydir2[i]);
            for (i=1;i<14;i++){//listelenen son + sayi ile ayni miktarda cikmis diger + sayilarin olup olmadigini kontrol edip yazdirir
                if (arti_sans_saydir2[i]==arti_sans_saydir2[0])
                    printf("%d sayisi %d kez cikti\n",arti_random_sans2[i],arti_sans_saydir2[i]);
            }

            printf("\nON NUMARA\n");

            for (i=0;i<80;i++)
            {
                on_saydir2[i]=on_saydir[i];
                random_on2[i]=random_on[i];
            }

            kabarcik_siralama(on_saydir2,random_on2,80);//sansli sayi ve frekansi siralama fonksiyonuna gonderilir

            for (i=0;i<10;i++)// en cok cikan 10 sayi istendigi icin 10 kez doner
                printf("%d sayisi %d kez cikti\n",random_on2[i],on_saydir2[i]);
            for (i=10;i<80;i++){
                if (on_saydir2[i]==on_saydir2[9])//listelenen son sayi ile ayni miktarda cikmis diger sayilarin olup olmadigini kontrol edip yazdirir
                    printf("%d sayisi %d kez cikti\n",random_on2[i],on_saydir2[i]);
            }

            printf("\nSUPER LOTO\n");

            for (i=0;i<54;i++)
            {
                super_saydir2[i]=super_saydir[i];
                random_super2[i]=random_super[i];
            }

            kabarcik_siralama(super_saydir2,random_super2,54);//sansli sayi ve frekansi siralama fonksiyonuna gonderilir

            for (i=0;i<6;i++)//en cok cikan 6 sayi istendigi icin 6 kez doner
                printf("%d sayisi %d kez cikti\n",random_super2[i],super_saydir2[i]);

            for (i=6;i<54;i++){//listelenen son sayi ile ayni miktarda cikmis diger sayilarin olup olmadigini kontrol edip yazdirir
                if (super_saydir2[i]==super_saydir2[5])
                    printf("%d sayisi %d kez cikti\n",random_super2[i],super_saydir2[i]);
            }

            break;

        case 3:
            do
            {
                printf("Cikmak istediginize emin misiniz?\n");
                scanf("%c",&cevap);
                cevap=getchar();

            }
            while (cevap!='e' && cevap!='E' && cevap!='h' && cevap!='H');//cevabin uygun kosullarda olmasi saglanir
        }
        if (cevap=='e' || cevap=='E')
            break;
    }
    while (cevap=='h' || cevap=='H' || secim2==5);/*alt menuden ana menuye cikilmasi veya ana menuden 3 secenegi
    secilip hayir secilmesi durumunda butun dongu bastan doner*/
    return 0;

}

void Ana_menu_goruntusu()
{
    printf("\n%s\n","ANA MENU");
    printf("1.Sans Oyunlari\n");
    printf("2.Cekilis Istatistikleri\n");
    printf("3.Cikis");
    printf("\nSeciminizi giriniz:");
}

void Alt_menu_sans()
{
    printf("\n%s","SANS OYUNLARI ALT MENUSU\n");
    printf("1.Sayisal Loto Oynama\n");
    printf("2.Sans Topu Oynama\n");
    printf("3.On Numara Oynama\n");
    printf("4.Super Loto Oynama\n");
    printf("5.Ana Menu\n");
}

int sayi_al(int alt_sinir,int ust_sinir)
{
    int sayi;

    do
    {
        printf("\n(Lutfen alt/ust sinir arasinda bir sayi giriniz.)\n");
        scanf("%d",&sayi);

    }
    while (sayi<alt_sinir || sayi>ust_sinir);

    return sayi;
}

void sayisal_loto(int sayisal_frekans[],int *toplam)//mainden frekans dizisinin adresini alir ve isleyerek geri gonderir
{
    int sayi[6]= {0},i,j,tahmin,k,l,b_sayi[6]={0};

    for (i=0; i<6; i++)
    {
        printf("\n%d. sayinizi giriniz(1-49):",i+1);
        sayi[i]=sayi_al(1,49);//kullanicinin girdigi sayilarin istenen kosullarda olmasi saglanir

        for (j=0; j<i; j++)
        {
            if (sayi[i]==sayi[j])
            {
                printf("Hatali veri girisi yaptiniz.Lutfen tekrar giriniz.\n");
                i=i-1;
                j=j-1;
            }
        }
    }
    printf("Kucukten buyuge sayilar:\n");
    bubble_sort(sayi,5);//kullanici taragindan girilen sayilar siralamaya gonderilir

    for (k=0; k<6; k++)//sansli sayilar uretilir
    {
        b_sayi[k]=1+(rand()%49);

        for (l=0; l<k; l++)
        {
            if (b_sayi[k]==b_sayi[l])
            {
                b_sayi[k]=1+(rand()%49);
            }
        }
    }

    for (k=0;k<6;k++)//uretilen sansli sayilara gore frekans artiriliyor
    {
        sayisal_frekans[b_sayi[k]-1]++;
    }
    printf("\n Sansli sayilar:\n");
    bubble_sort(b_sayi,5);//sansli sayilar siraya sokuluyor

    tahmin=tahmin_bul(b_sayi,sayi,6,6);/*kullanici tarafindan girilen sayilar ve sansli sayilar karsilastirilarak
    tahmin sayisi bulunur*/
    printf("\nDogru tahmin sayiniz:%d\n",tahmin);
    switch (tahmin)//tahmin sayisina gore odul belirlenir
    {
    case 3:
        printf("Odulunuz 32 puan!\n");
        *toplam+=32;
        break;
    case 4:
        printf("Odulunuz 64 puan!\n");
        *toplam+=64;
        break;
    case 5:
        printf("Odulunuz 128 puan!\n");
        *toplam+=128;
        break;
    case 6:
        printf("Odulunuz 256 puan!\n");
        *toplam+=256;
        break;
    default:
        printf("Uzgunuz odul kazanamadiniz.Sansinizi tekrar deneyin!\n");
        *toplam=*toplam;
        break;
    }
    printf("Su ana kadar sayisal loto oyununda aldiginiz toplam odul:%d\n",*toplam);/*Bu oyun cesidinin toplam
    puani hesaplanip yazdirilir*/

}

void bubble_sort(int *array,int a)//siralama yapilir
{
    int flag, i , gecici;
    do
    {
        flag=0;
        for(i=0; i<a; i++)
        {
            if(array[i]>array[i+1])
            {
                gecici=array[i];
                array[i]=array[i+1];
                array[i+1]=gecici;
                flag=1;
            }
        }
    }
    while(flag==1);
    for(i=0; i<a+1; i++)
        printf(" %d", array[i]);

}

void super_loto(int super_frekans[],int *toplam)
{
    int sayi[6]= {0},i,j,k,l,tahmin,b_sayi[6]={0};

    for (i=0; i<6; i++)//kullanicinin girdigi verilerin uygun kosullara uymasi saglanir
    {
        printf("\n%d. sayinizi giriniz(1-54):",i+1);
        sayi[i]=sayi_al(1,54);

        for (j=0; j<i; j++)
        {
            if (sayi[i]==sayi[j])
            {
                printf("Hatali veri girisi yaptiniz.Lutfen tekrar giriniz.\n");
                i=i-1;
                j=j-1;
            }
        }
    }
    printf("Kucukten buyuge sayilar:\n");
    bubble_sort(sayi,5);//kullanici tarafindan girilen veriler siraya sokulur

    for (k=0; k<6; k++)//sansli sayilar uretilir
    {
        b_sayi[k]=1+(rand()%54);

        for (l=0; l<k; l++)
        {
            if (b_sayi[k]==b_sayi[l])
            {
                b_sayi[k]=1+(rand()%54);
            }
        }
    }

    for (k=0;k<6;k++)//uretilen sansli sayinin frekansi artirilir
        super_frekans[b_sayi[k]-1]++;

    printf("\nSansli sayilar:\n");
    bubble_sort(b_sayi,5);//uretilen sansli sayilar siraya sokulur

    tahmin=tahmin_bul(b_sayi,sayi,6,6);//kullanicinin kac bildigi belirlenir
    printf("\nDogru tahmin sayiniz:%d\n",tahmin);
    switch (tahmin)//tahmin sayisina gore odul belirlenir
    {
    case 3:
        printf("Odulunuz 32 puan!\n");
        *toplam+=32;
        break;
    case 4:
        printf("Odulunuz 64 puan!\n");
        *toplam+=64;
        break;
    case 5:
        printf("Odulunuz 128 puan!\n");
        *toplam+=128;
        break;
    case 6:
        printf("Odulunuz 256 puan!\n");
        *toplam+=256;
        break;
    default:
        printf("Uzgunuz odul kazanamadiniz.Sansinizi tekrar deneyin!\n");
        *toplam=*toplam;
        break;
    }
    printf("Su ana kadar super loto oyununda aldiginiz toplam odul:%d\n",*toplam);/*bu oyun cesidinin toplam puani
    hesaplanip yazdirilir*/
}

void on_numara(int on_frekans[],int *toplam)
{
    int sayi[10]= {0},i,j,k,l,tahmin,b_sayi[22]={0};

    for (i=0; i<10; i++)//kullanicinin istenen kosullara gore veri girmesi saglanir
    {
        printf("\n%d. sayinizi giriniz(1-80):",i+1);
        sayi[i]=sayi_al(1,80);

        for (j=0; j<i; j++)
        {
            if (sayi[i]==sayi[j])
            {
                printf("Hatali veri girisi yaptiniz.Lutfen tekrar giriniz.\n");
                i=i-1;
                j=j-1;
            }
        }
    }

    printf("Kucukten buyuge sayilar:\n");
    bubble_sort(sayi,9);//kullanicidan alinan sayilar siraya sokulur

    for (k=0; k<22; k++)//sansli sayilar uretilir
    {
        b_sayi[k]=1+(rand()%80);

        for (l=0; l<k; l++)
        {
            if (b_sayi[k]==b_sayi[l])
            {
                b_sayi[k]=1+(rand()%80);
            }
        }
    }

    for (k=0;k<22;k++)//uretilen sansli sayinin frekansi artirilir
        on_frekans[b_sayi[k]-1]++;

    printf("\nSansli sayilar:\n");
    bubble_sort(b_sayi,21);//uretilen sansli sayilar siraya sokulur

    tahmin=tahmin_bul(b_sayi,sayi,22,10);//dogru tahmin sayisi bulunur
    printf("\nDogru tahmin sayiniz:%d\n",tahmin);
    switch (tahmin)//tahmin sayisina gore odul belirlenir
    {
    case 0:
        printf("Odulunuz 8 puan!\n");
        *toplam+=8;
        break;
    case 6:
        printf("Odulunuz 16 puan!\n");
        *toplam+=16;
        break;
    case 7:
        printf("Odulunuz 32 puan!\n");
        *toplam+=32;
        break;
    case 8:
        printf("Odulunuz 64 puan!\n");
        *toplam+=64;
        break;
    case 9:
        printf("Odulunuz 128 puan!\n");
        *toplam+=128;
        break;
    case 10:
        printf("Odulunuz 256 puan!\n");
        *toplam+=256;
        break;
    default:
        printf("Uzgunuz odul kazanamadiniz.Sansinizi tekrar deneyin!\n");
        *toplam=*toplam;
        break;
    }
    printf("Su ana kadar on numara oyununda aldiginiz toplam odul:%d\n",*toplam);/*bu oyun cesidinin toplam puani
    hesaplanip yazdirilir*/
}

void sans_topu(int sans_frekans[],int sans_arti_frekans[],int *toplam)
{
    int sayi[6]= {0},i,j,k,l,tahmin,b_sayi[6]={0};
    int ekstra_tahmin=0,esas_tahmin=0;

    for (i=0; i<5; i++)//kullanicinin istenen kosullara uygun 5 sayi girmesi saglanir
    {
        printf("\n%d. sayi giriniz(1-34):",i+1);
        sayi[i]=sayi_al(1,34);

        for (j=0; j<i; j++)
        {
            if (sayi[i]==sayi[j])
            {
                printf("Hatali veri girisi yaptiniz.Lutfen tekrar giriniz.\n");
                i=i-1;
                j=j-1;
            }
        }
    }

    do//kullanicinin istenen kosullara uygun + sayi girmesi saglanir
    {
        printf("+ sayiyi giriniz(1-14)");
        scanf("%d",&sayi[5]);
    }
    while (sayi[5]>14 || sayi[5]<1);

    printf("Kucukten buyuge sayilar:\n");
    bubble_sort(sayi,4);//girilen 5 sayi siraya sokulur
    printf("+%d",sayi[5]);

    for (k=0; k<5; k++)//sansli 5 sayi uretilir
    {
        b_sayi[k]=1+(rand()%34);

        for (l=0; l<k; l++)
        {
            if (b_sayi[k]==b_sayi[l])
            {
                b_sayi[k]=1+(rand()%34);
            }
        }
    }
    for (k=0;k<5;k++)//uretilen sansli 5 sayinin frekanslari artirilir
        sans_frekans[b_sayi[k]-1]++;
    b_sayi[5]=1+(rand()%14);//sansli + sayi uretilir
    sans_arti_frekans[b_sayi[5]-1]++;//sansli + sayinin frekansi artirilir

    printf("\nSansli sayilar:\n");
    bubble_sort(b_sayi,4);//uretilen sansli 5 sayi siraya sokulur
    printf("+%d",b_sayi[5]);

    tahmin=tahmin_bul(b_sayi,sayi,5,5);//dogru tahmin sayisi belirlenir

    if (b_sayi[5]==sayi[5])//+sayinin dogru tahmin edilip edilmedigi kontrol edilir
        ekstra_tahmin=ekstra_tahmin+1;

    esas_tahmin=tahmin+ekstra_tahmin;
    printf("\nDogru tahmin sayiniz: %d+%d\n",tahmin,ekstra_tahmin);
    switch (esas_tahmin)//dogru tahmin sayisi icinde + dogru tahmin olup olmadigina gore odullendirilir
    {
    case 6:
        printf("Odulunuz 256 puan!\n");
        *toplam+=256;
        break;
    case 5:
        if (ekstra_tahmin==0)
        {
            printf("Odulunuz 128 puan!\n");
            *toplam+=128;
        }
        else if (ekstra_tahmin==1)
        {
            printf("Odulunuz 64 puan!\n");
            *toplam+=64;
        }
        break;
    case 4:
        if (ekstra_tahmin==0)
        {
            printf("Odulunuz 32 puan!\n");
            *toplam+=32;
        }
        else if (ekstra_tahmin==1)
        {
            printf("Odulunuz 16 puan!\n");
            *toplam+=16;
        }
        break;
    case 3:
        if (ekstra_tahmin==0)
        {
            printf("Odulunuz 8 puan!\n");
            *toplam+=8;
        }
        else if (ekstra_tahmin==1)
        {
            printf("Odulunuz 4 puan!\n");
            *toplam+=4;
        }
        break;
    case 2:
        printf("Odulunuz 2 puan!\n");
        *toplam+=2;
        break;
    default:
        printf("Uzgunuz odul kazanamadiniz.Sansinizi tekrar deneyin!\n");
        *toplam=*toplam;
        break;
    }
    printf("Su ana kadar sans topu oyununda aldiginiz toplam odul:%d\n",*toplam);/*bu oyun turunden alinan toplam puan
    hesaplanir ve yazdirilir*/
}

int tahmin_bul(int *array1,int *array2,int x,int y)//array1=b_sayi,array2=sayi,x=b_sayi dizisinin sayisi,y=sayi dizisinin sayisi
{
    int sayac,sayici,dogru_tahmin=0;

    for (sayac=0; sayac<x; sayac++)
    {
        for (sayici=0; sayici<y; sayici++)
        {
            if (array1[sayac]==array2[sayici])
                dogru_tahmin=dogru_tahmin+1;
        }
    }

    return dogru_tahmin;
}

void kabarcik_siralama(int v1[], int v2[], int eleman_say)//istatistiklerde kullanilan siralama
{
    //her geciste en alta inen (yani dogru konumuna gelen) elemanlari disarda tutarak ve hic yer degistirme olmazsa erken bitirerek
    int i=0;
    int gecis_say=0;
    int yer_degisti;
    do
    {
        gecis_say++;
        yer_degisti=0;
        for (i=0; i<eleman_say-gecis_say; i++)
        {
            if (v1[i]<v1[i+1])
            {
                yer_degistir(&v1[i],&v1[i+1]);
                yer_degistir(&v2[i],&v2[i+1]);
                yer_degisti=1;
            }
            else if ((v1[i]==v1[i+1]) && (v2[i]>v2[i+1]))
            {
                yer_degistir(&v2[i],&v2[i+1]);
                yer_degisti=1;
            }
        }
    }
    while(yer_degisti==1);
}

void yer_degistir(int *sayi1, int *sayi2)
{
    int gecici_sayi;

    gecici_sayi=*sayi1;
    *sayi1=*sayi2;
    *sayi2=gecici_sayi;
}


