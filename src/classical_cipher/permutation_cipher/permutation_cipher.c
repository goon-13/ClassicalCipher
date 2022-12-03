#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "navi_menu.h"
#include "get_input_by_getch.h"
#include "math_in_cryptography.h"
#include "widgets.h"

/** 置换密码 不改变每一位字母，而是改变整个字符串中各个字母的位置序列
 *  [1] 先提示输入想要交换密钥的长度n
 *  [2] 输出1~n之间的所有值，以空格隔开
 *  [3] 提示输入1~n想要一一交换的是哪些对应值
 *  [4] 进行输入校验：值不能重复; 输入的每个值大小不能超过n; 输入数字个数需要刚好等于n
 */

/**
  * @brief  置换密码加密 提示输入
  *         E(x1, x2, ..., xm) = (x[PI(1)], x[PI(2)], ..., x[PI(m)]) 
  *         x1, x2, ..., xm 为明文分组
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  plaintext 明文字符串，包含小写字母和空格
  * @retval ciphertext 明文加密成的密文串
  */
char* permutationEncryption(char plaintext[], int key[], int plaintext_length, int key_length_m) {
    /*  申请一个一样大的数组 result，遍历使得 result[i] = plaintext[key[i]] 
        key的长度为 m （即key_length_m）
        将明文划分为几个区间: [0, m-1] [m+0, m+m-1] [2m+0, 2m+m-1] ... [当前元素所在区间]
        将 [当前元素所在区间] 映射至 [0, m]
        明文长度刚好为 m 的整数倍则密文长度就等于明文长度
        若明文可分为前 x 个 m 长度的分组，最后一个分组长度不满足 m ，则密文长度为 (x+1)*m
     */
    int ciphertext_length =  plaintext_length%key_length_m==0 ? plaintext_length : (plaintext_length/key_length_m+1)*key_length_m;
    char* ciphertext = (char *)calloc(ciphertext_length+1, sizeof(char)); /* +1 因为最后要多存一个结束符 记得free 使用 calloc，会在超出数组范围长度的内存块都赋值0，ASCII码值0对应'\0' */

    for(int i = 0; i < ciphertext_length; i++) { 
        int multi_of_m = i / key_length_m; /* 现在i所在区间前已经有了几个 m 长度的区间 */
        int key_index = i % key_length_m; /* 在当前区间映射至0~m取什么下标 */
        /* 明文当前第i位要与plaintext_index位的明文做置换
            multi_of_m*key_length_m 为 第i位所处区间前有多少数组元素，相当于把 0~m 区间 映射至 i所在区间
            考虑边界，如 i 为 3m，multi_of_m = 3，key_index = 0
            前面的区间为 [0, m-1] [m+0, m+m-1] [2m+0, 2m+m-1]
            plainttext_index = 3m + key[0]，相当于把 3m~4m-1 区间映射至 0~m 做置换 
         */
        int plaintext_index = multi_of_m*key_length_m + key[key_index];
        if(plaintext_index < plaintext_length) { /* 需要考虑若最后一个分组长度不满足 m 的情况 */
            if(plaintext[plaintext_index] >= 'a' && plaintext[plaintext_index] <= 'z') { /* 空格不做操作 */
                ciphertext[i] = plaintext[plaintext_index] - 'a' + 'A'; /* 密文需要为大写 */
            } else {
                ciphertext[i] = plaintext[plaintext_index]; /* 空格不做操作 */
            }
        } else {
            ciphertext[i] = ' '; /* 最后一个分组长度小于 m ，置换到位置上的明文不存在，则用 空格 表示 */
        }
    } // end of for

    return ciphertext; /* plaintext经加密已成ciphertext */
}

/**
  * @brief  置换密码解密
  *         D(y1, y2, ..., ym) = (y[PI^(-1)(1)], y[PI^(-1)(2)], ..., y[PI^(-1)(m))
  *         y1, y2, ..., ym 为密文序列
  *         PI^(-1) 是 PI 的逆置换
  *         ASCII 码值：a~z--97~122 A~Z--65~90 明文串小写字母，密文串大写字母
  * @param  ciphertext 密文字符串，包含大写字母和空格
  * @retval plaintext 密文解密成的明文
  */
