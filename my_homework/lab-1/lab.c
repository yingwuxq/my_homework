#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

// 栈结构定义
typedef struct {
    int top;
    char data[MAXSIZE];
} CharStack;

typedef struct {
    int top;
    int data[MAXSIZE];
} IntStack;

// 栈初始化
void initCharStack(CharStack *s) {
    s->top = -1;
}

void initIntStack(IntStack *s) {
    s->top = -1;
}

// 栈判空
int isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

int isIntStackEmpty(IntStack *s) {
    return s->top == -1;
}

// 栈判满
int isCharStackFull(CharStack *s) {
    return s->top == MAXSIZE - 1;
}

int isIntStackFull(IntStack *s) {
    return s->top == MAXSIZE - 1;
}

// 入栈操作
int pushChar(CharStack *s, char c) {
    if (isCharStackFull(s)) {
        return 0;
    }
    s->data[++s->top] = c;
    return 1;
}

int pushInt(IntStack *s, int n) {
    if (isIntStackFull(s)) {
        return 0;
    }
    s->data[++s->top] = n;
    return 1;
}

// 出栈操作
char popChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        return '#';
    }
    return s->data[s->top--];
}

int popInt(IntStack *s) {
    if (isIntStackEmpty(s)) {
        return 0;
    }
    return s->data[s->top--];
}

// 获取栈顶元素
char peekChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        return '#';
    }
    return s->data[s->top];
}

int peekInt(IntStack *s) {
    if (isIntStackEmpty(s)) {
        return 0;
    }
    return s->data[s->top];
}

// 运算符优先级
int Pre(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '#':
            return 0;
        default:
            return -1;
    }
}

// 打印栈状态
void printCharStack(CharStack *s, const char *action) {
    printf("  [Stack %s] ", action);
    if (isCharStackEmpty(s)) {
        printf("Empty");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%c ", s->data[i]);
        }
    }
    printf("\n");
}

void printIntStack(IntStack *s, const char *action) {
    printf("  [Stack %s] ", action);
    if (isIntStackEmpty(s)) {
        printf("Empty");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
    }
    printf("\n");
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '#');
}

// 将中缀表达式转换为后缀表达式
int infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    int i = 0, j = 0;
    char current;
    
    pushChar(&s, '#');
    
    while ((current = infix[i]) != '\0') {
        if (current == '#') {
            i++;
            continue;
        }
        if (isdigit(current)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            printCharStack(&s, "after read operand");
            continue;
        }
        if (current == ')') {
            char top;
            while (!isCharStackEmpty(&s) && (top = popChar(&s)) != '(') {
                postfix[j++] = top;
                postfix[j++] = ' ';
                printCharStack(&s, "after pop ')");
            }
            printCharStack(&s, "after remove '('");
            i++;
            continue;
        }
        if (current == '(') {
            pushChar(&s, current);
            printCharStack(&s, "after push '('");
            i++;
            continue;
        }
        if (isOperator(current)) {
            char top = peekChar(&s);
            while (!isCharStackEmpty(&s) && top != '(' && top != '#' && Pre(top) >= Pre(current)) {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
                printCharStack(&s, "after pop operator");
                top = peekChar(&s);
            }
            pushChar(&s, current);
            printCharStack(&s, "after push operator");
            i++;
            continue;
        }
        i++;
    }
    
    while (!isCharStackEmpty(&s) && peekChar(&s) != '#') {
        char top = popChar(&s);
        postfix[j++] = top;
        postfix[j++] = ' ';
        printCharStack(&s, "after pop remaining");
    }
    postfix[j] = '\0';
    printf("\nFinal Postfix Expression: %s\n", postfix);
    return 1;
}

// 计算后缀表达式的值
int evaluatePostfix(char *postfix) {
    IntStack s;
    initIntStack(&s);
    int i = 0, op1, op2;
    char current;
    
    while ((current = postfix[i]) != '\0') {
        if (current == ' ') {
            i++;
            continue;
        }
        if (isdigit(current)) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushInt(&s, num);
            printIntStack(&s, "after push operand");
            continue;
        }
        if (isOperator(current) && current != '#') {
            op2 = popInt(&s);
            op1 = popInt(&s);
            switch (current) {
                case '+': pushInt(&s, op1 + op2); break;
                case '-': pushInt(&s, op1 - op2); break;
                case '*': pushInt(&s, op1 * op2); break;
                case '/': pushInt(&s, op1 / op2); break;
            }
            printIntStack(&s, "after push result");
        }
        i++;
    }
    int result = popInt(&s);
    printIntStack(&s, "after pop result");
    return result;
}

// 从文件中读取表达式
void readExpression(char *filename, char *expression) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }
    if (fgets(expression, MAXSIZE, file) == NULL) {
        printf("Cannot read expression from file %s\n", filename);
        return;
    }
    expression[strcspn(expression, "\n")] = '\0';
    fclose(file);
}

int main () {
    char expression[MAXSIZE];
    char postfix[MAXSIZE];
    int result;
    char filename[MAXSIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    readExpression(filename, expression);
    printf("Expression read from file: %s\n", expression);
    infixToPostfix(expression, postfix);
    result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}