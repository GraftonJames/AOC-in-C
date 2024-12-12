#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000

struct pairs {
	int left[SIZE];
	int right[SIZE];
};

void push_c(struct pairs pairs, int i, int acc, char c, int side);  
void get_next_pair(struct pairs pairs, FILE* fp); 

void main(int argc, char **args) {

	const char* fname = "/home/james/proj/AOC-in-C/1/input";
	FILE* fp = fopen(fname, "r");

	struct pairs pairs = {0};

	get_next_pair(pairs, fp);

}

void get_next_pair(struct pairs pairs, FILE* fp) {

	int i = 0;
	int side = 0;
	int acc = 0;
	int left, right;
	char c;

	while ((c = fgetc(fp)) != EOF) {
		if (c == ' ' | c == '\n') {
			if (acc == 0) {}
			else if (side == 0) {
				pairs.left[i] = acc;
				acc = 0;
				side = 1;
			} else {
				pairs.right[i] = acc;
				acc = 0;
				side = 0;
				i++;
			}
		} else {
			if (c >= '0' && c <= '9') acc = (10*acc) + c - '0';
		}
	}

	i = 0;

	bool sorted = false;
	int swap = 0;

	while (!sorted) {
		i = 0;
		sorted = true;
		while (pairs.left[i+1] != 0) {
			if (pairs.left[i] > pairs.left[i+1]) {
				swap = pairs.left[i];
				pairs.left[i] = pairs.left[i+1];
				pairs.left[i+1] = swap;
				sorted = false;
			}
			i++;
		}
	}
	
	sorted = false;
	while (!sorted) {
		i = 0;
		sorted = true;
		while (pairs.right[i+1] != 0) {
			if (pairs.right[i] > pairs.right[i+1]) {
				swap = pairs.right[i];
				pairs.right[i] = pairs.right[i+1];
				pairs.right[i+1] = swap;
				sorted = false;
			}
			i++;
		}
	}

	i = 0;
	int j = 0;
	int count = 0;
	acc = 0;
	int next = 0;
	while (pairs.left[i] != 0) {
		
		next = pairs.left[i];

		while (pairs.left[i] == next) i++; 

		while (pairs.right[j] < next) j++;

		count = 0;
		while (pairs.right[j] == next) {
			j++;
			count++;
		}

		acc += count * next;
	}

	printf("ans: %d", acc);
}

void push_c(struct pairs pairs, int i, int acc, char c, int side)  {
}


