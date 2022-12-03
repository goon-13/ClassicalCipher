#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "navi_menu.h"
#include "get_input_by_getch.h"
#include "math_in_cryptography.h"
#include "widgets.h"

/**
  * @brief  单表代换密码加密 提示输入密钥字符串 再进行加密解密选项选择操作
  *         E(x) = π(x)
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  plaintext 明文字符串，包含小写字母和空格
  * @retval ciphertext 明文加密成的密文串
  */
char* monoalphabeticEncryption(char plaintext[], char key[]) {
    for(int i = 0; plaintext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        if(plaintext[i]>='a' && plaintext[i]<='z') { /* ASCII 空格 32 不处理 A~Z--65~90 */
            int x = plaintext[i] - 'a'; /* 把97~122映射至0~25，加密后再映射回97~122 */
            plaintext[i] = key[x];
        }
    }

    return plaintext; /* plaintext经加密已成ciphertext */
}

/**
  * @brief  单表代换密码解密
  *         D(x) = π^(-1)(x)
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  ciphertext 密文字符串，包含大写字母和空格
  * @retval plaintext 密文解密成的明文
  */
char* monoalphabeticDecryption(char ciphertext[], char key[]) {
    char inverse_key[26];
    /* 使用memset初始化数组 */
    memset(inverse_key, 0, 26);
    for(int i=0; i<26; i++) {
        int y = key[i] - 'A'; /* key输入的是大写字母，取出key在字母表中的序号 */
        inverse_key[y] = 'a' + i; /* i表示key数组的下标，其一一对应正常字母表顺序a~z，转换为对应明文小写字母即'a'+i */
    }
    for(int i = 0; ciphertext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        if(ciphertext[i]>='A' && ciphertext[i]<='Z') { /* ASCII 空格-32不处理 A~Z--65~90 */
            int y = ciphertext[i] - 'A'; /* 把65~90映射至0~25，解密后再映射回65~90 */
            ciphertext[i] = inverse_key[y];
        }
    }

    return ciphertext;  /* ciphertext经解密已成plaintext */
}

/**
  * @brief  代换密码 流程控制
  * @param  text[]-输入的内容
  * @retval 无
  */
void monoalphabeticProcess(char text[]) {
    int i = -1;
    int k1 = -1;
    int k2 = -1;

    char key[26] = {}; /* 未初始化的话，则后面判断是否输入26位时，会出现内存里存有数据的情况 */

    /* [1] 先提示输入密钥字符串，输入正确后才显示加密解密菜单 */
    printf("[[Please enter a key string to replace plaintext letters.]]\n");
    printf("[[The string you enter will replace the letters one by one in alphabetical order.]]\n");
    printf("[[Please enter 26 complete letters. Please be careful not to enter duplicate letters.]]\n");
    printf("[[Only uppercase letters are accepted.]]\n");
    printf(">>> abcdefghijklmnopqrstuvwxyz\n");
    printf("::: ");
    getInputUppercaseStringByGetchWithoutSpace(key);

    /* 对输入的密钥字符串进行合法性校验
        -1- 长度有26?
        -2- 是否有重复字母?
     */
    while(strlen(key)!=26 || checkForDuplication(key)) {
        printf("[[Illegal input, please re-enter.]]\n"); /* 错误提示 */
        printf(">>> abcdefghijklmnopqrstuvwxyz\n");
        printf("::: ");
        getInputUppercaseStringByGetchWithoutSpace(key);
    }

    while(i != 0) {
        system("cls"); /* 清屏 */
        printMonoalphabeticCipherMenu(); /* 打印密码加密解密菜单 */
        numPrompt();
        i = getInputNumByGetch();
        system("cls"); /* 清屏 */
        switch(i) {
            case 1: { /* 加密 */
                lowerPlaintextPrompt();
                getInputLowercaseStringByGetch(text);
                printEncryptedCipher(monoalphabeticEncryption(text, key));
                break;
            }
            case 2: { /* 解密 */
                upperCiphertextPrompt(); /* 提示输入大写密文串 */
                getInputUppercaseStringByGetch(text);
                printDecryptedPlaintext(monoalphabeticDecryption(text, key));
                break;
            }
        } // end of switch
    } // end of while
}