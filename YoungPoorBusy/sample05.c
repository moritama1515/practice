//列車データの処理
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAXCITY 100
#define MAXCONN 2000+1
#define INFINITE 9999999

char city_name[MAXCITY][18];
int ncity;
int nconn;
int from_hakodate[MAXCITY][MAXCONN],from_tokyo[MAXCITY][MAXCONN];

struct train{
  int from,to;
  int dpt,arv;
  int fare;
}trains[MAXCONN];

int city_id(char *name);
void parse_connection(char *baf);
int diff_time(int start_time,int end_time);
int cmp_arv(struct train *t1,struct train *t2);
void prepare_data(void);
int change(struct train tv[],int p,int st,int dpttime);
void make_table(int v[MAXCITY][MAXCONN],int org,struct train tv[]);



int main()
{
  int count;
  int i = 0;
  int j = 0;
  char buf[64];
  char max_fbuf[64];
  char max_lbuf[64];
  char search_from_name[64];
  char search_to_name[64];
  char search_train[64][MAXCONN];
  int max_fare,max_time;
  int from_num = -1;
  int to_num = -1;
      
  strcpy(search_from_name, "Hakodate");
  strcpy(search_to_name,"Morioka");
  from_num = city_id(search_from_name);
  to_num = city_id(search_to_name);       

  while(1){
    max_fare = 0;
    max_time = 0;
    i = 0;


    /*データセットの先頭（データ数）を読む*/
    if(fgets(buf,sizeof(buf),stdin) == NULL){
      break;
    }

    sscanf(buf,"%d",&count);//データセット中のデータ数
    printf("%d\n",count);
    
    if(count == 0){ /*データ全体の終了の判定*/
      break;
    }

    /*データセット（列車データ）を読み込む*/
    while(count-- > 0){
      if(fgets(buf,sizeof(buf),stdin) == NULL){
        break;
      }

 //     printf("%s",buf);
      parse_connection(buf);
      if(max_fare < trains[0].fare){
        max_fare = trains[0].fare;
        strcpy(max_fbuf,buf);
      } 
      if(max_time < diff_time(trains[0].dpt,trains[0].arv)){
        max_time = diff_time(trains[0].dpt,trains[0].arv);
        strcpy(max_lbuf,buf);
      }
      if(trains[0].from == from_num){
        if(trains[0].to == to_num){
          strcpy(&(search_train[i][0]),buf);
          i++;
        }
      }
    }
    /*最も金額が高い列車*/
    printf("%s",max_fbuf);
    /*最も時間がかかる列車*/
    printf("%s",max_lbuf);
    /*検索結果*/
    for(j = 0;j <= i;j++){
      printf("%s",&search_train[j][0]);
    }
  }
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


void parse_connection(char *buf)
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


int diff_time(int start_time,int end_time){
  int ans;
  ans = end_time - start_time;
  return ans;
}

int cmp_arv(struct train *t1,struct train *t2)
{
  return (t1->arv - t2->arv);
}

void prepare_data(void)
{
  qsort(trains,nconn,sizeof(struct train),cmp_arv);
}

int change(struct train tv[],int p,int st,int dpttime)
{
  while(p >= 0){
    if((tv[p].to == st) && (tv[p].arv <= dpttime))
      break;
    p--;
  }
  return p;
}

void make_table(int v[MAXCITY][MAXCONN],int org,struct train tv[])
{
  int ti;
  int i;
  int a;

  for(i = 0;i < ncity; i++){
    v[i][0] = INFINITE;
  }
  v[org][0] = 0;

  for(ti = 0; ti < nconn; ti++){
    for(i = 0; i < ncity; i++){
      v[i][ti+1] = v[i][ti];
    }
    a = change(tv,ti-1,tv[ti].from,tv[ti].dpt);
    v[tv[ti].to][ti+1] = fmin(v[tv[ti].to][ti],tv[ti].fare + v[tv[ti].from][a+1]);
  }
}
