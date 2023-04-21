//21UG1073

#include <stdio.h>
int main() {
    int year = 2023;
    int* ptr = &year;
    printf("The value of <year> is %d\n", year);
    printf("The memory address of <year> is %p\n", &year);
    printf("The 2023 <year> using the pointer <ptr> is %p\n", ptr);
    return 0;
}