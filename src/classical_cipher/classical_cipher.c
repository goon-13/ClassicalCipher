#include <stdlib.h>

#include "get_input_by_getch.h"
#include "navi_menu.h"
#include "substitution_cipher.h"
#include "permutation_cipher.h"

/**
  * @brief  古典密码 菜单控制
  * @param  text[]-输入的内容
  * @retval 无
  */
void classicalProcess(char text[]) {
    int i = -1;
   
    while(i != 0) {
        printClassicalCipherMenu();
        numPrompt();
        i = getInputNumByGetch();
        system("cls"); /* 清屏 */
        switch(i) {
            case 1: { /* 代换密码 */
                substitutionProcess(text);                
                break;
            }
            case 2: { /* 置换密码 */
                permutationProcess(text);
                break;
            }
        } // end of switch
        system("cls"); /* 清屏 */
    }
}