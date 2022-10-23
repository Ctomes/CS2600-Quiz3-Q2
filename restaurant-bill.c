//CS2600 Quiz 3 question 2 submission.
//Tomes, Christopher

//will create a main that stores a data structure containing the default meal costs. 
//main will take up to 2 args from command line.
//if none is taken; display prices without tax and tip applies.
//if 1 or more, a meal will be chosen from data structure and the tax/tip will be applied.
//display cost.
//------------------------
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//my meal struct to store name of item and price.
struct Meal{
    float price;
    char* name[20];
};

int main( int argc, char *argv[] ){

    
    struct Meal meals[] = {{9.95, "Salad"}, 
                           {4.55, "Soup"},
                           {13.25, "Sandwhich"},
                           {22.35, "Pizza"}};
    srand(time(NULL)); //initialize random numbers for picking meal.
    int r = rand()% 4;

    //Invalid inputs will simply be processed as 0.00 tip/tax.

    if(argc == 3){
        //tax AND tip
        float temp_val = meals[r].price + meals[r].price*atof(argv[1])*.01 + atof(argv[2]);
        printf("%s: $%.2f\n", *meals[r].name, temp_val);
    }else if(argc == 2){
        //tax 
        float temp_val = meals[r].price + meals[r].price*atof(argv[1])*.01;
        printf("%s: $%.2f\n", *meals[r].name, temp_val);
    }else if(argc == 1){
        //base price
        float temp_val = meals[r].price;
        printf("%s: $%.2f\n", *meals[r].name, temp_val);
    }else{
        //invalid inputs.
        printf("Invalid args:\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}