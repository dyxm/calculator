/**
 * 作者: 丁岳雄
 * 日期: 2017-10-28 21:05:15
 * 功能：29个原始递归函数（假设所有的输入数据均为大于等于零的数）
 */


/**
 * 初始函数，实现加一
 * @param x int
 * @return
 */
int S(int x) {
    return x + 1;
}

/**
 * 初始函数，零函数
 * @param x int
 * @return
 */
int N(int x) {
    return 0;
}

/**
 * 5、前驱函数，实现减一
 * @param x int
 * @return
 */
int P(int x) {
    if (x > 0)
        return x - 1;
    else
        return 0;
}

/**
 * 1、加法，x + y
 * @param x int
 * @param y int
 * @return
 */
int Add(int x, int y) {
    if (y == 0)
        return x;
    else
        return S(Add(x, P(y)));
}

/**
 * 2、乘法，x * y
 * @param x int
 * @param y int
 * @return
 */
int Mul(int x, int y) {
    if (y == 0)
        return 0;
    else
        return Add(Mul(x, P(y)), x);
}

/**
 * 3、阶乘，n!
 * @param x int
 * @return
 */
int Fac(int x) {
    if (x == 0)
        return 1;
        //return S(N(x));
    else
        return Mul(Fac(P(x)), x);
}

/**
 * 4、指数，x ^ y
 * @param x int
 * @param y int
 * @return
 */
int Exp(int x, int y) {
    if (y == 0)
        return 1;
    else
        return Mul(Exp(x, P(y)), x);
}

/**
 * 6、减法，x - y
 * @param x int
 * @param y int
 * @return
 */
int Sub(int x, int y) {
    if (y == 0)
        return x;
    else
        return P(Sub(x, P(y)));
}

/**
 * 7、绝对值，|x - y|
 * @param x int
 * @param y int
 * @return
 */
int Abs(int x, int y) {
    return Add(Sub(x, y), Sub(y, x));
}

/**
 * 8、阿尔法函数，x == 0 返回 1，否则返回 0
 * @param x int
 * @return
 */
int Alp(int x) {
    return Sub(1, x);
}

/**
 * 9、连加函数
 * @param f int(*)
 * @param x int
 * @param y int
 * @return
 * 示例：Adds(Mul, 3, 3) = Mul(3, 0) + Mul(3, 1) + Mul(3, 2) + Mul(3, 3)
 * 存在问题：f必须是一个接受两个个参数的函数，如Add(),Mul(),Exp(),Sub(),Abs()等
 */
int Adds(int (*f)(int, int), int x, int y) {
    if (y == 0)
        return f(x, y);
    else
        return Add(Adds(f, x, P(y)), f(x, y));
}

/**
 * 10、连乘函数
 * @param f int(*)
 * @param x int
 * @param y int
 * @return
 * 示例：Muls(Add, 3, 3) = Add(3, 0) * Add(3, 1) * Add(3, 2) * Add(3, 3)
 * 存在问题：f必须是一个接受两个个参数的函数，如Add(),Mul(),Exp(),Sub(),Abs()等
 */
int Muls(int (*f)(int, int), int x, int y) {
    if (y == 0)
        return f(x, y);
    else
        return Mul(Muls(f, x, P(y)), f(x, y));
}

/**
 * 11、d 函数，x == y 返回 0，否则返回 1
 * @param x int
 * @param y int
 * @return
 */
int D(int x, int y) {
    return Alp(Alp(Abs(x, y)));
}

/**
 * （谓词）取反函数
 * @param x int
 * @return
 */
int Not(int x) {
    return Alp(x);
}

/**
 * 析取函数，实现 P或Q
 * @param p int
 * @param q int
 * @return
 */
int Or(int p, int q) {
    return Mul(p, q);
}

/**
 * 合取函数，实现 P且Q
 * @param p int
 * @param q int
 * @return
 */
int And(int p, int q) {
    return Alp(Alp(Add(p, q)));
}

