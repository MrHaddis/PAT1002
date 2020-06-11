#include <stdio.h>
#include <string.h>
void getDat();


int main() {
    //定义一个数组 用来接收输入的值；
    char num[100];
    //定义一个二维数组，用来存储拼音
    //10行5列，其实4列应该也可以。
    //C语言的二维数组，每行不够时后面的空位会补位。
    //C语言的数组，如果不初始化，数组里面的值都是垃圾值，初始化一半的话，没有初始化的值，都为0
    char py[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    //定义一个数组用来存储求得的和的每一位。由于最大是100位，每位都是9,4位的长度足矣。
    int a[4];
    //输入数据
    scanf("%s", num);
    //定义一个total 去计算num每一位加起来的和
    int total = 0;
    //把total的每一位存起来，存的顺序是个十百千万
    int count = 0;
    //for循环去获取num的每一位
    for (int i = 0; i < strlen(num); ++i) {
        //把获取到的每一位num由char转为int值
        int a = num[i] - '0';
        //把每一位的int值相加
        total += a;
    }
    //循环计算
    while (total != 0) {
        // 获取total每一位的值，没循环一次 a的位置就多写一次
        //total % 10 就是依次计算各位十位百位等。
        a[count++] = total % 10;
        //取余以后要除以十，这样才可以依次取到每位的值。
        total /= 10;
    }
    //由于是顺序从个十百存的，取的时候要逆序。 例如 total是50，存的时候就是 a[0]=0,a[1]=5;
    //那读的时候如果正序读出来，就成了 ling wu. 正确的应该是 wu ling。
    //由于count 最后一次的时候会+1，所以这里取最后一位的时候要-1，不然会下标越界。
    for (int i = count - 1; i >= 0; i--) {
        //打印出答案即可
        printf("%s", py[a[i]]);
        //如果不是最后一位，则在后面加空格
        if (i != 0)
            printf(" ");
        //如果是最后一位，即认为是输出完成，则换行。
        else
            printf("\n");
    }
    getDat();
    return 0;
}


void getDat() {

}
