#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// List and function Declaration

int rooms[10];
char names[10];
int phones[10];
char addresses[10];
void Home();
void RoomBooking();
void RoomCancellation();
void RoomInfo();
void Search();
void Feedback();
void MenuCard();
int FoodOrder();
int Discount(int r);
void BillGenerate(int r,int d);

//Home Function
void Home()
{
    printf("-------- WELCOME TO HOTEL RAJMAHAL--------\n");
    printf("what would you like to do today?\n");
    printf("1. Room Booking\n");
    printf("2. Food Order\n");
    printf("3. Room Cancellation\n");
    printf("4. Room Info\n");
    printf("5. Search customer\n");
    printf("6. Feedback\n");
    printf("7. Exit\n");
    int ch;
    printf("Enter your choice:");
    scanf("%d",&ch);

    if (ch == 1)
        RoomBooking();
	
    if (ch == 2)
        FoodOrder();
	
    if (ch ==3)
        RoomCancellation();

    if (ch == 4)
        RoomInfo();

    if (ch == 5)
        Search();

    if (ch == 6)
        Feedback();

    if (ch==7)
        exit(0);
}

// RoomBooking

void RoomBooking()
{
    printf("----ROOM BOOKING---- ");
    char name[20],address[20];
    int phone,room ;
    printf("\nEnter your Name:\n ");
    scanf("%s",&name);
    printf("Enter your Phone No.:\n ");
    scanf("%d",&phone);
    printf("Enter your Address:\n ");
    scanf("%s",&address);
    printf("enter room number\n");
    scanf("%d",&room);
    int len=sizeof(rooms)/sizeof(int);
    int i,flag;
    for(i=0;i<len;i++)
       {
         if (rooms[i]==room)
         flag=0;
         else
         flag=1;
       }
     if (flag==1)
      {
        names[len]=name;
        phones[len]=phone;
        rooms[len]=room;
        addresses[len]=address;

        printf("Room booked successfully\n\n\n");
      }

    else 
       { printf("Room already booked!\n\n\n ");}
    Home();
}

// RoomCancellation
void RoomCancellation()
{
    int r,i,j;
    printf("Enter your room no.\n"); 
    scanf("%d",&r);  
    int len=sizeof(rooms)/sizeof(int);  
    for(i=0;i<len;i++)
    {  
      if (rooms[i]==r)
         {
           for(j=i;j<len;j++)
            {
              rooms[j+1]=rooms[j];
              names[j+1]=names[j];
              addresses[j+1]=addresses[j];
              phones[j+1]=phones[j];
            }
           printf("Room cancelled successfully\n\n\n");
         break;
         }
     else
        {printf("Room not booked!!\n\n\n");}
    }
    Home();
}

// RoomInfo
void RoomInfo()
{
    int i;
    printf(" -----Room Info-----\n");
    int len=sizeof(rooms)/4;  
    if (len!=0)
        {
          for(i=0;i<len;i++)
           { printf("Room No.=%d",rooms[i]," Name=%s",names[i],"; Phone No.=%d",phones[i],"; Address=%s",addresses[i]);}
            printf("----------------------------------------------------------------");}
    else
        {printf("No Rooms booked!!!\n\n\n");}
    Home();
}

//Search Coustomer
void Search()
{
    char n[20];
    printf("Enter your Name:");
    scanf("%s",&n);
    int len=(sizeof(names))/(sizeof(char));
    int i,flag;
    for(i=0;i<len;i++)
       {
         if (names[i]==n)
         flag=0;
         else
         flag=1;
       }
        if (flag==0)
        {printf("Name=%s",names[i]," Room No.=%d",rooms[i]," Phone No.=%d",phones[i]," Address=%s",addresses[i]);}
        else
        {printf("No entry of name %s",n);}
}

