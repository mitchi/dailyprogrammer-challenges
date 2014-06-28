#include <iostream>
#include <vector>
using namespace std;

//Next fastest after compile time regex
char table[256];
char example[] = "...You...!!!@!3124131212 Hello have this is a --- string Solved !!...? to test @\n\n\n#!#@#@%$**#$@ Congratz this!!!!!!!!!!!!!!!!one ---Problem\n\n";
char allow[] = "abcdefghijklmnopqrstuvwxiyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int check[] = {12,-1,1,-100,4,1000,9,-1000,16,13,17,15};

int main(void)
{
	//init the table at runtime
	char *p = allow; 
	while (*p != 0) 
		table[*p++] = *p;

	p = example;
	int len = 0;
	vector<char*> offsets;

	//parse the string, save the offsets
	while (1)
	{
		if (*p == 0) break;//eos
		if (table[*p] == 0) 
		{
			*p = 0;
			if (len>0) 
			{
				offsets.push_back( p - len);
				len = 0;
			}
			p++;
		}
		else {
			len++;
			p++;
		}
	}

	int len2 = sizeof(check) / 4;
	int size = offsets.size();

	for (int i = 0; i < len2; i++) {
		int offset = check[i];
		offset = offset-1; //indexes start at 1
		if (offset < size && !(offset < 0) ) puts ( offsets[offset]);
	}

	return 0;
}