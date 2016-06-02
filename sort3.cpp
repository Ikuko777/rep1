#include <stdio.h>
#include <vector>
#include<algorithm>
//#include <iostream>
using namespace std;

int hantei=0;
FILE *fp;

  


//ソート済みのvectorとその時の文字数を渡されたら、アナグラムがあれば出力
int anagram (vector<char> c,int j){
 
  //printf("きたよ");

  char a;
  vector<char> d,e;
  d.reserve(1000);
  e.reserve(1000);
  c.reserve(1000);
  int l,k,i;

  int test;
  /*
  for(i=0;i<10;i++){
    printf("%c",c[i]);
    }*/
  
  l=0;
  while((a=getc(fp)) != EOF){
    if(a!= '\n'){
      d[l]=a;
      l++;
    }else{
      l=l-1;
      //printf("%d\n",l);
      e.assign(&d[0],&d[l]);
      sort(&d[0],&d[l]);
      //printf("います");
      /*for(i=0;i<10;i++){
    printf("%c",d[i]);
    }*/
      if((j==l)&&(equal(&c[0],&c[j],&d[0]))){
	for(k=0;k<l;k++){
	  printf("%c",e[k]);
	printf("入ってる？");
	} 

	test = 1;
	hantei =1;
	return test;
	printf("終わるよ");
   
      }
      l=0;
    }
  }

  return 0;
}


int main(){
  int n=16;
  vector<char> c,d;
  c.reserve (1000);
  d.reserve (1000);
  char a;
  int i,j;
  
  //fp = fopen("/usr/share/dict/words","r");
  fp = fopen("sort2.txt","r");
  if(fp==NULL){
    printf("ファイル開けなかったよ；；\n");
    return 0;
  }
  

  
  printf("16文字入力してね♪：");
  for(i=0;i<n+1;i++){        
    scanf("%c",&a);
    if(a=='\n'){
      break;
    }
    else{
      c.push_back(a);
    }
  }
  sort(c.begin(),c.end());
  printf("並び替え：");
  for(i=0;i<c.size();i++){
    printf("%c",c[i]);
  }
  printf("\n");
 


  //anagram(c);
  printf("\n");



  for(j=0;j<c.size();j++){
    
  

  do {

    for ( int i=0; i<c.size()-j; i++ ) {
      // printf("%c ",c[i]);
      d[i]=c[i];
	}

    sort(&d[0],&d[c.size()]);

  for(i=0;i<c.size()+j;i++){
    printf("%c",c[i]);
  }
  printf("\n");


  //printf("%lu",c.size()-j-1);
  anagram(d,c.size()-j-1);

  // printf("a%d",anagram(d));
  // printf("b%d",hantei);
  if (anagram(d,c.size()-j)==1){
      printf("はい\n");
      return 0;
    }

  } while( next_permutation(c.begin(), c.end()) );


  }



}
