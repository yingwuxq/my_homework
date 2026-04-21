#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int weight; // 权重
    int parent; // 父节点下标
    int left, right; // 左右孩子节点下标
    unsigned char ch; // 对应的字符（仅叶子节点有效）
} HTNode, *HuffmanTree;

typedef char **HuffmanCode; // 哈夫曼编码表

char* charToCode[256] = {NULL};

// 统计文本中各个字符的出现频率
void countFrequencies(const char* filename, int freq[256], int *total_chars) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    int ch;
    *total_chars = 0;
    while ((ch = fgetc(fp)) != EOF) {
        freq[ch]++;
        (*total_chars)++;
    }
    fclose(fp);
}

// 在未分配父节点的节点中，找出权重最小的两个节点
void selectTwoMin(HuffmanTree HT, int n, int *s1, int *s2) {
    int min1 = 999999999;
    int min2 = 999999999;
    *s1 = -1;
    *s2 = -1;

    for (int i = 0; i < n; i++) {
        if (HT[i].parent == -1) { // 还没有父节点
            if (HT[i].weight < min1) {
                min2 = min1;
                *s2 = *s1;
                min1 = HT[i].weight;
                *s1 = i;
            } else if (HT[i].weight < min2) {
                min2 = HT[i].weight;
                *s2 = i;
            }
        }
    }
}

// 构造哈夫曼树
void buildHuffmanTree(HuffmanTree *HT, int freq[256], int *leaf_count) {
    *leaf_count = 0;
    // 统计有多少个不重复的字符
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) (*leaf_count)++;
    }

    if (*leaf_count <= 1) return;

    int n = *leaf_count; // 叶子节点数
    int m = 2 * n - 1; // 哈夫曼树总节点数
    *HT = (HuffmanTree)malloc(m * sizeof(HTNode));

    // 初始化所有节点
    for (int i = 0; i < m; i++) {
        (*HT)[i].parent = -1;
        (*HT)[i].left = -1;
        (*HT)[i].right = -1;
        (*HT)[i].weight = 0;
    }

    // 填充叶子节点数据
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            (*HT)[index].weight = freq[i];
            (*HT)[index].ch = (unsigned char)i;
            index++;
        }
    }

    // 构建非叶子节点：每次选择两个最小权重的节点合并
    for (int i = n; i < m; i++) {
        int s1, s2;
        selectTwoMin(*HT, i, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].left = s1;
        (*HT)[i].right = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight; // 父节点权重=子节点权重和
    }
}

// 逆向遍历树生成哈夫曼编码表
void generateHuffmanCodes(HuffmanTree HT, HuffmanCode *HC, int leaf_count) {
    *HC = (HuffmanCode)malloc(leaf_count * sizeof(char*));
    char *temp_code = (char*)malloc(leaf_count * sizeof(char)); 
    temp_code[leaf_count - 1] = '\0';

    for (int i = 0; i < leaf_count; i++) {
        int start = leaf_count - 1;
        int current = i;
        int parent = HT[i].parent;

        // 从叶子向上回溯到根
        while (parent != -1) {
            start--;
            if (HT[parent].left == current) {
                temp_code[start] = '0'; // 左子节点编码为0
            } else {
                temp_code[start] = '1'; // 右子节点编码为1
            }
            current = parent;
            parent = HT[parent].parent;
        }
        
        // 动态分配存储空间并复制编码
        (*HC)[i] = (char*)malloc((leaf_count - start) * sizeof(char));
        strcpy((*HC)[i], &temp_code[start]);
        
        // 保存到全局映射表，便于编码时快速查找
        charToCode[HT[i].ch] = (*HC)[i];
    }
    free(temp_code);
}

