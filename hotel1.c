# include<stdio.h>
# include<string.h>
# include<time.h>
# include<stdlib.h>
struct bill
{
      char room_type[30];
  char room_type1[30];
  char room_services[30];
  char restruant[3][30];
  char bar[30];
  char other_facilities[3][30];
  int cost;
  int discout;
  }b1;
void hotel(char hotelname[]);
int main()
{
  char hotel123[30];
  printf("enter hotel\n");
  gets(hotel123);
  hotel(hotel123);
  return 0;
  
}
void hotel(char hotelname[])
{
    char name[30][30]={"Pearl Continental Hotel","Beach Luxury Hotel","Royal Inn Hotel","Xefan Hotel","Ambiance Boutique Hotel","Avari Towers Hotel","Days Inn Hotel","Burj Al Arab Hotel","Mandariab Oriental Hotel","Peninsula Hotel","pearl continental hotel","beach luxury hotel","royal inn hotel","xefan xotel","ambiance boutique hotel","avari towers hotel","days inn hotel","burj al arab hotel","mandariab oriental hotel","peninsula hotel","PEARL CONTINENTAL HOTEL","BEACH LUXURY HOTEL","ROYAL INN HOTEL","XEFAN HOTEL","AMBIANCE BOUTIQUE HOTEL","AVARI TOWERS HOTEL","DAYS INN HOTEL","BURJ AL ARAB HOTEL","MANDARIN ORIENTAL HOTEL","PENINSULA HOTEL"};

    int num_hotels=sizeof(name)/sizeof(name[0]);
    srand(time(NULL));
    struct bill b1;
    int i;
    int yes=0;
    int room;
    int room1;
    int num_resturants=0;
    int food_and_beverages;
    int roomservice;
    int resturants;
    int service;
     b1.cost=0;
    int num_sercice=0;
    
    for(i=0;i<num_hotels;i++)
    {
        if (strcmp(hotelname,name[i])==0)
        {
            yes=1;
            break;
        }
    }
    if(yes==1)
    
    {   
         printf("Welcome to %s!\n",hotelname);
         printf("Enter the type of room you want!\n");
         printf("1.Single.\n");
         printf("2.Double.\n");
         scanf("%d",&room);
         switch(room)
         {
            case 1:
            strcpy(b1.room_type,"Single");
            printf("Enter the type of room you want!\n");
            printf("1.Premium.\n");
            printf("2.VIP.\n");
            printf("3.Medium.\n");
            scanf("%d",&room1);
            
                switch (room1)
                  {
                  case 1:
                       strcpy(b1.room_type1,"Premium");
                       b1.cost+=rand()%(1000-900+1)+900;
                       break;

                  case 2: 
                        strcpy(b1.room_type1,"VIP");
                       b1.cost+=rand()%(900-800+1)+800;
                        break;

                  case 3:
                        strcpy(b1.room_type1,"Medium");
                        b1.cost+=rand()%(500-400+1)+400;
                        break;   
            
                  default:
                   printf("Invalid choice!\n");

                        break;
                   }
            break;

            case 2:
            strcpy(b1.room_type,"Double");
            printf("Enter the type of room you want!\n");
            printf("Press 1 for King and Queen.\n");
            printf("Press 2 for Family.\n");
            scanf("%d",&room1);
            switch (room1)
                  {
                  case 1:
                       strcpy(b1.room_type1,"King and Queen");
                       b1.cost+=rand()%(1200-1000+1)+1000;
                       break;

                  case 2:
                        strcpy(b1.room_type1,"Family");
                        b1.cost+=rand()%(1500-1400+1)+1400;
                        break;

            
                  default:
                       printf("Invalid choice.\n");
                        break;
                   }
             default:
             printf("Invalid Choice!\n");     


         }
        
    printf("Bar Menu\n");
    printf("1. Pizza\n");
    printf("2. Burger\n");
    printf("3. Pasta\n");
    printf("4. Coke\n");
    printf("5. Coffee\n");
    while (1)
    {
         printf("Enter the Bar Menu from 0 to 5!\n");
         scanf("%d", &resturants);
    if(resturants==0)
         {
            break;
         }
    else
    {
    switch (resturants) {
        case 1:
         strcpy(b1.restruant[num_resturants],"Pizza");
          b1.cost+=rand()%(100-70+1)+70;
            break;
        case 2:
           strcpy(b1.restruant[num_resturants],"Burger");
            b1.cost+=rand()%(100-70+1)+70;
            break;
        case 3:
           strcpy(b1.restruant[num_resturants],"Pasta");
            b1.cost+=rand()%(100-70+1)+70;
            break;
        case 4:
            strcpy(b1.restruant[num_resturants],"Coke");
             b1.cost+=rand()%(100-70+1)+70;
            break;
        case 5:
            strcpy(b1.restruant[num_resturants],"Coffee");
             b1.cost+=rand()%(100-70+1)+70;
            break;
        default:
            printf("Invalid Choice!\n");
    }
    num_resturants++;
    } 
    }
    
        printf("Welcome to room services!\n");
         printf("1.Breakfast.\n");
         printf("2.Lunch.\n");
         printf("3.Dinner.\n");
         printf("4.avail all and  get 20 percent discount.\n");
         scanf("%d",&roomservice);

         switch (roomservice)
         {
         case 1:
           strcpy(b1.room_services,"Breakfast");
            b1.cost+=rand()%(100-70+1)+70;
            break;
         case 2:
           strcpy(b1.room_services,"Lunch");
            b1.cost+=rand()%(100-70+1)+70;
           break;
         case 3:
           strcpy(b1.room_services,"Dinner"); 
            b1.cost+=rand()%(100-70+1)+70;
           break;
         case 4:
           strcpy(b1.room_services,"Lunch,Dinner, and Breakfast");   
            b1.cost+=rand()%(100-70+1)+70;
         default:
          printf("Invalid choice!\n");
            break;
         }

         
       
         printf("Welcome to hotel services!\n");
         printf("0.Exit.\n");
         printf("1.Parking.\n");
         printf("2.SPA.\n");
         printf("3.Swimming Pool.\n");
         printf("4.Fitness centre.\n");
         printf("5.Business centre.\n");
        
         while(1)
         {
         printf("Enter service choice from 0 to 5\n");
         scanf("%d",&service);
         if(service==0)
         {
            break;
         }
         else if (service>=1&& service<=5)
         {

         
         switch (service)
         {
         case 1:
            strcpy(b1.other_facilities[num_sercice],"Parking");
           b1.cost+=rand()%(100-70+1)+70;
            break;
          case 2:
            strcpy(b1.other_facilities[num_sercice],"SPA");
            b1.cost+=rand()%(150-100+1)+100;
            break;
          case 3:
            strcpy(b1.other_facilities[num_sercice],"Swimming Pool");
            b1.cost+=rand()%(280-250+1)+250;
            break;
          case 4:
            strcpy(b1.other_facilities[num_sercice],"Fitness Centre");
             b1.cost+=rand()%(200-100+1)+100;
            break;
          case 5:
            strcpy(b1.other_facilities[num_sercice],"Bussiness");
            b1.cost+=rand()%(500-400+1)+400;
            break;
           default:
           printf("Invalid choice!\n");
            break;
         }
         num_sercice++;
         }
         else 
         {
            printf("Invalid choice!\n");;
         }
        }
        printf("Your room type is %s\n",b1.room_type);
        printf("Your room class is %s\n",b1.room_type1);
      
        for(i=0;i<num_sercice;i++)
        {
           printf("Your other facilities is %s\n",b1.other_facilities[i]);
        }

         for(i=0;i<num_resturants;i++)
        {
           printf("Your resturants facilities is %s\n",b1.restruant[i]);
        }

         printf("Your total cost is %d\n",b1.cost);
   
    }

    else
    {
        printf("Hotel not found");
    }

    

   
}



     
  
