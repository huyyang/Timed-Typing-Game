//Everything is done in the main function. This program is
//going to ask the user to type in certain words and the 
//program is going to calculate how many seconds, minutes or
//miliseconds it takes for the user to finish. They can
//type in wrong answers if they want to but it wouldn't 
//matter because it would just start over in the while loop
//the only downside is it will just take up more time for
//them. After they are done with the game their score is
//going to be posted up

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>	//determines the see random and generator

#define NUM 9		//our constant variable that is 9

int main(){

	//an array of strings that contains 10 characters in which is the setnence
	//the quick brown fox jumps over the lazy dog. Each letter represents 1 bit
	char * strings[NUM] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

	struct timeval start;		//the struct time interval that is our starting
	struct timeval end;		//the struct time interval that is our ending
	struct timeval complete;	//the struct time interval that is our remanding

	//an integer determined for the for loop
	int i;

	//time_t declares to for the seeding the random generator
	time_t t;

	//a for loop that will loop 10 times and will print out the setence in order
	for(i = 0; i < NUM; ++i){
		
		//if the string index does not equal null we will print out the word
		if(strings[i] != NULL)
			printf("%s\n", strings[i]);	//prints out the array of strings
	}

	//the random generator declared
	srand((unsigned) time(&t));

	//goes through the for loop 10 times and will mix and match the index container in which
	//is the worl from the sentence strings
	for(i = 0; i < NUM; ++i){
	
		//declare an integer and determine where the switch integer will be
		//it won't be the same index as the last
		int spot = (rand()%(NUM - i)) + i;

		//makes a new temporary word so we can add our word into temporarily
		char * temp = strings[i];

		//the current string is going to be qeual to that new string spot
		strings[i] = strings[spot];

		//then set that spot into the current temp in which strings[i] is at.
		//We have switched the two characters with each other
		strings[spot] = temp;
	}
	
	printf("|||||||||||||||||||||||||||||||||||\n");	
	
	//for loop that will loop 10 tmes through the array to print out the random generated
	//sentence in which we have randomized in the last for loop
	for(i = 0; i < NUM; ++i){
		//if the strings array is NOT null we will print out the indexed array char
		if(strings[i] != NULL)
			printf("%s\n", strings[i]);
	}

	printf("Type the following words\n");
	printf("Remember, you are being timed\n");	

	//populate your first struct. This function was given from our professor to use
	gettimeofday(&start, NULL);

	//integer j declared for the while loop
	i = 0;

	//a while loop that is going to go 9 times in the while loop. When our integer
	//hits 9 we are getting out of the while loop
	while(i != NUM){

		//if the strings[i] is not null we will continue on with the while loop
		if(strings[i] != NULL){
			printf("Word # %i is " ,i + 1);	  	//printing "word # i is:"
			printf("%s", strings[i]);		//printing the string
			printf(" : ");
			char enter[20];				//makes sa variable for user input
			scanf("%s", enter);			//asks for user input
			if(strcmp(strings[i], enter) == 0){	//string compares the user input and string[i]
				printf("%s\n", "correct");	//if it is corret we will print out correct
				++i;				//if it is correct we will also increment up
			}
			else					//if it is not correct we will start over
				printf("%s\n", "incorrect, do it over");	//we will not increment
		}
	}
	//populate the end pointer 
	gettimeofday(&end, NULL);

	//timbersub function will grab the end struct and the start struct
	//and then add up the numbers into the complete struct				
	timersub(&end, &start, &complete);
	
	//prints out the integer casts tv_sec of complete struct
	printf("This is how many seconds: %d :", (int)complete.tv_sec);

	//prints out the integer casts tv_usec of complete struct 
	printf("This is how many microseconds: %d\n", (int)complete.tv_usec);

	//return 0 to exit program
	return 0;
}
