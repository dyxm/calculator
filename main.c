/**
 * 作者:丁岳雄
 * 日期:2017-10-28 21:05:15
 * 功能：1、测试30个原始递归函数（假设所有的输入数据均为大于等于零的数）
 *       2、测试通用程序
 */

#include <stdio.h>
//#include <mem.h>
#include <conio.h>
#include <stdlib.h>
#include "recursionFunction.h"
#include "generalProgram.h"

// 测试
int main() {
    /*
     * 30 个原始递归函数的测试
     */
//    printf("1、 3 + 4 等于：%d\n", Add(3, 4));
//    printf("2、 3 x 4 等于：%d\n", Mul(3, 4));
//    printf("3、 4 的阶乘等于：%d\n", Fac(4));
//    printf("4、 2 的 4 次方等于：%d\n", Exp(2, 4));
//    printf("5、 2 的 前驱等于：%d\n", P(2));
//    printf("6、 5 - 2 等于：%d\n", Sub(5, 2));
//    printf("7、 |2 - 5| 等于：%d\n", Abs(2, 5));
//    printf("8、 0 取阿尔法等于：%d，3 取阿尔法等于：%d\n", Alp(0), Alp(3));
//    printf("9、 （3 + 0）+（3 + 1）+（3 + 2）+（3 + 3）+（3 + 4）等于：%d\n", Adds(Add, 3, 4));
//    printf("10、 （3 + 0）*（3 + 1）*（3 + 2）*（3 + 3）*（3 + 4）等于：%d\n", Muls(Add, 3, 4));
//    printf("11、 d(3, 3) 等于：%d ,d(3, 5) 等于：%d\n", D(3, 3), D(3, 5));
//    printf("12、 3 = 3 等于：%d ,3 = 5 等于：%d\n", Eq(3, 3), Eq(3, 5));
//    printf("13、 3 > 3 等于：%d ,5 > 3 等于：%d\n", Gt(3, 3), Gt(5, 3));
//    printf("14、 3 <= 3 等于：%d ,5 <= 3 等于：%d\n", Elt(3, 3), Elt(5, 3));
//    printf("15、 判断是否整除，3|6 等于：%d ,4|6 等于：%d\n", IsDivide(6, 3), IsDivide(6, 4));
//    printf("16、 6/3 等于：%d ,7/3 等于：%d\n", Divide(6, 3), Divide(7, 3));
//    printf("17、 判断是否是素数，IsPrim(3) 等于：%d ,IsPrim(9) 等于：%d\n", IsPrim(3), IsPrim(9));
//    printf("18、 第 4 个素数等于：%d\n", Prim(28));
//    printf("19、 3 除 7 的余数等于：%d\n", R(7, 3));
//    printf("20、 6 的素因子分解中非零指数个数等于：%d\n", T(6));
//    printf("21、 18 的素因子分解中第 2 个素数的指数等于：%d\n", PrimDecpExp(18, 2));
//    printf("22、 18 的素因子分解中非零指数最大的序号等于：%d\n", PrimDecpLgIndex(18));
//    printf("23、 GN(x)表示x的素因子分解中没有零指数，则GN(6) 等于：%d ,GN(9) 等于：%d\n", PrimDecpGn(6), PrimDecpGn(9));
//
//    int *gArr = RealNumToGodelArray(10);
//    printf("24、 10 的哥德尔数等于：[");
//    for (int i = 1; i <= gArr[0]; ++i) {
//        printf("%d", gArr[i]);
//        if(i != gArr[0])
//            printf(", ");
//    }
//    printf("]\n");
//
//    printf("25、 6 * 7(哥德尔乘)等于：%d\n", GodelMul(6, 7));
//    printf("26、 30 的素因子分解中指数为 1 的素因子个数等于：%d\n", PrimDecpExpCount(30, 1));
//    printf("27、 Cantor对角线上下标<3, 2>的元素的序号等于：%d\n", CantorIndex(3, 2));
//    printf("28、 Cantor对角线上序号为 17 的元素小标右部等于：%d\n", CantorR(17));
//    printf("29、 Cantor对角线上序号为 17 的元素小标左部等于：%d\n", CantorL(17));
//
//    int x[] = {6, 2, 2, 2, 2, 20, 2};
//    printf("30、 PROG(x),判断 x 是否为某个 P - T 函数的哥德尔数，如x = {6, 2, 2, 2, 2, 20, 2}，则 PROG（x）等于: %d\n", PROG(x));


    /*
     * 通用程序测试
     */
//    int P[] = {6, 4, 20, 7, 44, 5, 14}; // (X - 1) 程序
    int S[] = {4, 4, 27, 9, 2}; // (X + 1) 程序
    int x[] = {7, 2, 2, 2, 2, 2, 2, 1}; // 5
    int y = GeneralProgram(S, x);
    printf("%d\n", y);


    printf("\n\n\n按任意键结束~\n\n");
    getch();
    return 0;
}
