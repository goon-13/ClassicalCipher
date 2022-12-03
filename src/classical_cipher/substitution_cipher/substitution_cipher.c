#include <stdlib.h>

#include "get_input_by_getch.h"
#include "navi_menu.h"
#include "caesar_cipher.h"
#include "shift_cipher.h"
#include "affine_cipher.h"
#include "monoalphabetic_cipher.h"
#include "polyalphabetic_cipher.h"

/**
  * @brief  代换密码 菜单控制
  *         [1] 恺撒密码(Caesar cipher)
 *          [2] 移位密码(Shift cipher)
 *          [3] 仿射密码(Affine cipher)
 *          [4] 单表代换密码(Monoalphabetic cipher)
 *          [5] 多表代换密码(Polyalphabetic cipher)
  * @param  text[]-输入的内容
  * @retval 无
  */
void substitutionProcess(char text[]) {
    int i = -1;
   
    while(i != 0) {
        printSubstitutionCipherMenu();
        numPrompt();
        i = getInputNumByGetch();
        system("cls"); /* 清屏 */
        switch(i) {
            case 1: { /* 恺撒密码 */
                caesarProcess(text);
                break;
            }
            case 2: { /* 移位密码 */
                shiftProcess(text);
                break;
            }
            case 3: { /* 仿射密码 */
                affineProcess(text);
                break;
            }
            case 4: { /* 单表代换密码 */
                monoalphabeticProcess(text);
                break;
            }
            case 5: { /* 多表代换密码 */
                polyalphabeticProcess(text);
                break;
            }
        } // end of switch
        system("cls"); /* 清屏 */
    }
}