/**
 * 12、等于（谓词）， x = y 为真返回 0，否则返回 1
 * @param x int
 * @param y int
 * @return
 */
int Eq(int x, int y) {
    return D(x, y);
}

/**
 * 不等于（谓词）
 * @param x int
 * @param y int
 * @return
 */
int Neq(int x, int y) {
    return Not(Eq(x, y));
}

/**
 * 13、大于（谓词），x > y 为真返回 0，否则返回 1
 * @param x int
 * @param y int
 * @return
 */
int Gt(int x, int y) {
    return Alp(Sub(x, y));
}

/**
 * 小于（谓词），x < y 为真返回 0，否则返回 1
 * @param x int
 * @param y int
 * @return
 */
int Lt(int x, int y) {
    return Gt(y, x);
}

/**
 * 14、小于等于，x <= y 为真返回 0，否则返回 1
 * @param x int
 * @param y int
 * @return
 */
int Elt(int x, int y) {
    return Or(Lt(x, y), Eq(x, y));
    // x > y 取反亦可
    // return Not(Gt(x,y));
}

/**
 * 大于等于，x >= y 为真返回 0，否则返回 1
 * @param x int
 * @param y int
 * @return
 */
int Egt(int x, int y) {
    // 用小于等于函数，并将x, y位置对调
    return Elt(y, x);
    // x > y 析取 x = y
    // return Or(Gt(x, y), Eq(x, y));
    // x < y 取反
    // return Alp(Lt(x,y));

}

/*
 * 下面几个函数对参数的局限性较大，无法普遍使用，后面会根据实际情况重新写新的函数，不过思路是一致的
 *
// “分段”递归函数
int Sect(int g, int h, int p){
    return Add(Mul(g, Alp(p)), Mul(h,p));
}

// 存在量词,存在t（0 - y），使f(x,t)成立
int Exist(int (*f)(int, int), int x, int y){
    return Muls(f, x, y);
}

// 全称量词
int Any(int (*f)(int, int), int x, int y){
    return Alp(Alp(Adds(f, x, y)));
}

// 累加连乘
int AddsMuls(int (*f)(int, int),int x, int y){
    if(y == 0)
        return Muls(f, x, y);
    else
        return Add(AddsMuls(f, x, P(y)), Muls(f, x, y));
}

// 受囿取极小值函数
int Min(int (*f)(int, int),int x, int y){
    return Sect(AddsMuls(f, x, y), 0, Exist(f, x, y));
}
*/

/**
 * 15、是否整除（谓词），IsDivide(x, y) 表示 y 是否整除 x，为真返回 0，否则返回 1
 * @param x int 被除数
 * @param y int 除数
 * @return
 * 思路：x 每次都减 y，将每次的结果连乘起来；若 y 能整除 x 则必出现 x = y 的情况，连乘结果必为 0 ，否则为 1。
 * 问题：0 能被任何数整除，此函数却无法判别出
 */
int IsDivide(int x, int y) {
    if (y == 0)
        return 1;
    else if (x == 0)
        return Eq(x, y);
    else
        return Mul(IsDivide(Sub(x, y), y), Eq(x, y));
}

/**
 * 16、整除函数，Divide(x, y) 返回 y 整除 x 的商，其中 x 为被除数，y 为除数
 * @param x int 被除数
 * @param y int 除数
 * @return
 * 思路：x 每次都减 y，若 x > y 则加一，直到 x < y 为止。
 */
int Divide(int x, int y) {
    if (x < y)
        return 0;
    else
        return S(Divide(Sub(x, y), y));
}

/**
 * IsPrim() 函数的辅助函数(全称量词)
 * @param x int
 * @param t int
 * @return
 */
int AssiIsPrimAny(int x, int t) {
    if (t == 0)
        // 或 t = 1 或 t = x 或 t 不能整除 x
        return Or(Or(Eq(t, 1), Eq(t, x)), Not(IsDivide(x, t)));
        // 也可以直接返回 0
        // return 0;
    else
        return Add(AssiIsPrimAny(x, P(t)), Or(Or(Eq(t, 1), Eq(t, x)), Not(IsDivide(x, t))));
}

