/**
 * ����:������
 * ����:2017-10-28 21:05:15
 * ���ܣ�ʵ��29��ԭʼ�ݹ麯�����������е��������ݾ�Ϊ���ڵ����������
 */

#include <stdio.h>
//#include <mem.h>
#include <conio.h>
#include <stdlib.h>

/**
 * ��ʼ������ʵ�ּ�һ
 * @param x int
 * @return
 */
int S(int x) {
    return x + 1;
}

/**
 * ��ʼ�������㺯��
 * @param x int
 * @return
 */
int N(int x) {
    return 0;
}

/**
 * 5��ǰ��������ʵ�ּ�һ
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
 * 1���ӷ���x + y
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
 * 2���˷���x * y
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
 * 3���׳ˣ�n!
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
 * 4��ָ����x ^ y
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
 * 6��������x - y
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
 * 7������ֵ��|x - y|
 * @param x int
 * @param y int
 * @return
 */
int Abs(int x, int y) {
    return Add(Sub(x, y), Sub(y, x));
}

/**
 * 8��������������x == 0 ���� 1�����򷵻� 0
 * @param x int
 * @return
 */
int Alp(int x) {
    return Sub(1, x);
}

/**
 * 9�����Ӻ���
 * @param f int(*)
 * @param x int
 * @param y int
 * @return
 * ʾ����Adds(Mul, 3, 3) = Mul(3, 0) + Mul(3, 1) + Mul(3, 2) + Mul(3, 3)
 * �������⣺f������һ�����������������ĺ�������Add(),Mul(),Exp(),Sub(),Abs()��
 */
int Adds(int (*f)(int, int), int x, int y) {
    if (y == 0)
        return f(x, y);
    else
        return Add(Adds(f, x, P(y)), f(x, y));
}

/**
 * 10�����˺���
 * @param f int(*)
 * @param x int
 * @param y int
 * @return
 * ʾ����Muls(Add, 3, 3) = Add(3, 0) * Add(3, 1) * Add(3, 2) * Add(3, 3)
 * �������⣺f������һ�����������������ĺ�������Add(),Mul(),Exp(),Sub(),Abs()��
 */
int Muls(int (*f)(int, int), int x, int y) {
    if (y == 0)
        return f(x, y);
    else
        return Mul(Muls(f, x, P(y)), f(x, y));
}

/**
 * 11��d ������x == y ���� 0�����򷵻� 1
 * @param x int
 * @param y int
 * @return
 */
int D(int x, int y) {
    return Alp(Alp(Abs(x, y)));
}

/**
 * ��ν�ʣ�ȡ������
 * @param x int
 * @return
 */
int Not(int x) {
    return Alp(x);
}

/**
 * ��ȡ������ʵ�� P��Q
 * @param p int
 * @param q int
 * @return
 */
int Or(int p, int q) {
    return Mul(p, q);
}

/**
 * ��ȡ������ʵ�� P��Q
 * @param p int
 * @param q int
 * @return
 */
int And(int p, int q) {
    return Alp(Alp(Add(p, q)));
}

/**
 * 12�����ڣ�ν�ʣ��� x = y Ϊ�淵�� 0�����򷵻� 1
 * @param x int
 * @param y int
 * @return
 */
int Eq(int x, int y) {
    return D(x, y);
}

/**
 * �����ڣ�ν�ʣ�
 * @param x int
 * @param y int
 * @return
 */
int Neq(int x, int y) {
    return Not(Eq(x, y));
}

/**
 * 13�����ڣ�ν�ʣ���x > y Ϊ�淵�� 0�����򷵻� 1
 * @param x int
 * @param y int
 * @return
 */
int Gt(int x, int y) {
    return Alp(Sub(x, y));
}

/**
 * С�ڣ�ν�ʣ���x < y Ϊ�淵�� 0�����򷵻� 1
 * @param x int
 * @param y int
 * @return
 */
int Lt(int x, int y) {
    return Gt(y, x);
}

