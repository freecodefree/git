struct READ_LINES{
        char **lineptr;
        int maxLines;
        char *buffer;
        char **current;
        int maxSpace;
};
struct ALLOC{
        char *buffer;
        char **current;
        int len;
        int maxSpace;
        char **newSpace;
};//readLines.c
struct SORT{
	int start;
	int end;
	int isDecrease;
	int (*compare)(void *,void *);
	int isFold;
	int isNum;
	int isDirector;
	char **lineptr;
};
int sort(struct SORT);
int alloc(struct ALLOC);//readLines.c
int readLines(struct READ_LINES);
void push(double f);//stack.c
double pop(void);//stack.c
int printStack(void);//stack.c
int duplicateStack(double *);//stack.c
int swapTop2(void);//stack.c
void clearStack(void);//stack.c
int calc(int argc,char *argv[]);
int getop(char *op,int argc,char *argv[]);
float ftoc(float fah);//tempc.c
float ctof(float cel);//tempc.c
void ltempc(void);//tempc.c
void ltempf(void);//tempc.c
int getline1(char *line,int maxline);//getline.c
void copyline(char to[],char from[]);//getline.c
int removeBT(char *line);//reverse.c
//int reverse(char *line);//reverse.c
int detab(char *line);
int entab(char *line);//detab.c
int foldline(char *line);
int removecom(char *line,int s);
int recom(void);//removecom.c
long htoi(char *);
void squeezec(char *,int);//squeeze.c Remove a character from a string
void squeeze(char *,char *);//remove characters from the first string
//whitch matches any character in the second one
char *any(char *s1,char *s2);//return the first location in a string
//s1 where any characters from the string s2 occurs
int setbits(int *x,int p,int n,int y);//
//changes *x with the n bits that begin at position p set to the
//rightmost n bits of y
int invert(int *x,int p,int n);//setbits.c
//inverts the n bits of *x that begin at position p
int rightrot(unsigned int *x,int n);//setbits.c
//rotate integer *x to the right by n positions
int countbits(int x);//setbits.c
//counts the number of 1-bits in x
int lower(char *c);
int escape(char *s,char *t);
int unescape(char *s,char *t);//escape.c
int atoi(char *);
int itoa(int n,char *s,int w);
int reverse(char *begin,char *end);//itoa.c
int reverse1(char *s);//itoa.c
int expand1(char *s1,char *s2);//expand s1 to s2
int itob(int n,char *s,int b);
double atof(char *s);
int getUnitFromLineOriginal(char **from,char *to,char *separator);
//getUnitFromLine.c
int getUnitFromLine(char **from,char *to);//separators are:" \t,\n"
int isdigits(char *s);
#define MAXLINE 1000
#define TAB 8