/**
 * 17、是否为素数（谓词）
 * @param x int
 * @return
 */
int IsPrim(int x) {
    // x > 1 且 (任意t <= x 都有(或 t = 1 或 t = x 或 t 不能整除 x))
    return And(Gt(x, 1), Alp(Alp(AssiIsPrimAny(x, x))));
}

/*
 * 以下为课本上去第i个素数的思路，时间复杂度太大，故不采用
 *
// 取第i个素数的辅助函数1(连乘函数)
int AssiPrimMuls(int pi, int u){
    if (u == 0)
        return And(IsPrim(u), Gt(u, pi));
    else
        return Mul(AssiPrimMuls(pi, P(u)), And(IsPrim(u), Gt(u, pi)));
}

// 取第i个素数的辅助函数2(连加函数) -- 与上一个辅助函数组成受囿取极小值函数
int AssiPrimAdd(int pi, int t){
    if (t == 0)
        return AssiPrimMuls(pi, t);
    else
        return Add(AssiPrimAdd(pi, P(t)),AssiPrimMuls(pi, t));
}

// 取第i个素数的辅助函数3（受囿取极小值函数）
int AssiPrimMin(int pi){
    return AssiPrimAdd(pi,S(Fac(pi)));
}

// 第i个素数的值
int Prim(int i){
    if (i == 0)
        return 0;
    else
        return AssiPrimMin(Prim(P(i)));
}
*/

/**
 * Prim() 函数的辅助函数（取极小值函数）
 * @param p1 int
 * @return
 * 思路：设pi为第 i 个素数，则第 i + 1 个素数必在 pi 和 pi！+ 1 之间（课本已证明），
 * 则从 pi + 1 开始找，第一个是素数的数即为第 i + 1 个素数，返回之
 */
int AssiPrimMin(int p1) {
    if (Alp(IsPrim(p1)))
        return p1;
    else
        return AssiPrimMin(S(p1));
}

/**
 * 18、取 i 个素数的函数
 * @param i int
 * @return
 */
int Prim(int i) {
    if (i == 0)
        return 0;
    else
        return AssiPrimMin(S(Prim(P(i))));
}

/**
 * 19、取余函数，R(x, y)表示 y 除 x 的余数
 * @param x int 被除数
 * @param y int 除数
 * @return
 */
int R(int x, int y) {
    if (y > x)
        return x;
    else
        return Sub(x, Mul(y, Divide(x, y)));
}

/**
 * T() 函数的辅助函数
 * @param i int
 * @param x int
 * @return
 */
int AssiLh(int i, int x) {
    if (i == 0)
        // 当 pi 整除 x 时返回 1，否则返回 0
        return Alp(IsDivide(x, Prim(i)));
    else
        return Add(AssiLh(P(i), x), Alp(IsDivide(x, Prim(i))));
}

/**
 * 20、取 x 素因子分解中非零指数个数的函数
 * @param x int
 * @return
 */
int T(int x) {
    if (x == 0)
        return 0;
    else
        return AssiLh(x, x);
}

/**
 * PrimDecpExp() 函数的辅助函数（取极小值函数）
 * @param x int
 * @param pi int
 * @param t int
 * @return
 */
int AssiPrimDecpExpMin(int x, int pi, int t) {
    // t 从 0 开始递增，返回第一个使(pi ^ t 整除 x 且 pi ^ (t+1) 不能整除 x )的t值
    if (Alp(And(IsDivide(x, Exp(pi, t)), Not(IsDivide(x, Exp(pi, S(t)))))))
        return t;
    else
        return AssiPrimDecpExpMin(x, pi, S(t));
}

/**
 * 21、取 x 素因子分解中第i个素数的指数，即pi的指数
 * @param x int
 * @param i int
 * @return
 */
