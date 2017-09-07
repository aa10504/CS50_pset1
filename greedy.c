#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float m; //宣告一個float來存錢的數目 (e.g. 1.95鎂)
    int t = 0; //宣告一個變數t來儲存硬幣數目
    do
    {
        printf("O hai! How much change is owed?\n");
        m = get_float();
    }
    while(m < 0); //若m<0,就再要求使用者輸入一次
    
    int rounded = m * 100 + 0.5; //創一個新的int變數rounded來存[(四捨五入到小數點下兩位的m)*100],加0.5就是要達成四捨五入的功用,簡單說就是將小數點下兩位的float(0.XX)轉為int來存
    
    while(rounded >= 25) //只要錢的數目比25多,每減一次25就將t+1,減到沒有25可以減為止
    {
        rounded -= 25;
        t++;
    }
    
    while(rounded >= 10) //到這裡錢的數目應該已經比25少了,只要錢的數目比10多,每減一次10就將t+1,減到沒有10可以減為止
    {
        rounded -= 10;
        t++;
    }
    
    while(rounded >= 5) //到這裡錢的數目應該已經比10少了,只要錢的數目比5多,每減一次5就將t+1,減到沒有5可以減為止
    {
        rounded -= 5;
        t++;
    }
    
    while(rounded >= 1) //到這裡錢的數目應該已經比5少了,只要錢的數目比1多,每減一次1就將t+1,減到沒有1可以減為止
    {
        rounded -= 1;
        t++;
    }
    
    printf("%i\n", t); //最後得到t就是硬幣數
}