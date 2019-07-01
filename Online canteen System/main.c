#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
//#include<time.h>

COORD coord={0,0};
struct user_register
{
    char username[10];
    char password[10];
    char address[50];
    int amount;
};
struct table
{
    int table_number;
    char status[20];
};
int num_char();
void table(struct user_register);
void edit(struct user_register,int);
void menu(struct user_register);
void account(struct user_register);
void tableform();
void login();
//void time_show();
void gotoxy(int,int);
void order();
void about_us();
void registeration();


/*void time_show()
{
    time_t timer;
    printf("current time is %s",ctime(&timer));
}*/

void gotoxy(int x,int y)
{
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// Code to form the First Page
void tableform()
{
    int i;
    for(i=0;i<54;i++)
        printf("___");
        printf(" \n");
        for(i=0;i<20;i++)
        printf("|\n");
        for(i=0;i<54;i++)
        printf("___");
        gotoxy(162,6);
         for(i=0;i<21;i++)
         {gotoxy(162,7+i);
        printf("|");}
        gotoxy(2,7);
        for(i=0;i<53;i++)
        printf("~$~");
        printf("\n");
        gotoxy(6,10);
        printf("1.LOG IN");
        gotoxy(70,10);
        printf("2.REGISTER");
        gotoxy(140,10);
        printf("3.ORDER\n\n");
         for(i=0;i<54;i++)
        printf("!^!");
        gotoxy(70,20);
        printf("4.ABOUT US\n\n");
        for(i=0;i<81;i++)
        printf("/\\");
        printf("\n\n\n\n");
        for(i=0;i<54;i++)
        printf("~$~");
          gotoxy(60,40);
      //time_show();
        }


        //Code to register a user
        void registeration()
        {
            FILE *f;
            struct user_register user1,user2;
            printf("Enter your username");
            scanf("%s",user1.username);
            printf("Enter your password");
            scanf("%s",user1.password);
            printf("Enter your address.please enter your address without space. use underscore");
           scanf("%s",user1.address);
            user1.amount=5000;
             int c=0;
           f=fopen("User.txt","r");
              while(!feof(f)){

        fscanf(f,"%s %s %s %d\n",user2.username,user2.password,user2.address,&user2.amount);


         if(strcmp(user2.username,user1.username)==0)
            {
       printf("Sorry this username is already registered");
       fclose(f);
       c=1;
       break;
                  }}


    if(c==0){
     f=fopen("User.txt","a");
     fprintf(f,"%s %s %s %d\n",user1.username,user1.password,user1.address,user1.amount);
         fclose(f);
         }

            int cback;
            printf("\nEnter 1 to login otherwise press any key to exit\n");
            scanf("%d",&cback);
            if(cback==1)
            {
                login();
            }
            else
                exit(0);

        }



   // Here is the main function

int main()
{
    int ch,code;
    system("color 4e");
    gotoxy(50,5);
    printf("!!!!!!!!!!!!!*********WELCOME TO FOOD PLAZA***********!!!!!!!!!!!!!!\n");
    gotoxy(0,6);
    tableform();
    gotoxy(2,30);
    printf("SELECT THE OPTION DESIRED:");
    ch=getch();
    if(ch==49)
    {
        system("cls");

      login();

      gotoxy(60,10);
  //    time_show();
    }
    else if(ch==50)
    {
        printf("Enter the registration code provided by food plaza\n");
        scanf("%d",&code);
        if(code==338 || code==2227 || code==2731)
            {
        system("cls");
    registeration();
    }
    else
        printf("Sorry entered code is wrong");

    }
    else if(ch==51)
    {
        system("cls");
        order();
    }
    else if(ch==52)
    {
        system("cls");
        about_us();
    }
    else
    {system("cls");
        printf("Sorry Option not available");
    return 0;
}
}
int num_char(char file[10])
{
  FILE *fp;
  fp=fopen(file,"r");
  int count=0;
  char c;
  while(1)
  {
      c=fgetc(fp);
      if(c==EOF)
      {
          break;
      }
      count++;
  }
  fclose(fp);
  return count;
}
 void edit(struct user_register user4,int remain_bal)
        {
            struct user_register user5;
            FILE *f;
            int nC,n=0,c=1;
            nC = num_char("User.txt");

            char string[nC+2];
            f=fopen("User.txt","r");
            while(!feof(f))
            {
                char buff[1024];
                fgets(buff,1024,f);
               sscanf(buff,"%s %s %s %d",user5.username,user5.password,user5.address,&user5.amount);
                   if(strcmp(user5.username,user4.username)==0&&strcmp(user5.password,user4.password)==0&&c==1)
                {
                    printf("Your bill has been paid,your remaining balance is %d\n",remain_bal);
                    user5.amount=remain_bal;
                    c=2;
                }

                 sprintf(buff,"%s %s %s %d\n",user5.username,user5.password,user5.address,user5.amount);
                 if(n==0){
                        strcpy(string,buff);
                 n=1;
                 } else {
                     strcat(string,buff);
                 }

            }

               fclose(f);
               f = fopen("User.txt","w");
               fprintf(f,"%s",string);
               fclose(f);

}



//code to make the menu
void menu(struct user_register user4)
{
 int i,option,option2,remain_bal;
 FILE *fp;
 char add[50];
 for(i=0;i<3;i++)
 printf("\t");
 printf("MENU\n");
 printf("ITEM");
 for(i=0;i<6;i++)
 printf("\t");
 printf("PRICE");
 printf("\n");
 printf("\n");
 printf("1.BURGER");
 for(i=0;i<5;i++)
 printf("\t");
 printf("RS.50\n");
 printf("2.PIZZA");
 for(i=0;i<6;i++)
 printf("\t");
 printf("RS.80\n");
 printf("3.TEA");
 for(i=0;i<6;i++)
 printf("\t");
 printf("RS.15\n");
 printf("4.COFEE");
 for(i=0;i<6;i++)
 printf("\t");
 printf("RS.20\n");
 printf("5.SANDWICH");
 for(i=0;i<5;i++)
 printf("\t");
 printf("RS.45\n");
 printf("6.CHIPS");
 for(i=0;i<6;i++)
 printf("\t");
 printf("RS.10\n");
 printf("7.NOODLES");
 for(i=0;i<5;i++)
 printf("\t");
 printf("RS.60\n");
 printf("8.FRENCH FRIES");
 for(i=0;i<5;i++)
 printf("\t");
 printf("RS.80\n");
 printf("9.MANCHURIAN");
 for(i=0;i<5;i++)
 printf("\t");
 printf("RS.75\n");
 printf("10.GARLIC BREAD");
 for(i=0;i<5;i++)
 printf("\t");
 printf("RS.50\n");

 int c,ch;
 int amt=0;
 do
{
    printf("enter your order: ");
    scanf("%d",&c);
    switch(c)
    {
       case 1: amt=amt+50;
        break;
        case 2: amt=amt+80;
        break;
        case 3: amt=amt+15;
        break;
        case 4: amt=amt+20;
        break;
        case 5: amt=amt+45;
        break;
        case 6: amt=amt+10;
        break;
        case 7: amt=amt+60;
        break;
        case 8: amt=amt+80;
        break;
        case 9: amt=amt+75;
        break;
        case 10: amt=amt+50;
        break;
        default:
        printf("Your order doesn't exist.");
        break;
    }
    printf("Do you want anything else?1 for yes or 2 for no: ");
    scanf("%d",&ch);
  }while(ch==1);
   printf("Total Amount:" "%d",amt);
   printf("\n");
   printf("Do you want to paid by your online wallet, If yes press 1, otherwise pay offline");
   scanf("%d",&option);
   if(option==1)
   {
       remain_bal=(user4.amount-amt);
   edit(user4,remain_bal);
   printf("Do you want home delivery or Enter address,if home delivery then press 1,and if want to enter address then 2.\nIf you want to enter address then don't use space, use underscore\n");
                    scanf("%d",&option2);
                    if(option2==1)
                   {
                       printf("Your order will be delivered to this address\n");
                     printf("%s",user4.address);
                     printf("\nThank you for visiting our canteen\n");

                     }
                     else if(option2==2)
                     {
                         printf("Enter the address where order to deliver\n");
                         scanf("%s",add);
                         printf("\nYour order will be deliver to %s\n",add);
                     }
                     else
                        printf("\nWrong input");
                }
                int cback;
                printf("If you want to go in login page back press 1 otherwise press any key to exit");
                scanf("%d",&cback);
                if(cback==1)
                {
                    login();
                }
               exit(1);
   }




  // Code for making the table
void table(struct user_register user6)
{
    FILE *f;
    int z,m=0,remain_bal,k;
    int table_num;
struct table table2;

int num,n;
char buff[1024];

 char file[10];
    system("cls");
    printf("\t\t");
    printf("**********TABLE*********");
    printf("\n\n\n");
    printf("TABLE\t\t\t\t");
    printf("SEATER\t\t\t\t");
    printf("PRICE\n");
    printf("\n");
    for(z=0;z<80;z++)
        printf("-");
    printf("\n");
    for(z=1;z<5;z++)
    {
        printf("%d\t\t\t\t",z);
        printf("2\t\t\t\t");
        printf("800\n\n\n");
        for(k=0;k<80;k++)
            printf("-");
            printf("\n");
    }
for(z=5;z<9;z++)
{
     printf("\n%d\t\t\t\t",z);
        printf("3\t\t\t\t");
        printf("500\n\n");
        int k;
        for(k=0;k<80;k++)
            printf("-");

}
for(z=9;z<11;z++)
{
     printf("\n%d\t\t\t\t",z);
        printf("4\t\t\t\t");
        printf("300\n\n");
        int k;
        for(k=0;k<80;k++)
            printf("-");
}

printf("\nEnter the Table Number to book");
scanf("%d",&table_num);
strcpy(file,"table.txt");
  num=num_char(file);
    char string[num+5];
switch(table_num)
{
case 1:
    printf("Enter 1 for table booking,your bill will be deducted from your food plaza account ");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==1)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-800);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
case 2:
     printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==2)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-800);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
