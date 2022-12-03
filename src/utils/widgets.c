#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "widgets.h"

/**
  * @brief  交换 a 和 b 两个数的值
  * @param  a 
  * @param  b 
  * @retval 无
  */
void swap(int* a, int* b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

/**
  * @brief  检查传入的字符串是否出现重复字母
  * @param  text 字符串
  * @retval 0 无重复 1 有重复
  */
int checkForDuplication(char text[]) {
    /* 通过 letters_show_num 数组记录每位字母在字符串中出现的次数，只要超过1则返回1表示有重复，否则返回0表示没有重复 */
    char letters_show_num[26];
    memset(letters_show_num, 0, 26);
    for(int i = 0; i < strlen(text); i++) {
        switch(text[i]) {
            case 'a': case 'A': {letters_show_num[0]++; if(letters_show_num[0]>1){return 1;} break;}
            case 'b': case 'B': {letters_show_num[1]++; if(letters_show_num[1]>1){return 1;} break;}
            case 'c': case 'C': {letters_show_num[2]++; if(letters_show_num[2]>1){return 1;} break;}
            case 'd': case 'D': {letters_show_num[3]++; if(letters_show_num[3]>1){return 1;} break;}
            case 'e': case 'E': {letters_show_num[4]++; if(letters_show_num[4]>1){return 1;} break;}
            case 'f': case 'F': {letters_show_num[5]++; if(letters_show_num[5]>1){return 1;} break;}
            case 'g': case 'G': {letters_show_num[6]++; if(letters_show_num[6]>1){return 1;} break;}
            case 'h': case 'H': {letters_show_num[7]++; if(letters_show_num[7]>1){return 1;} break;}
            case 'i': case 'I': {letters_show_num[8]++; if(letters_show_num[8]>1){return 1;} break;}
            case 'j': case 'J': {letters_show_num[9]++; if(letters_show_num[9]>1){return 1;} break;}
            case 'k': case 'K': {letters_show_num[10]++; if(letters_show_num[10]>1){return 1;} break;}
            case 'l': case 'L': {letters_show_num[11]++; if(letters_show_num[11]>1){return 1;} break;}
            case 'm': case 'M': {letters_show_num[12]++; if(letters_show_num[12]>1){return 1;} break;}
            case 'n': case 'N': {letters_show_num[13]++; if(letters_show_num[13]>1){return 1;} break;}
            case 'o': case 'O': {letters_show_num[14]++; if(letters_show_num[14]>1){return 1;} break;}
            case 'p': case 'P': {letters_show_num[15]++; if(letters_show_num[15]>1){return 1;} break;}
            case 'q': case 'Q': {letters_show_num[16]++; if(letters_show_num[16]>1){return 1;} break;}
            case 'r': case 'R': {letters_show_num[17]++; if(letters_show_num[17]>1){return 1;} break;}
            case 's': case 'S': {letters_show_num[18]++; if(letters_show_num[18]>1){return 1;} break;}
            case 't': case 'T': {letters_show_num[19]++; if(letters_show_num[19]>1){return 1;} break;}
            case 'u': case 'U': {letters_show_num[20]++; if(letters_show_num[20]>1){return 1;} break;}
            case 'v': case 'V': {letters_show_num[21]++; if(letters_show_num[21]>1){return 1;} break;}
            case 'w': case 'W': {letters_show_num[22]++; if(letters_show_num[22]>1){return 1;} break;}
            case 'x': case 'X': {letters_show_num[23]++; if(letters_show_num[23]>1){return 1;} break;}
            case 'y': case 'Y': {letters_show_num[24]++; if(letters_show_num[24]>1){return 1;} break;}
            case 'z': case 'Z': {letters_show_num[25]++; if(letters_show_num[25]>1){return 1;} break;}
        } // end of switch
    } // end of for
    return 0;
}

/**
  * @brief  检查传入的数字数组是否出现重复
  * @param  nums[] 传入的数字数组
  * @param  max_value 传入的数字数组最大值
  * @retval 0 无重复 1 有重复
  */
int checkForDuplicationForNums(int nums[], int max_value){
  /* 动态申请内存空间，存储在 1~max_value 之间所有值是否出现次数，calloc初始化全部元素为0 */
  int* within_max_value = (int *)calloc(max_value, sizeof(int)); 
  for(int i=0; i<max_value; i++) {
    /* 传入的 nums 已经是 1~m 映射至 0~m-1 不需要再特殊处理
      只处理 0~max_value-1 之间的值，超出申请内存范围的值会引起异常
      within_max_value[nums[i]-1]++; // 1~m 在 whthin_max_value中的下标对应 0~m-1 
    */
    if(0 <= nums[i] && nums[i] <= max_value-1) {
      within_max_value[nums[i]]++;
    }
  }
  for(int i=0; i<max_value; i++) {
    if(within_max_value[i] > 1) {
      return 1; /* 有元素出现超过1次即重复，返回1 */
    }
  } // end of for
  free(within_max_value);
  return 0; /* 无重复返回0 */
}

/**
  * @brief  检查传入的数字数组是否存在元素超过最大值
  * @param  nums[] 传入的数字数组
  * @param  max_value 传入的数字数组最大值
  * @retval 0 未超过 1 存在超过
  */
int checkElemExceedsMax(int nums[], int max_value) {
  for(int i=0; i<max_value; i++) { 
    if(i > max_value) {
      return 1; /* 存在元素超过最大值 */
    } // end of if
  } // end of for
  return 0; /* 不存在元素超过最大值 */
}

/**
  * @brief  检查传入的数字数组在最大值范围内是否有没出现的 1~max_value
  * @param  nums[] 传入的数字数组
  * @param  maxValue 传入的数字数组最大值
  * @retval 0 都出现了 1 存在未出现过的数字
  */
int checkNumWithinMaxNotAppear(int nums[], int max_value) {
  /* 动态申请内存空间，存储在 1~max_value 之间所有值是否出现次数，calloc初始化全部元素为0 */
  int* within_max_value = (int *)calloc(max_value, sizeof(int)); 
  for(int i=0; i<max_value; i++) { 
    /* 传入的 nums 已经是 1~m 映射至 0~m-1 不需要再特殊处理
      只处理 0~max_value-1 之间的值，超出申请内存范围的值会引起异常
      within_max_value[nums[i]-1]++; // 1~m 在 whthin_max_value中的下标对应 0~m-1 
    */
    if(0 <= nums[i] && nums[i] <= max_value-1) {
      within_max_value[nums[i]]++;
    }
  } // end of for
  for(int i=0; i<max_value; i++) {
    if(within_max_value[i] < 1) {
      return 1; /* 有元素1次都没出现过，返回1 */
    }
  } // end of for i
  free(within_max_value); /* 释放申请动态内存分配的内存空间 */
  return 0; /* 都出现了返回0 */
}