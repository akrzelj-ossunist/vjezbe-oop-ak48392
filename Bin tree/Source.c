#include "header.h"

BSTree NewBSTree()
{
	return NULL;
}

void AddNode(BSTree* bst, char* word)
{
	if ((*bst) == NULL) {
		BSTree novi = (BSTree)malloc(sizeof(Node));
		novi->word = (char*)malloc(sizeof(char) * strlen(word) + 1);
		novi->word = word;
		novi->left = novi->right = NULL;
		*bst = novi;
		return;
	}
	if (strcmp((*bst)->word, word) == 0)
		return;
	if (strcmp((*bst)->word, word) > 0)
		AddNode(&(*bst)->left, word);
	if (strcmp((*bst)->word, word) < 0)
		AddNode(&(*bst)->right, word);
}

int BSTHeight(BSTree bst)
{
	if (bst == NULL)
		return 0;
	int l = BSTHeight(bst->left);
	int r = BSTHeight(bst->right);
	return (l > r) ? l + 1 : r + 1;
}


void PrintBSTree(BSTree bst)
{
	if (bst->left)
		PrintBSTree(bst->left);

	printf("%s\n", bst->word);

	if (bst->right)
		PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE* fd)
{
	if (bst == NULL)
		return;
	fwrite(bst->word, sizeof(char) * strlen(bst->word) + 1, 1, fd);
	fwrite(" ", 1, 1, fd);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	if (bst == NULL)
		return;
	if (bst->left == NULL && bst->right == NULL) {
		free(bst->word);
		free(bst);
		bst = NULL;
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
}

BSTree LoadBSTree(FILE* fd)
{
	BSTree bst;
	bst = NewBSTree();
	char buffer[1024];
	while (fscanf(fd, " %s", buffer) != EOF) {
		AddNode(&bst, _strdup(buffer));
	}
	return bst;
}
