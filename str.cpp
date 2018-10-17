#include <stdio.h>
#include <stdlib.h>
int strlen(char* a);
char* strcpy(char* a,char* b);
char* strcat(char* a,char* b);
int strcmp(char* a,char* b);
int main(){
	int menu;
	do{
		char stra[100],strb[100];
		puts("informe sua opcao para operacao com strings:\n1:tamanho da string\n2:copia de uma string para outra\n3:cocatenacao\n4:comparacao(ver se e igual)\n5:sair");
		scanf("%d",&menu);
		if(menu<1||menu>5){
			puts("opcao invalida");
		}
		switch(menu){
			case 1:
				puts("informe a string:");
				scanf("%s",stra);
				printf("o tamanho da string e de %d caracteres\n",strlen(stra));
				break;
			case 2:
				puts("informe as strings:");
				scanf("%s%s",stra,strb);
				printf("a string %s foi copiada com sucesso(ambas as strings estao com o mesmo conteudo)",strcpy(stra,strb));
				break;
			case 3:	
				puts("informe as strings:");
				scanf("%s%s",stra,strb);
				printf("string cocatenada:%s\n",strcat(stra,strb));
				break;
			case 4:
				puts("informe as strings:");
				scanf("%s%s",stra,strb);
				if(strcmp(stra,strb)==0){
					puts("as strings sao iguais");
				}
				else{
					puts("as strings sao diferentes");
				}
				break;
			case 5:
				puts("obrigado por usar nosso programa");	
		}
		printf("\n");
	}while(menu!=5);
	return 0;
}
int strlen(char* a){
	int i=0;
	while(a[i]){
		i++;
	}
	return i;
}

char* strcat(char* a,char* b){
	int i,j;
	char *c=(char*)malloc((strlen(a)+strlen(b))*sizeof(char));
	for(i=0;i<strlen(a);i++){
			c[i]=a[i];
	}
	for(j=0;j<strlen(b);j++){
		c[i+j]=b[j];
	}
	return c;
}
int strcmp(char* a,char* b){
	int i;
	if(strlen(a)!=strlen(b)){
		return 1;
	}
	for(i=0;i<strlen(a);i++){
		if(a[i]!=b[i]){
			return 1;
		}
	}
	return 0;
}
char* strcpy(char* a,char* b){
	int i;
	a=(char*)malloc(strlen(b)*sizeof(char));
	for(i=0;i<strlen(b);i++){
		a[i]=b[i];
	}
	return a;
}
