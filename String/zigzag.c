#include<stdbool.h>
char* convert(char* s, int numRows) {
    int len= strlen(s);
    if(numRows==1 || numRows>= len){
        char* ans=(char*)malloc(len+1);
        strcpy(ans,s);
        return ans;
    }
    char** rows=(char**)malloc(numRows*sizeof(char*));
    for(int i=0; i<numRows; i++){
        rows[i]=(char*)calloc(len+1,sizeof(char));
    }
    int currentRow=0;
    bool goingDown=false;
    for(int i=0;i<len;i++){
        int rowLen=strlen(rows[currentRow]);
        rows[currentRow][rowLen]=s[i];
        if(currentRow==0 || currentRow==numRows-1)
            goingDown= !goingDown;
        currentRow+=goingDown?1:-1;
    }
    char* result=(char*)malloc(len+1);
    result[0]='\0';
    for(int i=0;i<numRows;i++){
        strcat(result,rows[i]);
    }
    return result;
}