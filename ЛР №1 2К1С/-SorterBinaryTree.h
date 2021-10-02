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

// �����, �������������� �������� ������
template <class T, class SeqType>
class BinaryTree
{
protected:
    // ���� ��������� ������
    struct BinaryTreeNode
    {
        shared_ptr<BinaryTreeNode> left, right; // ����� � ������ ���������
        T* key; // ����
    };

    shared_ptr<BinaryTreeNode> m_root; // ������ ������

protected:
    // ����������� ��������� ������� �����
    // cur_node - ������� ���� ������, � ������� ������������ ����������� ����
    // node_to_insert - ����������� ����
    void insert_recursive(const shared_ptr<BinaryTreeNode>& cur_node, const shared_ptr<BinaryTreeNode>& node_to_insert)
    {
        assert(cur_node != nullptr);
        // ���������
        bool insertIsLess = node_to_insert->key < cur_node->key;
        if (insertIsLess)
        {
            // ������� � ����� ���������
            if (cur_node->left == nullptr)
                cur_node->left = node_to_insert;
            else
                insert_recursive(cur_node->left, node_to_insert);
        }
        else
        {
            // ������� � ������ ���������
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
    // ����������� ��������� ������ ������
    // cur_node - ���������� � ������ ������ ����
    void visit_recursive(SeqType* Sequence, int& j, const shared_ptr<BinaryTreeNode>& cur_node, const Visitor& visitor)
    {
        assert(cur_node != nullptr);

        // ������� �������� ����� ���������
        if (cur_node->left != nullptr)
            visit_recursive(Sequence, j, cur_node->left, visitor);

        // �������� ������� �������
        visitor(cur_node->key);
        Sequence->Set(j, cur_node->key);
        j++;
        // �������� ������ ���������
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