/**
 * 14��С�ڵ��ڣ�x <= y Ϊ�淵�� 0�����򷵻� 1
 * @param x int
 * @param y int
 * @return
 */
int Elt(int x, int y) {
    return Or(Lt(x, y), Eq(x, y));
    // x > y ȡ�����
    // return Not(Gt(x,y));
}

/**
 * ���ڵ��ڣ�x >= y Ϊ�淵�� 0�����򷵻� 1
 * @param x int
 * @param y int
 * @return
 */
int Egt(int x, int y) {
    // ��С�ڵ��ں���������x, yλ�öԵ�
    return Elt(y, x);
    // x > y ��ȡ x = y
    // return Or(Gt(x, y), Eq(x, y));
    // x < y ȡ��
    // return Alp(Lt(x,y));

}

/*
 * ���漸�������Բ����ľ����Խϴ��޷��ձ�ʹ�ã���������ʵ���������д�µĺ���������˼·��һ�µ�
 *
// ���ֶΡ��ݹ麯��
int Sect(int g, int h, int p){
    return Add(Mul(g, Alp(p)), Mul(h,p));
}

// ��������,����t��0 - y����ʹf(x,t)����
int Exist(int (*f)(int, int), int x, int y){
    return Muls(f, x, y);
}

// ȫ������
int Any(int (*f)(int, int), int x, int y){
    return Alp(Alp(Adds(f, x, y)));
}

// �ۼ�����
int AddsMuls(int (*f)(int, int),int x, int y){
    if(y == 0)
        return Muls(f, x, y);
    else
        return Add(AddsMuls(f, x, P(y)), Muls(f, x, y));
}

// ����ȡ��Сֵ����
int Min(int (*f)(int, int),int x, int y){
    return Sect(AddsMuls(f, x, y), 0, Exist(f, x, y));
}
*/

/**
 * 15���Ƿ�������ν�ʣ���IsDivide(x, y) ��ʾ y �Ƿ����� x��Ϊ�淵�� 0�����򷵻� 1
 * @param x int ������
 * @param y int ����
 * @return
 * ˼·��x ÿ�ζ��� y����ÿ�εĽ�������������� y ������ x ��س��� x = y ����������˽����Ϊ 0 ������Ϊ 1��
 * ���⣺0 �ܱ��κ����������˺���ȴ�޷��б��
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
 * 16������������Divide(x, y) ���� y ���� x ���̣����� x Ϊ��������y Ϊ����
 * @param x int ������
 * @param y int ����
 * @return
 * ˼·��x ÿ�ζ��� y���� x > y ���һ��ֱ�� x < y Ϊֹ��
 */
int Divide(int x, int y) {
    if (x < y)
        return 0;
    else
        return S(Divide(Sub(x, y), y));
}

/**
 * IsPrim() �����ĸ�������(ȫ������)
 * @param x int
 * @param t int
 * @return
 */
int AssiIsPrimAny(int x, int t) {
    if (t == 0)
        // �� t = 1 �� t = x �� t �������� x
        return Or(Or(Eq(t, 1), Eq(t, x)), Not(IsDivide(x, t)));
        // Ҳ����ֱ�ӷ��� 0
        // return 0;
    else
        return Add(AssiIsPrimAny(x, P(t)), Or(Or(Eq(t, 1), Eq(t, x)), Not(IsDivide(x, t))));
}

/**
 * 17���Ƿ�Ϊ������ν�ʣ�
 * @param x int
 * @return
 */
int IsPrim(int x) {
    // x > 1 �� (����t <= x ����(�� t = 1 �� t = x �� t �������� x))
    return And(Gt(x, 1), Alp(Alp(AssiIsPrimAny(x, x))));
}

