/**
 * 作者: 丁岳雄
 * 日期: 2017/12/10
 * 功能：通用程序的实现
 */
//#include "recursionFunction.h"

/**
 * 取左部为 W 的指令的位置
 * @param Z
 * @param W
 * @param t
 * @return
 */
int MinLeft(int *Z, int W, int t) {
    if (CantorL(Z[t]) == W)
        return t;
    else
        return MinLeft(Z, W, ++t);
}


/**
 * 纸带左移
 * @param X
 * @return
 */
int *Left(int *X) {
    int len = X[0] + 2;
    int *Y = calloc((len), sizeof(int));
    Y[0] = len - 1;
    Y[1] = 1;
    for (int i = 2; i < len; i++)
        Y[i] = X[i - 1];
    return Y;
}


/**
 * 纸带右移
 * @param X
 * @return
 */
int *Right(int *X) {
    int len = X[0] + 2;
    int *Y = calloc((len), sizeof(int));
    Y[0] = len - 1;
    Y[len - 1] = 1;
    for (int i = 1; i < Y[0]; i++)
        Y[i] = X[i];
    return Y;
}


/**
 * 计算个数
 * @param t
 * @param X
 * @return
 */
int Count(int t, int *X) {
    int sum = 0;
    for (int i = 1; i <= X[0]; i++) {
//        printf("%d ", X[i]);
        if (X[i] == t)
            sum++;
    }
    return sum;
}

/**
 * 模拟 P-T 通用程序
 * 说明：由于将实数转化为哥德尔数计算太慢，故将参数设为数组形式传入
 * @param Z  array 表示程序的哥德尔数组
 * @param X  array 表示纸带的哥德尔数组
 * @return
 */
int GeneralProgram(int *Z, int *X) {
    int V = 1;
    int I = 1;
    char s = 'A';
    if (PROG(Z) == 0) {
        while (1) {
            switch (s) {
                case 'A':
                    if (I == 0 || I > Z[0])
                        s = 'G';
                    else if (CantorR(Z[I]) == 1)
                        s = 'R';
                    else if (CantorR(Z[I]) == 2)
                        s = 'L';
                    else if (CantorR(Z[I]) == 3)
                        s = 'F';
                    else if (CantorR(Z[I]) == 4)
                        s = 'B';
                    else if (R(CantorR(Z[I]), 2) == 1)
                        s = 'T';
                    else if (X[V] == 2)
                        s = 'C';
                    else
                        s = 'D';
                    break;
                case 'D':
                    I++;
                    s = 'A';
                    break;
                case 'C':
                    I = MinLeft(Z, ((CantorR(Z[I]) - 3) / 2), 1);
                    s = 'A';
                    break;
                case 'T':
                    if (X[V] == 1)
                        s = 'C';
                    else
                        s = 'D';
                    break;
                case 'B':
                    if (X[V] != 1)
                        X[V]--;
                    s = 'D';
                    break;
                case 'F':
                    if (X[V] != 2)
                        X[V]++;
                    s = 'D';
                    break;
                case 'L':
                    if (V != 1)
                        s = 'M';
                    else {
                        X = Left(X);
                        s = 'D';
                    }
                    break;
                case 'M':
                    V--;
                    s = 'D';
                    break;
                case 'R':
                    if (V != X[0])
                        s = 'S';
                    else
                        X = Right(X);
                    break;
                case 'S':
                    V++;
                    s = 'D';
                    break;
                case 'G':
                    return Count(2, X) - 1;
            }
        }
    } else {
        return 0;
    }
}

