#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include<time.h>
#define MAXL 100
//we are pre-setting 50 max blocks for dynamic memory

void func(int id, int prog);
void hotel(char hotelname[],char username[]);
void func(int id, int prog) {
    printf("ID %d : [", id);
    for (int i = 0; i < MAXL; i++) {
        if (i < prog) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\r", prog);
    fflush(stdout);
}

int main() {
    char *pwd, *name;
    pwd = (char *)malloc(50 * sizeof(char)); //50 memory heap me derha instead of stack
    name = (char *)malloc(50 * sizeof(char));

    if (pwd == NULL || name == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    FILE *cred = fopen("creds.txt", "a");
    if (cred == NULL) {
        printf("NULL FILE : ERROR 404 \n");
        return 1;
    }

  
    printf("Enter Username: \n");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; 

    printf("Enter Password: ");
    fgets(pwd, 50, stdin);
    pwd[strcspn(pwd, "\n")] = '\0'; 

    // Store credentials in file
    fprintf(cred, "%s\n%s\n", name, pwd);
    fclose(cred);

    // maskin
    printf("NAME : %s  PASSWORD : ", name);
    for (int i = 0; i < strlen(pwd); i++) {
        printf("*");
    }
    printf("\n");

    
    char *login_name = (char *)malloc(50 * sizeof(char));  
    char *login_pwd = (char *)malloc(50 * sizeof(char));   

    if (login_name == NULL || login_pwd == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int logged_in = 0;
    while (!logged_in) {
        printf("Please log in to continue.\n");
        printf("Enter Username: \n");
        fgets(login_name, 50, stdin);
        login_name[strcspn(login_name, "\n")] = '\0'; 

        printf("Enter Password: ");
        fgets(login_pwd, 50, stdin);
        login_pwd[strcspn(login_pwd, "\n")] = '\0'; 

        // Open credentials file to validate login
        FILE *cred_check = fopen("creds.txt", "r");
        if (cred_check == NULL) {
            printf("Error reading credentials file\n");
            free(login_name);
            free(login_pwd);
            return 1;
        }

        char file_name[50], file_pwd[50];
        while (fscanf(cred_check, "%s\n%s\n", file_name, file_pwd) == 2) {
            if (strcmp(file_name, login_name) == 0 && strcmp(file_pwd, login_pwd) == 0) {
                printf("Login successful!\n");
                logged_in = 1;
                break;
            }
        }
        fclose(cred_check);

        if (logged_in!=1) {
            printf("Invalid login. Please try again.\n");
        }
    }

    printf("WELCOME TO PROXIMITY PING!\n");

    char yn[15]; // yes or no
    int ans = 0;
    printf("DEAR %s, WOULD YOU LIKE TO ACCESS CURRENTLY AVAILIBLE LOCATIONS? \n", name);
    scanf("%s", yn);
    if ((strcmp(yn, "yes") == 0) || (strcmp(yn, "YES") == 0)) {
        ans = ans + 1;

        int id = 2;
        int prog = 100;
        for (int i = 0; i <= prog; i++) {
            func(id, i);
            Sleep(1000);
        }
        printf("\n");
    }

    if (ans == 1) {
        // Password saving ends here
        char *locations[10] = {
            "civil lines (1)",
            "pechs (2)",
            "clifton (3)",
            "cantonment (4)",
            "sector 14 (5)",
            "regal chowk (6)",
            "malir cantt (7)",
            "shah latif (8)",
            "shahrah-e-faisal (9)",
            "north nazimabad (10)"
        };

        for (int i = 0; i < 10; i++) {
            printf("%s\n", locations[i]);
        }
        printf("\n");
        int loc; // location number
        char ping[30];

        while (1) {
            printf("ENTER THE NUMBER OF LOCATION YOU WANT TO ACCESS: \n");
            scanf("%d", &loc);

            if (loc == 0) {
                printf("EXITING PROGRAM. THANK YOU FOR USING PROXIMITY PING!\n");
                break; // Exit the loop
            }
            if (loc == 111) {
                printf("PROCEEDING FURTHER \n");
                printf("ENTER THE PLACE YOU WOULD LIKE TO HEAD TO: \n");
                getchar();
                fgets(ping, sizeof(ping), stdin);
                ping[strcspn(ping,"\n")]='\0';
                hotel(ping,name);
                //CALL THE 2 FUNCTIONS

                break;
            }

            switch (loc) {
            
        case 1 : {
            printf("**********************************\n");
            printf("\n HOTEL PEARL CONTINENTAL \n RATING ON TRIVAGO : **** \n JAMSHED SAYS : AMAZING AMBIANCE! \n RUBA SAYS : VERY BEAUTIFUL \n");
            printf("FINE-DINE/ROOM SERVICES\n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT FOODS INN \n RATING ON ZOMATO : **** \n ZAHRA SAYS : EXCELLENT TASTE, AFFORDABLE PRICES! \n AHMED SAYS : A PERFECT PLACE FOR FAMILIES. \n");

            break;
        }
                case 2 : {
            printf("**********************************\n");
            printf("\n HOTEL BEACH LUXURY \n RATING ON TRIVAGO : ***** \n ARHUM SAYS : OUTCLASS.\n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("06:00AM-04:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT GHALIB \n RATING ON GOOGLE : **** \n IMRAN SAYS : A LEGENDARY SPOT FOR DESI FOOD! \n KIRAN SAYS : THE BBQ IS SIMPLY AMAZING. \n");

            break;

        }
                case 3 : {
            printf("**********************************\n");
            printf("\n ROYAL-INN HOTEL \n RATING ON TRIVAGO : ** \n ZALIK SAYS : POOR SERVICE \n AHMAD SAYS : TOO EXPENSIVE \n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("DOES NOT ACCEPT CARD PAYMENTS\n");
            printf("11:00AM-12:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT LAL QILA \n RATING ON TRIPADVISOR : ***** \n SAMEER SAYS : A ROYAL DINING EXPERIENCE! \n ANAM SAYS : GREAT VARIETY OF FOOD WITH LIVE COOKING. \n");

            break;
        }
                case 4 : {
            printf("**********************************\n");
            printf("\n XEFAN HOTEL \n RATING ON TRIVAGO : *** \n JARASEEM SAYS : GOOD FOOD \n TOSI SAYS : NOT BAD \n");
            printf("FINE-DINE AVAILIBLE\n");
            printf("ROOM SERVICES NOT AVAILIBLE\n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT COCONUT GROVE \n RATING ON YELP : **** \n ALIA SAYS : RELAXING ATMOSPHERE WITH GREAT SEAFOOD. \n HASSAN SAYS : THE COCONUT CURRY IS A MUST-TRY. \n");


            break;
        }
                case 5 : {
            printf("**********************************\n");
            printf("\n AMBIANCE BOUTIQUE HOTEL \n RATING ON TRIVAGO : * \n ABDULLAH SAYS : WORST HOTEL IVE STAYED IN \n HAMZA SAYS : NO, JUST NO \n");
            printf("OUTDOOR-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("DOES NOT ACCEPT CARD PAYMENTS\n");
            printf("12:00PM-12:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS NOT AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT XANDER'S \n RATING ON GOOGLE : ***** \n SAAD SAYS : GREAT FOR BRUNCH! \n LINA SAYS : FRESH INGREDIENTS AND TRENDY VIBE. \n");

            break;
        }        case 6 : {
            printf("**********************************\n");
            printf("\n AVARI TOWERS \n RATING ON TRIVAGO : ***** \n SHAHVEER SAYS : BEST HOTEL EVER! \n ISBAH SAYS : I LOVE THIS PLACE \n");
            printf("PROXIMITY PING'S BEST RATED+");
            printf("FINE-DINE/ROOM-SERVICES/JACQUZEE/LODGES AVAILIBLE\n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("OPEN 24/7\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT GAFFAR KABAB HOUSE \n RATING ON ZOMATO : **** \n ABDULLAH SAYS : THE JUICIEST KABABS IN TOWN! \n AMINA SAYS : PURE DESI TASTE, GREAT PORTIONS. \n");

            break;
        }
                case 7 : {
            printf("**********************************\n");
            printf("\n DAYS-INN HOTEL \n RATING ON TRIVAGO : * \n SALEEM SAYS : WORST QUALITY BEDS AND ROOMS \n");
            printf("FINE-DINE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS NOT AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT LOTUS COURT \n RATING ON GOOGLE : **** \n NAIMA SAYS : EXCELLENT CHINESE FOOD. \n JUNAID SAYS : LOVE THE AUTHENTIC FLAVORS. \n");

            break;
        }
                case 8 : {
            printf("**********************************\n");
            printf("\n HOTEL MANDARIAB \n RATING ON TRIVAGO : *** \n HADEED SAYS : A LITTLE EXPENSIVE \n AASHIR SAYS : BRING BUCKS HAHAHA \n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-12:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS NOT AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT SAKURA \n RATING ON TRIPADVISOR : ***** \n AYESHA SAYS : BEST SUSHI IN THE CITY! \n DANIAL SAYS : AUTHENTIC JAPANESE FLAVORS. \n");

            break;
        }
                case 9 : {
            printf("**********************************\n");
            printf("\n BURJ-AL ARAB HOTEL \n RATING ON TRIVAGO : **** \n LUQMAN SAYS : FRIENDLY STAFF, BEAUTIFUL ROOMS \n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT OKRA \n RATING ON YELP : ***** \n RABIA SAYS : A COZY PLACE WITH AMAZING FOOD. \n TALHA SAYS : THE PASTA AND DESSERTS ARE MUST-TRIES! \n");

            break;
        }
                case 10 : {
            printf("**********************************\n");
            printf("\n PENNINSULA HOTEL \n RATING ON TRIVAGO : * \n RAMEEL SAYS : VERY BAD EXPERIENCE :( ) \n ZULQARNAIN SAYS : EWW \n");
            printf("FINE-DINE/DELIVERY SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 5 DAYS APART FROM WEDNESDAYS/FRIDAYS \n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
            printf("\n**********************************\n");
            printf("**********************************\n");
            printf("\n RESTAURANT BBQ TONIGHT \n RATING ON ZOMATO : ***** \n FARHAN SAYS : THE BBQ IS NEXT LEVEL! \n NIDA SAYS : A CLASSIC FOR PAKISTANI CUISINE LOVERS. \n");
            break;
        }
            default:
            printf("Invalid option. Please try again.\n");
            break;
            }
        }
    } else {
        printf("WE ARE SORRY TO SEE YOU GO :( COME BACK SOON! \n");
    }
    free(pwd);
    free(name);
    free(login_name);
    free(login_pwd);

    return 0;
}

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

void hotel(char hotelname[],char username[])
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
   
        printf("************ Final Billing Statement ************\n");
        printf("Username: %s\n", username);
        printf("Hotel Name: %s\n", hotelname);
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



     
  