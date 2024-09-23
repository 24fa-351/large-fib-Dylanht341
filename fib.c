#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int recursive_fibonacci(int n) {     // Takes in the nth number to calculate to
   // Checks certain cases that do not need calculation
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

unsigned long long int iterative_fibonacci(int n) {     // Takes in the nth number to calculate to
   unsigned long long int first = 0;
   unsigned long long int second = 1;
   unsigned long long int sum;
   int ix;                 // Iterator variable that keeps track of the nth iteration of the Fibonacci sequence
   
   // Checks certain cases that do not need calculation
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   for (ix = 3; ix <= n; ix++) {
      sum = first + second;         // Stores the current Fibonacci number
      first = second;               // Sets variable to the next Fibonacci number
      second = sum;                 // Sets variable to the next Fibonacci number
   }
   return sum;
}

int main(int argc, char *argv[]) {   // Reads command line arguments and stores them in argv
   
   int command_line_input = atoi(argv[1]);   // Stores the integer to be added to the one in the file
   const char *method = argv[2];             // Stores the method of calculating the Fibonacci Sequence
   unsigned long long int answer;                               // Creates an integer to store the answer

   // Checks the method of calculation and calls the respective function and returns the result
   if (strcmp(method, "i") == 0) {
      answer = iterative_fibonacci(command_line_input);
      printf("%llu", answer);
      return answer;
   } else if (strcmp(method, "r") == 0) {
      answer = recursive_fibonacci(command_line_input);
      printf("%llu", answer);
      return answer;
   } else {                                     // Prints an error in case of an invalid input
      printf("Unrecognized method.\n");
   }
   return 0;
}
