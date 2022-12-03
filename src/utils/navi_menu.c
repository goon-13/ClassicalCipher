#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_input_by_getch.h"

/*[1] begin***********************************************************************************/
/* [1] 菜单提示的固定部分，不写入头文件，仅本文件其他函数调用 */
/**
  * @brief  [1.1] 菜单的固定开头的提示
  * @param  无
  * @retval 无
  */
void menuHeadline() {
   printf("========================================================================\n");
   printf("*          [[Welcome to this encryption and decryption tool]]          *\n");
   printf("=====[[Please enter the corresponding number to use the function]]======\n");
}
/**
  * @brief  [1.2] 菜单的返回上一级的提示
  * @param  无
  * @retval 无
  */
void menuGoBack() {
   printf("=============================[0] [[GO BACK]]============================\n");
}
/**
  * @brief  [1.3] 菜单的结尾显示退出的提示
  * @param  无
  * @retval 无
  */
void menuExit() {
   printf("========================================================================\n");
}
/*[1] end***********************************************************************************/

/*[2] begin***********************************************************************************/
/* [2] 提示输入 */
/**
  * @brief  [2.1] 提示输入数字选择对应菜单
  * @param  无
  * @retval 无
  */
void numPrompt() {
   printf("[[Please enter the corresponding number]]\n[[(only the menu number can be entered, enter 0 to GO BACK)]]\n");
   printf(":: ");
}
/**
  * @brief  [2.2] 提示输入明文小写字符串
  * @param  无
  * @retval 无
  */
void lowerPlaintextPrompt() {
   printf("[[Please enter the plaintext to be encrypted]]\n[[(only lowercase letters and spaces can be entered, and the length is less than 2000 characters)]]\n");
   printf("::: ");
}
/**
  * @brief  [2.3] 提示输入密文大写字符串
  * @param  无
  * @retval 无
  */
void upperCiphertextPrompt() {
   printf("[[Please enter the ciphertext to decrypt]]\n[[(only uppercase letters and spaces can be entered, and the length is less than 2000 characters)]]\n");
   printf("::: ");
}
/**
  * @brief  [2.4] 错误输入提示
  * @param  无
  * @retval 无
  */
void illegalInputPrompt() {
   printf("[[Illegal input, please re-enter.]]\n"); /* 错误提示 */
   printf("::: ");
}
/*[2] end***********************************************************************************/

/*[3] begin***********************************************************************************/
/* [3] 输出提示 */
/**
  * @brief  [3.1] 输出加密后的密文串
  * @param  无
  * @retval 无
  */
void printEncryptedCipher(char ciphertext[]) {
   printf("\n>>> The encrypted ciphertext is: \n[[[ %s ]]]\n", ciphertext);
   system("pause"); /* 让输入结果暂留 */
}
/**
  * @brief  [3.2] 输出解密后的明文串
  * @param  无
  * @retval 无
  */
void printDecryptedPlaintext(char plaintext[]) {
   printf("\n>>> The plaintext after decryption is: \n[[[ %s ]]]\n", plaintext);
   system("pause"); /* 让输入结果暂留 */
}
/**
  * @brief  [3.3] 根据传入的密文串长度输出加密后的密文串
  * @param  无
  * @retval 无
  */
void printEncryptedCipherByStrlen(char ciphertext[]) {
   int text_length = strlen(ciphertext);
   printf("\n>>> The encrypted ciphertext is: \n[[[");
   for(int i=0; i<text_length; i++) {
      printf("%c", ciphertext[i]);
   }
   printf("]]]\n");
   system("pause"); /* 让输入结果暂留 */
}
/*[3] end***********************************************************************************/

/*[4] begin***********************************************************************************/
/* [4] 完整的菜单显示 */
/**
  * @brief  输出主导航菜单提示
  * @param  无
  * @retval 无
  */
 void printMainMenu() {
   menuHeadline();
   printf("*                   >>> [1] [[Classical cipher]] <<<                   *\n");
   printf("*                   >>> [2] [[Symmetric Key Algorithm]] <<<            *\n");
   printf("==============================[0] [[EXIT]]==============================\n");
   printf("========================================================================\n");
 }
/**
 * @brief  输出古典密码导航菜单提示，分为
 *         [1] 代换密码(Substitution cipher)
 *         [2] 置换密码(Permutation cipher)
 * @param  无
 * @retval 无
 */
