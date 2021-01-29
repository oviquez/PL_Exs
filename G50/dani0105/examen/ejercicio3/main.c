#include <stdio.h>

int space = 0;

void printLine(int group){
    for(int x = 0;x <= (space-group);x++){
        printf(" ");
    }

    for(int x = 0; x < group;x++){
        printf("* ");
    }
    printf("\n");
}

int printStructure(int current, int deep,int line,int group){
    if(deep == current){
        printLine(group);
        return group;
    }
    current++;

    if(line == group){
        group++;
        space++;
        line=1;
    }else
        line++;

    group = printStructure(current,deep,line,group);
    line--;
    if(line == 0){
        group--;
    }
    printLine(group);
    return group;
}

int main() {
    int n;
    printf("Profundidad: ");
    scanf ("%d",&n);
    printf("\n");
    return printStructure(1,n,1,1);
}
