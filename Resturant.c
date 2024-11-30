#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Maximum number of restaurants and time slots
#define MAX_RESTAURANTS 10
#define MAX_SLOTS 5
#define MAX_NAME_LEN

// Structure
struct Reservation {
    char time[10];       // time slot for reservation
    int reservedSeats;   // reserved seats for this time slot
};

struct ResturantDetails {
    char Name[50];
    char mealType[40];
    char Timings[20];
    char Desc[200];
    char address[50];
    float price;
    float rating;
    int area;
    int availableSeats;
    struct Reservation reservations[MAX_SLOTS];
};

// Global array of restaurants
struct ResturantDetails details[MAX_RESTAURANTS] = {
    {"Foods inn", "Breakfast/Lunch/Dinner", "9:00am - 12:00am", 
     "#A popular spot for family gatherings#Wide variety of cuisines to choose from#Known for its friendly service#Spacious and comfortable seating#Family-friendly atmosphere#", 
     "plot A-99 main Shah Latif", 785.20, 3.68, 1, 100, 
     {{"9:00am", 10}, {"12:00pm", 15}, {"3:00pm", 10}, {"6:00pm", 20}, {"9:00pm", 30}}},
    
    {"Lotus court", "Lunch/Dinner", "1:00pm - 12:00am", 
     "#Specializes in Asian fusion dishes#Elegant and modern interior#Perfect for formal dinners#Excellent seafood options#Ideal for romantic dinners#", 
     "plot C-143 Civil Lines", 888.80, 3.7, 2, 80, 
     {{"1:00pm", 8}, {"4:00pm", 10}, {"7:00pm", 15}, {"9:00pm", 20}, {"11:00pm", 10}}},

    {"Ghalib", "Dinner", "7:00pm - 12:00am", 
     "#Offers a rooftop dining experience#Known for its traditional Pakistani dishes#Great ambiance for evening meals#Reasonably priced menu options#Scenic views of the city skyline#", 
     "PLot-0987 block-6 PECHS", 904.43, 3.9, 3, 70, 
     {{"7:00pm", 10}, {"8:00pm", 15}, {"9:00pm", 20}, {"10:00pm", 15}, {"11:00pm", 10}}},

    {"Lal Qila", "Breakfast/Brunch", "9:00am - 12:00pm", 
     "#A heritage-themed restaurant#Offers live cooking stations#Famous for its buffet options#Located near the seashore#Perfect for family celebrations#", 
     "plot-555 block-12 Clifton", 1034.20, 4.12, 4, 150, 
     {{"9:00am", 25}, {"10:00am", 30}, {"11:00am", 40}, {"11:30am", 35}, {"12:00pm", 20}}},

    {"Coconut Grove", "Lunch/Dinner", "2:00pm - 12:00am", 
     "#A cozy restaurant with a tropical theme#Serves a mix of continental and local dishes#Affordable menu prices#Known for its fresh seafood platters#Scenic and relaxing atmosphere#", 
     "plot-45678 block-098 Cantonment", 1200.00, 4.25, 5, 90, 
     {{"2:00pm", 15}, {"5:00pm", 20}, {"7:00pm", 20}, {"9:00pm", 25}, {"11:00pm", 10}}},

    {"Xander's", "Brunch/Lunch/Dinner", "12:00pm - 12:00am", 
     "#Known for its vibrant and trendy atmosphere#Offers a great selection of sandwiches and salads#Ideal for casual dining#Features an open kitchen concept#Family-friendly dining spot#", 
     "plot-678 block-57 sector 14", 1500.00, 4.4, 6, 110, 
     {{"12:00pm", 20}, {"2:00pm", 25}, {"5:00pm", 25}, {"8:00pm", 30}, {"10:00pm", 10}}},

    {"Gaffar Kabab house", "Breakfast/Brunch/Lunch/Dinner", "8:00am - 12:00am", 
     "#Famous for its authentic BBQ and kababs#Simple yet cozy interior#Affordable pricing for all#Loved by locals for its traditional recipes#Perfect for family celebrations#", 
     "plot-101 block-13 Regal Chowk", 2489.11, 4.5, 7, 120, 
     {{"8:00am", 10}, {"12:00pm", 20}, {"3:00pm", 30}, {"6:00pm", 40}, {"9:00pm", 20}}},

    {"Sakura", "Lunch/Dinner", "1:00pm - 11:00pm", 
     "#An upscale Japanese restaurant#Known for its fresh sushi and sashimi#Features a minimalist and elegant decor#Ideal for business or romantic dinners#Romantic ambiance with subtle lighting#", 
     "plot-45 block-5 Malir Cantt", 3625.54, 4.55, 8, 80, 
     {{"1:00pm", 10}, {"4:00pm", 15}, {"7:00pm", 20}, {"9:00pm", 20}, {"10:00pm", 15}}},

    {"Okra", "Dinner", "7:00pm - 11:30pm", 
     "#A fine dining restaurant with a gourmet menu#Offers creative and innovative dishes#Small, intimate seating arrangements#Known for its high-quality ingredients#Perfect for a romantic evening#", 
     "plot-234 block-7 Shahrah-e-Faisal", 3900.00, 4.6, 9, 60, 
     {{"7:00pm", 10}, {"8:00pm", 15}, {"9:00pm", 15}, {"10:00pm", 10}, {"11:00pm", 10}}},

    {"BBQ tonight", "Dinner", "6:00pm - 12:00am", 
     "#A classic BBQ spot popular among locals#Wide range of grilled meats and curries#Large outdoor seating area#Great for group dinners and celebrations#Family-friendly and lively atmosphere#", 
     "plot-12 main North Nazimabad", 4500.00, 4.71, 10, 150, 
     {{"6:00pm", 30}, {"7:00pm", 40}, {"8:00pm", 40}, {"9:00pm", 30}, {"10:00pm", 10}}}
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

    // Loop to continuously show filter options until option 3 is chosen
    while (1) {
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

            // Convert Name, Description, and Address to lowercase
            toLowerCaseString(details[i].Name, lowerName);
            toLowerCaseString(details[i].Desc, lowerDesc);
            toLowerCaseString(details[i].address, lowerAddress);

            // Check if the search term exists in any of the fields
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



void reservations(){

}

void menu() {
    int display;
    while (1) { // Main menu loop
        printf("\nSelect an option:\n");
        printf("1. Display All Restaurants\n");
        printf("2. Filter by Ratings or Price\n");
        printf("3. Search by Name or Description\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &display);

        // Validation check
        if (display == 1) {
            DisplayAll();
        } 
        else if (display == 2) {
            Filter();
        } 
        else if (display == 3) {
            Search();
        }  
        else if (display == 4) {
            printf("Exiting the menu. Goodbye!\n");
            break; // Exit the loop
        } 
        else {
            printf("Invalid option. Please select a valid choice.\n");
        }
        
    
    }
}


void main(){
    menu();
}    
    

