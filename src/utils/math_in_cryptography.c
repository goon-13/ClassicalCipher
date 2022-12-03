#include "widgets.h"

/**
  * @brief  若传入的 a < b 则交换，确保传入的两个值关系为 a >= b
  * @param  a 
  * @param  b 
  * @retval 无
  */
void makeAGreaterThanB(int* a, int* b) {
  if(*a < *b) {
    swap(a, b);
  }
}

/**
  * @brief  不使用递归实现辗转相除法求整数 a 和整数 b 的最大公约数(Greatest Common Divisor)
  * 欧几里得算法： a >= b >= 0
  * b = 0时：gcd(a,b) = a
  * b > 0时：gcd(a,b) = gcd(b,r) a%b=r
  * @param  a 
  * @param  b 
  * @retval result 整数 a 和整数 b 的最大公约数
  */
int gcd(int a, int b) {
    /* 对数据预处理，需要使 a 和 b 不为负数，且 a >= b */
    int r = 0; /* remainder 余数 */
    makeAGreaterThanB(&a, &b);
    if(b == 0) {
      return a;
    } else {
      do {
        r = a % b;
        /* 简化代码-这样写 return b 为算法倒数第二次的结果
          * if(r != 0) {
          *   a = b;
          *   b = r;
          * }
        */
        a = b;
        b = r;
      } while (r != 0);
      return a;
    }
}

/**
 * @brief  利用扩展欧几里得算法(Extended Euclidean algorithm)计算整数 a 在 mod n（模n）下的乘法逆元
 * 扩展欧几里得算法数学原理： s(0)=1, s(1)=0; t(0)=0, t(1)=1,
 *           r(0)=a, r(1)=b
 *           r(0)=r(1)q(1)+r(2) ; r(1)=r(2)q(2)+r(3) ; ... ; r(i-1)=r(i)q(i)+r(i+1) ;
 *           ... ; r(n-2)=r(n-1)q(n-1)+r(n) ; r(n-1)=r(n)q(n)
 *           递推公式：s(i+1) = s(i-1) - s(i)q(i) ; t(i+1) = t(i-1) - t(i)q(i) (i=1, ..., n)
 *           as(n) + bt(n) = r(n) <-- 由最大公约数表示定理 as + bt = gcd(a, b)
 *           r(n) = gcd(a, b)
 * 求乘法逆元原理：要求 gcd(a, n) = 1
 *          则有 as + tn = 1
 *          左右同时模n，得as ≡ 1 (mod n)，s 即为 a 的乘法逆元
 * @param  a
 * @param  n
 * @retval result 整数 a 在 mod n（模n）下的乘法逆元
 */
int modularMultiplicativeInverse(int a, int n) {
  /* a 与 n 互素才有乘法逆元，先进行互素校验，无乘法逆元，返回 0 （乘法逆元a^(-1)取值范围：1 <= a^(-1) < n） */
  if(gcd(a, n) != 1) {
    return 0;
  }
  int r; /* remainder 每一轮中的余数 */
  int q; /* 每一轮中的乘数 */
  int s_pre=1, s_cur=0, s_next;
  int modulus = n; /* 存储模数，过程中n值会被改变，但最后还需要用到 */

  do {
    q = a / n; /* 第cur轮计算，q_cur */
    r = a % n; /* 第cur轮计算，r_next */
    s_next = s_pre - s_cur * q;
    /* 准备好下一轮计算的数值 */
    a = n;
    n = r;
    s_pre = s_cur;
    s_cur = s_next;
  } while(r != 0);
  return (s_pre%modulus + modulus) % modulus;
}   