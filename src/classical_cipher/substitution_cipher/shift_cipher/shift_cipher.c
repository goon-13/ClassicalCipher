#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "navi_menu.h"
#include "get_input_by_getch.h"

/**
  * @brief  移位密码加密 对输入的明文字符串，每一位字母都按字母序循环右移key位得到密文串
  *         将恺撒密码的3改为任意数key∈Z26 （Z26表示{0, 1, ..., 25}）
  *         E(x) = (x+key) mod 26
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  plaintext 明文字符串，包含小写字母和空格
  * @retval ciphertext 明文加密成的密文串
  */
char* shiftEncryption(char plaintext[], int key) {
    key %= 26;
    for(int i = 0; plaintext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        plaintext[i] = toupper(plaintext[i]); /* toupper from <ctype.h> 把小写字母转换为大写字母 */
        if(plaintext[i]>=65 && plaintext[i]<=90) { /* ASCII 空格 32 不处理 A~Z--65~90 */
            plaintext[i] = 65 + ((plaintext[i]-65+key) % 26); /* 把65~90映射至0~25，加key后取余26再映射回65~90 */
        }
    }

    return plaintext; /* plaintext经加密已成ciphertext */
}

/**
  * @brief  移位密码解密 对输入的密文字符串，每一位字母都按字母序循环左移3位得到明文串
  *         D(x) = (x-key) mod 26
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  ciphertext 密文字符串，包含大写字母和空格
  * @retval plaintext 密文解密成的明文
  */
char* shiftDecryption(char ciphertext[], int key) {
    key %= 26;
    for(int i = 0; ciphertext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        ciphertext[i] = tolower(ciphertext[i]); /* tolower from <ctype.h> 把大写字母转换为小写字母 */
        if(ciphertext[i]>=97 && ciphertext[i]<=122) { /* ASCII 空格-32不处理 a~z--97~122 */
            ciphertext[i] = 97 + ((ciphertext[i]-97-key+26) % 26); /* 把97~122映射至0~25，减key后取余26再映射回97~122 */
        }
    }

    return ciphertext;  /* ciphertext经解密已成plaintext */
}

/**
  * @brief  代换密码 流程控制
  * @param  text[]-输入的内容
  * @retval 无
  */
void shiftProcess(char text[]) {
    int i = -1;
    int key = -1;

    while(i != 0) {
        printShiftCipherMenu();
        numPrompt();
        i = getInputNumByGetch();
        switch(i) {
            case 1: {
                system("cls"); /* 清屏 */
                lowerPlaintextPrompt();
                getInputLowercaseStringByGetch(text);

                printf("[[Please enter the key of the substitution cipher]]\n[[(please enter a legal number > 0 and <= 32767)]]\n");
                printf(":: ");
                while(key <= 0 || key > 32767) {
                    key = getInputNumByGetch();
                }
                
                printEncryptedCipher(shiftEncryption(text, key));
                key = -1; /* 还原key值 */
                break;
            }
            case 2: {
                system("cls"); /* 清屏 */
                upperCiphertextPrompt();
                getInputUppercaseStringByGetch(text);

                printf("[[Please enter the key of the substitution cipher]]\n[[(please enter a legal number > 0 and <= 32767)]]\n");
                printf(":: ");
                while(key <= 0 || key > 32767) {
                    key = getInputNumByGetch();
                }

                printDecryptedPlaintext(shiftDecryption(text, key));
                key = -1; /* 还原key值 */
                break;
            }
        } // end of switch
        system("cls"); /* 清屏 */
    } // end of while i
}