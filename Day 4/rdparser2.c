#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int S();
int A();
int B();

char ip[100];
int pos = 0, l;	

void main(){
	printf("Enter string : ");
	scanf("%s",ip);
	l = strlen(ip);
	if(S() && pos>=l){
		printf("Valid\n");
	}
	else{
		if(ip[pos] != '\0')
			printf("mismatch : %c\n",ip[pos]);
		else
			printf("mismatch : none\n");
		printf("Invalid\n");
	}
}
int S(){
	if(ip[pos] == 'c'){
		pos++;
		if(ip[pos] == 'd'){
			printf("S -> cd\n");
			pos++;
			return true;
		}
	}
	else{
		printf("S -> AB\n");
		if(A()){
			if(B()){
				return true;
			}
		}
		return false;
	}
}

int A(){
	if(ip[pos] == 'a'){
		pos++;
		printf("A -> a\n");
		return true;
	}
	else{
		if(ip[pos] == 'b'){
			pos++;
			printf("A -> b\n");
			return true;
		}
		return false;
	}
}

int B(){
	if(ip[pos] == 'b'){
		pos++;
		printf("B -> b\n");
		return true;
	}
	else{
		if(ip[pos] == 'c'){
			printf("B -> cAd\n");
			pos++;
			if(A()){
				if(ip[pos] == 'd'){
					pos++;
					return true;
				}
				else{
					return false;
				}
			}
		}
	}
}
