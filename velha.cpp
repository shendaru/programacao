#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,i,j,marc,coord1,coord2,res=0,qnt;
	char marc1,marc2;
	puts("informe o tamanho do jogo da velha(de 3 a 10):");
	scanf("%d",&a);
	if(a<3||a>10){
		puts("numero invalido");
		return 1;
	}
	char** mat=(char**)malloc(a*sizeof(char*));
	for(i=0;i<a;i++){
		mat[i]=(char*)malloc(a*sizeof(char));
	}
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			mat[i][j]='-';		
		}
	}
	do{
		puts("o jogador numero 1 sera X ou O?(1 para X, 2 para O):");
		scanf("%d",&marc);
		if(marc!=1&&marc!=2){
			puts("numero invalido, tente novamente");
		}}while(marc!=1&&marc!=2);
	if(marc==1){
		marc1='X';
		marc2='O';
	}	
	else{
		marc1='O';
		marc2='X';	
	}
	do{
		errado:
		do{
			i=0;
			printf("selecione as coordenadas onde voce quer marcar %c(de 1 a %d)",marc1,a);
			scanf("%d%d",&coord1,&coord2);
			if(coord1<1||coord1>a||coord2<1||coord2>a){
				puts("coordenada invalida,tente novamente");}
			else{
				i++;
			}	
			}while(i==0);
		if(mat[coord1-1][coord2-1]=='X'||mat[coord1-1][coord2-1]=='O'){
			printf("espaco ja ocupado, tente novamente:\n");
			goto errado;
		}
		else{
			mat[coord1-1][coord2-1]=marc1;
		}
		for(i=0;i<a;i++){
			for(j=0;j<a;j++){
				printf("%c\t",mat[i][j]);
			}
			printf("\n\n");
		}
		for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
			if(mat[i][j]==marc1){
				qnt++;
			}
			if(qnt==a){
				printf("fim do jogo, %c ganhou",marc1);
				goto fim;
			}
			}
			qnt=0;}
		for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
			if(mat[j][i]==marc1){
				qnt++;
			}
			if(qnt==a){
				printf("fim do jogo, %c ganhou",marc1);
				goto fim;
			}
		}
		qnt=0;
		}
		for(i=0,j=0,qnt=0;j<a&&i<a;i++,j++){
			if(mat[i][j]==marc1){
				qnt++;
		}}
		if(qnt==a){
				printf("fim do jogo, %c ganhou",marc1);
				goto fim;
		}	
		for(i=a-1,j=0,qnt=0;j<a&&i>=0;i--,j++){
			if(mat[i][j]==marc1){
				qnt++;
		}}
		if(qnt==a){
				printf("fim do jogo, %c ganhou",marc1);
				goto fim;
		}
		for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
				if(mat[i][j]!='-'){
					qnt++;
				}
			}
		}
		if(qnt==a*a){
			puts("empate");
			goto fim;
		}
		errado2:
		do{
			i=0;
			printf("selecione as coordenadas onde voce quer marcar %c(de 1 a %d)",marc2,a);
			scanf("%d%d",&coord1,&coord2);
			if(coord1<1||coord1>a||coord2<1||coord2>a){
				puts("coordenada invalida,tente novamente");}
			else{
				i++;
			}	
			}while(i==0);
		if(mat[coord1-1][coord2-1]=='X'||mat[coord1-1][coord2-1]=='O'){
			printf("espaco ja ocupado, tente novamente:\n");
			goto errado2;
		}
		else{
			mat[coord1-1][coord2-1]=marc2;
		}
		for(i=0;i<a;i++){
			for(j=0;j<a;j++){
				printf("%c\t",mat[i][j]);
			}
			printf("\n\n");
		}
		for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
			if(mat[i][j]==marc2){
				qnt++;
			}
			if(qnt==a){
				printf("fim do jogo, %c ganhou",marc2);
				goto fim;
			}
			}
			qnt=0;}
		for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
			if(mat[j][i]==marc2){
				qnt++;
			}
			if(qnt==a){
				printf("fim do jogo, %c ganhou",marc2);
				goto fim;
			}
		}
		qnt=0;
		}
		for(i=0,j=0,qnt=0;j<a&&i<a;i++,j++){
			if(mat[i][j]==marc2){
				qnt++;
		}}
		if(qnt==a){
				printf("fim do jogo, %c ganhou",marc2);
				goto fim;
		}	
		for(i=a-1,j=0,qnt=0;j<a&&i>=0;i--,j++){
			if(mat[i][j]==marc2){
				qnt++;
		}}
		if(qnt==a){
				printf("fim do jogo, %c ganhou",marc2);
				goto fim;
		}
		for(i=0,qnt=0;i<a;i++){
			for(j=0;j<a;j++){
				if(mat[i][j]!='-'){
					qnt++;
				}
			}
		}
		if(qnt==a*a){
			puts("empate");
			goto fim;
		}								
	}while (res!=1);
	fim:	
	free(mat);
	return 0;
}

