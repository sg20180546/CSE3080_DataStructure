#include <stdio.h>

enum tagField{
	pitcher,
	hitter
};

typedef struct{
	enum tagField role;
	union{
		int SO;
		double HR;
	} u;
	
} playerType;


typedef struct{
	char name[10];
	int age;
	float salary;
	playerType playerInfo;
} baseballPlayer;

int main(void){
	baseballPlayer person1,person2;
	person1.playerInfo.role=hitter;
	printf("%d\n",sizeof(enum tagField));
	
	printf("%d\n",sizeof(playerType));
	printf("%d\n",sizeof(person1));
	
	return 0;
}