case 3:
     printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==3)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-800);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
    case 4:
     printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==4)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-800);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
    case 5:
         printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==5)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-500);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
    case 6:
         printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==6)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-500);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
    case 7:
         printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==7)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-500);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
    case 8:
         printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==8)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-500);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
    case 9:
         printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==9)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-300);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;
    case 10:
         printf("Enter 1 for table booking,your bill will be deducted from your food plaza account");
    scanf("%d",&n);

    if(n==1)
    {
        f=fopen(file,"r");
        fflush(f);
        while(!feof(f))
        {
            fgets(buff,1024,f);
            sscanf(buff,"%d %s\n",&table2.table_number,table2.status);
            if(table2.table_number==10)
            {
                 if(strcmp(table2.status,"Booked")==0)
                {
                    printf("Sorry this table is not available");
                    exit(1);
                }
                printf("Your table is booked");
                remain_bal=(user6.amount-300);
                edit(user6,remain_bal);
               strcpy(table2.status,"Booked");

            }

            sprintf(buff,"%d %s\n",table2.table_number,table2.status);
           if(m==0)
           {
               strcpy(string,buff);
               m=1;
           }
           else
           {
               strcat(string,buff);
           }
        }
        fclose(f);
        f=fopen("table.txt","w");

        fprintf(f,"%s",string);

        fclose(f);

    }
    break;

}
int cback;
printf("Press 1 if you want to go back to login page or press 2 to book table again otherwise press any other key to exit");
scanf("%d",&cback);
if(cback==1)
{
    login();
}
else if(cback==2)
{
    table(user6);
}
else
exit(1);
}

