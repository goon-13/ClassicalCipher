#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "navi_menu.h"
#include "get_input_by_getch.h"
#include "math_in_cryptography.h"

/**
  * @brief  仿射密码加密 对输入的明文字符串，k1,k2∈Z26 且k1和26互素[k1取值:1,3,5,7,9,11,15,17,19,21,23,25]
  *         E(x) = (k1 x + k2) mod 26
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  plaintext 明文字符串，包含小写字母和空格
  * @retval ciphertext 明文加密成的密文串
  */
char* affineEncryption(char plaintext[], int k1, int k2) {
    k1 %= 26;
    k2 %= 26;
    for(int i = 0; plaintext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        plaintext[i] = toupper(plaintext[i]); /* toupper from <ctype.h> 把小写字母转换为大写字母 */
        if(plaintext[i]>='A' && plaintext[i]<='Z') { /* ASCII 空格 32 不处理 A~Z--65~90 */
            int x = plaintext[i] - 'A'; /* 把65~90映射至0~25，加密后再映射回65~90 */
            plaintext[i] = 'A' + ((k1*x + k2) % 26);
        }
    }

    return plaintext; /* plaintext经加密已成ciphertext */
}

/**
  * @brief  仿射密码解密 对输入的密文字符串，k1,k2∈Z26 且k1和26互素[k1取值:1,3,5,7,9,11,15,17,19,21,23,25]
  *         D(x) = k1^(-1)(y - k2) mod 26
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  ciphertext 密文字符串，包含大写字母和空格
  * @retval plaintext 密文解密成的明文
  */
char* affineDecryption(char ciphertext[], int k1, int k2) {
    k1 %= 26;
    k2 %= 26;
    for(int i = 0; ciphertext[i] != '\0'; i++) { /* 循环条件也可改成strlen */
        ciphertext[i] = tolower(ciphertext[i]); /* tolower from <ctype.h> 把大写字母转换为小写字母 */
        if(ciphertext[i]>='a' && ciphertext[i]<='z') { /* ASCII 空格-32不处理 a~z--97~122 */
            int y = ciphertext[i] - 'a'; /* 把97~122映射至0~25，解密后再映射回97~122 */
            /* 【BUG】会出现负数取余的情况，先将y-k2为负数的结果先加上26再参与运算则结果为预期结果，why? */
            // if(y-k2 < 0) {
            //     y += 26;
            // }
            /* 【BUG解决如下】 */
            int y_minus_k2 = y - k2;
            if(y_minus_k2 < 0) {
                y_minus_k2 = (y_minus_k2%26 + 26) % 26;
            }
            ciphertext[i] = 'a' + (modularMultiplicativeInverse(k1, 26)*y_minus_k2 % 26); /* D(x) = k1^(-1)(y - k2) mod 26 */
        }
    }

    return ciphertext;  /* ciphertext经解密已成plaintext */
}

/**
  * @brief  代换密码 流程控制
  * @param  text[]-输入的内容
  * @retval 无
  */
void affineProcess(char text[]) {
    int i = -1;
    int k1 = -1;
    int k2 = -1;

    while(i != 0) {
        printAffineCipherMenu(); /* 打印密码加密解密菜单 */
        numPrompt();
        i = getInputNumByGetch();
        switch(i) {
            case 1: { /* 加密 */
                system("cls"); /* 清屏 */
                lowerPlaintextPrompt();
                getInputLowercaseStringByGetch(text);

                printf("[[E(x) = (k1 x + k2) mod 26]]\n");
                printf("[[Please enter k1 of the affine cipher]]\n[[k1 needs to be mutually prime with 26]]\n");
                printf("[[The legal values of k1 are (1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25)]]\n");
                printf(":: ");

                /* 校验输入，没输入合法数字就一直输 */
                unsigned char loop_flag = 1;
                while(loop_flag) {
                    k1 = getInputNumByGetch();
                    switch(k1) {
                        case 1: case 3: case 5: case 7: case 9: case 11: case 15: case 17: case 19: case 21: case 23: case 25: {
                            loop_flag = 0;
                            break;
                        }
                        default: {
                            printf("[[Illegal input, please re-enter]]\n:: "); /* 错误提示 */
                        }
                    } // end of switch
                } // end of while

                printf("[[Please enter k2 of the affine cipher, 0 <= k2 <= 25]]\n");
                printf(":: ");
                k2 = getInputNumByGetch();
                while (k2<0 || k2>25) {
                    printf("[[Illegal input, please re-enter]]\n:: "); /* 错误提示 */
                    k2 = getInputNumByGetch();
                }

                printEncryptedCipher(affineEncryption(text, k1, k2));
                break;
            }
            case 2: { /* 解密 */
                system("cls"); /* 清屏 */
                upperCiphertextPrompt(); /* 提示输入大写密文串 */
                getInputUppercaseStringByGetch(text);

                printf("[[D(x) = k1^(-1)(y - k2) mod 26]]\n");
                printf("[[Please enter k1 of the affine cipher]]\n[[k1 needs to be mutually prime with 26]]\n");
                printf("[[The legal values of k1 are (1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25)]]\n");
                printf(":: ");

                /* 校验输入，没输入合法数字就一直输 */
                unsigned char loop_flag = 1;
                while(loop_flag) {
                    k1 = getInputNumByGetch();
                    switch(k1) {
                        case 1: case 3: case 5: case 7: case 9: case 11: case 15: case 17: case 19: case 21: case 23: case 25: {
                            loop_flag = 0;
                            break;
                        }
                        default: {
                            printf("[[Illegal input, please re-enter]]\n:: "); /* 错误提示 */
                        }
                    } // end of switch
                } // end of while

                printf("[[Please enter k2 of the affine cipher, 0 <= k2 <= 25]]\n");
                printf(":: ");
                k2 = getInputNumByGetch();
                while (k2<0 || k2>25) {
                    printf("[[Illegal input, please re-enter]]\n:: "); /* 错误提示 */
                    k2 = getInputNumByGetch();
                }

                printDecryptedPlaintext(affineDecryption(text, k1, k2));
                break;
            }
        } // end of switch
        system("cls"); /* 清屏 */
    }
}