/*
 * ����Ϊ�α���ȥ��i��������˼·��ʱ�临�Ӷ�̫�󣬹ʲ�����
 *
// ȡ��i�������ĸ�������1(���˺���)
int AssiPrimMuls(int pi, int u){
    if (u == 0)
        return And(IsPrim(u), Gt(u, pi));
    else
        return Mul(AssiPrimMuls(pi, P(u)), And(IsPrim(u), Gt(u, pi)));
}

// ȡ��i�������ĸ�������2(���Ӻ���) -- ����һ�����������������ȡ��Сֵ����
int AssiPrimAdd(int pi, int t){
    if (t == 0)
        return AssiPrimMuls(pi, t);
    else
        return Add(AssiPrimAdd(pi, P(t)),AssiPrimMuls(pi, t));
}

// ȡ��i�������ĸ�������3������ȡ��Сֵ������
int AssiPrimMin(int pi){
    return AssiPrimAdd(pi,S(Fac(pi)));
}

// ��i��������ֵ
int Prim(int i){
    if (i == 0)
        return 0;
    else
        return AssiPrimMin(Prim(P(i)));
}
*/

/**
 * Prim() �����ĸ���������ȡ��Сֵ������
 * @param p1 int
 * @return
 * ˼·����piΪ�� i ����������� i + 1 ���������� pi �� pi��+ 1 ֮�䣨�α���֤������
 * ��� pi + 1 ��ʼ�ң���һ��������������Ϊ�� i + 1 ������������֮
 */
int AssiPrimMin(int p1) {
    if (Alp(IsPrim(p1)))
        return p1;
    else
        AssiPrimMin(S(p1));
}

/**
 * 18��ȡ i �������ĺ���
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
 * 19��ȡ�ຯ����R(x, y)��ʾ y �� x ������
 * @param x int ������
 * @param y int ����
 * @return
 */
int R(int x, int y) {
    if (y > x)
        return x;
    else
        return Sub(x, Mul(y, Divide(x, y)));
}

/**
 * T() �����ĸ�������
 * @param i int
 * @param x int
 * @return
 */
int AssiLh(int i, int x) {
    if (i == 0)
        // �� pi ���� x ʱ���� 1�����򷵻� 0
        return Alp(IsDivide(x, Prim(i)));
    else
        return Add(AssiLh(P(i), x), Alp(IsDivide(x, Prim(i))));
}

/**
 * 20��ȡ x �����ӷֽ��з���ָ�������ĺ���
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
 * PrimDecpExp() �����ĸ���������ȡ��Сֵ������
 * @param x int
 * @param pi int
 * @param t int
 * @return
 */
int AssiPrimDecpExpMin(int x, int pi, int t) {
    // t �� 0 ��ʼ���������ص�һ��ʹ(pi ^ t ���� x �� pi ^ (t+1) �������� x )��tֵ
    if (Alp(And(IsDivide(x, Exp(pi, t)), Not(IsDivide(x, Exp(pi, S(t)))))))
        return t;
    else
        return AssiPrimDecpExpMin(x, pi, S(t));
}

/**
 * 21��ȡ x �����ӷֽ��е�i��������ָ������pi��ָ��
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
 * PrimDecpLgIndex() �����ĸ���������ȫ�����ʣ�
 * @param i int
 * @param j int
 * @param x int
 * @return
 */
int AssiPrimDecpLgIndexAny(int i, int j, int x) {
    if (j == 0)
        // �� j <= i �� PrimDecpExp(x,j) = 0
        return Or(Elt(j, i), Eq(PrimDecpExp(x, j), 0));
    else
        return Add(AssiPrimDecpLgIndexAny(i, P(j), x), Or(Elt(j, i), Eq(PrimDecpExp(x, j), 0)));
}

/**
 * PrimDecpLgIndex() �����ĸ���������ȡ��Сֵ��
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
 * 22�� ȡ x �����ӷֽ��з�0ָ��������������
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
 * PrimDecpGn() �����ĸ���������ȫ�����ʣ�
 * @param x int
 * @param i int
 * @return
 */
int AssiPrimDecpGnAny(int x, int i) {
    if (i == 0)
        // �� i = 0 �� PrimDecpExp(x,i) ������ 0
        return Or(Eq(i, 0), Neq(PrimDecpExp(x, i), 0));
    else
        return Add(AssiPrimDecpGnAny(x, P(i)), Or(Eq(i, 0), Neq(PrimDecpExp(x, i), 0)));
}

