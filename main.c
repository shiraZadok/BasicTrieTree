#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "trieTree.h"

#define ADD_SIZE 30

int main(int argc,char* argv[]){
  TrieNode *root = createNode();
  char *word = (char*)malloc(sizeof(char)*256);
  int sizeOfWord=256;
  char *help=NULL;
  int counter=0;

  char c=getchar();
  if(c==EOF){
    printf("There is no file enter. please try insert again");
    return 1;
  }

  do{ //cheack if there is more file to read.
  if(counter==sizeOfWord){ //if the word is lonnger then 256 char.

     help=(char*)realloc(word,(sizeOfWord+ADD_SIZE)*sizeof(char));
     sizeOfWord+=ADD_SIZE;
     if(help==NULL&& word!=NULL){ //cheack if the realloc done.
        free(word);
        printf("ERR: There is not enough space on the computer");
        freeTrie(&root);
        return 1;
    }
      word=(char*)calloc(sizeOfWord,sizeof(char));
      strcpy(word,help);
      free(help);
}

    word[counter]=c;
    counter++;

if((c==' ' || c=='\n' || c=='\t' || c=='\0') || c==EOF){
    word[counter]='\0';
    if(word[0]!=' ' && counter>=1){
       insert(&root,word);
    }
    counter=0;
}
 c=getchar();

} while(c!=EOF);


   if(argc==2 && strcmp(argv[1],"r")==0){
     printAllWordsR(&root,word,0);

   }
   else{
     printAllWords(&root,word,0);

   }

   free(word);
   freeTrie(&root);

   return 0;
}
