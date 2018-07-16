#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1000
FILE *kiem_tra_file(char *ten_file)
{
    int i,vol;
    printf("%s\n",ten_file);
    FILE *p = fopen(ten_file,"a+");
    if(p != NULL)
    {
        char x[1000];
        int co = 1;
        while(feof(p) != NULL)
        {
                fgets(x,1000,p);
                for(i = 0;i<strlen(x);i++)
                {
                    vol =x[i];
                    if(vol < 33 || vol == 127)
                    {
                        co = 1;
                        break;
                    }
                }
        }
        if(co == 2)
            printf("trong file chua ky tu khong hop le\n");
        else return p;
    }
    else printf("khong the tim thay file\n");
}
void nhap_ten_file(char *a[])
{
    printf("de nghi nhap ten file\n");
    fflush(stdin);
    gets(a);
}
void thay_the(char *str, const char *tu_cu, const char *tu_moi)
{
     char *p, tam[1000];
    int i = 0;
    int len;
    len = strlen(tu_cu);
    while ((p = strstr(str, tu_cu)) != NULL)
    {
        strcpy(tam, str);
        i = p - str;
        str[i] = '\0';
        strcat(str, tu_moi);
        strcat(str, tam + i + len);
    }
}

int so_lan_xuat_hien(char *ten_file,char tu_khoa[],char tu_thay_the[],int chuc_nang)
{
    char x[1000],tenFileTam[100]="file.tmp",tenFOut[100]= "OUTPUT.txt";
    int i;
    i = 0;
    int z;
    z = 0;
    int k;
    int co;
    int b;
    int x1;
    int x2;
    int dem_dong ;
    dem_dong = 0;
    FILE *p = kiem_tra_file(ten_file);
    FILE *pTam;
    FILE *fOut;
    fOut = kiem_tra_file(tenFOut);
    fputs(ten_file,fOut);
    fputs(" \n ",fOut);
    if(chuc_nang == 1)
    {
        fputs("chuc nang 1\n",fOut);
        fputs("tu khoa la: ",fOut);
        fputs(tu_khoa,fOut);
        fputs(" \n ",fOut);
    }
    else {
        fputs("chuc nang 2\n tu thay the la: ",fOut);
        fputs(tu_thay_the,fOut);
         fputs("tu khoa la: ",fOut);
        fputs(tu_khoa,fOut);
        fputs(" \n ",fOut);
    }
    printf("tu khoa la : %s\n",tu_khoa);
    pTam = fopen(tenFileTam,"a+");
    int dem_lan_xuat_hien;
    dem_lan_xuat_hien = 0;
    while( feof(p) == 0 )
    {
            fgets( x, 1000, p);
            dem_dong++;
            for(i = 0; i < strlen(x);i++)
            {
                x2 = tu_khoa[0];
                x1 = x[i];
                if(x1 == x2 || (x1-32)==x2 || (x1+32) == x2|| (x2-32) == x1 || (x2+32) == x1)
                {
                    z = i+1;
                    b = 1;
                    while(b < strlen(tu_khoa))
                    {
                        x1 = x[z];
                        x2 = tu_khoa[b];
                        if(x1 == x2 || (x1-32)==x2 || (x1+32) == x2|| (x2-32) == x1 || (x2+32) == x1)
                        {
                            b++;
                            z++;
                            co = 1;
                        }
                        else
                        {
                        co = 0;
                        break;
                        }
                    }
                    if(co == 1)
                    {
                        dem_lan_xuat_hien++;
                        printf("dong %d cach dau dong %d \n", dem_dong,i);
                        fputs("dong ",fOut);
                        fprintf(fOut,"%d",dem_dong);
                        fputs(" cach dau dong ",fOut);
                        fprintf(fOut,"%d",i);
                        fputs(" \n ",fOut);
                    }
                }
            }
            if(chuc_nang == 2)
            {

                thay_the(x,tu_khoa,tu_thay_the);
                fputs(x,pTam);
            }
    }
    fclose(p);
    fclose(pTam);
    if(chuc_nang == 2)
    {
        remove(ten_file);
        rename(tenFileTam,ten_file);
    }
    printf("so lan xuat hien la: %d \n",dem_lan_xuat_hien);
    fputs("so lan xuat hien la: ",fOut);
    fprintf(fOut,"%d",dem_lan_xuat_hien);
    fputs("\n",fOut);
    return 0;
}
void tim_kiem(char *ten_file,int chuc_nang)
{
    char tu_khoa[20];
    printf("de nghi nhap tu khoa\n");
    fflush(stdin);
    gets(tu_khoa);
    char tu_thay_the[20];
    if(chuc_nang == 2)
    {
        printf("tu de thay the la: \n");
        fflush(stdin);
        gets(tu_thay_the);
    }
    so_lan_xuat_hien(ten_file,tu_khoa,tu_thay_the,chuc_nang);
}
void main()
{
    char x[100];
    printf("nhap file ban muon tim\n");
    fflush(stdin);
    gets(x);
       int chuc_nang;
    do
    {

    printf("chuc nang:\n");
    printf("1: tim tu\n");
    printf("2: tim va sua tu\n");
    printf("3 ket thuc\n");
    printf("nhap chuc nang\n");
    scanf("%d",&chuc_nang);
    switch(chuc_nang)
    {
        case 1:
        case 2:
        tim_kiem(x,chuc_nang) ; break;
        case 3: break;
    }
    }while(chuc_nang != 3);
}