/**
 * 23���ж� x �������ӷֽ����Ƿ�û����ָ����ν�ʣ�
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
 * PrimDecpExpCount() �����ĸ������������ӣ�
 * @param x int
 * @param a int
 * @param i int
 * @return
 */
int AssiPrimDecpExpCountAdd(int x, int a, int i) {
    if (i == 1)
        // ��� a = PrimDecpExp(x, i) �򷵻� 1�����򷵻� 0
        return Alp(Eq(a, PrimDecpExp(x, i)));
    else
        return Add(AssiPrimDecpExpCountAdd(x, a, P(i)), Alp(Eq(a, PrimDecpExp(x, i))));
}

/**
 * 26������ x �������ӷֽ���ָ��Ϊa�������Ӹ���
 * @param x int
 * @param a int
 * @return
 */
int PrimDecpExpCount(int x, int a) {
    return AssiPrimDecpExpCountAdd(x, a, PrimDecpLgIndex(x));
}

/**
 * RealNumToGodelArray() �����ĸ�������
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
        ToGodelArray(arr, x, P(i));
    }
}

/**
 * 24��������ת��¶���
 * @param x int
 * @return
 * ˵�������ص������һ��Ԫ�ش�����ø�¶�����Ԫ�صĸ���������ĳ��¶���Ϊ[1, 0, 1]����ʵ�ʷ��ص�����Ϊ[3, 1, 0, 1]
 */
int *RealNumToGodelArray(int x) {
    int len = PrimDecpLgIndex(x);
    int *arr = calloc((len + 1), sizeof(int));
    arr[0] = len;//�������һ���洢��¶�����ĳ���
    return ToGodelArray(arr, x, len);
}

/**
 * GodelArrayToRealNum() �����ĸ�������
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
 * ��¶���ת������
 * @param arr int * ,�����һԪ�ر�ʾ�����¶����ĳ���
 * @return
 */
int GodelArrayToRealNum(int *arr) {
    return ToRealNum(arr, arr[0]);
}

/**
 * GodelMul() �����ĸ�������
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
 * 25����¶��ˣ����ص���ʵ����
 * @param x int
 * @param y int
 * @return
 */
int GodelMul(int x, int y) {
    int *arr = RealNumToGodelArray(y);
    return Mul(x, AssiGodelMul(arr, PrimDecpLgIndex(x), arr[0]));
}

/**
 * Cantor ����ǰ��x + y�����Խ���Ԫ�ظ���֮�ͣ��� 1+2+...+n
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
 * 27��Cantor����Խ���Ԫ����Ӧ���
 * @param x int
 * @param y int
 * @return
 */
int CantorIndex(int x, int y) {
    return Add(H(Add(x, y)), y);
}

/**
 * ����������ȡ��Сֵ������
 * @param z int
 * @param n int
 * @return
 */
int AssiCantorMin(int z, int n) {
    // ���ص�һ��ʹ h(n) < Z �� z < h(n + 1) ������ n ֵ
    if (Alp(And(Elt(H(n), z), Lt(z, H(S(n))))))
        return n;
    else
        return AssiCantorMin(z, S(n));
}

/**
 * 28��ȡCantor����Խ���Ԫ����ŵ��Ҳ�
 * @param z int
 * @return
 */
int CantorR(int z) {
    return Sub(z, H(AssiCantorMin(z, 0)));
}

/**
 * 29��ȡCantor����Խ���Ԫ����ŵ���
 * @param z int
 * @return
 */
int CantorL(int z) {
    return Sub(AssiCantorMin(z, 0), CantorR(z));
}


