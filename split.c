#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "split.h"

char *str1 = "...Hi...my.name.is.Amit......";
char *str2 = "Hi my name is Amit";

int number_of_delimeters(char *str, char delim){
	int res = 0;
	while (*str == delim) str++;
	while (*str != '\0'){
		if (*str == delim && *str != *(str - 1)){
			res++;
		}
		str++;
	}
	if (*(str - 1) != delim) res++;
	return (res == 0) ? 1 : res;
}


void parse(char ***res, char *str, char delim, int number_of_elements){
	char **str_arr = *res;
	char *start = str;
	while (*start == delim) start++;
	char *end = start;
	int current_element = 0;
	char *temp = NULL;
	int size = 0;
	while (*start != '\0'){
		size = 0;
		while (*end != delim && *end != '\0') {
			size++;
			end++;
		}
		if (*(end - 1) == *end && *end == delim){
			end++;
			start = end;
			continue;
		}
		temp = (char *)malloc(sizeof(size) + 1);
		strncpy(temp, start, size);
		temp[size] = '\0';
		str_arr[current_element] = temp;
		
		current_element++;
		if (*end == '\0'){
			break;
		}
		end++;
		start = end;
	}

}


void print_string_array(char **arr, int nelem){
	int i;
	printf("[");
	for (i = 0 ; i < nelem ; i++){
		if (i == nelem - 1){
			printf("%s", arr[i]);
		}else {
			printf("%s, ", arr[i]);
		}
	}
	printf("]\n");
}


char **split(char *str, ...){
	char **res = NULL;
	char delimeter;
	va_list args;
	va_start(args, str);
	// exit(1);
	if (args == NULL){
		delimeter = ' ';
	}else{
		delimeter = va_arg(args, int);
	}
	va_end(args);
	printf("delimeter is: '%c'\n", delimeter);
	int number_of_elements = number_of_delimeters(str, delimeter);
	printf("number_of_elements: %d\n", number_of_elements);
	
	res = malloc(sizeof(char (*)[]) * number_of_elements);
	parse(&res, str, delimeter, number_of_elements);
	print_string_array(res, number_of_elements);
	return res;
}
