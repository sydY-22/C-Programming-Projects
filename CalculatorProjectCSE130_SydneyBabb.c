/*
Sydney Babb
Lab 4, Sec. B
February 10, 2022
Calculator Part 2
*/
#include <stdio.h>
//CECS130Lab4_Babb_Sydney.c
//variables
int Selection;
int Num_1;
int Num_2;

float Number_1;
float Number_2;

int TestVal;
int PrimeNum;
int Fact_Num;

//the function prototypes
float addTwoNumbers(float, float);
float subtractTwoNumbers(float, float);
float multiplyTwoNumbers(float, float);
float divideTwoNumbers(float, float);
int modulusTwoNumbers(int, int);
int testIfPrime(int);
int factorial(int);
int powerOfNumber(int, int);
int allEvenNumbers(int);

//global variables
int ans;
int f;
int main()
{
	//do while loop  to loop through the menu and the operations.
	do{
	
		printf("\nCalculator Menu:");
		printf("\n1) Addition");
		printf("\n2) Subtract");
		printf("\n3) Multiplication");
		printf("\n4) Division");
		printf("\n5) Modulus");
		printf("\n6) Test if Prime");
		printf("\n7) Factorial");
		printf("\n8) Power");
		printf("\n9) Find all Even Numbers between 1 and integer");
		printf("\n0) Exit");
		printf("\n Choose an operation: ");
		scanf("%d", &Selection);
		//if statements for if the user selected 1 to add.
		if (Selection == 1) {
			//then the use inputs the two numbers to perform the operation.
			printf("\n First Number: ");
			scanf("%f", &Number_1);
			printf("\n Second Number: ");
			scanf("%f", &Number_2);
			//then call the addTwoNumbers function.
			printf("\n Answer: %.2f", addTwoNumbers(Number_1, Number_2));
		}
		if (Selection == 2) {
			//ask the user for two numbers
			printf("\n First Number: ");
			scanf("%f", &Number_1);
			printf("\n Second Number: ");
			scanf("%f", &Number_2);
			//call the function and print then round the answer to hundredths place
			printf("\n Answer: %.2f", subtractTwoNumbers(Number_1, Number_2));
		}
		if (Selection == 3){
			//ask the user for the two numbers
			printf("\n First Number: ");
			scanf("%f", &Number_1);
			printf("\n Second Number: ");
			scanf("%f", &Number_2);
			//call the function
			printf("\n Answer: %.2f", multiplyTwoNumbers(Number_1, Number_2));
		}
		if (Selection == 4) {
			//ask the user for two numbers to perform the operation
			printf("\n First Number: ");
			scanf("%f", &Number_1);
			printf("\n Second Number: ");
			scanf("%f", &Number_2);
			//call the function
			printf("\n Answer: %.2f", divideTwoNumbers(Number_1, Number_2));
		}
		if (Selection == 5) {
			//ask for two numbers (integers)
			printf("\n First Number: ");
			scanf("%d", &Num_1);
			printf("\n Second Number: ");
			scanf("%d", &Num_2);
			//call the function
			printf("\n Answer: %d", modulusTwoNumbers(Num_1, Num_2));
		}
		if (Selection == 6) {
			//ask the user for an integer to test
			printf("\n Please enter a number to be tested: ");
			scanf("%d", &TestVal);
			//then call the function
			testIfPrime(TestVal);
		}
		if (Selection == 7) {
			//ask the user for an integer
			printf("\n Please enter a number to calculate the factorial: ");
			scanf("%d", &Fact_Num);
			//then call the function
			factorial(Fact_Num);
		}
		if (Selection == 8) {
			//ask the user for a base value and exponent value
			printf("\n Base Number: ");
			scanf("%d", &Num_1);
			printf("\n Exponent: ");
			scanf("%d", &Num_2);
			//call the function
			printf("\n %d^%d = %d", Num_1, Num_2, powerOfNumber(Num_1, Num_2));
		}
		if (Selection == 9) {
			//ask the user for an integer
			printf("\n Please enter a number: ");
			scanf("%d", &Num_1);
			//then call the function
			allEvenNumbers(Num_1);
		}
    }
    //if the user selects operation 0 (exit) the do while loop will end.
	while(Selection != 0);
	return 0;
}
	//for this function I would add the two numbers the user inputted and then call it in the main function.
	float addTwoNumbers(float Number_1, float Number_2) {
		//this is the return value of the operation.
		return Number_1 + Number_2;
	}
	//the function definition
	float subtractTwoNumbers(float Number_1, float Number_2){
		//then return value 
		return Number_1 - Number_2;
	}
	float multiplyTwoNumbers(float Number_1, float Number_2){
		return Number_1 * Number_2;
	}
	float divideTwoNumbers(float Number_1, float Number_2) {
		return Number_1 / Number_2;
	}
	int modulusTwoNumbers(int Num_1, int Num_2) {
		return Num_1 % Num_2;
	}
	int testIfPrime(int TestVal) {
		 int i;
		 //if TestVal (user input) equals 2 to be a prime number
		 if (TestVal == 2) {
		 	//return value if true
		 	return printf("%d is a prime number\n", TestVal);
		 }
		 //I made a for loop to loop through the i and then increment it until it is less than the TestVal.
		 for (i = 2; i < TestVal; i++) {
			 //if the TestVal modulo i is equal to 1 to print the number is prime.
			 if (i == TestVal - 1 && TestVal % i == 1) {
			 	//returns the value that the number is prime.
		 		return printf("%d is a prime number\n", TestVal);
		 	}
		 	//if the TestVal is not prime
			 if (TestVal % i == 0) {
			 	//then return the TestVal is not prime because...
		 		return printf("%d is not a prime number because %d * %d = %d\n", TestVal, TestVal / i, i, TestVal / i * i);		 	
			 }
		 }
	}
	//fucntion defintion
	int factorial(int Fact_Num) {
		int x;
		//for loop x = Fact_Num - 1 and then decrement the x until is equal to 1
		for (x = Fact_Num - 1; x >= 1; x--) {
			//multily Fact_Num by x each time the x is decremented
			Fact_Num *= x;
		}
		//then return value
		return printf("%d", Fact_Num);
	}
	int powerOfNumber(int Num_1, int Num_2) {
		int p;
		int s = 0;
		p = Num_1;
		//for loop for s equal to 1 and s is less than Num_2 and increment s.
		for (s = 1; s < Num_2; s++) {
			//multiply Num_1 and p
			Num_1 *= p;
		}
		//then return value
		return Num_1;
	}
	int allEvenNumbers(int Num_1) {
		int r;
		int n = 0;
		//array that holds 1000 elements
		int even[1000];
		//for loop for r equal zero, r is less than Num_1, and increment r.
		for (r = 0; r < Num_1; r++) {
			//if statement r modulo 2 equal 0 then its even number.
			if (r % 2 == 0) {
				//store array elements n and values of r.
				even[n] = r;
				//increment n each time
				n += 1;
				//return value
				printf("%d\t", r);
			}
		}
	}
	
