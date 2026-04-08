#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10

typedef char ElemType;

typedef struct {
    char data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack &S) {
    return S.top == -1;
}

bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1) {
        return false;
    }
    S.top++;
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    S.top--;
    return true;
}

bool bracketCheck(char str[], int len) {
    SqStack S;
    InitStack(S);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (StackEmpty(S)) {
                return false;
            }
            char top;
            Pop(S, top);
            if ((str[i] == ')' && top != '(') ||
                (str[i] == ']' && top != '[') ||
                (str[i] == '}' && top != '{')) {
                return false;
            }
        }
    }
    return StackEmpty(S);
}

int main() {
    char str[] = "({[(hello world!)]})";
    int len = sizeof(str) / sizeof(str[0]) - 1;
    if (bracketCheck(str, len)) {
        printf("matched successfully\n");
    } else {
        printf("match filed\n");
    }
    return 0;
}