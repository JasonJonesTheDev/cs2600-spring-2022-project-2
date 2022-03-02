
#include <stdio.h>

// do not accept numbers less than 1 
int number_of_days () {

	int days;

	do {

		printf("\nPlease enter the number of days: ");

		scanf("%d", &days);

		if (days < 1) {
			printf("Number of days must be greater or equal to 1.\n");
			continue;
		}

		else {
			printf("You enter: %d.\n", days);
			break;
		}


	} while ((user < 1) || (user == 1));

	return user; 
}

// int main() {
// 
	// int i = number_of_days();
// 
// 
	// return 0; 
// }