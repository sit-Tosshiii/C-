#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void timer_start(void);
double timer_time(void);

clock_t st;

int main(void){
    
    double i;
    int count=0;
    char gar[100];
    int index,moji,set,SET,fake;
    
    srand(time(NULL));
    
    while(1){
        /*fakeの処理時間*/
        puts("\nProcessing...\nPlease wait a moment.");
        fake=rand()%(6-3)+3;
        timer_start();
        while(1){
            if(timer_time()>=(double)fake)
                break;
        }
        puts("");
        /*fakeの処理時間*/
        puts("COUNT : NUMBER : ______");
        SET=rand()%(30-10)+10;//１セットのれ行数決定
        for(i=0;i<=SET;i++){
            timer_start();
            while(1){
                if(timer_time()>=0.75)//数値が表示時間の間隔
                    break;
            }/*ここから表示*/
            index=rand()%100000;//表示数字の最大数字
            set=rand()%100;//文字一行の文字数
            count++;
            printf("%5d : %6d : " ,count,index);//回数、数列表示
            //文字列生成出力ループ
            for(;set>0;set--){
                moji=rand()%(122-58)+58;//大文字小文字とその前後のここ記号生成
                printf("%c",moji);
            }
            /*行の最後の列に???を入れてそれっぽくする*/
            if(i==SET)
                printf("???");
            puts("");
            /*行の最後の列に???を入れてそれっぽくする*/
            /*ここまで表示*/
        }
        /*fakeの入力　面倒な方はコメントアウト*/
        printf("=> ");
        scanf("%s",gar);
        /*fakeの入力*/
    }
    return 0;
}

void timer_start(void){
    st=clock();
}

double timer_time(void){
    return (double)(clock()-st)/CLOCKS_PER_SEC;
}
