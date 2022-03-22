// Simple olympic sporting datatbase, Written by: David Alter

#include <ctype.h>
#include <stdio.h>
#include <readline/readline.h>

#define NAME_LEN 49 //Maximum length of a name in the structure
#define DB_SIZE 100 //Size of the database (number of entries allowed)

struct event //defining the sporting event structure
{
    int event_code; //event id 
    char name[NAME_LEN + 1]; //name of sporting event
    int num_in_team; //number of participants in each team
    char gender; //gender of participants
} events[DB_SIZE]; //create an array of structures

int num_events = 0; //number of total events in the database

//function declarations
int find_event(int num); //used to check wether an event cell is empty 
void i(void); //inserting a new event into the database
void s(void); //searching for and printing an entry in the database
void u(void); //updating an entry in the database
void p(void); //print the entire databsae
int read_line(char str[], int n);

int main(void){
    char code; //variable for menu option

    for (;;){ //infite loop
        printf("Enter operation code: "); //prompt user to enter command
        scanf(" %c", &code);

        while(getchar() != '\n'){ //skip until the end of the line
            ;
        }

        switch (code){
            case 'i':
                i(); //in the case of i, call insert command
                break;
            case 's':
                s(); //in the case of s, call search command
                break;
            case 'u':
                u(); //in the case of u, call update command
                break;
            case 'p':
                p(); //in the case of p, call print command
                break;
            case 'q':
                return 0; //quit the program
            default:
                printf("Unknow code, type i, s, u, p, or q to quit only.");
                //prompt for invalid input
        }
        printf("\n");
    }
}

/*
  find _event Looks up an event id in the events 
  array. Returns the array index if the part 
  number is found; otherwise, returns -1. 
*/
int find_event(int num){
    int i;

    for (i =0; i < num_events; i++)
        if (events[i].event_code == num) //if an event code is set, an entry exists
            return i;
    return -1; //else, return -1
}
/*
  i Prompts the user for information about a new 
  event and then inserts the event into the 
  database. Prints an error message and returns 
  prematurely if the event already exists or the 
  database is full.
*/ 
void i(void){
    int e_code, in_team; //variables for event code and number of competitors
    char gen; //gender of competitors

    if (num_events == DB_SIZE){ //check if the database is full
        printf("Database is full; can't add more.\n");
        return;
    }

    printf("Enter event code: "); //prompt user for event id
    scanf("%d", &e_code);

    if (find_event(e_code) >= 0){ //check to see if the event exists
        printf("Event already exists.\n");
        return;
    }

    events[num_events].event_code = e_code; //if the event does not exist, set the id
    
    printf("Enter event name: "); //prompt user for name of sporting event
    read_line(events[num_events].name, NAME_LEN);

    printf("Enter number of competitors: "); //prompt user for number of participants
    scanf("%d", &in_team);

    if(in_team < 10 || in_team > 99){ //check to see if number of participants is in range of 10 to 99
        printf("Error, number of competitors must be between 10 and 99");
        return;
    }
    events[num_events].num_in_team = in_team; //if it is, set the integer

    printf("Enter the gender: "); //prompt user to enter gender
    scanf(" %c", &gen);

    if (gen == 'M' || gen == 'W' || gen == 'X'){ //check to see if input is valid
        events[num_events].gender = gen;
    } else {
        printf("Gender can only be M for Men, W for Women, and X for Mixed");
        return;
    }

    num_events++; //increment number of events in database
}
/*
  s Prompts the user to enter an event id, then 
  looks up the event in the database. If the event 
  exists, prints the id, name, competitors, and gender; 
  if not, prints an error message. 
*/
void s(void){
    int i, num; //variables for array index 

    printf("Enter event code: ");
    scanf("%d", &num);
    i = find_event(num);

    if(i >= 0){ //if event exists print it
        printf("Event Code      Event Name      Competitors     Gender");
        printf("\n%d              %s              %d              %c", events[i].event_code, events[i].name, 
        events[i].num_in_team, events[i].gender);
    } else //send error message if does not exist
        printf("Event not found.\n");
        return; 

}
/*
  u Prompts the user to enter an event id. 
  Prints an error message if the event doesn't 
  exist; otherwise, prompts the user to enter 
  change in all event properties and updates the database. 
*/
void u(void){
    int i, code, competitors; //variables for index, number of competitiors
    char gender;
    char name[NAME_LEN];

    printf("Enter event code: ");
    scanf("%d", &code);
    i = find_event(code);

    if (i >= 0){ //if event exists prompt user to update fields
        printf("Enter event name: "); //prompt user for name of sporting event
        read_line(events[code-1].name, NAME_LEN);

        printf("Enter number of competitors: "); //prompt user for number of participants
        scanf("%d", &competitors);

        if(competitors < 10 || competitors > 99){ //check to see if number of participants is in range of 10 to 99
            printf("Error, number of competitors must be between 10 and 99");
            return;
        }
        events[code-1].num_in_team = competitors; //if it is, set the integer

        printf("Enter the gender: "); //prompt user to enter gender
        scanf(" %c", &gender);

        if (gender == 'M' || gender == 'W' || gender == 'X'){ //check to see if input is valid
            events[code-1].gender = gender;
    }   else {
            printf("Gender can only be M for Men, W for Women, and X for Mixed");
            return;
        }

    } else {
        printf("Event not found.\n");
        return;
    }

}
/*
  p Prints a listing of all events in the database, 
  showing the event id, name, competitors, 
  and gender. Events are printed in the 
  order in which they were entered into the 
  database. 
*/
void p(void){
   int i;

   printf("Event Code      Event Name      Competitors     Gender");
   for(i =0; i < num_events; i++){
        printf("\n%d              %s            %d              %c", events[i].event_code, events[i].name, 
        events[i].num_in_team, events[i].gender);
   }
}

/*
  read_line Skips leading white-space characters, then 
  reads the remainder of the input line and 
  stores it in str. Truncates the line if its 
  length exceeds n. Returns the number of 
  characters stored. 
*/
int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()))
    ;
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}