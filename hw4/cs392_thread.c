/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * cs392_thread
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int item1_counter = 0; 		//Creation of global variables (counters)
int item2_counter = 0;
int item3_counter = 0;

void *cs392_thread_run(void *path){
	char str[8];	//8 chosen because it is the exact length of each line including the '\0'.

	pthread_mutex_t lock1;
	pthread_mutex_t lock2;		//Locks set for each counter
	pthread_mutex_t lock3;
	
	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);	//Locks initialized
	pthread_mutex_init(&lock3, NULL);
	
	while(fgets(str, 8, path) != NULL){
	//Locks each counter when used so that no race conditions occur 
	//Destroys each lock when done
		if(strcmp(str, "+item1\n") == 0){
			pthread_mutex_lock(&lock1);
			item1_counter++;
			pthread_mutex_unlock(&lock1);
		} else if(strcmp(str, "-item1\n") == 0){
			pthread_mutex_lock(&lock1);
			item1_counter--;
			pthread_mutex_unlock(&lock1);
		} else if(strcmp(str, "+item2\n") == 0){
			pthread_mutex_lock(&lock2);
			item2_counter++;
			pthread_mutex_unlock(&lock2);
		} else if(strcmp(str, "-item2\n") == 0){
			pthread_mutex_lock(&lock2);
			item2_counter--;
			pthread_mutex_unlock(&lock2);
		} else if(strcmp(str, "+item3\n") == 0){
			pthread_mutex_lock(&lock3);
			item3_counter++;
			pthread_mutex_unlock(&lock3);
		} else if(strcmp(str, "-item3\n") == 0){
			pthread_mutex_lock(&lock3);
			item3_counter--;
			pthread_mutex_unlock(&lock3);
		} else {
			perror("Error: Encountered incorrect file argument."); 
			exit(1);
		}
	}	
	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	pthread_mutex_destroy(&lock3);
}



int main(int argc, char* argv[]){
	//Input checking and thread creation
	if(argc != 4){
		perror("Incorrect number of args.");
		exit(1);
	}

	FILE *fp1, *fp2, *fp3;
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");
	fp3 = fopen(argv[3], "r");
	if(fp1 == NULL || fp2 == NULL || fp3 == NULL){  
		perror("File Missing");
		exit(1);
	} 
	
	pthread_t thread1, thread2, thread3;
	int x, y, z;
	x = pthread_create(&thread1, NULL, cs392_thread_run, fp1);
	y = pthread_create(&thread2, NULL, cs392_thread_run, fp2);
	z = pthread_create(&thread3, NULL, cs392_thread_run, fp3);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("The final value of item1_counter, item2_counter, and item3_counter are %d, %d, and %d", item1_counter, item2_counter, item3_counter);

	exit(0);
}
