//列車データの処理
#include<stdio.h>
#include<string.h>

#define MAXCITY 100

char city_name[MAXCITY][18];
int ncity;
int nconn;

#define MAXCONN 2000+1

struct train{
  int from,to;
  int dpt,arv;
  int fare;
}trains[MAXCONN];

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

parse_connection(char *buf)
{
  char from[18],to[18];
  int dpt[2],arv[2],fare;

  sscanf(buf,"%s %d:%d %s %d:%d %d",
      from,&(dpt[0]),&(dpt[1]),to,&(arv[0]),&(arv[1]),&fare);

  trains[nconn].from = city_id(from);
  trains[nconn].to = city_id(to);
  trains[nconn].dpt = dpt[0]*60+dpt[1];
  trains[nconn].arv = arv[0]*60+arv[1];
  trains[nconn].fare = fare;
}

int city_id(char *name)
{
  int i;

  for(i = 0;i < ncity; i++){
    if(strcmp(name,&(city_name[i][0])) == 0){
      return i;
    }
  }

  strcpy(&(city_name[ncity][0]),name);
  return ncity++;
}

int diff_time(int start_time,int end_time){
  int ans;
  ans = end_time - start_time;
  return ans;
}

