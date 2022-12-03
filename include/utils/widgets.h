#ifndef __WIDGETS_H__
#define __WIDGETS_H__

void swap(int *a, int *b); /* 交换两个数的值 */
int checkForDuplication(char text[]); /* 检查传入的字符串是否出现重复字母 */
int checkForDuplicationForNums(int nums[], int max_value); /* 检查传入的数字数组是否出现重复 */
int checkElemExceedsMax(int nums[], int max_value); /* 检查传入的数字数组是否存在元素超过最大值 */
int checkNumWithinMaxNotAppear(int nums[], int max_value); /* 检查传入的数字数组在最大值范围内是否有没出现的 1~max_value */

#endif