char* permutationDecryption(char ciphertext[], int key[], int ciphertext_length, int key_length_m) {
    /* 先将 key 转换为逆置换 key^(-1) */
    int key_inverse[key_length_m];
    for(int i=0; i<key_length_m; i++) {
        /* 例如：
           i             :     1 2 3 4
           key[i]        :     2 4 1 3
           key_inverse[i]:     3 1 4 2
         */
        key_inverse[key[i]] = i;
    }
    /*  申请一个一样大的数组 result，遍历使得 result[i] = plaintext[key[i]] 
        key的长度为 m （即key_length_m）
        将明文划分为几个区间: [0, m-1] [m+0, m+m-1] [2m+0, 2m+m-1] ... [当前元素所在区间]
        将 [当前元素所在区间] 映射至 [0, m]
    */
    int plaintext_length =  ciphertext_length%key_length_m==0 ? ciphertext_length : (ciphertext_length/key_length_m+1)*key_length_m;

    char* plaintext = (char *)calloc(plaintext_length+1, sizeof(char)); /* +1 因为最后要多存一个结束符 使用 calloc，会在超出数组范围长度的内存块都赋值0，ASCII码值0对应'\0' */
    int i; /* 循环中表示数组下标 */
    for(i = 0; i < plaintext_length; i++) {
        int multi_of_m = i / key_length_m; /* 现在i所在区间前已经有了几个 m 长度的区间 */
        int key_index = i % key_length_m; /* 在当前区间映射至0~m取什么下标 */
        /* 明文当前第i位要与plaintext_index位的明文做置换
            multi_of_m*key_length_m 为 第i位所处区间前有多少数组元素，相当于把 0~m 区间 映射至 i所在区间
            考虑边界，如 i 为 3m，multi_of_m = 3，key_index = 0
            前面的区间为 [0, m-1] [m+0, m+m-1] [2m+0, 2m+m-1]
            ciphertext_index = 3m + key[0]，相当于把 3m~4m-1 区间映射至 0~m 做置换 
         */
        int ciphertext_index = multi_of_m*key_length_m + key_inverse[key_index];
        /* 直接取ciphertext数组的第 ciphertext_index 位存储到plaintext的第 i 位
            不能使用swap，这是位置的单向调换，不是两两交换。
            若不使用辅助数组，则顺序遍历，后面的元素需要取前面位置元素时，前面元素可能已经被修改了
        */
        if(ciphertext_index < ciphertext_length) { /* 需要考虑若最后一个分组长度不满足 m 的情况 */
            if(ciphertext[ciphertext_index] >= 'A' && ciphertext[ciphertext_index] <= 'Z') { /* 空格不做操作 */
                plaintext[i] = ciphertext[ciphertext_index] - 'A' + 'a'; /* 密文需要为大写 */
            } else {
                plaintext[i] = ciphertext[ciphertext_index]; /* 空格不做操作 */
            }
        } else {
            plaintext[i] = ' '; /* 最后一个分组长度小于 m ，置换到位置上的明文不存在，则用 空格 表示 */
        }
    } // end of for
    /* 处理结尾可能多出的明文不满足 m 整数倍填充的空格
       保证 结尾标识符 '\0' 的前面一定不是'-'或空格
       经过上轮的循环，i = ciphertext_length，即结尾标识符'\0'
     */
    while(plaintext[i-1]==' ' && plaintext[i]=='\0') {
        i--;
        plaintext[i] = '\0';
    }

    return plaintext; /* ciphertext经解密已成plaintext */
}

/**
  * @brief  置换密码 流程控制
  * @param  text[]-输入的内容
  * @retval 无
  */
