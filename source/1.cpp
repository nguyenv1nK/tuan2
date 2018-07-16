#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ngoac
{
    char data;
    int t;
    struct Ngoac *next;
} Ngoac;
Ngoac *head = NULL;
Ngoac *tao_node(char a,int i)
{
    Ngoac *x = (Ngoac *)malloc(sizeof(Ngoac));
    x->data = a;
    x->t = i+1;
    return x;
}
void them(char a[])
{   int i;
    i = 0;
    do{

        Ngoac *x = (Ngoac *)malloc(sizeof(Ngoac));
        x = tao_node(a[i],i);
        i++;
        printf("%c ",x->data);
        x->next = head;
        head = x;
    }while(a[i] != '\0');
}
void Xoa(int i)
{
     Ngoac *x = head;
     Ngoac *p = NULL;
    while(x->t != i)
     {
         p = x;
         x = x->next;
     }
     if(p == NULL)
     {
         head = head->next;
     }
     else
     {
         p->next = x->next;
     }
     free(x);
}
void Kiem_tra()
{
    Ngoac *x = head;
    Ngoac *h;
    printf("\n");
    int j;
    j = 0;
    while(x != NULL)
    {
        if(x->data == ')')
        {
            for(h = x->next; h != NULL; h = h->next)
            {
                if(h->data == '(')
                {
                    j++;
                    Xoa(x->t);
                    Xoa(h->t);
                    break;
                }
            }
        }
        if( x->data == ']')
        {
            for(h = x->next; h != NULL; h = h->next)
            {

                if(h->data == '[')
                {
                    j++;
                    Xoa(x->t);
                    Xoa(h->t);
                    break;
                }
            }
        }
        x=x->next;
    }
}
void In()
{
    FILE *fp;
    fp = fopen("BRACKET.OUT","a+");
    int dem;
    dem =0;
    Ngoac *x = head;
    while(x != NULL)
    {   dem++;
        x = x->next;
    }
    fprintf(fp,"%d",dem);
    fprintf(fp,"\n");
    x = head;
    while(x != NULL)
    {
        if( x->data == '(')
        {
            fputc(')',fp);
            fprintf(fp,"%d",x->t);
            fputc('\n',fp);
        }
        else
        {
            if(x->data== ')')
               {
                   fputc('(',fp);
                    fprintf(fp,"%d",x->t);
                    fputc('\n',fp);

               }
            else
            {
                if( x->data == '[' )
                {
                    fputc(']',fp);
                    fprintf(fp,"%d",x->t);
                    fputc('\n',fp);
                }
                else
                {
                    fputc('[',fp);
                    fprintf(fp,"%d",x->t);
                    fputc('\n',fp);
                }
            }
        }

       x=x->next;
    }

}

void main()
{
    char a[100];
    char ten_file[100];
    FILE *p;
    printf("de nghi nhap ten file\( link file)\) \n");
    fflush(stdin);
    gets(ten_file);
    p = fopen(ten_file,"a+");
    if(p != NULL)
    {
        printf("thanh cong roi\n");
        fscanf(p,"%s",&a);
    }
    else
    {
        printf("khong tim thay file\n");
        return 0;
    }
    fclose(p);
    printf("%s\n",a);
    int z;
    int k;
    k = 1;
    int vol;
    for(z = 0;z < strlen(a); z++)
    {
        if( a[z] != '(' && a[z] != ')' && a[z] != '[' && a[z] != ']')
        {
             k = 0;
        }
    }
    if(k == 0)
        printf("de nghi chay lai chuong trinh va nhap dung theo yeu cau\n");
    else{
        them(a);
        Kiem_tra();
        In();
    }
}
