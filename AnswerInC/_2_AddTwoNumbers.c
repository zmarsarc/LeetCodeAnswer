/*
    基本思路是：
    对输入的两个链表对位的每个节点进行带进位的加法。
    当一条链表结束，剩下的各个位都视为0。
    当两条链表都结束时，让两条链表都进行 0 与 0 的带进位的加法。
*/

/*
    对 1562 个 Sample 进行测试
    正确率 100%
    运行时间 43ms
    击败了 9.94% 的 C 提交
*/

#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
}

int isCarry = 0;

//  这里一定需要注意的是，由于 C 调用栈在运行时对调用参数的入栈顺序是从后前
//  ------!!!------ 所以参数的顺序非常重要 ------!!!------
//  每次运算需要前一次的进位结果做支撑
//  所以在每次进入下层递归之前，必须完成当前层次的所有运算
struct ListNode* newNode(struct ListNode* next, int val) {
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = next;
    return ret;
}

int addWithCarry(int a, int b) {
    int num  = a + b + isCarry;
    isCarry = (num > 9) ? 1 : 0;
    return (num % 10);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 && !l2) {
        //  完成所有求值后需要复位 isCarry 标志
        struct ListNode* ret =  isCarry ? newNode(NULL, isCarry) : NULL;
        isCarry = 0;
        return ret;
    }
    if (!l1) {
        return newNode(addTwoNumbers(NULL, l2->next), addWithCarry(0, l2->val));
    }
    if (!l2) {
        return newNode(addTwoNumbers(NULL, l1->next), addWithCarry(0, l1->val));
    }
    return newNode(addTwoNumbers(l1->next, l2->next), addWithCarry(l1->val, l2->val));
}