// 编码文件并将位(bits)按字节(bytes)压入二进制文件中实现真实压缩
void encodeFile(const char* in_filename, const char* out_filename, int total_chars) {
    FILE *in_fp = fopen(in_filename, "r");
    FILE *out_fp = fopen(out_filename, "wb"); // 以二进制写模式打开
    
    if (!in_fp || !out_fp) {
        printf("File error during encoding.\n");
        exit(1);
    }

    unsigned char buffer = 0; // 8位的缓冲器
    int bit_count = 0; // 缓冲区中已使用的位数
    int ch;
    
    // 逐个字符读取并编码
    while ((ch = fgetc(in_fp)) != EOF) {
        char *code = charToCode[ch];
        for (int i = 0; code[i] != '\0'; i++) {
            buffer = buffer << 1; // 左移一位
            if (code[i] == '1') {
                buffer = buffer | 1; // 最低位置1
            }
            bit_count++;

            // 凑满8位写入文件
            if (bit_count == 8) {
                fputc(buffer, out_fp);
                buffer = 0;
                bit_count = 0;
            }
        }
    }

    // 处理最后不满8位的，补0对齐
    if (bit_count > 0) {
        buffer = buffer << (8 - bit_count);
        fputc(buffer, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
}

// 读入二进制压缩文件，通过遍历哈夫曼树进行译码
void decodeFile(const char* in_filename, const char* out_filename, HuffmanTree HT, int total_chars, int root_index) {
    FILE *in_fp = fopen(in_filename, "rb"); // 以二进制读模式打开
    FILE *out_fp = fopen(out_filename, "w");
    
    if (!in_fp || !out_fp) {
        printf("File error during decoding.\n");
        exit(1);
    }

    int current_node = root_index;
    int decoded_chars = 0;
    int byte;

    // 逐字节读取
    while ((byte = fgetc(in_fp)) != EOF && decoded_chars < total_chars) {
        // 逐位解析（从高位到低位）
        for (int i = 7; i >= 0; i--) {
            int bit = (byte >> i) & 1; // 获取当前位(0或1)

            if (bit == 0) {
                current_node = HT[current_node].left;
            } else {
                current_node = HT[current_node].right;
            }

            // 如果到达叶子节点
            if (HT[current_node].left == -1 && HT[current_node].right == -1) {
                fputc(HT[current_node].ch, out_fp);
                decoded_chars++;
                current_node = root_index; // 重新回到根节点
                
                // 如果已经解码完成所有原字符，跳出循环（防止最后的补齐0被多余解析）
                if (decoded_chars >= total_chars) {
                    break;
                }
            }
        }
    }

    fclose(in_fp);
    fclose(out_fp);
}

// 逐字节比较两个文件是否完全相同
void compareFiles(const char* file1, const char* file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");

    if (!f1 || !f2) {
        printf("Error opening files for comparison.\n");
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        return;
    }

    int ch1, ch2;
    bool is_identical = true;

    while (1) {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);

        if (ch1 != ch2) {
            is_identical = false;
            break;
        }
        if (ch1 == EOF) break;
    }

    fclose(f1);
    fclose(f2);

    if (is_identical) {
        printf("Result: MATCH! The decoded file is identical to the original.\n");
    } else {
        printf("Result: MISMATCH! Data was lost or corrupted.\n");
    }
}

// 获取文件大小（字节数）计算压缩率
long getFileSize(const char* filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return 0;
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    
    return size;
}

int main() {
    const char* original_file = "input.txt";
    const char* encoded_file = "encoded.bin";
    const char* decoded_file = "decoded.txt";
    
    int freq[256] = {0};
    int total_chars = 0;
    int leaf_count = 0;
    HuffmanTree HT = NULL;
    HuffmanCode HC = NULL;

    // 统计字符频率
    printf("[1] Counting character frequencies...\n");
    countFrequencies(original_file, freq, &total_chars);
    if (total_chars == 0) {
        printf("Error: The input file is empty!\n");
        return 1;
    }
    
    // 打印字符频率统计结果
    printf("--- Character Frequency Statistics ---\n");
    printf("Total characters: %d\n", total_chars);
    int printed_count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printed_count++;
            if (i == '\n') {
                printf("  '\\n'  (ASCII %d): %d (%.2f%%)\n", i, freq[i], (freq[i] * 100.0) / total_chars);
            } else if (i == '\r') {
                printf("  '\\r'  (ASCII %d): %d (%.2f%%)\n", i, freq[i], (freq[i] * 100.0) / total_chars);
            } else if (i == '\t') {
                printf("  '\\t'  (ASCII %d): %d (%.2f%%)\n", i, freq[i], (freq[i] * 100.0) / total_chars);
            } else if (i == ' ') {
                printf("  ' '   (ASCII %d): %d (%.2f%%)\n", i, freq[i], (freq[i] * 100.0) / total_chars);
            } else if (i >= 32 && i <= 126) {
                printf("  '%c'   (ASCII %d): %d (%.2f%%)\n", i, i, freq[i], (freq[i] * 100.0) / total_chars);
            } else {
                printf("  (0x%02X) (ASCII %d): %d (%.2f%%)\n", i, i, freq[i], (freq[i] * 100.0) / total_chars);
            }
        }
    }
    printf("Distinct characters: %d\n", printed_count);
    printf("-------------------------------------\n");

    // 构建哈夫曼树
    printf("[2] Building Huffman Tree...\n");
    buildHuffmanTree(&HT, freq, &leaf_count);
    int root_index = 2 * leaf_count - 2; // 哈夫曼树根节点的下标

    // 生成哈夫曼编码
    printf("[3] Generating Huffman Codes...\n");
    generateHuffmanCodes(HT, &HC, leaf_count);
    
    printf("--- Huffman Dictionary ---\n");
    for (int i = 0; i < leaf_count; i++) {
        unsigned char c = HT[i].ch;
        if (c == '\n') printf(" '\\n' : %s\n", HC[i]);
        else if (c == '\r') printf(" '\\r' : %s\n", HC[i]);
        else if (c == ' ') printf(" ' '  : %s\n", HC[i]);
        else printf("  %c   : %s\n", c, HC[i]);
    }
    printf("--------------------------\n");

    // 对文件进行编码压缩（位操作）
    printf("[4] Encoding '%s' to '%s'...\n", original_file, encoded_file);
    encodeFile(original_file, encoded_file, total_chars);

    // 计算并打印压缩率
    long original_size = getFileSize(original_file);
    long encoded_size = getFileSize(encoded_file);
    double ratio = ((double)encoded_size / original_size) * 100.0;
    printf("[5] Compression Statistics:\n");
    printf("Original size: %ld bytes\n", original_size);
    printf("Encoded size:  %ld bytes\n", encoded_size);
    printf("Compression ratio: %.2f%%\n", ratio);

    // 解码文件
    printf("[6] Decoding '%s' to '%s'...\n", encoded_file, decoded_file);
    decodeFile(encoded_file, decoded_file, HT, total_chars, root_index);

    // 比较原文件和解码后的文件
    printf("[7] Comparing original file and decoded file...\n");
    compareFiles(original_file, decoded_file);

    // 释放内存
    for (int i = 0; i < leaf_count; i++) {
        free(HC[i]);
    }
    free(HC);
    free(HT);
    return 0;
}