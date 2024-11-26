#include <stdio.h>
#include<string.h>

struct ResturantDetails{
    char Name[50];
    char mealType[10]; 
    char reviews[200]; //all of them in one record seperated by #
    char creditCard[3];
    char address[100];
    //char char time or open close;
    float price;
    float rating;
    int area;

    };
    struct ResturantDetails  details[24]={};
    
    

void DisplayResturant( int num,int end){
    int i=0;
    while (details[i].area== num)
    {
       

        if(num==details[i].area){
        printf("\n==================================================================\n");
        printf("%s\n",details[i].Name);
        printf("Meal Type: %s  Rating: %.1f/5.0\n",details[i].mealType,details[i].rating);
        printf("Price: $%.2f  Credit Card: %s\n",details[i].price,details[i].creditCard);
        printf("Adress: %s",details[i].address);
        }
        i++;
        
        
}
}
void MainResturant(int choice){
    

    while (choice>=1 && choice<=10){

        switch (choice)
        {
        case 1://DHA
            DisplayResturant(1,24);
            break;
        case 2://pechs
            DisplayResturant(2,24);
            break;
         case 3://jauhar
            DisplayResturant(3,24);
            break;
         case 4://nazimbad
            DisplayResturant(4,24);
            break;
         case 5://gulshan
            DisplayResturant(5,24);
            break;
         case 6://Bahadrabad
            DisplayResturant(6,24);
            break;
         case 7://Bahadrabad
            DisplayResturant(7,24);
            break;
        case 8://Bahadrabad
            DisplayResturant(8,24);
            break;
             case 9://Bahadrabad
            DisplayResturant(9,24);
            break;
             case 10://Bahadrabad
            DisplayResturant(10,24);
            break;
        
        default:
            break;
        }

    }
    char reserve;
    printf("Would you like to make a reservation[y/n]: ");
    scanf("%c",reserve);
    if (reserve =='y'){
        BookingDetails()
    }   
}