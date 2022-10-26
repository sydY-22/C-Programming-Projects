#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//global variables
int Selection;
int x;
int y;
int r;
int d;
//int z;
//initializing typedef struct contact
typedef struct {
	char firstName[30];
	char lastName[30];
	char number[15];
} contact;
//declaring the functions
void addFriend(contact *);
void showFriends(contact *);
void deleteFriend(contact *);
void orderFriends(contact *);
void findFriend(contact *);
void randomFriend(contact *);
void deleteAllFriends(contact *);

//intialize size = 1
//size keeps track of the amount of memory
int size = 1;
//main function
int main () {
	//allocating the memory from the contact struct to phoneBook
	contact * phoneBook = malloc(size * sizeof(contact ));
	//do while loop
	do {
		//int number;
		printf("\nPhone Book Menu: \t");
		printf("\n1) Add a Friend");
		printf("\n2) Show Friends");
		printf("\n3) Delete Friends");
		printf("\n4) Order Phone Book Alphabetically");
		printf("\n5) Find a Number");
		printf("\n6) Call a Random Friend");
		printf("\n7) Delete all");
		printf("\n8) Exit");
		printf("\n Please choose an Option: ");
		scanf("%d", &Selection);
		//if user pressed 1 to add a friend
		if (Selection == 1) {
			//call the function
			addFriend(phoneBook);
		}
		//if the user pressed 2 to show friends
		if (Selection == 2) {
			//call the function
			showFriends(phoneBook);
		}
		//if the user pressed 3 to delete a friend
		if (Selection == 3) {
			//call the function
			deleteFriend(phoneBook);
		}
		//if the user pressed 4 to order friends alphabetically by last name
		if (Selection == 4) {
			//call the function
			orderFriends(phoneBook);
		}
		//if the user pressed 5 to find a friend
		if (Selection == 5) {
			//call the function
			findFriend(phoneBook);
		}
		//if the user pressed 6 to randomly call a friend
		if (Selection == 6) {
			//call the function
			randomFriend(phoneBook);
		}
		//if the user pressed 7 to delete all friends
		if (Selection == 7) {
			//call the function
			deleteAllFriends(phoneBook);
		}
	}
	//while selection = 8 the do while loop is terminated
	while (Selection != 8);
	return 0;
}

//addFriend function
void addFriend(contact * phoneBook) {
	//takes the user input for first name
	printf("\nFirst Name: ");
	scanf("%s", phoneBook[size-1].firstName);
	//takes input for a last name
	printf("\nLast Name: ");
	scanf("%s", phoneBook[size-1].lastName);
	//takes input for the number
	printf("\n Enter the Number: ");
	scanf("%s", phoneBook[size-1].number);
	//adds on to the size of memory
	size ++;
	//then use the realloc function to copy the memory into a new location
	phoneBook = realloc(phoneBook, size * sizeof(contact));
	printf("\n%d) %s %s \t %s", size-2, phoneBook[size-2].firstName, phoneBook[size-2].lastName, phoneBook[size-2].number);
} //end addFriend function

//showFriends function
void showFriends(contact * phoneBook) {
	//loops through all the inputted contact information that was stored in phoneBook
	for (x = 0; x < size-1; x++) {
		//displays the contact information
		printf("\n\t %d)%s \t %s \t %s \n", x, phoneBook[x].firstName, phoneBook[x].lastName, phoneBook[x].number);
	} //end for loop
} //end showFriends function

//deleteFriend function
void deleteFriend(contact * phoneBook) {
	//is variable to let the user choose which friend to delete
	int choice;
	//is the index value
	int i;
	//ask the user for a contact number to be deleted
	printf("\n Which contact do you want to delete: ");
	scanf("%d", &choice);
	//loops through to find the contact the user wanted to delete
	for (i = choice; i < size; i++) {
		phoneBook[i] = phoneBook[i +1];
	} //end for loop
	//subtracts from size of memory
	size --;
	//use the realloc function to copy memory into a new location
	phoneBook = realloc(phoneBook, size * sizeof(contact));
} //end deleteFriend function

//orderFriends function sorts friends alphabetically by last name
void orderFriends(contact * phoneBook) {
	//character array for order 
	char order[25];
	//index value
	int z;
	for (z = 0; z < size-1; z++) {
		for (y = z+1; y < size-1; y++) {
			//sorts the values alphabeticaly by last name
			//use the strcmp function to compare the values
			if (strcmp(phoneBook[z].lastName, phoneBook[y].lastName) > 0) {
				strcpy(order, phoneBook[z].firstName);
				strcpy(phoneBook[z].firstName, phoneBook[y].firstName);
				strcpy(phoneBook[y].firstName, order);
				
				strcpy(order, phoneBook[z].lastName);
				strcpy(phoneBook[z].lastName, phoneBook[y].lastName);
				strcpy(phoneBook[y].lastName, order);
				
				strcpy(order, phoneBook[z].number);
				strcpy(phoneBook[z].number, phoneBook[y].number);
				strcpy(phoneBook[y].number, order);
				
			} //end of if statement
		} //end of for loop
	} //end of for loop
//prints out the alphabetically ordered contacts by looping through the index value z.
//sorted alphabetically by last name
for (z = 0; z < size-1; z++) {
	printf("\n\t%d)%s\t%s\t%s\n", z, phoneBook[z].firstName, phoneBook[z].lastName, phoneBook[z].number);
	} //end for loop
} //end orderFunction


//findFriend function
void findFriend(contact * phoneBook) {
	//character array for find
	char find[20];
	//user enters a first name
	printf("\nPlease enter a First Name: ");
	//the name the user entered is stored in "find" character array 
	scanf("%s", find);
	//loops through all the phoneBook values
	for (x  = 0; x < size-1; x ++) {
		//if the first name the user entered is equal to a first name in the phoneBook
		//strstr function takes two strings and compares to see if they are alike.
		if (strstr(find, phoneBook[x].firstName) != NULL) {
			//then print the contact information 
			printf("\n\t%d) %s\t%s\t%s\n", y, phoneBook[x].firstName, phoneBook[x].lastName, phoneBook[x].number);
		} //end if statement
	} //end for loop
} //end findFriend function

//randomFriend function
void randomFriend(contact * phoneBook) {
	int random;
	srand(time(0));
	random = rand() % size;
	//if the contacts stored in memory is less than the total + 1.	
	if (random < size-1) {
		//prints a random contact
		printf("\n Calling: \t%d) %s\t%s\t%s\n", random, phoneBook[random].firstName, phoneBook[random].lastName, phoneBook[random].number);
	}
	//if statement for if size is over the number of contacts stored in memory.
	if (random == size-1) {
		//subtract 1 from random to get random < size-1
		random = random -1;
		//prints a random contact
			printf("\n Calling: \t%d) %s\t%s\t%s\n", random, phoneBook[random].firstName, phoneBook[random].lastName, phoneBook[random].number);
	}
}
//deleteAllFriends function
void deleteAllFriends(contact * phoneBook) {
	//in this for loop I loop through the number index values stored in memory
	for (d = 0; d < size-1; d++) {
		phoneBook[d] = phoneBook[d+1];
		//subtract from size to delete all the memory
		size--;
		//then realloc function to copy memory into a new location
		phoneBook = realloc(phoneBook, size * sizeof(contact));
	}	
	printf("\n All Friends have been deleted.");
	//subtract from the size to get rid of all the memory stored
	size--;
	//use the free function to free up the avaliable memory in phoneBook
	free(phoneBook);
}