//Code for account
void account(struct user_register user)
{ int cback;
    system("cls");
    printf("Your Current balance is %d\n",user.amount);
    printf("Enter 1 to back to login page otherwise press any key to exit");
    scanf("%d",&cback);
    if(cback==1)
    {
        login();
    }
    else
    exit(1);
}

//Code to Login
void login()
{
    struct user_register user2,user3;
    FILE *f;
    int choice;
    char string[1024];
    system("cls");
    printf("Enter Your Username\n");
    scanf("%s",user2.username);
    printf("Enter you password");
    scanf("%s",user2.password);
    f=fopen("User.txt","r+");
    int initstat=0;

   while(!feof(f)){

        fscanf(f,"%s %s %s %d",user3.username,user3.password,user3.address,&user3.amount);

    if(strcmp(user2.username,user3.username)==0 && strcmp(user2.password,user3.password)==0)
     {
         restart:
         system("cls");
         printf("\t\t\t1.MENU\n");
         printf("\t\t\t2.TABLE BOOKING\n");
         printf("\t\t\t3.Account Balance\n");
         printf("Enter Your choice Number");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
        menu(user3);
        initstat=1;
        break;
        case 2:
      table(user3);
        initstat=1;
        break;
        case 3:
        account(user3);
        initstat=1;
            break;
         }
     }
   }
    if(initstat==0){
        printf("\nNo such username or password.\n");
    }
    exit(0);
  }

//order
void order()
{
    FILE *f;
    int n,i;
    char address[50];
    f=fopen("order.txt","r");
    char String[1024];
    while(!feof(f))
    {
        fgets(String,1024,f);
        printf("%s",String);
    }

printf("\nHome delivery is only available for registered users\n");
printf("Thank you for visiting");
}




void about_us()
{
    FILE *f;
    char String[1024];
    f=fopen("About_us.txt","r");
    while(!feof(f))
    {
        fgets(String,1024,f);
        printf("%s",String);
    }
}



