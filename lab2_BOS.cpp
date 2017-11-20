/* заменяет  все  вхождения подстроки  в строку в строку
вводить имя программы  исходная_строка исходная_подстрока строка_замещения

пример ввода
./BOS  mybosmy my you
вывод
youbosyou


*/
#include <stdio.h>
#include<string.h>
void Replace(char str[],char a[],char b[],char buffer[])
{
    int i,j,pos=0;
    for(i=0;str[i];i++)
    {
        for(j=0;str[i+j]&&a[j];j++)   //начинается ли с i-ой позиции строка a
            if(str[i+j]!=a[j]) break;
        if(!a[j])  //если a[j]=0, то мы дошли до конца строки a
        {
            i+=j-1;  //в j у нас длина стоки a, которую мы перепрыгиваем
            for(j=0;b[j];j++) buffer[pos++]=b[j];  //на место стоки a ставим строку b
        }
        else
        {
            buffer[pos++]=str[i];   //просто копируем символ
        }
        buffer[pos]='\0';  //ставим конец строки
    }
    strcpy(str,buffer);  //копируем в первоначальную строку
}

int main(int argc, char* argv[])
{
    char* str= argv[1];
    char* a=argv[2];
    char*b=argv[3];
    char buffer[200];
    Replace(str,a,b,buffer);
    printf("%s",str);
    return 0;
}
