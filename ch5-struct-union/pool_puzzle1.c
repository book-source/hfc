#include<stdio.h>

struct fish {
	const char *name;
	const char *species;
	int teeth;
	int age;
};


void catalog(struct fish f)
{
	printf("%s is a %s with %i teeth. He is %i\n",
		f.name, f.species, f.teeth, f.age);
}

int main()
{
	struct fish snappy = {"Snappy", "Piranha", 69, 4};
	printf("%d\n", snappy);
	printf("%d\n", &snappy);
	printf("sizeof fish is:%d\n", sizeof(struct fish));
	printf("sizeof int is:%d\n", sizeof(int));
	printf("sizeof char* is:%d\n", sizeof(char*));
	catalog(snappy);
	return 0;
}
