#include <stdlib.h>
#include <stdbool.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

typedef struct {
    char *ch;
    int length;
} HString;

typedef struct StringNode {
    char *ch[4];
    struct StringNode *next;
} StringNode, *String;

bool SubString(SString &Sub, SString S, int pos, int len) {
    if (pos + len - 1 >= S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

int Index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;
    SString sub;
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    return 0;
}

int IndexString(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i, ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    } 
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}

int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i, ++j;
        } else {
            j = next[j];
        }
    }
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}