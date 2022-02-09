/*
converter.c is a program that asks the user for an input and converts it into 
a different unit. User is able to choose their conversion units. 

Conversions supported:
kilometers and miles
litres and gallons 
hectares and acres
kilograms and pounds

Written by: David Alter
251158774
*/
#include <stdio.h>
#define MILES 0.621371  // A constant for the km/miles conversion
#define GALLONS 0.264172 // A constant for the L/gallons conversion
#define ACRES 2.47105 // A constant for the hectares/acres conversion
#define POUNDS 2.20462 // A constant for the kg/pounds conversion

int main(void)
{
    int option = 0; //represents the option the user chooses from the main menu
    char conversion; // represents the option the user chooses from the sub (inner) menu
    float input; // number that user wants to convert
    float output; //converted number, printed back to user

    //prompting user to choose a mode and read input
    printf("Select a mode: (1 - 4), 5 to quit. \n");
    printf("1: Kilometers and Miles , 2: Litres and Gallons,\n 3: Hectares and Acres , 4: Kilograms and Pounds: ");
    scanf("%d", &option);

    // menu will stay open until user hits 5 to quit the program
    while (option != 5){  
        // if the user enters 1, kilometer and miles mode 
        if (option ==1){
            //prompt the user to enter a conversion preference, read input 
            printf("K for Kilometers to Miles, M for Miles to Kilometers: ");
            getchar();
            scanf("%c", &conversion);

            //if the user enters K, we are converting km to mi
            if (conversion == 'K')
            {
                //prompt user to enter number of km, read input
                printf("Please enter a value: ");
                scanf("%f", &input);

                //convert km to mi, print output to user
                output = input * MILES;
                printf("Your conversion is: %f miles\n", output);

            }
            //if the user enters M, we are converting mi to km
            else if (conversion == 'M')
            {
                //prompt user to enter number of mi, read input
                printf("Please enter a value: ");
                scanf("%f", &input);

                //convert mi to km, print output to user
                output = input / MILES;
                printf("Your conversion is: %f kilometres\n", output);

            }
            //reset user main menu option
            option = 0;
        }

         // if the user enters 2, litres and gallons mode 
        else if (option ==2){
            //prompt the user to enter a conversion preference, read input
            printf("L for Litres to Gallons, G for gallons to Litres: ");
            getchar();
            scanf("%c", &conversion);

            //if the user enters L, we are converting litres to gallons
            if (conversion == 'L')
            {
                //prompt user to enter number of litres, read input
                printf("Please enter a value: ");
                scanf("%f", &input);

                //convert litres to gallons, print output to user
                output = input * GALLONS;
                printf("Your conversion is: %f gallons\n", output);

            }
            //if the user enters G, we are converting gallons to litres
            else if (conversion == 'G')
            {
                //prompt user to enter number of gallons, read input
                printf("Please enter a value: ");
                scanf("%f", &input);

                //convert gallons to litres, print output to user
                output = input / GALLONS;
                printf("Your conversion is: %f litres\n", output);

            }
            //reset user main menu option
            option = 0;
        }

        // if the user enters 3, hectares and acres mode
        else if (option == 3){
            //prompt the user to enter a conversion preference, read input
            printf("H for Hectares to Acres, A for Acres to Hectares: ");
            getchar();
            scanf("%c", &conversion);

            //if the user enters H, we are converting hectares to acres
            if (conversion == 'H')
            {
                //prompt user to enter number of hectares, read input
                printf("Please enter a value: ");
                scanf("%f", &input);

                //convert hectares to acres, print output to user
                output = input * ACRES;
                printf("Your conversion is: %f acres\n", output);

            }

            //if the user enters A, we are converting acres to hectares
            else if (conversion == 'A')
            {
                //prompt user to enter number of acres, read input
                printf("Please enter a value: ");
                scanf("%f", &input);
                
                //convert acres to hectares, print output to user
                output = input / ACRES;
                printf("Your conversion is: %f hectares\n", output);

            }
            //reset user main menu option
            option = 0;
        }
        
        // if the user enters 4, kilograms and pounds mode
        else if (option == 4){ 
            //prompt the user to enter a conversion preference, read input
            printf("K for Kilograms to Pounds, P for Pounds to Kilograms: ");
            getchar();
            scanf("%c", &conversion);

            //if the user enters K, we are converting kg to lbs
            if (conversion == 'K')
            {
                //prompt user to enter number of kgs, read input   
                printf("Please enter a value: ");
                scanf("%f", &input);

                //convert kgs to lbs, print output to user
                output = input * POUNDS;
                printf("Your conversion is: %f pounds\n", output);

            }
            //if the user enters P, we are converting lbs to kg
            else if (conversion == 'P')
            {
                //prompt user to enter number of lbs, read input
                printf("Please enter a value: ");
                scanf("%f", &input);

                //convert lbs to kgs, print output to user
                output = input / POUNDS;
                printf("Your conversion is: %f kilograms\n", output);

            }
            //reset user main menu option
            option = 0;
         // if the user enters anything other than 1,2,3,4 or 5, prompt them to choose again
        } else {
            printf("Select a mode: (1 - 4), 5 to quit. \n");
            printf("1: Kilometers and Miles , 2: Litres and Gallons,\n 3: Hectares and Acres , 4: Kilograms and Pounds: ");
            scanf("%d", &option);

        }
    }
}