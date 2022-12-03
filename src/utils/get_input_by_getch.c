#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

/**
  * @brief  使用getch获取输入，取得输入的数字
  * @param  无
  * @retval num getch逐位拼凑出的字符串所转换成的数字
  */
int getInputNumByGetch() {
    char input_num[50] = {'0'};
    char c;
    int i = 0; /* 用于存储输入的字符到input_num的数组下标 */
    int num = 0;

    /* 使用getch逐个获取字符c，最后再把获取的字符拼成串，转化为数字
     * 使用do while 因为第一次需要先获取输入c再进行判断
     */
    do {
        c = getch(); /* getch from <conio.h>, getch不等the Return key, 马上响应输入的字符。使用getchar会需要  */
        if(isdigit(c) != 0) { /* isdigit from <ctype.h> */
            input_num[i] = c;
            i++;
            input_num[i] = '\0'; /* 字符串最后一位 */
            printf("%c", c);
        } else if(c == 8 && i) {/* ASCII码值8对应退格，&& i必需，判断输入字符串还有字符可以删 */
            input_num[i] = '\0'; /* 字符串最后一位 */
            i--;
            printf("\b \b"); /* 光标回退一格，输出空格覆盖想删掉的上一字符，光标再回退一格 */
        }
    } while (c != 13);/* ASCII码值对应：10-\n-换行 13-\r-回车 */

    num = atoi(input_num); /* atoi from <stdlib.h> 字符串转整数 */
    printf("\n");
    return num;
}

/**
  * @brief  使用getch获取输入，取得输入的数字（包含空格），返回整个数字的字符串
  * @param  input_num_string 存储输入数字字符串的数组
  * @param  input_num 存储要返回的数字数组 getch逐位拼凑出的字符串所转换成的数字
  * @retval 无
  */
void getInputNumArrayByGetchHaveSpaces(char input_num_string[], int input_num[]) {
    char c;
    int i = 0; /* 用于存储输入的字符到input_num_string的数组下标 */
    const char split_symbol[2] = " ";
    char* token;

    /* [1] 先输入完整的以空格隔开数字的字符串，再对其进行分割处理 */
    /* 使用do while 因为第一次需要先获取输入c再进行判断 */
    do {
        c = getch(); /* getch from <conio.h>, getch不等the Return key, 马上响应输入的字符。使用getchar会需要  */
        if(isdigit(c) || c==32) { /* 输入明文字符串必须是小写字母或空格 ASCII码值 a~z-97~122 空格-32 */
            input_num_string[i] = c;
            i++;
            input_num_string[i] = '\0'; /* 字符串最后一位 */
            printf("%c", c);
        } else if(c == 8 && i) {/* ASCII码值8对应退格，&& i必需，判断输入字符串还有字符可以删 */
            input_num_string[--i] = '\0'; /* 字符串最后一位 */
            printf("\b \b"); /* 光标回退一格，输出空格覆盖想删掉的上一字符，光标再回退一格 */
        }
    } while (c != 13);/* ASCII码值对应：10-\n-换行 13-\r-回车 */
    printf("\n");
    /* 输入为空校验 */
    if(i == 0) { /* 什么都没输入直接回车 */
        return; /* 接下来的操作都不要做了直接返回 */
    }

    /* [2] 使用 strtok 分割成unsigned int数组再返回
     * 由于strtok函数并不是线程安全的，所以很多情况下并不再使用这个函数，而是由程序员实现自己的字符串分割函数从而保证线程安全，
     * 在Linux中定义了strtok_r函数，这个函数是strtok函数的线程安全版本
     */
    i = 0; /* 存储到input_num数组的下标 */
    token = strtok(input_num_string, split_symbol);
    input_num[i++] = atoi(token)-1; /* 数组下标从 0 开始，故所有下标位置需要-1 */
    while(token != NULL) {
        /* 【错误写法】 
            if(token != 32) { // 空格 ASCII 32 
                printf("token[%s]\n", token);
            }
        */
        /* 在strtok第一个参数为NULL的时候，该函数默认使用上一次未分割完的字符串的未分割的起始位置作为本次分割的起始位置，直到分割结束为止 */
        token = strtok(NULL, split_symbol); /* 用法为何是NULL?  */
        if(token != 0) {
            input_num[i++] = atoi(token)-1; /* 数组下标从 0 开始，故所有下标位置需要-1 */
        }
    }
}

/**
  * @brief  使用getch逐位取得输入的字符串（小写）
  * @param  lower_string
  * @retval lower_string 输入的小写字符串
  */
