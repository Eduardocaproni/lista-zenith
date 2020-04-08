#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
 char *frase;
 int i,w=0,j=0,numpalavras,maiortamanho=0,menortamanho=100,l=0,m=0;
 char **palavras;
 palavras=(char **)malloc(10*sizeof(char *));
 for(i=0;i<10;i++){
    palavras[i]=(char *)malloc(10*sizeof(char));
 }

 frase=malloc(60*sizeof(char));
 scanf("%[^\n]",frase);
 for(i=0;i<60;i++){
    if(frase[i]=='\0')
        for(i=i;i<60;i++)
            frase[i]='\0';
 }
 for(i=0;i<60;i++){
    if(frase[i]!=' '){
        palavras[w][j]=frase[i];
        j++;
        }
    else{
    palavras[w][j]='\0';
    w++;
    j=0;
    }

 }
 numpalavras=w+1;
for(i=0;i<numpalavras;i++){
    if(maiortamanho<strlen(palavras[i]))
       maiortamanho=strlen(palavras[i]);
    if(menortamanho>strlen(palavras[i]))
        menortamanho=strlen(palavras[i]);
}
for(i=0;i<numpalavras;i++){
    if(menortamanho==strlen(palavras[i])){
        if(l!=0)
            printf(" ");
        printf("%s",palavras[i]);
    l=1;
    }
}
printf("\n");
for(i=0;i<numpalavras;i++){
    if(maiortamanho==strlen(palavras[i])){
        if(m!=0)
            printf(" ");
        printf("%s",palavras[i]);
    m=1;
    }
}
    return 0;
}