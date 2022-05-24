//////////////////////////////////////////////////////////
//////////Banking Application Managemeny...///////////////
//////////////////////////////////////////////////////////
#include <stdio.h>
#include<malloc.h>
#include<string.h>
//Struct Creation.....
struct node
{
    char name[100];
    int age;
    int balance;
    int history[10];
    int summa;
    char history1[10];
    char username[100];
    char password[100];
}head[20];
int val=0;
////Account Creating function/////
void print()
{
    printf("Enter the CustomerName:\n");
    scanf("%s",head[val].name);
    printf("Customerage:\n");
    scanf("%d",&head[val].age);
    printf("Enter the username:\n");
    while(1)
    {
    int i=0,temp=0;
    char name[100];
    scanf("%s",name);
    if(val==0)
    {
        strcpy(head[val].username,name);
        break;
    }
    else
    {
    while(val>0 && i<val)
    {
        if(strcmp(head[i].username,name)==-1)
        {
         temp=0;   
        }
        else
        {
            temp=1;
            printf("Enter a valid username\n");
            break;
        }
        i++;
    }
    if(temp==0)
    {
        strcpy(head[val].username,name);
        break;
    }
    }
    }
    char s[100];
    printf("Enter the password:\n");
    while(1)
    {
    scanf("%s",s);
    int i=0,temp=0,temp1=0,temp2=0,temp3=0;
    while(i<strlen(s))
    {
        if(s[i]>=47 && s[i]<=56 && temp==0)
        {
            temp=1;
        }
        else if(s[i]>='A' && s[i]<='Z' && temp1==0)
        {
            temp1=1;
        }
        else if(s[i]>='a' && s[i]<='z' && temp2==0)
        {
            temp2=1;
        }
        else if(s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='^' && temp3==0)
        {
            temp3=1;
        }
        s[i]=s[i]+1;
        i++;
    }
    if(temp==1 && temp1==1 && temp2==1 && temp3==1)
    {
        strcpy(head[val].password,s);
        break;
    }
    else
    {
        printf("Enter the proper password\n");
    }
    }
    printf("Minimam amount is 1000:\n");
    scanf("%d",&head[val].balance);
    head[val].history[head[val].summa]=head[val].balance;
    head[val].history1[head[val].summa]='c';
    val++;
}
//////No of account holders show all users.......
void print1()
{
    int i=0;
    for(;i<val;i++)
    {
        printf("%s\n",head[i].username);
    }
}
/////Show the Transfer history to the perticular /////
void history(int p)
{
    int i=0;
    while(i<=head[p].summa)
    {
        printf("%d    %c\n",head[p].history[i],head[p].history1[i]);
        i++;
    }
    printf("The total amount is:%d\n",head[p].balance);
}
//////One account to another account money transfer/////
void transfer(int p)
{
    char s[100];
    int i=0,transferamount=0;
    printf("Benifierary account Username:\n");
    scanf("%s",s);
    while(i<=val)
    {
        if(strcmp(head[i].username,s)==0)
        {
            printf("Tranfered Amount:\n");
            scanf("%d",&transferamount);
            if(head[p].balance-transferamount>=1000)
            {
            head[i].summa++;
            head[p].summa++;
            head[i].balance=head[i].balance+transferamount;
            head[i].history[head[i].summa]=transferamount;
            head[i].history1[head[i].summa]='c';
            head[p].balance=head[p].balance-transferamount;
            head[p].history[head[p].summa]=transferamount;
            head[p].history1[head[p].summa]='d';
            }
            else{
                i--;
            }
        }
        i++;
    }
}
////Login.......//////
void print2()
{
    char a[100],b[100];
    printf("Enter the Username\n");
    scanf("%s",a);
    printf("Enter the Password:\n");
    scanf("%s",b);
    int i=0;
    for(;i<val;i++)
    {
        
        if(strcmp(a,head[i].username)==0)
        {
            if(strlen(b)==strlen(head[i].password))
            {
                char s[100];
                strcpy(s,head[i].password);
                int j=0;
                while(b[j]==s[j]-1 && j<strlen(b))
                {
                    printf("%s",head[i].username);
                    j++;
                }
                if(j==strlen(b))
                {
                    printf("account varified...");
                    while(1)
                    {
                    printf("1.credit\n2.depit\n3.History\n4.Transfer\n5.logout\n");
                    int value,temp=0;
                    scanf("%d",&value);
                    switch(value)
                    {
                        case 1:
                        {
                            int newamount;
                            head[i].summa++;
                            scanf("%d",&newamount);
                            head[i].balance=head[i].balance+newamount;
                            head[i].history[head[i].summa]=newamount;
                            head[i].history1[head[i].summa]='c';
                            break;
                        }
                        case 2:
                        {
                            
                         int newdepit;
                         scanf("%d",&newdepit);
                         if(head[i].balance-newdepit>=1000)
                         {
                             head[i].summa++;
                             head[i].balance=head[i].balance-newdepit;
                             head[i].history[head[i].summa]=newdepit;
                             head[i].history1[head[i].summa]='d';
                             break;
                         }
                         else
                         {
                             printf("Amount bound\n");
                             break;
                         }
                         break;
                        }
                        case 3:
                        {
                            history(i);
                            break;
                        }
                        case 4:
                        {
                            transfer(i);
                            break;
                        }
                        case 5:
                        {
                            temp=1;
                            break;
                        }
                    }
                    if(temp==1)
                    {
                        printf("Successfully Logout...");
                        break;
                    }
                    }
                    
                }
            }
            else
            {
                printf("Password dos't match...");
            }
        }
        else
        {
            printf("The user not in Database...");
        }
    }
}
int main()
{
    int a;
    while(1)
    {
        printf("1.create\n2.print\n3.Login\n4.exit\n");
        int a,temp=0;
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            {
                print();
                break;
            }
            case 2:
            {
                print1();
                break;
            }
            case 3:
            {
                
                print2();
                break;
            }
            case 4:
            {
                temp=1;
                break;
            }
        }
        if(temp==1)
        {
            break;
        }
    }
    return 0;
}
