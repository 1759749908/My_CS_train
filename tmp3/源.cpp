#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct binary_tree {
	char* name;
	struct binary_tree* Next_1;
	struct binary_tree* Next_2;
};

struct binary_tree root;

struct binary_tree* find_tree_2(struct binary_tree* node, char* s) {
	if (!(strcmp(node->name, s))) {
		return node;
	}
	struct binary_tree* ans;
	if (node->Next_1 == NULL && node->Next_2 == NULL) {
		return NULL;
	}
	else {
		if (node->Next_1 != NULL) {
			ans = find_tree_2(node->Next_1, s);
			if (ans != NULL) {
				return ans;
			}
		}
		if (node->Next_2 != NULL) {
			ans = find_tree_2(node->Next_2, s);
			if (ans != NULL) {
				return ans;
			}
		}
	}
	return NULL;
}

struct binary_tree* find_tree(char* s) {
	return find_tree_2(&root, s);
}

void push_tree(char* s1, char* s2) {
	if (!(strcmp(s2, "~~~"))) {
		root.name = (char*)malloc(strlen(s2));
		strcpy(root.name, s2);
		if (root.Next_1 == NULL) {
			root.Next_1 = (struct binary_tree*)malloc(sizeof(struct binary_tree));
			root.Next_1->name = (char*)malloc(strlen(s1));
			strcpy(root.Next_1->name, s1);
			root.Next_1->Next_1 = NULL;
			root.Next_1->Next_2 = NULL;

		}
		else {
			root.Next_2 = (struct binary_tree*)malloc(sizeof(struct binary_tree));
			root.Next_2->name = (char*)malloc(strlen(s1));
			strcpy(root.Next_2->name, s1);
			root.Next_2->Next_1 = NULL;
			root.Next_2->Next_2 = NULL;
		}
	}
	else {
		struct binary_tree* tmp = find_tree(s2);
		if (tmp->Next_1 == NULL) {
			tmp->Next_1 = (struct binary_tree*)malloc(sizeof(struct binary_tree));
			tmp->Next_1->name = (char*)malloc(strlen(s1));
			strcpy(tmp->Next_1->name, s1);
			tmp->Next_1->Next_1 = NULL;
			tmp->Next_1->Next_2 = NULL;

		}
		else {
			tmp->Next_2 = (struct binary_tree*)malloc(sizeof(struct binary_tree));
			tmp->Next_2->name = (char*)malloc(strlen(s1));
			strcpy(tmp->Next_2->name, s1);
			tmp->Next_2->Next_1 = NULL;
			tmp->Next_2->Next_2 = NULL;
		}
	}
}

int	query_tree_2(struct binary_tree* node) {
	int sum = 1;

	if (node->Next_1 != NULL) {
		sum += query_tree_2(node->Next_1);
	}

	if (node->Next_2 != NULL) {
		sum += query_tree_2(node->Next_2);
	}
	return sum;
}

int	query_tree(char* s) {
	return query_tree_2(find_tree(s));
}

void remove_tree(char* s) {
	struct binary_tree* tmp = find_tree(s);
	free(tmp->Next_1);
	free(tmp->Next_2);
	tmp->Next_1 = NULL;
	tmp->Next_2 = NULL;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);

	char str1[100];
	char str2[100];

	memset(str1, 0, 100);
	memset(str2, 0, 100);

	for (int i = 0; i < n; i++) {
		memset(str1, 0, 100);
		memset(str2, 0, 100);
		scanf("%s %s", str1, str2);
		push_tree(str1, str2);
	}

	for (int i = 0; i < q; i++) {
		memset(str1, 0, 100);
		memset(str2, 0, 100);
		scanf("%s %s", str1, str2);
		if (!(strcmp(str1, "query"))) {
			printf("%d\n", query_tree(str2));
		}
		else if (!(strcmp(str1, "remove"))) {
			//remove
			remove_tree(str2);
		}
	}
}