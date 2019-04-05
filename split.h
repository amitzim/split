#ifndef _SPLIT_H_
#define _SPLIT_H_

#define SIZE(arr) sizeof(*arr)/sizeof(arr[0])

int number_of_delimeters(char *str, char delim);
char **split(char *str, ...);
void parse(char ***res, char *str, char delim, int number_of_elements);
void print_string_array(char **arr, int nelem);



#endif