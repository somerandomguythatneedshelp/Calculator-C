#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

// dear me

int (*(*createFunctionPointerArray())[])() {
	static int (*functionPointers[])(int, int) = { &add, &subtract };
	return &functionPointers;
}

int main() {

	int number1, number2;
	float answer;

	printf("Enter a number you want to add: ");
	scanf_s(" %d", &number1);

	printf("Enter another number you would like to add with %d: ", number1);
	scanf_s(" %d", &number2);


	int (*(*functionPtrArray)[])() = createFunctionPointerArray();

	int result = (*((*functionPtrArray)[0]))(number1, number2);
	printf("Result of 10 + 5: %d\n", result);

	result = (*((*functionPtrArray)[1]))(number1, number2);
	printf("Result of 10 - 5: %d\n", result);
}
