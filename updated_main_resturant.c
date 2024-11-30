#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <ctype.h>
#define MAXL 100
//we are pre-setting 50 max blocks for dynamic memory
#define MAX_RESTAURANTS 10
#define MAX_NAME_LEN 50
#define MAX_DATE_LEN 20
#define MAX_RESERVATIONS 50


// Structure to hold restaurant details
struct ResturantDetails {
    char Name[MAX_NAME_LEN];          
    char mealType[MAX_NAME_LEN];      
    char Timings[MAX_NAME_LEN];      
    char Desc[200];                  
    char address[50];               
    float price;                     
    float rating;                    
    int area;                        
    int availableSeats;
    int reservedSeats;               
};
// Global array to store details of all restaurants
struct ResturantDetails details[MAX_RESTAURANTS] = {
    {"Foods inn", "Breakfast/Lunch/Dinner", "9:00am - 12:00am", 
     "#A popular spot for family gatherings#Wide variety of cuisines to choose from#Known for its friendly service#Spacious and comfortable seating#Family-friendly atmosphere#", 
     "plot A-99 civil lines", 785.20, 3.68, 1, 30,0},

    {"Lotus court", "Lunch/Dinner", "1:00pm - 12:00am", 
     "#Specializes in Asian fusion dishes#Elegant and modern interior#Perfect for formal dinners#Excellent seafood options#Ideal for romantic dinners#", 
     "plot C-143 pechs", 888.80, 3.7, 2, 40,0},

    {"Ghalib", "Dinner", "7:00pm - 12:00am", 
     "#Offers a rooftop dining experience#Known for its traditional Pakistani dishes#Great ambiance for evening meals#Reasonably priced menu options#Scenic views of the city skyline#", 
     "PLot-0987 block-6 clifton", 904.43, 3.9, 3, 45,0},

    {"Lal Qila", "Breakfast/Brunch", "9:00am - 12:00pm", 
     "#A heritage-themed restaurant#Offers live cooking stations#Famous for its buffet options#Located near the seashore#Perfect for family celebrations#", 
     "plot-555 block-12 cantonment", 1034.20, 4.12, 4, 20,0},

    {"Coconut Grove", "Lunch/Dinner", "2:00pm - 12:00am", 
     "#A cozy restaurant with a tropical theme#Serves a mix of continental and local dishes#Affordable menu prices#Known for its fresh seafood platters#Scenic and relaxing atmosphere#", 
     "plot-45678 block-098 sector-14", 1200.00, 4.25, 5, 52,0},

    {"Xander's", "Brunch/Lunch/Dinner", "12:00pm - 12:00am", 
     "#Known for its vibrant and trendy atmosphere#Offers a great selection of sandwiches and salads#Ideal for casual dining#Features an open kitchen concept#Family-friendly dining spot#", 
     "plot-678 block-57 regal chowk", 1500.00, 4.4, 6, 10,0},

    {"Gaffar Kabab house", "Breakfast/Brunch/Lunch/Dinner", "8:00am - 12:00am", 
     "#Famous for its authentic BBQ and kababs#Simple yet cozy interior#Affordable pricing for all#Loved by locals for its traditional recipes#Perfect for family celebrations#", 
     "plot-101 block-13 malir cantt", 2489.11, 4.5, 7, 30,0},

    {"Sakura", "Lunch/Dinner", "1:00pm - 11:00pm", 
     "#An upscale Japanese restaurant#Known for its fresh sushi and sashimi#Features a minimalist and elegant decor#Ideal for business or romantic dinners#Romantic ambiance with subtle lighting#", 
     "plot-45 block-5 shah latif", 3625.54, 4.55, 8, 45,0},

    {"Okra", "Dinner", "7:00pm - 11:30pm", 
     "#A fine dining restaurant with a gourmet menu#Offers creative and innovative dishes#Small, intimate seating arrangements#Known for its high-quality ingredients#Perfect for a romantic evening#", 
     "plot-234 block-7 shahrah-e-faisal", 3900.00, 4.6, 9, 60,0},

    {"BBQ tonight", "Dinner", "6:00pm - 12:00am", 
     "#A classic BBQ spot popular among locals#Wide range of grilled meats and curries#Large outdoor seating area#Great for group dinners and celebrations#Family-friendly and lively atmosphere#", 
     "plot-12 main north nazimabad", 4500.00, 4.71, 10, 150,0}
};



void DisplayAll(){

    for(int i=0;i<10;i++){
        printf("\n==================================================================\n");
        printf("%s\n",details[i].Name);
        printf("reservation code: %d\n",details[i].area);
        printf("Meal Type: %s\n",details[i].mealType);
        printf("About:\n ");
        printf("%s\n",details[i].Desc);
        printf("Average Price(per head): Rs.%.2f Rating: %.1f/5.0\n" ,details[i].price,details[i].rating);
        printf("Timings: %s Adress: %s\n",details[i].Timings,details[i].address);
        printf("==========================================================================\n");
        }
    }
                

