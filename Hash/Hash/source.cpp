#include <cstdio>
#include <map>
#include <algorithm>
#include "Windows.h"
using namespace std;

map<char*, int> stl_hash;

char input[30000][100];
int cmd[30000][2];

int my_find[30000], stl_find[30000];

const int REMOVE = 1;
const int FIND = 2;

const int PN = 23;
const int HASH_SIZE = 10000;

int name_size;
char name[30000][100];
int table[HASH_SIZE][30];

unsigned int get_key(char _name[])
{
	unsigned int key = 0, p = 1;
	for (int i = 0; _name[i] != 0; ++i)
	{
		key += (_name[i] * p);
		p *= PN;
	}
	return (key % HASH_SIZE);
}

int my_strcmp(char a[], char b[])
{
	int i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			break;
		++i;
	}
	return (a[i] - b[i]);
}
int contain(char _name[])
{
	unsigned int key = get_key(_name);
	int h_size = table[key][0];
	for (int i = 1; i <= h_size; ++i)
	{
		int n_pos = table[key][i];
		if (my_strcmp(name[n_pos], _name) == 0)
		{
			return n_pos;
		}
	}
	return -1;
}
void add(char _name[])
{
	int len;
	for (len = 0; _name[len] != 0; ++len)
	{
		name[name_size][len] = _name[len];
	}
	name[name_size][len] = 0;

	unsigned int key = get_key(_name);
	int& h_size = table[key][0];
	table[key][++h_size] = name_size;
	++name_size;
}

bool remove(char _name[])
{
	unsigned int key = get_key(_name);
	int& h_size = table[key][0];
	for (int i = 1; i <= h_size; ++i)
	{
		int n_pos = table[key][i];
		if (my_strcmp(name[n_pos], _name) == 0)
		{
			for (int j = i + 1; j <= h_size; ++j)
			{
				table[key][j - 1] = table[key][j];
			}
			--h_size;
			return true;
		}
	}
	return false;
}

int main()
{

	return 0;
}