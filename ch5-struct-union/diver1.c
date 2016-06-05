#include <stdio.h>

typedef struct {
// if add private , the program will error
//private:
//public:
	float tank_capacity;
	int tank_psi;
	const char *suit_material;
} equipment;

typedef struct {
	const char *name;
	equipment kit;
} diver;

void badge(diver d)
{
	printf("in the function the int value of d is :%d\n", d);
	d.name = "ss";
	d.kit.suit_material = "helo";
	printf("Name: %s Tank: %2.2f(%i) Suit: %s\n",
		d.name, d.kit.tank_capacity, d.kit.tank_psi, d.kit.suit_material);
}

int main()
{
	diver randy = {"Randy", {5.5, 3500, "Neoprene"}};
	printf("after define, the int value of randy is: %d\n", randy);
	badge(randy);
	return 0;
}