void DisplayResturant( int num){
    printf("\n==================================================================\n");
    printf("%s\n",details[num].Name);
        printf("reservation code: %d\n",details[num].area);
        printf("Meal Type: %s\n",details[num].mealType);
        printf("About:\n ");
        printf("%s\n",details[num].Desc);
        printf("Price: $%.2f Rating: %.1f/5.0\n" ,details[num].price,details[num].rating);
        printf("Timings: %s Adress: %s\n",details[num].Timings,details[num].address);
        printf("==========================================================================\n");
}
        

void Filter() {
    int option;

    while(1){
        printf("\nSelect a filter option:\n");
        printf("1. Filter by Price Range\n");
        printf("2. Filter by Rating Range\n");
        printf("3. Exit Filtering\n");
        scanf("%d", &option);

        if (option == 1) {
            // Filter by price range
            float minPrice, maxPrice;
            printf("Enter minimum price: ");
            scanf("%f", &minPrice);
            printf("Enter maximum price: ");
            scanf("%f", &maxPrice);

            printf("\nFiltered Restaurants by Price Range (Rs. %.2f - Rs. %.2f):\n", minPrice, maxPrice);
            int found = 0;
            for (int i = 0; i < MAX_RESTAURANTS; i++) {
                if (details[i].price >= minPrice && details[i].price <= maxPrice) {
                    DisplayResturant(i);
                    found = 1;
                }
            }
            if (!found) {
                printf("No restaurants found in this price range.\n");
            }
        }
        else if (option == 2) {
            // Filter by rating range
            float minRating, maxRating;
            printf("Enter minimum rating: ");
            scanf("%f", &minRating);
            printf("Enter maximum rating: ");
            scanf("%f", &maxRating);

            printf("\nFiltered Restaurants by Rating Range (%.1f - %.1f):\n", minRating, maxRating);
            int found = 0;
            for (int i = 0; i < MAX_RESTAURANTS; i++) {
                if (details[i].rating >= minRating && details[i].rating <= maxRating) {
                    DisplayResturant(i);
                    found = 1;
                }
            }
            if (!found) {
                printf("No restaurants found in this rating range.\n");
            }
        }
        else if (option == 3) {
            // exit filtering
            printf("Exiting filter menu...\n");
            break;  // exit the loop and return to the main menu
        }
        else {
            printf("Invalid option selected. Please try again.\n");
        }
    }
}
void toLowerCaseString(char *source, char *destination) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = tolower(source[i]); // Convert each character to lowercase
        i++;
    }
    destination[i] = '\0'; // Null-terminate the destination string
}


void Search() {
    while (1) {
        char searchTerm[100];
        char lowerSearchTerm[100]; // To hold the lowercase search term
        printf("\nEnter search term (or type 'exit' to stop searching):\n");
        fgets(searchTerm, sizeof(searchTerm), stdin);
        searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Remove trailing newline

        // Convert the search term to lowercase
        toLowerCaseString(searchTerm, lowerSearchTerm);

        // Check if the user wants to exit the search loop
        if (strcmp(lowerSearchTerm, "exit") == 0) {
            printf("Exiting search...\n");
            break;
        }

        int found = 0; // Tracks if any matches are found
        for (int i = 0; i < MAX_RESTAURANTS; i++) {
            char lowerName[50], lowerDesc[200], lowerAddress[50];

            // lowercase all
            toLowerCaseString(details[i].Name, lowerName);
            toLowerCaseString(details[i].Desc, lowerDesc);
            toLowerCaseString(details[i].address, lowerAddress);

            // Check
            if (strstr(lowerName, lowerSearchTerm) || strstr(lowerDesc, lowerSearchTerm) || strstr(lowerAddress, lowerSearchTerm)) {
                DisplayResturant(i);
                found = 1;
            }
        }

        if (!found) {
            printf("No items found matching '%s'.\n", searchTerm);
        }
    }
}



void makeReservation(int index, int seats) {
    char reserveName[10];
    
    printf("Enter name to put reservation under: ");
    scanf("%s",reserveName);

        if (index < 0 || index >= 10) {
        printf("Invalid restaurant index!\n");
        return;
    }

    // Check seat availability
    if (details[index].reservedSeats + seats > details[index].availableSeats) {
        printf("Sorry, not enough seats available at %s.\n", details[index].Name);
        return;
    }
    
    // Update reserved seats
    details[index].reservedSeats += seats;
    printf("Reservation successful at %s for %d seats under the name %s.\n", details[index].Name, seats,reserveName);
    printf("Seats remaining: %d\n", details[index].availableSeats - details[index].reservedSeats);
    }
    
    
