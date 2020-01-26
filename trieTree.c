#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#include "trieTree.h"

//create new node in the trie tree
 TrieNode* createNode(){
  TrieNode *pNode = NULL;
  pNode = (TrieNode *)malloc(sizeof(TrieNode));
  if(pNode){
  pNode->count = 0;
  pNode->isLeaf=False;
  for (int i = 0; i < NUM_LETTERS; i++){
        pNode->children[i] = NULL;
      }
  }
  return pNode;
}

//insert only lowercase letters to the trie tree
void insert(TrieNode **hRoot, char *word){
    int lengthW = (int)strlen(word);
    TrieNode *runner = *hRoot;
    for (int i = 0; i < lengthW; i++)
    {
      char c=word[i];
      if(c>=65 && c<=90){
            c = c+32;
        }
        if(c>=97 && c<=122 && c!=' ' && c!= '\n' && c!='\0' && c!='\t' && c!=','){
        int index = (int) c -(int)'a';
        if (!runner->children[index]){
            runner->children[index] = createNode();
          }
        runner = runner->children[index];
        runner->letter=c;
       }
     }
  runner->isLeaf = True;
  runner->count++;
}


// Print all words in Trie
void printAllWords(TrieNode **root, char *wordArray, int pos){
  TrieNode *pCrawl = (*root);

   if(pCrawl == NULL)
      return;

   if((pCrawl->isLeaf)==0){
     wordArray[pos] = '\0';
     printf("%s\t%ld\n", wordArray, pCrawl->count);
   }

   for(int i=0; i < NUM_LETTERS; i++){
      if(pCrawl->children[i] != NULL){
         wordArray[pos] = pCrawl->children[i]->letter;
         printAllWords(&(pCrawl->children[i]), wordArray, pos+1);
      }
   }
 }

   // Print all words in Trie in revers
   void printAllWordsR(TrieNode **root, char *wordArray, int pos){
     TrieNode *pCrawl = (*root);

      if(pCrawl == NULL)
         return;

      if((pCrawl->isLeaf)==0){
        wordArray[pos] = '\0';
        printf("%s\t%ld\n", wordArray, pCrawl->count);
      }

      for(int i=NUM_LETTERS-1; i >= 0; i--){
         if(pCrawl->children[i] != NULL){
            wordArray[pos] = pCrawl->children[i]->letter;
            printAllWordsR(&(pCrawl->children[i]), wordArray, pos+1);
         }
      }
  }


//free the memory of the Trie tree.
void freeTrie(TrieNode **root){
  TrieNode *runner = *root;
  if(runner == NULL) return;
  for(int i=0; i< NUM_LETTERS; i++){
    if (runner->children[i] != NULL){
      freeTrie(&(runner->children[i]));
    }
  }
  free(runner);
}
