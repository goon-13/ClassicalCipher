#ifndef __GET_INPUT_BY_GETCH_H__
#define __GET_INPUT_BY_GETCH_H__

int getInputNumByGetch();
void getInputNumArrayByGetchHaveSpaces(char input_num_string[], int input_num[]);
char* getInputLowercaseStringByGetch(char lower_string[]);
char* getInputUppercaseStringByGetch(char upper_string[]);
char* getInputUppercaseStringByGetchWithoutSpace(char upper_string[]); /* 接收输入的大写字符串，不能输入空格 */
char* getInputStringByGetch(char string[], unsigned int string_length); /* 获取输入的字符串，任意字符都会被接受 */

#endif