//21UG1073

#include <stdio.h>

int divide(int *num1_ptr, int *num2_ptr);

int main() {
    int num1, num2;
    int *ptr1, *ptr2;
    
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    
    printf("Enter the second integer: ");
    scanf("%d", &num2);
    
    ptr1 = &num1;
    ptr2 = &num2;
    
    int result = divide(ptr1, ptr2);
    
    printf("The result of num1 / num2 is: %d\n", result);
    
    return 0;
}

int divide(int *num1_ptr, int *num2_ptr) {
    return (*num1_ptr) / (*num2_ptr);
}