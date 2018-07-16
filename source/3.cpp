#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tuyen_duong
{
    int x;
    int y;
    int dem;
    struct tuyen_duong *next;
}Tuyen_Duong;
Tuyen_Duong *head1 = NULL;
Tuyen_Duong *head2 = NULL;
void tao_node(int x,int y,int so_thu_tu,int loai_head)
{
    Tuyen_Duong *p;
    p = (Tuyen_Duong *)malloc(sizeof(Tuyen_Duong));
    p->x = x;
    p->y = y;
    p->dem = so_thu_tu;
    if(loai_head == 2)
    {
        p->next = head2;
        head2 = p;
    }
    else
    {
        p->next = head1;
        head1 = p;
    }

}
void them_node(Tuyen_Duong *p)
{
    Tuyen_Duong*x = p;
    x->next = head2;
    head2 = x;
}
void xoa(int i)
{
    Tuyen_Duong *x = head1;
    Tuyen_Duong *p = NULL;
    while( x->dem != i)
     {
         p = x;
         x = x->next;
     }
    if(x == head1)
    head1 = x->next;
    else
    p->next = x->next;
    free(x);
}
void in(Tuyen_Duong *head)
{
    FILE *fp;
    fp = fopen("OUTPUT.txt","a+");
    Tuyen_Duong *p = head;
    printf("%d",p->x);
    fprintf(fp,"%d ",p->y);
    while(p != NULL)
    {
        fprintf(fp,"%d ",p->x);
        p = p->next;

    }
    fclose(fp);
}
void tim_duong(int n,int u,int v)
{
    Tuyen_Duong *node1;
    Tuyen_Duong *node2 = (Tuyen_Duong *)malloc(sizeof(Tuyen_Duong));
    Tuyen_Duong *node3;
    int dem=0; int y;
    int co;
    node1 = head1;
    int i=0;
    while(node1 != NULL) // Duyệt head1
    {
        if1: if( node1->x == u)
		{
                dem =1;
				y = node1->y;
				tao_node(node1->x,node1->y,dem,2);
				xoa(node1->dem);
				node1 = head1;
			do{
				if(node1->x == y)
				{	dem++;
					y = node1->y;
					tao_node(node1->x,node1->y,dem,2);
					xoa(node1->dem);
					if(y == v)
					{
					    co = 1;
					    break;
                    }
					node1 = head1;
					if( dem >n ||node1->y == u) break;
                    node3 = head2;
					while(node3!= NULL)
                    {
                        if(node1->y == node3->x){
                                printf("vao roi nhe\n");
                        if(node3->next == NULL)
                            break;
                        else
                            head2 = head2->next;
                        }
                        node3 = node3->next;
                    }
				}
				else
				{
						node1 = node1->next;
						co = 0; //co = 0
						if(node1 == NULL)
                        {
                                node1 = head1;
                                if(head2->dem == 1)
                                   {
                                    head2 = NULL;
                                   }
                                else
                                {
                                    head2 = head2->next;
                                }
						}
						if(head2 == NULL) {goto if1;}
				}
			}while(node1 != NULL);
			if(co == 1) break;
		}
        if(co == 1)
        {
            break;
        }
        if(node1 != NULL)
        {
            node1 = node1->next;
        }
        if(co == 0 )
        {
            node2 = head2;
            node1 = head1;
            co = 2; // co =2
        }
    }
}
void main()
{
    int n,m,u,v;
    int x,y;
    int i;
    i = 0;
    char ten_file[100];
    printf("nhap vi tri luu file INPUT\n");
    fflush(stdin);
    gets(ten_file);
    FILE *p = fopen(ten_file,"a+");
    fscanf(p,"%d",&n);
    fscanf(p,"%d",&m);
    fscanf(p,"%d",&u);
    fscanf(p,"%d",&v);
    while(!feof(p))
    {
        i++;
        fscanf(p,"%d",&x);
        fscanf(p,"%d",&y);
        tao_node(x,y,i,1);
    }
    fclose(p);
    tim_duong(n,u,v);
    in(head2);
    return 0;
}
