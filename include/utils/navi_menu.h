#ifndef __NAVI_MENU_H__
#define __NAVI_MENU_H__

void numPrompt(); /* 提示输入数字选择菜单 */
void lowerPlaintextPrompt();
void upperCiphertextPrompt();
void illegalInputPrompt(); /* 非法输入提示 */

void printEncryptedCipher(char ciphertext[]);
void printDecryptedPlaintext(char plaintext[]);
void printEncryptedCipherByStrlen(char ciphertext[]); /* 根据传入的密文串长度输出加密后的密文串 */

void printMainMenu();
void printClassicalCipherMenu(); /* 选择古典密码菜单提示 */
void printSubstitutionCipherMenu(); /* 代换密码菜单提示 */
void printCaesarCipherMenu(); /* 恺撒密码菜单界面 */
void printShiftCipherMenu(); /* 代换密码菜单界面 */
void printAffineCipherMenu(); /* 代换密码菜单界面 */
void printMonoalphabeticCipherMenu(); /* 单表代换密码菜单界面 */
void printPolyalphabeticCipherMenu(); /* 多表代换密码菜单界面 */
void printVigenereCipherMenu(); /* 维吉尼亚密码菜单界面 */
void printPermutationCipherMenu(); /* 置换密码菜单界面 */

#endif