// ����
int main() {
    printf("1�� 3 + 4 ���ڣ�%d\n", Add(3, 4));
    printf("2�� 3 x 4 ���ڣ�%d\n", Mul(3, 4));
    printf("3�� 4 �Ľ׳˵��ڣ�%d\n", Fac(4));
    printf("4�� 2 �� 4 �η����ڣ�%d\n", Exp(2, 4));
    printf("5�� 2 �� ǰ�����ڣ�%d\n", P(2));
    printf("6�� 5 - 2 ���ڣ�%d\n", Sub(5, 2));
    printf("7�� |2 - 5| ���ڣ�%d\n", Abs(2, 5));
    printf("8�� 0 ȡ���������ڣ�%d��3 ȡ���������ڣ�%d\n", Alp(0), Alp(3));
    printf("9�� ��3 + 0��+��3 + 1��+��3 + 2��+��3 + 3��+��3 + 4�����ڣ�%d\n", Adds(Add, 3, 4));
    printf("10�� ��3 + 0��*��3 + 1��*��3 + 2��*��3 + 3��*��3 + 4�����ڣ�%d\n", Muls(Add, 3, 4));
    printf("11�� d(3, 3) ���ڣ�%d ,d(3, 5) ���ڣ�%d\n", D(3, 3), D(3, 5));
    printf("12�� 3 = 3 ���ڣ�%d ,3 = 5 ���ڣ�%d\n", Eq(3, 3), Eq(3, 5));
    printf("13�� 3 > 3 ���ڣ�%d ,5 > 3 ���ڣ�%d\n", Gt(3, 3), Gt(5, 3));
    printf("14�� 3 <= 3 ���ڣ�%d ,5 <= 3 ���ڣ�%d\n", Elt(3, 3), Elt(5, 3));
    printf("15�� �ж��Ƿ�������3|6 ���ڣ�%d ,4|6 ���ڣ�%d\n", IsDivide(6, 3), IsDivide(6, 4));
    printf("16�� 6/3 ���ڣ�%d ,7/3 ���ڣ�%d\n", Divide(6, 3), Divide(7, 3));
    printf("17�� �ж��Ƿ���������IsPrim(3) ���ڣ�%d ,IsPrim(9) ���ڣ�%d\n", IsPrim(3), IsPrim(9));
    printf("18�� �� 4 ���������ڣ�%d\n", Prim(4));
    printf("19�� 3 �� 7 ���������ڣ�%d\n", R(7, 3));
    printf("20�� 6 �������ӷֽ��з���ָ���������ڣ�%d\n", T(6));
    printf("21�� 18 �������ӷֽ��е� 2 ��������ָ�����ڣ�%d\n", PrimDecpExp(18, 2));
    printf("22�� 18 �������ӷֽ��з���ָ��������ŵ��ڣ�%d\n", PrimDecpLgIndex(18));
    printf("23�� GN(x)��ʾx�������ӷֽ���û����ָ������GN(6) ���ڣ�%d ,GN(9) ���ڣ�%d\n", PrimDecpGn(6), PrimDecpGn(9));

    int *gArr = RealNumToGodelArray(10);
    printf("24�� 10 �ĸ�¶������ڣ�[");
    for (int i = 1; i <= gArr[0]; ++i) {
        printf("%d", gArr[i]);
        if(i != gArr[0])
            printf(", ");
    }
    printf("]\n");

    printf("25�� 6 * 7(��¶���)���ڣ�%d\n", GodelMul(6, 7));
    printf("26�� 30 �������ӷֽ���ָ��Ϊ 1 �������Ӹ������ڣ�%d\n", PrimDecpExpCount(30, 1));
    printf("27�� Cantor�Խ������±�<3, 2>��Ԫ�ص���ŵ��ڣ�%d\n", CantorIndex(3, 2));
    printf("28�� Cantor�Խ��������Ϊ 17 ��Ԫ��С���Ҳ����ڣ�%d\n", CantorR(17));
    printf("29�� Cantor�Խ��������Ϊ 17 ��Ԫ��С���󲿵��ڣ�%d\n", CantorL(17));

    printf("\n\n\n�����������~\n\n");
    getch();
    return 0;
}