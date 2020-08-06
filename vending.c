#include <stdio.h>
#include <stdlib.h>

typedef struct obj
{
    char name[30];
    int price;
    int count;
} onj_l;

typedef struct monlist
{
    int coin;
    int count;
} monlist_l;

int main()
{
    int i, size, sum = 0, count, summon = 0, change = 0;
    char ans;
    struct obj list[] = {
        {"ザク", 540, 0},
        {"グフ", 670, 0},
        {"ドム", 720, 0},
        {"ジオング", 1000, 0}};

    struct monlist money[] = {
        {10000, 0},
        {5000, 0},
        {1000, 0},
        {500, 0},
        {100, 0},
        {50, 0},
        {10, 0},
        {5, 0},
        {1, 0}};

    size = sizeof(list) / sizeof(struct obj);
    for (i = 0; i < size; i++)
    {
        printf("商品%d、%s%d\n", i + 1, list[i].name, list[i].price);
    }
    do
    {
        printf("商品を番号で選んでください。\n");
        scanf("%d", &count);
        printf("個数は？\n");
        scanf("%d", &list[count].count);
        printf("まだ購入しますか？(y or n)\n");
        scanf("%s", &ans);
    } while (ans == 'y');
    for (i = 0; i < size; i++)
    {
        sum += list[i].price * list[i].count;
    }
    printf("商品代金は%d円です\n", sum);
    printf("投入金額(それぞれの投入枚数を入力してください)。\n");
    do
    {
        size = sizeof(money) / sizeof(struct monlist);
        for (i = 0; i < size; i++)
        {
            printf("%d円:\t", money[i].coin);
            scanf("%d", &money[i].count);
            summon += money[i].coin * money[i].count;
        }
        change = summon - sum;
        if (change < 0)
        {
            printf("%d円足りないよ！\n", change);
            summon = 0;
        }
    } while (change < 0);

    printf("投入金額%d円-商品代金%d円＝%d円\n", summon, sum, change);

    printf("お釣りです\n");
    for (i = 0; i < size; i++)
    {
        if (change / money[i].coin >= 1)
        {
            count = change / money[i].coin;
            change -= (change / money[i].coin) * money[i].coin;
            printf("%d円\t%d枚\n", money[i].coin, count);
        }
    }

    return 0;
}