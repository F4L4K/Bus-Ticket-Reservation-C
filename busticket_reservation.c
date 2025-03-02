#include<stdio.h> //bus ticket reservation(final)
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct bus_reservation
{
    char name[100];
    int bus_num;
    int seat_num;
    int available_seats;
} bus;

void bus_reserve();
void details();
void ticket(char name[], int a, int b, float x);
void selected_bus(int y);
float price(int b, int s);
int main()
{


    int choice;
    do
    {

        printf("\n\t\t\t=====BUS TICKET MANAGEMENT SYSTEM=====");
        printf("\n\n\n\t\t\t\t     1.Book Tickets\n");
        printf("\t\t\t\t     2.Bus List\n");
        printf("\t\t\t\t     3.Exit\n");
        printf("\t\t\t\t    ___\n");
        printf("\t\t\t\t     ");
        printf("\n\n ENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            bus_reserve();
            break;
        case 2:
            details();
            break;
        case 3:
            printf("\n\t\t\t\t  Press any key to exit\n");
            break;
        }
        getch();
    }
    while(choice!=5);
    return 0;
}

void bus_reserve(void)
{
    char confirm;
    int i=0;
    float cost;
    FILE *fptr;
    fptr=fopen("seats_reserved.txt","a");
    system("cls");

    printf("\nEnter Your Name: ");
    fflush(stdin);
    gets(bus.name);

    printf("\nEnter number of seats: ");
    scanf("%d",&bus.seat_num);
    printf("\n\n>>Press Enter To View Available Bus<< ");
    getch();
    system("cls");
    details();
    printf("\n\nEnter bus number: ");

start1:
    scanf("%d",&bus.bus_num);
    if(bus.bus_num==194210 || bus.bus_num==194220 || bus.bus_num==194230|| bus.bus_num==194240|| bus.bus_num==194250 )
    {
        cost=price(bus.bus_num,bus.seat_num);
        ticket(bus.name,bus.seat_num,bus.bus_num,cost);
    }
    else
    {
        printf("\nInvalid bus Number! Enter again-> ");
        goto start1;
    }

    printf("\n\nConfirm Ticket (y/n):");
start:
    scanf(" %s",&confirm);
    if(confirm == 'y')
    {
        fprintf(fptr,"%s\t\t%d\t\t%d\t\t%.2f\n",&bus.name,bus.seat_num,bus.bus_num,cost);
        printf("==================");
        printf("\n Reservation successful\n");
        printf("==================");
        printf("\nPress any key to go back to Main menu");
    }
    else
    {
        if(confirm=='n')
        {
            printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
        }
        else
        {
            printf("\nInvalid choice entered! Enter again-> ");
            goto start;
        }
    }
    fclose(fptr);
    getch();
}

void details()
{
    char ch;
    FILE *fptr;
    if((fptr=fopen("D:\\bus.txt","r"))== NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (1)
    {
        ch = fgetc(fptr);

        if (ch == EOF)
            break;
        printf("%c", ch);
    }
    printf("\n\nPress any key to go back");
    fclose(fptr);
    return;
}

float price(int bus_num, int seat_num)
{
    if(bus_num==194210)
    {
        return(400*seat_num);
    }
    if(bus_num==194220)
    {
        return(600*seat_num);
    }
    if(bus_num==194230)
    {
        return(400*seat_num);
    }
    if(bus_num==194240)
    {
        return(1200*seat_num);
    }
    if(bus_num==194250)
    {
        return(400*seat_num);
    }
}

void ticket(char name[],int seat_num,int bus_num,float price)
{
    system("cls");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\tTICKET\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("NAME OF PASSENGER:\t\%s",name);
    printf("\nNUMBER OF SEATS:\t%d",seat_num);
    printf("\nBUS NUMBER:\t\t%d",bus_num);
    selected_bus(bus_num);
    printf("\nTOTAL COST:\t\t%.2f",price);
}

void selected_bus(int bus_num)
{
    if(bus_num==194210)
    {
        printf("\nBUS NAME:\t\tDahlia");
        printf("\nDESTINATION:\t\tChittagong to Dhaka");
        printf("\nTIME:\t\t\t6 A.M.");
    }
    if(bus_num==194220)
    {
        printf("\nBUS NAME:\t\tGreen Line");
        printf("\nDESTINATION:\t\tChittagong to Rajshahi");
        printf("\nTIME:\t\t\t5 A.M.");
    }
    if(bus_num==194230)
    {
        printf("\nBUS NAME:\t\tShohagh");
        printf("\nDESTINATION:\t\tDhaka to Sylhet");
        printf("\nTIME:\t\t\t11 P.M.");
    }
    if(bus_num==194240)
    {
        printf("\nBUS NAME:\t\tShyamoli");
        printf("\nDESTINATION:\t\tSylhet to Cox's Bazar");
        printf("\nTIME:\t\t\t5 A.M.");
    }
    if(bus_num==194250)
    {
        printf("\nBUS NAME:\t\tSoudia");
        printf("\nDESTINATION:\t\tCox's Bazar to Chittagong");
        printf("\nTIME:\t\t\t2 P.M.");
    }
}
