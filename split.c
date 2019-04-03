#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define SIZE(arr) sizeof(*arr)/sizeof(arr[0])

char *str1 = "Hi.my.name.is.Amit";
char *str2 = "Hi my name is Amit";

int number_of_delimeters(char *str, char delim);
char **split(char *str, ...);
void parse(char ***res, char *str, char delim, int number_of_elements);
void print_string_array(char **arr, int nelem);


int main(int argc, char *argv[]){
	split(str1, '.');
	return 0;
}

int number_of_delimeters(char *str, char delim){
	int res = 0;
	while (*str != '\0'){
		if (*str == delim)
			res++;
		str++;
	}
	return res;
}


void parse(char ***res, char *str, char delim, int number_of_elements){
	char **str_arr = *res;
	char *start = str;
	char *end = str;
	int current_element = 0;
	char *temp = NULL;
	int size = 0;
	while (*start != '\0'){
		size = 0;
		while (*end != delim && *end != '\0') {
			size++;
			end++;
		}
		temp = (char *)malloc(sizeof(size) + 1);
		strncpy(temp, start, size);
		temp[size] = '\0';
		str_arr[current_element] = temp;
		// printf("temp: %s\n", temp);
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
	int number_of_elements = number_of_delimeters(str, delimeter) + 1;
	printf("number_of_elements: %d\n", number_of_elements);
	
	res = malloc(sizeof(char (*)[]) * number_of_elements);
	// printf("HERE1\n");
	// print_string_array(res, number_of_elements);
	parse(&res, str, delimeter, number_of_elements);
	// printf("HERE2\n");
	print_string_array(res, number_of_elements);
	return res;
}
