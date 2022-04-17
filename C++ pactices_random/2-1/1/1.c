#include<stdio.h>

struct Person{
    char name[10];
    int  age;
};

int main(){
    struct Person people[3];
    int i;
    
    for(i=0; i<3; i++){
        scanf("%s", people[i].name);
        //fgets(people[i].name, 10, stdin);
        scanf("%d", &people[i].age);
        getchar();
    }
    
    for(i=0; i<3; i++){
        printf("Name:%s ,Age: %d\n", people[i].name, people[i].age);
    }
    return 0;
}
