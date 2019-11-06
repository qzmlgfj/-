#pragma once
#include "List.hpp"

class HuffmanTreeNode
{
private:
    unsigned char data; //储存字节数据
    int weight;         //存储节点权重
    HuffmanTreeNode *parent, *leftChild, *rightChild;
    friend class HuffmanTree;
    friend class List<HuffmanTreeNode *>;

public:
    HuffmanTreeNode() {}

    HuffmanTreeNode(unsigned char Data, int Weight) //以Data和Weight为参数生成叶节点
    {
        data = Data;
        weight = Weight;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

    HuffmanTreeNode(HuffmanTreeNode *p1, HuffmanTreeNode *p2) //生成哈夫曼树时用来生成子树根节点
    {
        data = -1;
        weight = p1->weight + p2->weight;
        leftChild = p1;
        rightChild = p2;
    }
};

class HuffmanTree
{
public:
    HuffmanTreeNode *root;

    HuffmanTree(HuffmanTreeNode *p);
    HuffmanTreeNode *newNode(unsigned char Data, int Weight); //以Data和Weight为参数生成节点
    void addNode(HuffmanTreeNode *&p);                        //在指定指针处新建节点
    void buildHuffmanTree();                                  //前序方式建立哈夫曼树,可能需要添加参数
    void buildHuffmanTree(List<HuffmanTreeNode *> list);
    int getDepth(HuffmanTreeNode *p);
    void fixArray(HuffmanTreeNode *p, HuffmanTreeNode *parent); //补充父指针
    int isLeaf(HuffmanTreeNode *p);
};

HuffmanTree::HuffmanTree(HuffmanTreeNode *p = NULL)
{
    root = p;
}

HuffmanTreeNode *HuffmanTree::newNode(unsigned char Data, int Weight)
{
    return new HuffmanTreeNode(Data, Weight);
}

void HuffmanTree::addNode(HuffmanTreeNode *&p)
{
    unsigned char Data;
    int Weight;

    //Data来源,注意标记NULL

    p = newNode(Data, Weight);

    addNode(p->leftChild);
    addNode(p->rightChild);
}

void HuffmanTree::buildHuffmanTree()
{
    unsigned char Data;
    int Weight;

    //Data来源，注意第一次读取的数据放在根节点处

    addNode(root->leftChild);
    addNode(root->rightChild);

    fixArray(root, NULL);
}

void HuffmanTree::fixArray(HuffmanTreeNode *p, HuffmanTreeNode *parent)
{
    if (!p)
        return;

    p->parent = parent;
    fixArray(p->leftChild, p); //递归补充父指针
    fixArray(p->rightChild, p);
}

void HuffmanTree::buildHuffmanTree(List<HuffmanTreeNode *> list)
{
    if (list.end == list.head)
        return;

    HuffmanTreeNode *group[2];

    while (list.total > 1)
    {
        group[1] = list.getMin()->data;
        group[0] = list.getMin()->data;

        list.AddNode(new HuffmanTreeNode(group[0], group[1]));
    }

    root = list.head->next->data;

    fixArray(root, NULL);
}

int HuffmanTree::isLeaf(HuffmanTreeNode *p)
{
    if (p->leftChild == NULL && p->rightChild == NULL)
        return 1;
    else
        return 0;
}