int PrimDecpExp(int x, int i) {
    if (i == 0)
        return 0;
    else
        return AssiPrimDecpExpMin(x, Prim(i), 0);
}

/**
 * PrimDecpLgIndex() 函数的辅助函数（全称量词）
 * @param i int
 * @param j int
 * @param x int
 * @return
 */
int AssiPrimDecpLgIndexAny(int i, int j, int x) {
    if (j == 0)
        // 或 j <= i 或 PrimDecpExp(x,j) = 0
        return Or(Elt(j, i), Eq(PrimDecpExp(x, j), 0));
    else
        return Add(AssiPrimDecpLgIndexAny(i, P(j), x), Or(Elt(j, i), Eq(PrimDecpExp(x, j), 0)));
}

/**
 * PrimDecpLgIndex() 函数的辅助函数（取极小值）
 * @param x int
 * @param i int
 * @return
 */
int AssiPrimDecpLgIndexMin(int x, int i) {
    if (Alp(And(Neq(PrimDecpExp(x, i), 0), Alp(Alp(AssiPrimDecpLgIndexAny(i, x, x))))))
        return i;
    else
        return AssiPrimDecpLgIndexMin(x, S(i));
}

/**
 * 22、 取 x 素因子分解中非0指数最大素数的序号
 * @param x int
 * @return
 */
int PrimDecpLgIndex(int x) {
    if (x > 1)
        return AssiPrimDecpLgIndexMin(x, 0);
    else
        return 0;
}

/**
 * PrimDecpGn() 函数的辅助函数（全称量词）
 * @param x int
 * @param i int
 * @return
 */
int AssiPrimDecpGnAny(int x, int i) {
    if (i == 0)
        // 或 i = 0 或 PrimDecpExp(x,i) 不等于 0
        return Or(Eq(i, 0), Neq(PrimDecpExp(x, i), 0));
    else
        return Add(AssiPrimDecpGnAny(x, P(i)), Or(Eq(i, 0), Neq(PrimDecpExp(x, i), 0)));
}

/**
 * 23、判断 x 的素因子分解中是否没有零指数（谓词）
 * @param x int
 * @return
 */
int PrimDecpGn(int x) {
    if (Alp(Gt(x, 1)))
        return Alp(Alp(AssiPrimDecpGnAny(x, PrimDecpLgIndex(x))));
    else
        return 1;
}

/**
 * PrimDecpExpCount() 函数的辅助函数（连加）
 * @param x int
 * @param a int
 * @param i int
 * @return
 */
int AssiPrimDecpExpCountAdd(int x, int a, int i) {
    if (i == 1)
        // 如果 a = PrimDecpExp(x, i) 则返回 1，否则返回 0
        return Alp(Eq(a, PrimDecpExp(x, i)));
    else
        return Add(AssiPrimDecpExpCountAdd(x, a, P(i)), Alp(Eq(a, PrimDecpExp(x, i))));
}

/**
 * 26、计算 x 的素因子分解中指数为a的素因子个数
 * @param x int
 * @param a int
 * @return
 */
int PrimDecpExpCount(int x, int a) {
    return AssiPrimDecpExpCountAdd(x, a, PrimDecpLgIndex(x));
}

/**
 * RealNumToGodelArray() 函数的辅助函数
 * @param arr int *
 * @param x int
 * @param i int
 * @return
 */
int *ToGodelArray(int *arr, int x, int i) {
    if (i == 0)
        return arr;
    else {
        arr[i] = PrimDecpExp(x, i);
        return ToGodelArray(arr, x, P(i));
    }
}

/**
 * 24、正整数转哥德尔数
 * @param x int
 * @return
 * 说明：返回的数组第一个元素存的数该哥德尔数组元素的个数，例如某哥德尔数为[1, 0, 1]，则实际返回的数组为[3, 1, 0, 1]
 */
