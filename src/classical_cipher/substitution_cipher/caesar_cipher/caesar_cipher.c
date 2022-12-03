#include <ctype.h>
#include <stdlib.h>

#include "navi_menu.h"
#include "get_input_by_getch.h"

/**
  * @brief  恺撒密码加密 对输入的明文字符串，每一位字母都按字母序循环右移3位得到密文串
  *         E(x) = (x+3) mod 26
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  plaintext 明文字符串，包含小写字母和空格
  * @retval ciphertext 明文加密成的密文串
  */
char* caesarEncryption(char plaintext[]) {
    for(int i = 0; plaintext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        plaintext[i] = toupper(plaintext[i]); /* toupper from <ctype.h> 把小写字母转换为大写字母 */
        if(plaintext[i]>=65 && plaintext[i]<=90) { /* ASCII 空格 32 不处理 A~Z--65~90 */
            plaintext[i] = 65 + ((plaintext[i]-65+3) % 26); /* 把65~90映射至0~25，加3后取余26再映射回65~90 */
        }
    }

    return plaintext;/* plaintext经加密已成ciphertext */
}

/**
  * @brief  恺撒密码解密 对输入的密文字符串，每一位字母都按字母序循环左移3位得到明文串
  *         D(x) = (x-3) mod 26
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  ciphertext 密文字符串，包含大写字母和空格
  * @retval plaintext 密文解密成的明文
  */
char* caesarDecryption(char ciphertext[]) {
    for(int i = 0; ciphertext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        ciphertext[i] = tolower(ciphertext[i]); /* tolower from <ctype.h> 把大写字母转换为小写字母 */
        if(ciphertext[i]>=97 && ciphertext[i]<=122) { /* ASCII 空格-32不处理 a~z--97~122 */
            ciphertext[i] = 97 + ((ciphertext[i]-97-3+26) % 26); /* 把97~122映射至0~25，减3后取余26再映射回97~122 */
        }
    }

    return ciphertext; /* ciphertext经解密已成plaintext */
}

/**
  * @brief  恺撒密码 流程控制
  * @param  text[]-输入的内容
  * @retval 无
  */
void caesarProcess(char text[]) {
    int i = -1;
   
    while(i != 0) {
        printCaesarCipherMenu();
        numPrompt();
        i = getInputNumByGetch();
        switch(i) {
            case 1: {
                system("cls"); /* 清屏 */
                lowerPlaintextPrompt();
                getInputLowercaseStringByGetch(text);
                printEncryptedCipher(caesarEncryption(text));
                break;
            } 
            case 2: {
                system("cls"); /* 清屏 */
                upperCiphertextPrompt();
                getInputUppercaseStringByGetch(text);
                printDecryptedPlaintext(caesarDecryption(text));
                break;
            }
        } // end of switch
        system("cls"); /* 清屏 */
    }
}