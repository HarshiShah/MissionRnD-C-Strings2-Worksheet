/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word){
	int index1 = 0, index2 = 0, count = 0, len = 0;
	while (word[index2] != 0){
		len++;
		index2++;
	}
	index2 = 0;
	while (str[index1] != '\0'){
		if (word[index2] == '\0'){
			count++;
			index2 = 0;
			index1 = index1 - (len - 1);
		}
		if (str[index1] == word[index2]){
			index1++;
			index2++;
		}
		else{
			if (index2 == 0)
				index1++;
			else
				index2 = 0;
		}
	}
	if (word[index2] == '\0')
		count++;
	return count;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	static int index;
	static int len;
	int index2 = 0;
	if (index == 0){
		while (word[index2] != '\0'){
			len++;
			index2++;
		}
		index2 = 0;
	}
	while (word[index2] != '\0'){
		if (str[index] == '\0'){
			index = 0;
			len = 0;
			return 0;
		}
		if (str[index] == word[index2]){
			index++;
			index2++;
		}
		else{
			if (index2 == 0)
				index++;
			else
				index2 = 0;
		}
	}
	index -= (len - 1);
	return 1 + count_word_int_str_way_2_recursion(str, word);

}

