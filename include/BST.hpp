/**
* @file BST.hpp
* @description Bu sınıf, ikili arama ağacı (Binary Search Tree - BST) yapısını temsil eder.
* Ağaç içerisine ekleme, yükseklik hesaplama, düğüm sayma ve
* postorder dolaşım ile tüm düğümleri silerek değerleri dışarı alma işlemlerini gerçekleştirir.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"

class BST
{
private:
    Node* root;

    void clearRec(Node* node);
    int heightRec(Node* node) const;
    int countRec(Node* node) const;

    // Postorder gezinti ile diziye ekleme yapan yardımcı
    void postorderRemoveRec(Node* node, int* arr, int& currentIndex);

public:
    BST();
    ~BST();

    void insert(int value);
    int getHeight() const;
    int getNodeCount() const;
    int getRootData() const;

    // outSize referans parametresi ile eleman sayısını dışarı verir.
    int* extractPostorderValues(int& outSize);

    void clear();
};

#endif