//
// Created by 王阳 on 2018/3/30.
//

#ifndef LEETCODE_HEADER_H
#define LEETCODE_HEADER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

/**
 * 链表节点定义。
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 打印一个链表的所有元素。
 * @param p 链表。
 */
void print_list(ListNode *p) {
    int i = 1;
    while (p != NULL) {
        printf("第 %d 个结点的取值 val = %d\n", i, p->val);
        p = p->next;
        i++;
    }
}

/**
 * 树的节点定义。
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 遍历一个二叉树，深度优先遍历。
 * @param root 根节点。
 * @param layer 层次，默认值为0，即从根节点开始。
 */
void tree_dfs(TreeNode *root, int layer = 0) {
    if (NULL == root) {
        return;
    }

    printf("第 %d 层，当前结点的值：%d 。\n", layer + 1, root->val);
    tree_dfs(root->left, layer + 1);
    tree_dfs(root->right, layer + 1);
}

/**
 * 遍历一个二叉树，广度优先遍历。
 * @param root 根节点。
 */
void tree_bfs(TreeNode *root) {
    if (NULL == root) {
        return;
    }

    queue<TreeNode *> *my_queue = new queue<TreeNode *>();

    my_queue->push(root);

    while (!my_queue->empty()) {
        TreeNode *tmp = my_queue->front();
        my_queue->pop();
        printf("当前结点的值为：%d\n。", tmp->val);
        if (NULL != tmp->left) {
            my_queue->push(tmp->left);
        }

        if (NULL != tmp->right) {
            my_queue->push(tmp->right);
        }
    }
}

/**
 * 遍历一个二叉树。
 * @param root
 */
void print_tree(TreeNode *root) {
    tree_dfs(root, 0);
}

#endif //LEETCODE_HEADER_H
