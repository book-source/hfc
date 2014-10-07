
FILE *in = fopen("iam_not_exist.txt", "r");


//can to write to:

FILE * in;
if (!(in = fopen("iam_not_exist.txt", "r"))) {
	fprintf(stderr, "can not open file.\n");
	return 1;
}
