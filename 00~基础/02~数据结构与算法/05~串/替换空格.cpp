// 网络编程中，URL参数含有特殊字符会导致服务器无法获取正确的参数值
// 需要将特殊符号转换为服务器可以识别的字符
// 如空格十六进制是0x20，被替换为%20
// 如#十六进制是0x23，被替换为%23

/*
方法选择：
1. 将1个字符替换为3个字符，空格后面的字符后移两个字节。对于每个空格字符，需要移动O(n)
个字符，对于O(n)个字符时间效率是O(n^2)

2. 换一种思路，从后向替换，改为前向替换。
  * 先遍历一遍字符串，找到空格个数，计算出字符串替换后的长度
  * p1指向原来字符串末尾，p2指向新字符串末尾
  * 将不是空格的移动到p2位置， p1--, p2--,如果是空格，则替换为%20，直到p1到达头部
  * 所有元素只移动一遍，所以时间效率为O(n)
*/

#include <cstdio>
#include <cstring>

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
    if (str == nullptr && length <= 0)
        return;

    /*originalLength 为字符串str的实际长度*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        ++originalLength;

        if (str[i] == ' ')
            ++numberOfBlank;

        ++i;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (str[indexOfOriginal] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOriginal];
        }

        --indexOfOriginal;
    }
}

// ====================测试代码====================
void Test(char *testName, char str[], int length, char expected[])
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if (expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if (expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if (strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}