void permutationProcess(char text[]) {
    int i = -1;

    unsigned int key_length_m = 0;
    unsigned int* key; /* 将采用动态分配内存的方式申请内存空间存储置换密钥key */
    char* key_string; /* 暂存输入的一长串密钥数字字符串（包含空格，一个空格占一字节） */
    unsigned int key_string_length = 0; /* 用于计算存储 key_string 所需内存空间 */
    char key_each_num[50] = {0}; /* 暂存1~m每个数字，转换为字符串以计算整个数字字符串需要占多少内存空间 */

    /* [1] 先提示输入密钥分组长度 */
    printf("[[Please enter the length 'm' of each permutation cipher group.]]\n");
    printf("[[The plaintext will be divided into several groups according to the input length.]]\n");
    printf("[[And each group will be internally encrypted according to the replacement key entered later.]]\n");
    printf("::: ");
    key_length_m = getInputNumByGetch();

    /* 校验：值不能为空 */
    while(key_length_m <= 0) {
        illegalInputPrompt(); /* 非法输入提示 */
        key_length_m = getInputNumByGetch();
    }

    /* 动态内存分配，用完一定要记得free */
    key = (unsigned int *)calloc(key_length_m, sizeof(unsigned int)); /* calloc区别于malloc在于calloc会初始化元素全为0 */

    /* [2] 提示输入密钥字符串，输入正确后才显示加密解密菜单 */
    printf("[[Please enter the permutation cipher to disrupt the order of each letter in the group.]]\n");
    printf("[[Only numbers between 1~m can be entered, separated by spaces.]]\n");
    printf(">>> ");
    /* 打印出顺序排序的分组下标，以便用户对照着打乱顺序 */
    for(int a=1; a<=key_length_m; a++) {
        printf("%d ", a);
        /* 计算 key_string_length */
        itoa(a, key_each_num, 10); /* int转化为字符串，存储进key_each_num */
        key_string_length += strlen(key_each_num); /* 每个数字占的位数 */
        /* 每个数字之间的间隔符--空格，也占一个字节，为规避用户可能多键入空格，每位数字多申请两个字节 */
        key_string_length += 3; 
    }
    printf("\n");
    printf("::: ");
    /* 获取以空格分隔的一串数字存进数组key
     * 先全部字符串获取存储，再用<string.h>的 strtok 方法按空格分割
     */
    /* 动态内存分配，用完一定要记得free */
    key_string = (char *)calloc(key_string_length, sizeof(char)); /* calloc区别于malloc在于calloc会初始化元素全为0 */
    getInputNumArrayByGetchHaveSpaces(key_string, key);
          
    /* 对输入的密钥字符串进行合法性校验
        -1- 值不能重复; 
        -2- 输入的每个值大小不能超过n; 
        -3- 输入数字个数需要刚好等于n (这样也检查了输入为空)
     */
    while(checkForDuplicationForNums(key, key_length_m) 
    || checkElemExceedsMax(key, key_length_m) 
    || checkNumWithinMaxNotAppear(key, key_length_m)) {
        illegalInputPrompt(); /* 非法输入提示 */
        getInputNumArrayByGetchHaveSpaces(key_string, key);
    }

    free(key_string); /* 释放动态分配的内存 */

    while(i != 0) {
        system("cls"); /* 清屏 */
        printPermutationCipherMenu(); /* 打印密码加密解密菜单 */
        numPrompt();
        i = getInputNumByGetch();
        system("cls"); /* 清屏 */
        switch(i) {
            case 1: { /* 加密 */
                lowerPlaintextPrompt();
                getInputLowercaseStringByGetch(text);
                unsigned int plaintext_length = 0;
                for(int j=0; text[j] != '\0'; j++, plaintext_length++);
                if(plaintext_length == 0) { /* 非空校验 */
                    printEncryptedCipher("");
                    break;
                }
                /* 明文中只含有小写字母和空格 */
                char* ciphertext = permutationEncryption(text, key, plaintext_length, key_length_m);
                printEncryptedCipher(ciphertext);
                free(ciphertext); /* 释放动态分配的内存 */
                break;
            }
            case 2: { /* 解密 */
                upperCiphertextPrompt(); /* 提示输入大写密文串 */
                getInputUppercaseStringByGetch(text);
                unsigned int ciphertext_length = 0;
                for(int j=0; text[j] != '\0'; j++, ciphertext_length++);
                if(ciphertext_length == 0) { /* 非空校验 */
                    printDecryptedPlaintext("");
                    break;
                }
                char* plaintext = permutationDecryption(text, key, ciphertext_length, key_length_m);
                printDecryptedPlaintext(plaintext);
                free(plaintext); /* 释放动态分配的内存 */
                break;
            }
        } // end of switch
    } // end of while
    free(key); /* 释放动态分配的内存 */
}