// MenuCard
void MenuCard()
   {     
	printf("-----Menu Card-----\n\n\n");
	printf(" 1 Regular Tea............. 20.00");
	printf(" 2 Masala Tea.............. 25.00");
	printf(" 3 Coffee.................. 25.00");
	printf(" 4 Cold Drink.............. 25.00");
	printf(" 5 Bread Butter............ 30.00");
	printf(" 6 Bread Jam............... 30.00");
	printf(" 7 Veg. Sandwich........... 50.00");
	printf(" 8 Veg. Toast Sandwich..... 50.00");
	printf(" 9 Cheese Toast Sandwich... 70.00");
	printf(" 10 Grilled Sandwich........70.00");
	printf(" 11 Tomato Soup............ 100.00");
	printf(" 12 Hot & Sour............. 100.00");
	printf(" 13 Veg. Noodle Soup....... 100.00");
	printf(" 14 Sweet Corn............. 100.00");
	printf(" 15 Veg. Munchow........... 100.00");
	printf(" 16 Shahi Paneer........... 100.00");
	printf(" 17 Kadai Paneer........... 100.00");
	printf(" 18 Handi Paneer........... 120.00");
	printf(" 19 Palak Paneer........... 120.00");
	printf(" 20 Chilli Paneer.......... 120.00\n");
	
  }

//Food Order
int FoodOrder()
   {
              MenuCard();
              int ch=1,r=0,rs;
             
              while (ch!=0)
             {
                printf("Enter item no. or else enter 0:");
                  scanf("%d",&ch);
                  if (ch==1)
                      {rs=20;
                      r=r+rs;}
                  else if (ch<=4 && ch>=2)
                      {rs=25;
                      r=r+rs;}
                  else if (ch<=6 && ch>=5)
                      {rs=30;
                      r=r+rs;}
                  else if (ch<=8 && ch>=7)
                      {rs=50;
                      r=r+rs;}
                  else  if (ch<=10 && ch>=9)
                      {rs=70;
                      r=r+rs;}
                  else if (ch<=17 && ch>=11)
                      {rs=100;
                      r=r+rs;}
                  else if (ch<=20 && ch>=18)
                      {rs=120;
                      r=r+rs;}
                  else  if (ch==0)
                      {printf("Total Bill:%d ",r);
                      Discount(r);}
                  else
                      {printf("Wrong Choice..!!");}
             }
  }

//Discount
int Discount(int r)
{ 
    int d;
    if (r>=200)
       { printf("Congratulations!!! you get discount of 10 percent.");
        d=10;}
    if (r>=100)
       { printf("Congratulations!!! you get discount of 5 percent ");
        d=5;}
    else
        {d=0;}
    BillGenerate(r,d);
}   
  
//BillGenerate
void BillGenerate(int r,int d)
{
    printf("\n---Bill Generate---");
    char name[20];
    printf("Enter your Name: ");
    scanf("%s",&name);
    int phone;
    printf("Enter your Phone No.: ");
    scanf("%d",&phone);
    printf("\n-------HOTEL RAJMAHAL--------\n");
    printf("Sudama Nagar, Indore\n");
    printf("contact no.- 123456\n\n");
    time_t t;
    time(&t);
    printf("Bill no.=%d",rand());
    printf("\nName-%s",name);
    printf("phone-%d",phone);
    printf("\nyour total bill is Rs.%d\n ",r);
    int dis=r*d/100;
    printf("discount=%d\n",dis);
    printf("amount payble: Rs. %d\n",r-dis);
    printf("\nThank you!!!!\nVisit again!!!");
    exit(0);
}

//Feedback
void Feedback()
{
    printf("\nHow many stars would you give to Hotel Rajmahal(out of 5)");
    int ch,i;
    printf("\nEnter your rating");
    scanf("%d",&ch);
    if (ch>5)
       { printf("Please give rating out of 5");
        Feedback();}
    else
       { printf("your rating is: ");
        for(i=0;i<ch;i++)
            printf("*"); }    
}
int main() {
    Home();
}