void printClassicalCipherMenu() {
   menuHeadline();
   printf("*                  >>> [1] [[Substitution cipher]] <<<                 *\n");
   printf("*                  >>> [2] [[Permutation cipher]] <<<                  *\n");
   menuGoBack();
   menuExit();
}
/**
 * @brief  输出代换密码导航菜单提示，分为
 *         [1] 恺撒密码(Caesar cipher)
 *         [2] 移位密码(Shift cipher)
 *         [3] 仿射密码(Affine cipher)
 *         [4] 单表代换密码(Monoalphabetic cipher)
 *         [5] 多表代换密码(Polyalphabetic cipher)
 * @param  无
 * @retval 无
 */
void printSubstitutionCipherMenu() {
   menuHeadline();
   printf("*                  >>> [1] [[Caesar cipher]] <<<                 *\n");
   printf("*                  >>> [2] [[Shift cipher]] <<<                  *\n");
   printf("*                  >>> [3] [[Affine cipher]] <<<                 *\n");
   printf("*                  >>> [4] [[Monoalphabetic cipher]] <<<         *\n");
   printf("*                  >>> [5] [[Polyalphabetic cipher]] <<<         *\n");
   menuGoBack();
   menuExit();
}
/**
* @brief  输出恺撒密码导航菜单提示，分为
*           [1] 恺撒加密
*           [2] 恺撒解密
* @param  无
* @retval 无
*/
void printCaesarCipherMenu() {
   menuHeadline();
   printf("*               >>> [1] [[Caesar cipher encryption]] <<<               *\n");
   printf("*               >>> [2] [[Caesar cipher decryption]] <<<               *\n");
   menuGoBack();
   menuExit();
}
/**
* @brief  输出代换密码导航菜单提示，分为
*           [1] 代换密码加密
*           [2] 代换密码解密
* @param  无
* @retval 无
*/
void printShiftCipherMenu() {
   menuHeadline();
   printf("*                >>> [1] [[Shift cipher encryption]] <<<               *\n");
   printf("*                >>> [2] [[Shift cipher decryption]] <<<               *\n");
   menuGoBack();
   menuExit();
}
/**
* @brief  输出仿射密码导航菜单提示，分为
*           [1] 仿射密码加密
*           [2] 仿射密码解密
* @param  无
* @retval 无
*/
void printAffineCipherMenu() {
   menuHeadline();
   printf("*               >>> [1] [[Affine cipher encryption]] <<<               *\n");
   printf("*               >>> [2] [[Affine cipher decryption]] <<<               *\n");
   menuGoBack();
   menuExit();
}
/**
* @brief  输出单表代换密码导航菜单提示，分为
*           先提示输入密钥字符串，正确输入后才提示加密解密选项
*           [1] 单表代换密码加密
*           [2] 单表代换密码解密
* @param  无
* @retval 无
*/
void printMonoalphabeticCipherMenu() {
   menuHeadline();
   printf("*           >>> [1] [[Monoalphabetic cipher encryption]] <<<           *\n");
   printf("*           >>> [2] [[Monoalphabetic cipher decryption]] <<<           *\n");
   menuGoBack();
   menuExit();
}
/**
  * @brief  多表代换密码 菜单控制
  *         [1] 维吉尼亚密码(Vigenere cipher)
 * @param  无
 * @retval 无
 */
void printPolyalphabeticCipherMenu() {
   menuHeadline();
   printf("*                 >>> [1] [[Vigenere cipher]] <<<                *\n");
   menuGoBack();
   menuExit();
}
/**
  * @brief  维吉尼亚密码 菜单控制
*           先提示输入密钥字符串，正确输入后才提示加密解密选项
*           [1] 维吉尼亚密码加密
*           [2] 维吉尼亚密码解密
 * @param  无
 * @retval 无
 */
void printVigenereCipherMenu() {
   menuHeadline();
   printf("*              >>> [1] [[Vigenere cipher encryption]] <<<              *\n");
   printf("*              >>> [2] [[Vigenere cipher decryption]] <<<              *\n");
   menuGoBack();
   menuExit();
}
/**
  * @brief  置换密码 菜单控制
*           先提示输入密钥字符串，正确输入后才提示加密解密选项
*           [1] 置换密码加密
*           [2] 置换密码解密
 * @param  无
 * @retval 无
 */
void printPermutationCipherMenu() {
   menuHeadline();
   printf("*            >>> [1] [[Permutation cipher encryption]] <<<             *\n");
   printf("*            >>> [2] [[Permutation cipher decryption]] <<<             *\n");
   menuGoBack();
   menuExit();
}
/*[4] end***********************************************************************************/