int *RealNumToGodelArray(int x) {
    int len = PrimDecpLgIndex(x);
    int *arr = calloc((len + 1), sizeof(int));
    arr[0] = len;//用数组第一个存储哥德尔数组的长度
    return ToGodelArray(arr, x, len);
}

/**
 * GodelArrayToRealNum() 函数的辅助函数
 * @param arr int *
 * @param i int
 * @return
 */
int ToRealNum(int *arr, int i) {
    if (i == 1)
        return Exp(Prim(i), arr[i]);
    else
        return Mul(ToRealNum(arr, P(i)), Exp(Prim(i), arr[i]));
}

/**
 * 哥德尔数转正整数
 * @param arr int * ,数组第一元素表示这组哥德尔数的长度
 * @return
 */
int GodelArrayToRealNum(int *arr) {
    return ToRealNum(arr, arr[0]);
}

/**
 * GodelMul() 函数的辅助函数
 * @param arr int *
 * @param len int
 * @param i int
 * @return
 */
int AssiGodelMul(int *arr, int len, int i) {
    if (i == 1)
        return Exp(Prim(Add(len, i)), arr[i]);
    else
        return Mul(AssiGodelMul(arr, len, P(i)), Exp(Prim(Add(len, i)), arr[i]));
}

/**
 * 25、哥德尔乘（返回的是实数）
 * @param x int
 * @param y int
 * @return
 */
int GodelMul(int x, int y) {
    int *arr = RealNumToGodelArray(y);
    return Mul(x, AssiGodelMul(arr, PrimDecpLgIndex(x), arr[0]));
}

/**
 * Cantor 矩阵前（x + y）条对角线元素个数之和，即 1+2+...+n
 * @param n int
 * @return
 */
int H(int n) {
    if (n == 0)
        return 0;
    else
        return Add(H(P(n)), n);
}

/**
 * 27、Cantor矩阵对角线元素相应编号
 * @param x int
 * @param y int
 * @return
 */
int CantorIndex(int x, int y) {
    return Add(H(Add(x, y)), y);
}

/**
 * 辅助函数（取极小值函数）
 * @param z int
 * @param n int
 * @return
 */
int AssiCantorMin(int z, int n) {
    // 返回第一个使 h(n) < Z 且 z < h(n + 1) 成立的 n 值
    if (Alp(And(Elt(H(n), z), Lt(z, H(S(n))))))
        return n;
    else
        return AssiCantorMin(z, S(n));
}

/**
 * 28、取Cantor矩阵对角线元素序号的右部
 * @param z int
 * @return
 */
int CantorR(int z) {
    return Sub(z, H(AssiCantorMin(z, 0)));
}

/**
 * 29、取Cantor矩阵对角线元素序号的左部
 * @param z int
 * @return
 */
int CantorL(int z) {
    return Sub(AssiCantorMin(z, 0), CantorR(z));
}


int  AssiProgExit_1(int* x, int i, int j){
    if (j == 0)
        return Eq(CantorL(x[i]), 0);
    else
        return Mul(AssiProgExit_1(x, i, P(j)), Eq(CantorL(x[i]), CantorL(x[j])));
}

int  AssiProgExit_2(int* x, int i){
    if (i == 0)
        return 1;
    else
        return Mul(AssiProgExit_2(x, P(i)), And(AssiProgExit_1(x, i, P(i)),Neq(CantorL(x[i]), 0)));
}


int  AssiProgAny(int* x, int i){
    if(i == 0)
        return 0;
    else
        return Add(AssiProgAny(x, P(i)), Or(Eq(i, 0),Neq(CantorR(x[i]), 0)));
}

int PROG(int* x){
//    int a[] = {6, 2, 2, 2, 2, 2, 2};
//    int *gArr = a;
//    int *gArr = RealNumToGodelArray(x);
//    int Lt = x[0];
    return And(AssiProgAny(x, x[0]), Not(Alp(Alp(AssiProgExit_2(x, x[0])))));
}
