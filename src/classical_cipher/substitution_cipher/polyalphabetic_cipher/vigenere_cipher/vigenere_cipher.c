#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "navi_menu.h"
#include "get_input_by_getch.h"
#include "math_in_cryptography.h"
#include "widgets.h"

/**
  * @brief  维吉尼亚密码加密 提示输入密钥字符串 再进行加密解密选项选择操作
  *         E(x1, x2, ..., xm) = (x1+k1, x2+k2, ..., xm+km) mod 26 
  *         x1, x2, ..., xm 为明文序列
  *         k1, k2, ..., km 为密钥序列
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  plaintext 明文字符串，包含小写字母和空格
  * @retval ciphertext 明文加密成的密文串
  */
char* vigenereEncryption(char plaintext[], char key[]) {
    int key_length = strlen(key); /* 获取密钥长度，密钥将循环使用明文 */
    int key_num = 0; /* 当前使用到了密钥的第几位，范围 0~key_length-1 */
    for(int i = 0; plaintext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        if(plaintext[i]>='a' && plaintext[i]<='z') { /* ASCII 空格 32 不处理 A~Z--65~90 */
            if(key_num >= key_length) {
                key_num = 0; /* 循环使用key */
            }
            int k = key[key_num] - 'A'; /* 当前加密的这一位明文所使用的对应密钥的一位 */
            key_num++;
            int x = plaintext[i] - 'a'; /* 把97~122映射至0~25 */
            plaintext[i] = 'A' + (x+k)%26;
        }
    }

    return plaintext; /* plaintext经加密已成ciphertext */
}

/**
  * @brief  维吉尼亚密码解密
  *         D(y1, y2, ..., ym) = (y1-k1, y2-k2, ..., ym-km) mod 26
  *         y1, y2, ..., ym 为密文序列
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  ciphertext 密文字符串，包含大写字母和空格
  * @retval plaintext 密文解密成的明文
  */
char* vigenereDecryption(char ciphertext[], char key[]) {
    int key_length = strlen(key); /* 获取密钥长度，密钥将循环使用明文 */
    int key_num = 0; /* 当前使用到了密钥的第几位，范围 0~key_length-1 */
    for(int i = 0; ciphertext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        if(ciphertext[i]>='A' && ciphertext[i]<='Z') { /* ASCII 空格-32不处理 A~Z--65~90 */
            if(key_num >= key_length) {
                key_num = 0; /* 循环使用key */
            }
            int k = key[key_num] - 'A'; /* 当前加密的这一位明文所使用的对应密钥的一位 */
            key_num++;
            int y = ciphertext[i] - 'A'; /* 把65~90映射至0~25 */
            ciphertext[i] = 'a' + ((y-k)%26+26)%26; /* 预防y-k为负数的情况 */
        }
    }

    return ciphertext;  /* ciphertext经解密已成plaintext */
}

/**
  * @brief  维吉尼亚密码 流程控制
  * @param  text[]-输入的内容
  * @retval 无
  */
void vigenereProcess(char text[]) {
    int i = -1;
    int k1 = -1;
    int k2 = -1;

    char key[26] = {}; /* 未初始化的话，则后面判断是否至少输入一位时，会出现内存里存有数据的情况 */

    /* [1] 先提示输入密钥字符串，输入正确后才显示加密解密菜单 */
    printf("[[Please enter the key to encrypt plaintext.]]\n");
    printf("[[Please enter at least one letter.]]\n");
    printf("[[Only uppercase letters are accepted.]]\n");
    printf("::: ");
    getInputUppercaseStringByGetchWithoutSpace(key);

    /* 对输入的密钥字符串进行合法性校验
        -1- 是否至少输入了一位?
     */
    while(strlen(key) < 1) { 
        printf("[[Illegal input, please re-enter.]]\n"); /* 错误提示 */
        printf("::: ");
        getInputUppercaseStringByGetchWithoutSpace(key);
    }

    while(i != 0) {
        system("cls"); /* 清屏 */
        printVigenereCipherMenu(); /* 打印密码加密解密菜单 */
        numPrompt();
        i = getInputNumByGetch();
        system("cls"); /* 清屏 */
        switch(i) {
            case 1: { /* 加密 */
                lowerPlaintextPrompt();
                getInputLowercaseStringByGetch(text);
                printEncryptedCipher(vigenereEncryption(text, key));
                break;
            }
            case 2: { /* 解密 */
                upperCiphertextPrompt(); /* 提示输入大写密文串 */
                getInputUppercaseStringByGetch(text);
                printDecryptedPlaintext(vigenereDecryption(text, key));
                break;
            }
        } // end of switch
    } // end of while i
}