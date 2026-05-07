#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(TrieNode* root, const char* key) {
    TrieNode* current = root;

    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';

        if (!current->children[index])
            current->children[index] = createNode();

        current = current->children[index];
    }

    current->isEndOfWord = 1;
}

int search(TrieNode* root, const char* key) {
    TrieNode* current = root;

    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';

        if (!current->children[index])
            return 0;

        current = current->children[index];
    }

    return current != NULL && current->isEndOfWord;
}

int main() {
    TrieNode* root = createNode();

    insert(root, "elma");
    insert(root, "armut");

    printf("elma: %d\n", search(root, "elma"));
    printf("kiraz: %d\n", search(root, "kiraz"));

    return 0;
}
