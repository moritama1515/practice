//データセットを意識して読み込む
#include<stdio.h>

int main()
{
  int count;
  char buf[64];

  while(1){
    /*データセットの先頭（データ数）を読む*/
    if(fgets(buf,sizeof(buf),stdin) == NULL){
      break;
    }

    sscanf(buf,"%d",&count);
    printf("%d\n",count);
    
    if(count == 0){ /*データ全体の終了の判定*/
      break;
    }

    /*データセット（列車データ）を読み込む*/
    while(count-->0){
      if(fgets(buf,sizeof(buf),stdin)==NULL){
        break;
      }
    }
  }
}
