/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	int index = 0, start = 0;
	while (str[index] != '\0'){
		if (str[index] == ' ' && str[index + 1] != ' ' && str[index + 1] != '\0')
			start = index + 1;
		index++;
	}
	while (index != 0 && str[index - 1] == ' ')
		index--;
	char* last_word = (char*)malloc(sizeof(char)*(index - start + 1));
	int i = 0;
	while (start < index){
		last_word[i++] = str[start++];
	}
	last_word[i] = '\0';
	return last_word;

}
