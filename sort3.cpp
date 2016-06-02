#include <stdio.h>
#include <vector>
#include<algorithm>
//#include <iostream>
using namespace std;

int hantei=0;
FILE *fp;

//ソート済みのvectorとその時の文字数を渡されたら、アナグラムがあれば出力
int anagram (vector<char> &c,int j){
 
  //printf("きたよ\n");

  char a;
  vector<char> d,e;
  d.reserve(1000);
  e.reserve(1000);
  c.reserve(1000);
  int l,k,i;

  l=0;

  rewind(fp);
  //fseek(fp,0,SEEK_SET);

  if((a=getc(fp)) == EOF){printf("ファイルを開けません；；\n");}
  
  while((a=getc(fp)) != EOF){
    if(a != '\n'){
      d[l]=a;
      l++;
    }else{
      l=l-1;
      
      e.assign(&d[0],&d[l+1]);
      sort(&d[0],&d[l+1]);
   
      if((j==l)&&(equal(&c[0],&c[l+1],&d[0]))){ 
	for(k=0;k<l+1;k++){
	  printf("%c",e[k]);
	} 
	hantei =1;
	return 1;	
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
  
  fp = fopen("/usr/share/dict/words","r");
  //fp = fopen("sort2.txt","r");
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
  
  
  
  for(j=0;j<c.size();j++){
    printf("削除する文字数：%d\n",j);
    

    do {
      
      for ( int i=0; i<c.size()-j; i++ ) {
	
	d[i]=c[i];
      }
      
      sort(&d[0],&d[c.size()]);
      
      anagram(d,c.size()-j-1);
      
      
      
      if(hantei==1){printf("\n");return 0;}
    } while( next_permutation(c.begin(), c.end()) );
    
    
  }
  


}
