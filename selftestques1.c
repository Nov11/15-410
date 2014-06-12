#include <stdio.h>
struct s1{
	char a[3];
	union u1* b;
	int c;
};
struct s2{
	struct s1 d;
	struct s1* e;
	struct s2* f;
	double g;
	int h[4];
};
union u1{
	int i;
	struct s2 j;
	struct s1* k;
};
struct s6
{
char a[8];
};

struct s7
{
double d;
};

struct s8
{
	struct s1 s;
	char a;
};

struct s9
{
	struct s2 s;
	char a;
};

struct s10
{
	struct s6 ab;
	char a;
};
struct s11
{
	struct s7 ab;
	char a;
};
int main()
{
	printf("s1: %lu s2: %lu u1: %lu\n", sizeof(struct s1)/*4+ 4+ 4 on 32 bit*/, sizeof(struct s2)/* 12 + 4 + 4 + 8 + 4 * 4 */,
									sizeof(union u1)/* biggest is s2 */);
	printf("sizeof(int) : %lu\n", sizeof(int));
	printf("sizeof(union u1*): %lu\n", sizeof(union u1*));
	printf("sizeof(int*): %lu\n", sizeof(int*));
	printf("sizeof(double): %lu\n", sizeof(double));
	printf("sizeof(s6): %lu sizeof(s7): %lu sizeof(s8): %lu sizeof(s9): %lu\n", 
			sizeof(struct s6), sizeof(struct s7), sizeof(struct s8), sizeof(struct s9));
	printf("sizeof(s10): %lu sizeof(s11): %lu\n", sizeof(struct s10), sizeof(struct s11));
	return 0;
}
/*in this machine one pointer is 8 bytes, int is 4 byte*/
/*s1: char a[3]; will align to 8 bytes, cause the biggest element in the struct is union u1*, which is 8 bytes*/
/*sizeof s1 is : 3->align to 8 + 8 + 4->aligned to 8 that is 8 + 8 + 8 = 24*/
/*s2 the biggest one is 8 double is 8 as well as a pointer in both s2 and s1 . so s2 is aligned to 8*/
/*s2: s1->24bytes aligned to 8 two pointers and one double aligned to 8 and two int aligned to 8 so int[]is 16*/
/*sum those up: 24 + 8 + 8 + 8 + 16 = 64*/
/*as with u1 the biggets is s2 and all the elements in u1 is aligned to 8 which is the case with s2 so sizeof u1 is 64*/
/*s6 and s7 is 8 with no surprise s8 is 24 + (1 which aligned to 8) = 32 s9 is 64 + (1 alignd to 8)*/
/* s10 is aligned to 1 cause char inside it and struct s6 is aligned to 1 as well*/
/* s11 is aligned to 8 cause s7 is aligned to 8 and char to 1 so take the bigger on s11 is aligned to 8 that result to 16 bytes*/
/*Aproc1: return x->g;
	movl 8(%ebp), %eax #ebp is saved ebp  ebp + 4 (32bit machine)is return addr ebp + 8 is the parameter push in stack
	which is struct s1* , the addr of a struct typed struct s1
	movl 4(%eax), %eax #here 4(%eax) is the 4th byte in struct s1 which is union u1* b
	movl 40(%eax), %eax #the 40th byte in union u1 is 40th byte in struct s2, so that is the start addr of g 
	and %eax store the return value
*/
/*Bprco2:same as above this is x->f;*/
/*Cprct3:x->i*/