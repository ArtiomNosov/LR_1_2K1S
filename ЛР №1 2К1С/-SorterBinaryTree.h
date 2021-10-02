/*
*	SorterBinaryTree.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"

#include <memory>
#include <cassert>
#include <algorithm>

#include <vector>
#include <iostream>

using namespace std;

// класс, представл€ющий бинарное дерево
template <class T, class SeqType>
class BinaryTree
{
protected:
    // узел бинарного дерева
    struct BinaryTreeNode
    {
        shared_ptr<BinaryTreeNode> left, right; // левое и правое поддерево
        T* key; // ключ
    };

    shared_ptr<BinaryTreeNode> m_root; // корень дерева

protected:
    // рекурсивна€ процедура вставки ключа
    // cur_node - текущий узел дерева, с которым сравниваетс€ вставл€емый узел
    // node_to_insert - вставл€емый узел
    void insert_recursive(const shared_ptr<BinaryTreeNode>& cur_node, const shared_ptr<BinaryTreeNode>& node_to_insert)
    {
        assert(cur_node != nullptr);
        // сравнение
        bool insertIsLess = node_to_insert->key < cur_node->key;
        if (insertIsLess)
        {
            // вставка в левое поддерево
            if (cur_node->left == nullptr)
                cur_node->left = node_to_insert;
            else
                insert_recursive(cur_node->left, node_to_insert);
        }
        else
        {
            // вставка в правое поддерево
            if (cur_node->right == nullptr)
                cur_node->right = node_to_insert;
            else
                insert_recursive(cur_node->right, node_to_insert);
        }
    }

public:
    void insert(T* key)
    {
        shared_ptr<BinaryTreeNode> node_to_insert(new BinaryTreeNode);
        node_to_insert->key = key;

        if (m_root == nullptr)
        {
            m_root = node_to_insert;
            return;
        }

        insert_recursive(m_root, node_to_insert);
    }

public:
    typedef function<void(T* key)> Visitor;

protected:
    // рекурсивна€ процедура обхода дерева
    // cur_node - посещаемый в данный момент узел
    void visit_recursive(SeqType* Sequence, int& j, const shared_ptr<BinaryTreeNode>& cur_node, const Visitor& visitor)
    {
        assert(cur_node != nullptr);

        // сначала посещаем левое поддерево
        if (cur_node->left != nullptr)
            visit_recursive(Sequence, j, cur_node->left, visitor);

        // посещаем текущий элемент
        visitor(cur_node->key);
        Sequence->Set(j, cur_node->key);
        j++;
        // посещаем правое поддерево
        if (cur_node->right != nullptr)
            visit_recursive(Sequence, j, cur_node->left, visitor);
        visit_recursive(Sequence, j, cur_node->right, visitor);
    }

public:
    void visit(SeqType* Sequence, const Visitor& visitor)
    {
        if (m_root == nullptr)
            return;
        int j = 0;
        visit_recursive(Sequence, j, m_root, visitor);
    }
};

template <class SeqType, class T>
class SorterBinaryTree : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    void BinaryTreeSort(SeqType* Sequence) {
        BinaryTree<T, SeqType> tree; int size = Sequence->GetLength();
        for (int i = 0; i < size; i++) {
            tree.insert((*Sequence)[i]);
        }
        int j = 0;
        tree.visit(Sequence, {});
    }
public:
};
