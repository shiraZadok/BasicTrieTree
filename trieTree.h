#define NUM_LETTERS ((int)26)

typedef enum Boolean {True, False} Boolean;


typedef struct TrieNode{
    char letter;
    long unsigned int count;
    Boolean isLeaf;
    struct TrieNode *children[NUM_LETTERS];
} TrieNode;


TrieNode* createNode();
void insert(struct TrieNode **hRoot, char *word);
void printAllWords(TrieNode **root, char *wordArray, int pos);
void printAllWordsR(TrieNode **root, char *wordArray, int pos);
void freeTrie(TrieNode **root);