char* getInputLowercaseStringByGetch(char lower_string[]) {
    char c; /* 用于获取每一位输入的字符 */
    int i = 0; /* 用于存储输入的字符到input_string的数组下标 */

    /* 使用getch逐个获取字符c，最后再把获取的字符拼成串
     * 使用do while 因为第一次需要先获取输入c再进行判断
     */
    do {
        c = getch(); /* getch from <conio.h>, getch不等the Return key, 马上响应输入的字符。使用getchar会需要  */
        if((c>=97 && c<=122) || c==32) { /* 输入明文字符串必须是小写字母或空格 ASCII码值 a~z-97~122 空格-32 */
            lower_string[i] = c;
            i++;
            lower_string[i] = '\0'; /* 字符串最后一位 */
            printf("%c", c);
        } else if(c == 8 && i) {/* ASCII码值8对应退格，&& i必需，判断输入字符串还有字符可以删 */
            lower_string[i] = '\0'; /* 字符串最后一位 */
            i--;
            printf("\b \b"); /* 光标回退一格，输出空格覆盖想删掉的上一字符，光标再回退一格 */
        }
    } while (c != 13);/* ASCII码值对应：10-\n-换行 13-\r-回车 */

    printf("\n");
    return lower_string;
}

/**
  * @brief  使用getch逐位取得输入的字符串（大写）
  * @param  upper_string
  * @retval upper_string 输入的大写字符串
  */
char* getInputUppercaseStringByGetch(char upper_string[]) {
    char c; /* 用于获取每一位输入的字符 */
    int i = 0; /* 用于存储输入的字符到input_string的数组下标 */

    /* 使用getch逐个获取字符c，最后再把获取的字符拼成串
     * 使用do while 因为第一次需要先获取输入c再进行判断
     */
    do {
        c = getch(); /* getch from <conio.h>, getch不等the Return key, 马上响应输入的字符。使用getchar会需要  */
        if((c>=65 && c<=90) || c==32) { /* 输入明文字符串必须是大写字母或空格 ASCII码值 A~Z-65~90 空格-32 */
            upper_string[i] = c;
            i++;
            upper_string[i] = '\0'; /* 字符串最后一位 */
            printf("%c", c);
        } else if(c == 8 && i) {/* ASCII码值8对应退格，&& i必需，判断输入字符串还有字符可以删 */
            upper_string[i] = '\0'; /* 字符串最后一位 */
            i--;
            printf("\b \b"); /* 光标回退一格，输出空格覆盖想删掉的上一字符，光标再回退一格 */
        }
    } while(c != 13);/* ASCII码值对应：10-\n-换行 13-\r-回车 */

    printf("\n");
    return upper_string;
}

/**
  * @brief  使用getch逐位取得输入的字符串（大写），不接收空格
  * @param  upper_string
  * @retval upper_string 输入的大写字符串
  */
char* getInputUppercaseStringByGetchWithoutSpace(char upper_string[]) {
    char c; /* 用于获取每一位输入的字符 */
    int i = 0; /* 用于存储输入的字符到input_string的数组下标 */

    /* 使用getch逐个获取字符c，最后再把获取的字符拼成串
     * 使用do while 因为第一次需要先获取输入c再进行判断
     */
    do {
        c = getch(); /* getch from <conio.h>, getch不等the Return key, 马上响应输入的字符。使用getchar会需要  */
        if((c>=65 && c<=90)) { /* 输入明文字符串必须是大写字母或空格 ASCII码值 A~Z-65~90 */
            upper_string[i] = c;
            i++;
            upper_string[i] = '\0'; /* 字符串最后一位 */
            printf("%c", c);
        } else if(c == 8 && i) { /* ASCII码值8对应退格，&& i必需，判断输入字符串还有字符可以删 */
            upper_string[i] = '\0'; /* 字符串最后一位 */
            i--;
            printf("\b \b"); /* 光标回退一格，输出空格覆盖想删掉的上一字符，光标再回退一格 */
        }
    } while(c != 13);/* ASCII码值对应：10-\n-换行 13-\r-回车 */

    printf("\n");
    return upper_string;
}

/**
  * @brief  使用getch逐位取得输入的字符串
  * @param  string
  * @param  string_length 输入字符串的长度，超过这个长度不会被接收和显示在控制台
  * @retval string 输入的字符串
  */
char* getInputStringByGetch(char string[], unsigned int string_length) {
    char c; /* 用于获取每一位输入的字符 */
    int i = 0; /* 用于存储输入的字符到input_string的数组下标 */

    /* 使用getch逐个获取字符 c，最后再把获取的字符拼成串
     * 使用do while 因为第一次需要先获取输入c再进行判断
     */
    do {
        c = getch(); /* getch from <conio.h>, getch不等the Return key, 马上响应输入的字符。使用getchar会需要  */
        
        if(c == 8 && i) {/* ASCII码值8对应退格，&& i必需，判断输入字符串还有字符可以删 */
            string[i] = '\0'; /* 字符串最后一位 */
            i--;
            printf("\b \b"); /* 光标回退一格，输出空格覆盖想删掉的上一字符，光标再回退一格 */
        } else if(i < string_length) {
            string[i++] = c;
            string[i] = '\0';
            if(c == 8 || c == 13) {
                printf("*");    
            } else {
                printf("%c", c);
            }
        }
    } while (c != 13);/* ASCII码值对应：10-\n-换行 13-\r-回车 */

    printf("\n");
    return string;
}