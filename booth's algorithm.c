//program to perform booth algorithm

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>

void booth(int*,int*,int*);
void  comp(int*,int,int);
void ncomp(int*,int);
char* print(int);
void shift(int*,int*,int);
int deci(int*);

void main()
{
    printf("COA Project:BOOTH's ALGORITHM\nDone By:\n1.NAVIN THOMAS:12CO60\n2.MUKUND Y.R:12CO58\n3.R.M SUMUKHA:12CO67\n4.SURAJ KRISHNAN RAJAN:12CO94\nPress any key to continue.");
    getch();
    int ch;
    do
    {
        int a[8]={0},b[9]={0},dec1,dec2,ab,i=0,j=0,arr[16],ans,c[8]={0};
        system("cls");
        printf("\nEnter two decimal numbers:");
        scanf("%d %d",&dec1,&dec2);
        if(dec1<0)
            comp(a,-dec1,8);

        else
            ncomp(a,dec1);

        if(dec2<0)
            comp(b,-dec2,8);

        else
            ncomp(b,dec2);

        booth(a,b,c);
        for(i=0;i<8;i++)
            arr[i]=c[i];
        for(j=0;j<8;j++)
            arr[i+j]=b[j];
        if(((dec1>0)&&(dec2>0))||((dec1<0)&&(dec2<0)))
            ans=deci(arr);
        else
        {
            comp(arr,-999,16);
            ans=deci(arr);
            ans=-ans;
        }
        printf("\n\nThe answer of %d*%d=%d",dec1,dec2,ans);
        printf("\n\nPress 1 to continue:");
        ch=getch();
    }while(ch==1+'0');
}

void ncomp(int ar[],int a)
{
    int p=a;
    int i=7;
        while(p!=0)
        {
            ar[i--]=p%2;
            p=p/2;
        }
}

void comp(int ar[],int a,int max)
{
    int i=7,j=1;
    int p=a;
    if(a!=-999)
    {
        while(p!=0)
        {
            ar[i--]=p%2;
            p=p/2;
        }
    }
    for(i=0;i<max;i++)
    {
        if(ar[i]==0)
            ar[i]=1;
        else
            ar[i]=0;
    }
    i--;
    while(((ar[i]+1)==2)&&(i!=0))
        ar[i--]=0;
    ar[i]=1;
}

void booth(int a[],int b[],int c[])
{
    int i=1,j,k;
    printf("\nStep\tAction\t\t\tAccumulator\t\tRegister Q\n");
    for(k=0;k<=40;k++)
        printf("--");

    printf("\n");
    printf("0\t%s\t",print(0));
    for(j=0;j<8;j++)
        printf("%d",c[j]);

    printf("\t\t");

    for(j=0;j<8;j++)
        printf("%d",b[j]);

    printf("\n\n");

    printf("\t%s\t\t",print(1));

    for(j=0;j<8;j++)
        printf("%d",c[j]);

    printf("\t\t");

    for(j=0;j<9;j++)
        printf("%d",b[j]);

    printf("\n");
    int u;
    for(u=0;u<=40;u++)
        printf("--");
    printf("\n");
    while(i<=8)
    {
        int k,l,n=0;
        printf("%d",i);
        if((b[7]==1)&&(b[8]==0))
        {
            printf("\t\t\t\t");
            for(k=0;k<8;k++)
                printf("%d",a[k]);
                printf("\n");
            printf("\t%s\t",print(2));
            int e[8],h;
            for(h=0;h<8;h++)
                e[h]=a[h];
            comp(e,-999,8);
            for(k=7;k>=0;k--)
            {
                if((n+c[k]+e[k])==0)
                {
                    n=0;
                    c[k]=0;
                }
                else if((n+c[k]+e[k])==1)
                {
                    n=0;
                    c[k]=1;
                }
                else if((n+c[k]+e[k])==2)
                {
                    n=1;
                    c[k]=0;
                }
                else
                {
                    n=1;
                    c[k]=1;
                }
            }
            for(k=0;k<8;k++)
                printf("%d",c[k]);
            printf("\t\t");
            for(k=0;k<9;k++)
                printf("%d",b[k]);
                printf("\n");

            if(i==8)
                break;
            shift(c,b,c[0]);
            printf("\n\t%s\t\t",print(3));
            for(k=0;k<8;k++)
                printf("%d",c[k]);
            printf("\t\t");
            for(k=0;k<9;k++)
                printf("%d",b[k]);
            printf("\n");
        }
        else if((b[7]==0)&&(b[8]==1))
        {
            n=0;
            printf("\t\t\t\t");
            for(k=0;k<8;k++)
                printf("%d",a[k]);
                printf("\n");
            for(k=7;k>=0;k--)
            {
                if((n+c[k]+a[k])==0)
                {
                    n=0;
                    c[k]=0;
                }
                else if((n+c[k]+a[k])==1)
                {
                    n=0;
                    c[k]=1;
                }
                else if((n+c[k]+a[k])==2)
                {
                    n=1;
                    c[k]=0;
                }
                else
                {
                    n=1;
                    c[k]=1;
                }
            }
            printf("\t%s\t\t",print(4));
            for(k=0;k<8;k++)
                printf("%d",c[k]);
            printf("\t\t");
            for(k=0;k<9;k++)
                printf("%d",b[k]);
                printf("\n\n");

                if(i==8)
                    break;

            shift(c,b,c[0]);
            printf("\t%s\t\t",print(3));
            for(k=0;k<8;k++)
                printf("%d",c[k]);
            printf("\t\t");
            for(k=0;k<9;k++)
                printf("%d",b[k]);
            printf("\n");
        }
        else
        {
            printf("\t%s\t",print(5));
            for(k=0;k<8;k++)
                printf("%d",c[k]);
            printf("\t\t");
            for(k=0;k<9;k++)
                printf("%d",b[k]);
                printf("\n\n");
                if(i==8)
                    break;
            shift(c,b,c[0]);
            printf("\t%s\t\t",print(3));
            for(k=0;k<8;k++)
                printf("%d",c[k]);
            printf("\t\t");
            for(k=0;k<9;k++)
                printf("%d",b[k]);
            printf("\n");


        }
        i++;
        int z;
        for(z=0;z<=40;z++)
                printf("--");
                printf("\n");

    }
    b[7]=0;
    printf("\t%s\t\t",print(6));
    int m;
    for(m=0;m<8;m++)
        printf("%d",c[m]);
    printf("\t\t");
    for(m=0;m<9;m++)
        printf("%d",b[m]);

}
char* print(int a)
{
    if(a==0)
        return("Initialize Registers");

    else if(a==1)
        return("Set Q[-1] to 0");

    else if(a==2)
        return("Subtract M from A");

    else if(a==3)
        return("Right shift A.Q");

    else if(a==4)
        return("Add M to A");

    else if(a==5)
        return("Skip Add/Subtract");

    else if(a==6)
        return("Set Q[0] to 0");
}

void shift(int a[],int b[],int d)
{
    int i,j;
    for(i=7;i>=0;i--)
        b[i+1]=b[i];
    b[0]=a[7];
    for(j=6;j>=0;j--)
        a[j+1]=a[j];
    a[0]=d;
}




int deci(int a[])
{
    int abc=0,i,j;
    for(i=0,j=14;i<16,j>0;i++,j--)
        abc+=pow(2,i)*a[j];

    return abc;
}
