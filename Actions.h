#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

int todigit(char str[100]);
int power(int m,int k);
char lowerUpper(char s);
void cellWithFlag(int m,int n,char a[m][n],char b[m][n],int i,int j,int* p,int* mov,double t,int mines, int raw[],int col[],int* flags,int* quest);
void cellUnopened(int m,int n,char a[m][n],char b[m][n],int i,int j,int* p,int* mov,double t,int mines,int raw[],int col[],int *flags,int* quest);
void cellWithQuestion(int m,int n,char a[m][n],char b[m][n],int i,int j,int* p,int* mov,double t,int mines, int raw[],int col[],int* flags,int* quest);
void operations(int m,int n,char a[m][n],char b[m][n],int *p,int* mov,double t,int mines ,int raw[], int col[], int *flags,int* quest);

#endif // ACTIONS_H_INCLUDED
