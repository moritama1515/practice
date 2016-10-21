//各行ごとに読み込んで，そのまま出力する
#include<stdio.h>

int main()
{
  char buf[64];

  while(fgets(buf,sizeof(buf),stdin) != NULL){
      fputs(buf,stdout);
  }
}
