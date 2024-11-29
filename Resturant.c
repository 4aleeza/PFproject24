#include <stdio.h>
#include<string.h>

struct ResturantDetails{
    char Name[50];
    char mealType[20];
    char Timings[20];
    char Desc[100]; //3 to 4 review in one record seperated by #
    char address[50];
    float price;
    float rating;
    int area;

    };
struct ResturantDetails details[10] = {
    {"Foods inn", "Breakfast#Lunch#Dinner", "9:00am - 12:00am", 
     "#A popular spot for family gatherings#Wide variety of cuisines to choose from#Known for its friendly service#Spacious and comfortable seating#Family-friendly atmosphere#", 
     "plot A-99 main Shaheed-e-millat rd", 785.20, 3.68, 1},

    {"Lotus court", "Lunch/Dinner", "1:00pm - 12:00am", 
     "#Specializes in Asian fusion dishes#Elegant and modern interior#Perfect for formal dinners#Excellent seafood options#Ideal for romantic dinners#", 
     "plot C-143 Bahadurabad", 888.80, 3.7, 2},

    {"Ghalib", "Dinner", "7:00pm - 12:00am", 
     "#Offers a rooftop dining experience#Known for its traditional Pakistani dishes#Great ambiance for evening meals#Reasonably priced menu options#Scenic views of the city skyline#", 
     "PLot-0987 block-6 Gulshan-e-Iqbal", 904.43, 3.9, 3},

    {"Lal Qila", "Breakfast/Brunch", "9:00am - 12:00pm", 
     "#A heritage-themed restaurant#Offers live cooking stations#Famous for its buffet options#Located near the seashore#Perfect for family celebrations#", 
     "plot-555 block-12 Clifton", 1034.20, 4.12, 4},

    {"Coconut Grove", "Lunch/Dinner", "2:00pm - 12:00am", 
     "#A cozy restaurant with a tropical theme#Serves a mix of continental and local dishes#Affordable menu prices#Known for its fresh seafood platters#Scenic and relaxing atmosphere#", 
     "plot-45678 block-098 Nazimabad", 1200.00, 4.25, 5},

    {"Xander's", "Brunch/Lunch/Dinner", "12:00pm - 12:00am", 
     "#Known for its vibrant and trendy atmosphere#Offers a great selection of sandwiches and salads#Ideal for casual dining#Features an open kitchen concept#Family-friendly dining spot#", 
     "plot-678 block-57 DHA", 1500.00, 4.4, 6},

    {"Gaffar Kabab house", "Breakfast/Brunch/Lunch/Dinner", "8:00am - 12:00am", 
     "#Famous for its authentic BBQ and kababs#Simple yet cozy interior#Affordable pricing for all#Loved by locals for its traditional recipes#Perfect for family celebrations#", 
     "plot-101 block-13 Gulshan-e-Iqbal", 2489.11, 4.5, 7},

    {"Sakura", "Lunch/Dinner", "1:00pm - 11:00pm", 
     "#An upscale numapanese restaurant#Known for its fresh sushi and sashimi#Features a minimalist and elegant decor#Ideal for business or romantic dinners#Romantic ambiance with subtle lighting#", 
     "plot-45 block-5 Clifton", 3625.54, 4.55, 8},

    {"Okra", "Dinner", "7:00pm - 11:30pm", 
     "#A fine dining restaurant with a gourmet menu#Offers creative and innovative dishes#Small, intimate seating arrangements#Known for its high-quality ingredients#Perfect for a romantic evening#", 
     "plot-234 block-7 Clifton", 3900.00, 4.6, 9},

    {"BBQ tonight", "Dinner", "6:00pm - 12:00am", 
     "#A classic BBQ spot popular among locals#Wide range of grilled meats and curries#Large outdoor seating area#Great for group dinners and celebrations#Family-friendly and lively atmosphere#", 
     "plot-12 main Shahrah-e-Quaideen", 4500.00, 4.71, 10}
};

void DisplayAll();
void DisplayResturant(int num);
void Menu();
void Search();
void Filter();
void Booking();

void main(){
    menu();
}



void DisplayAll(){

    for(int i=0;i<10;i++){
        printf("\n==================================================================\n");
        printf("%s\n",details[i].Name);
        printf("Meal Type"); 
        char *myPtr = strstr(details[i].mealType, "BreakFast");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
         char *myPtr = strstr(details[i].mealType, "Brunch");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
         char *myPtr = strstr(details[i].mealType, "Lunch");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
         char *myPtr = strstr(details[i].mealType, "Dinner");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
        printf("Average Price(per head): $%.2f Rating: %.1f/5.0\n" ,details[i].price,details[i].rating);
        printf("Timings: %s Adress: %s",details[i].Timings,details[i].address);
        printf("==========================================================================\n");
        }
    }
                

void DisplayResturant( int num){
       
        printf("\n==================================================================\n");
        char *myPtr = strstr(details[num].mealType, "BreakFast");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
         char *myPtr = strstr(details[num].mealType, "Brunch");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
         char *myPtr = strstr(details[num].mealType, "Lunch");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
         char *myPtr = strstr(details[num].mealType, "Dinner");
        if (myPtr != NULL) {
            printf("%s", myPtr);
        }
        printf("Price: $%.2f Rating: %.1f/5.0\n" ,details[num].price,details[num].rating);
        printf("Timings: %s Adress: %s",details[num].Timings,details[num].address);
        printf("==========================================================================\n");
        }
    

void Filter(){

}  
void Search(char string){
    for(int i =0;i<10;i++){
        char *found1 = strstr(details[i].Name, string);
        char *found2 = strstr(details[i].Desc, string);
        if(found1 || found2){
            DisplayResturant(i);
        }
        else
        {
            printf("No items found");
        }
        
    }
}

void Booking(){

}

void Menu(){
    int display;
    printf("Select corresponding number to choose option: ");
    printf("Display all options - 1");
    printf("Filter by ratings or price(per head)- 2");
    printf("Search name or description- 3");
    scanf("%d",&display);

    while(display>=1 && display<=3){//validation check
        if(display == 1){
            DisplayAll();
        }
        else if (display == 2){
        int option;
        printf("Filter by: ");
        printf("Meal Type - 1 ");
        printf("Rating - 2");
        printf("Price - 3");
        scanf("%d",&option);
        Filter();
        }
        else{
            char searchString[100];
            printf("Search term: ");
            fgets(searchString, sizeof(searchString), stdin);
            searchString[strcspn(searchString, "\n")] = '\0'; 
            Search(searchString);
        }
    }
    
    
    
     
}
