#include <stdlib.h>

#include "get_input_by_getch.h"
#include "navi_menu.h"
#include "vigenere_cipher.h"

/**
  * @brief  多表代换密码 菜单控制
  *         [1] 维吉尼亚密码(Vigenere cipher)
  * @param  text[]-输入的内容
  * @retval 无
  */
void polyalphabeticProcess(char text[]) {
    int i = -1;
   
    while(i != 0) {
        printPolyalphabeticCipherMenu();
        numPrompt();
        i = getInputNumByGetch();
        system("cls"); /* 清屏 */
        switch(i) {
            case 1: { /* 维吉尼亚密码 */
                vigenereProcess(text);
                break;
            }
        } // end of switch
        system("cls"); /* 清屏 */
    }
}