void Resturantmenu() {
    int option;
    

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Display All Restaurants\n");
        printf("2. Filter by price or ratings\n");
        printf("3. Search for resturant by area/name/description\n");
        printf("4. Make a Reservation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 1) {
            // Display all restaurants function
            DisplayAll();
        } 
        else if (option == 2) {
            Filter();
        } 
        else if (option == 3) {
            Search();
        }
        else if (option == 4){
            int choice, seats;
            printf("Enter the reservation code of the resturant: ");
            scanf("%d", &choice);
            printf("Enter the number of seats to reserve for today: ");
            scanf("%d", &seats);
            
            makeReservation(choice-1, seats);
        } 
        else if (option == 5){
            printf("Exiting the menu. Goodbye!\n");
            break;  // Exit the loop
        }
        else{
            printf("Invalid option. Please select a valid choice.\n");
        }
    }
}

void func(int id, int prog);

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
    int resturant =0;
    printf("PRESS 1 FOR RESTURANTS OR 2 FOR HOTELS: ");
    scanf("%d",&resturant);
    if (resturant == 1){
        Resturantmenu();
    }
    else{
        printf("DEAR %s, WOULD YOU LIKE TO ACCESS CURRENTLY AVAILIBLE LOCATIONS? \n", name);
        scanf("%s", yn);
        if ((strcmp(yn, "yes") == 0) || (strcmp(yn, "YES") == 0)) {
            ans = ans + 1;
            int id = 2;
            int prog = 100;
            for (int i = 0; i <= prog; i++) {
                func(id, i);
                usleep(100000);
            }
            printf("\n");
    }
    
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
                fgets(ping, sizeof(ping), stdin);
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

            break;
        }
                case 2 : {
            printf("**********************************\n");
            printf("\n HOTEL BEACH LUXURY \n RATING ON TRIVAGO : ***** \n ARHUM SAYS : OUTCLASS.\n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("06:00AM-04:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");

            break;

        }
                case 3 : {
            printf("**********************************\n");
            printf("\n ROYAL-INN HOTEL \n RATING ON TRIVAGO : ** \n ZALIK SAYS : POOR SERVICE \n AHMAD SAYS : TOO EXPENSIVE \n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("DOES NOT ACCEPT CARD PAYMENTS\n");
            printf("11:00AM-12:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");

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


            break;
        }
                case 5 : {
            printf("**********************************\n");
            printf("\n AMBIANCE BOUTIQUE HOTEL \n RATING ON TRIVAGO : * \n ABDULLAH SAYS : WORST HOTEL IVE STAYED IN \n HAMZA SAYS : NO, JUST NO \n");
            printf("OUTDOOR-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("DOES NOT ACCEPT CARD PAYMENTS\n");
            printf("12:00PM-12:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS NOT AVAILIBLE\n");

            break;
        }        case 6 : {
            printf("**********************************\n");
            printf("\n AVARI TOWERS \n RATING ON TRIVAGO : ***** \n SHAHVEER SAYS : BEST HOTEL EVER! \n ISBAH SAYS : I LOVE THIS PLACE \n");
            printf("PROXIMITY PING'S BEST RATED+");
            printf("FINE-DINE/ROOM-SERVICES/JACQUZEE/LODGES AVAILIBLE\n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("OPEN 24/7\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");

            break;
        }
                case 7 : {
            printf("**********************************\n");
            printf("\n DAYS-INN HOTEL \n RATING ON TRIVAGO : * \n SALEEM SAYS : WORST QUALITY BEDS AND ROOMS \n");
            printf("FINE-DINE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS NOT AVAILIBLE\n");

            break;
        }
                case 8 : {
            printf("**********************************\n");
            printf("\n HOTEL MANDARIAB \n RATING ON TRIVAGO : *** \n HADEED SAYS : A LITTLE EXPENSIVE \n AASHIR SAYS : BRING BUCKS HAHAHA \n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-12:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS NOT AVAILIBLE\n");

            break;
        }
                case 9 : {
            printf("**********************************\n");
            printf("\n BURJ-AL ARAB HOTEL \n RATING ON TRIVAGO : **** \n LUQMAN SAYS : FRIENDLY STAFF, BEAUTIFUL ROOMS \n");
            printf("FINE-DINE/ROOM SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 7 DAYS\n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");

            break;
        }
                case 10 : {
            printf("**********************************\n");
            printf("\n PENNINSULA HOTEL \n RATING ON TRIVAGO : * \n RAMEEL SAYS : VERY BAD EXPERIENCE :( ) \n ZULQARNAIN SAYS : EWW \n");
            printf("FINE-DINE/DELIVERY SERVICES AVAILIBLE \n");
            printf("ACCEPTS CARD PAYMENTS\n");
            printf("09:00AM-02:00AM OPEN 5 DAYS APART FROM WEDNESDAYS/FRIDAYS \n");
            printf("PROXIMITY PING DISCOUNTS AVAILIBLE\n");
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