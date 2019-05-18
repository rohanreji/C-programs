#include<stdio.h>
#include<stdarg.h>

void myprint(char *form,...){
        va_list list;
        va_start(list, form);
        vfprintf(stdout,form,list);
        va_end(list);
}
int main() {
        int a=10;
        char name[5]="rohan";
        myprint("%d %s \n",a,name);
        return 0;
}
