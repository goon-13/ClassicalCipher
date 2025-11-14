# ClassicalCipher-密码学教材中几种古典密码的C语言实现

## 参考-Reference
写之前先学习了[ColdmaterL](https://github.com/ColdmaterL)的[Caesar-Cipher](https://github.com/ColdmaterL/Caesar-Cipher)，参考了其中获取控制台输入的方式。

Learn [ColdmaterL](https://github.com/ColdmaterL)'s [Caesar-Cipher](https://github.com/ColdmaterL/Caesar-Cipher) before coding, refered to his way to obtain console input.

## 简介-Brief Introduction
代码为密码学教材("Cryptography Theory and Practice Third Edition")中几种古典密码的C语言实现。通过控制台程序使用。  
因为是初学者，可能难免出现一些错误，如果发现了错误以及不规范之处希望能帮忙指出，非常感谢~

The code is the C language implementation of several classical ciphers in the Cryptography Theory and Practice Third Edition. Use through the console program.  
As a beginner, some mistakes may be unavoidable. If you find mistakes and irregularities, I hope you can help me point them out. Thank you very much~

具体实现的古典密码如下:

The classical ciphers are as follows:

1. 代换密码 (Substitution cipher)
    - 恺撒密码 (Caesar cipher)
    - 移位密码 (Shift cipher)
    - 仿射密码 (Affine cipher)
    - 单表代换密码 (Monoalphabetic cipher)
    - 多表代换密码 (Polyalphabetic cipher)
        - 维吉尼亚密码 (Vigenere cipher)
2. 置换密码 (Permutation cipher)

## 使用-Tutorial
0. 主菜单-Main Menu  
![main_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/1_main_menu.jpg)
1. 主菜单输入 1 进入代换密码菜单选择  
Enter 1 in the main menu to enter the substitution cipher menu  
![substitution_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/2_substitution_menu.jpg)
    - 代换密码菜单界面输入 1 进入恺撒密码菜单界面  
    Substitute cipher menu interface Enter 1 to enter Caesar cipher menu interface  
![caesar_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/3_caesar_menu.jpg)
        - 恺撒密码菜单界面输入 1 进行恺撒密码加密  
        Enter 1 in Caesar cipher menu interface to encrypt Caesar cipher  
![caesar_encryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/4_caesar_encryption.jpg)
        - 恺撒密码菜单界面输入 2 进行恺撒密码解密  
        Enter 2 in the Caesar cipher menu interface to decrypt the Caesar cipher  
![caesar_decryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/5_caesar_decryption.jpg)
    - 代换密码菜单界面输入 2 进入移位密码菜单界面  
    Substitution cipher menu interface Enter 2 to enter the shift cipher menu interface  
![shift_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/6_shift_menu.jpg)
        - 移位密码菜单界面输入 1 进行移位密码加密  
        Input 1 in the shift cipher menu interface to encrypt the shift cipher  
![shift_encryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/7_shift_encryption.jpg)
        - 移位密码菜单界面输入 2 进行移位密码解密  
        Input 2 in the shift cipher menu interface to decrypt the shift cipher  
![shift_decryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/8_shift_decryption.jpg)
    - 代换密码菜单界面输入 3 进入仿射密码菜单界面  
    Substitution cipher menu interface Enter 3 to enter the affine cipher menu interface  
![affine_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/9_affine_menu.jpg)
        - 仿射密码菜单界面输入 1 进行仿射密码加密  
        Input 1 in the affine cipher menu interface to encrypt the affine cipher  
![affine_encryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/10_affine_encryption.jpg)
        - 仿射密码菜单界面输入 2 进行仿射密码解密  
        Enter 2 in the affine cipher menu interface to decrypt the affine cipher  
![affine_decryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/11_affine_decryption.jpg)
    - 代换密码菜单界面输入 4 进入单表代换密码项，需要先输入密钥  
    Enter 4 in the replacement cipher menu interface to enter the single table replacement cipher item. You need to enter the key first  
![pre_mono](https://github.com/goon-13/ClassicalCipher/blob/main/img/12_pre_mono.jpg)
    - 输入密钥后进入单表代换密码菜单界面  
    Enter the key to enter the single table substitution cipher menu interface  
![mono_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/13_mono_menu.jpg)
        - 单表代换密码菜单界面输入 1 进行单表代换密码加密  
        Input 1 in the menu interface of single table replacement cipher to encrypt the single table replacement cipher  
![mono_encryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/14_mono_encryption.jpg)
        - 单表代换密码菜单界面输入 2 进行单表代换密码解密  
        Single table substitution cipher menu interface, enter 2 to decrypt the single table substitution cipher  
![mono_decryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/15_mono_decryption.jpg)
    - 代换密码菜单界面输入 5 进入多表代换密码菜单界面  
    Enter 5 in the substitution cipher menu interface to enter the multi table substitution cipher menu interface  
![poly_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/16_poly_menu.jpg)
        - 多表代换密码菜单界面输入 1 进入维吉尼亚密码项，需要先输入密钥  
        Enter 1 in the menu interface of multi meter substitution cipher to enter the Virginia cipher item. You need to enter the key first  
![pre_vigenere](https://github.com/goon-13/ClassicalCipher/blob/main/img/17_pre_vigenere.jpg)
        - 输入密钥后进入维吉尼亚密码菜单  
        Enter the key to enter the Virginia cipher menu  
![vigenere_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/18_vigenere_menu.jpg)
        - 维吉尼亚密码菜单界面输入 1 进行维吉尼亚密码加密  
        Enter 1 in the Virginia cipher menu interface to encrypt the Virginia cipher  
![vigenere_encryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/19_vigenere_encryption.jpg)
        - 维吉尼亚密码菜单界面输入 2 进行维吉尼亚密码解密  
        Enter 2 in the Virginia cipher menu interface to decrypt the Virginia cipher  
![vigenere_decryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/20_vigenere_decryption.jpg)
2. 主菜单输入 2 进入置换密码  
Enter 2 in the main menu to enter the replacement cipher  
    - 按照提示输入密钥后才进入置换密码菜单界面  
    Enter the key according to the prompts before entering the replacement cipher menu interface  
![pre_permutation](https://github.com/goon-13/ClassicalCipher/blob/main/img/21_pre_permutation.jpg)  
![permutation_menu](https://github.com/goon-13/ClassicalCipher/blob/main/img/22_permutation_menu.jpg)
    - 置换密码菜单界面输入 1 进行置换密码加密  
    Input 1 in the replacement cipher menu interface to encrypt the replacement cipher  
![permutation_encryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/23_permutation_encryption.jpg)
    - 置换密码菜单界面输入 2 进行置换密码解密  
    Enter 2 in the permutation cipher menu interface to decrypt the permutation cipher  
![permutation_decryption](https://github.com/goon-13/ClassicalCipher/blob/main/img/24_permutation_decryption.jpg)

## 更多-More
最初是想把教材上的加解密都统一实现的，但刚做到DES就发现使用控制台获取用户输入不方便了...

At first, I wanted to implement all the encryption and decryption in the textbooks in a unified way, but I found it inconvenient to use the console to obtain user input just after I achieved DES. So I still separated them for implementation.  
Later, I will continue to use C language to implement other encryption and decryption methods.
