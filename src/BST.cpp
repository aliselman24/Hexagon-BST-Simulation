/**
* @file BST.cpp
* @description Bu sınıf, ikili arama ağacı (Binary Search Tree - BST) yapısını temsil eder.
* Ağaç içerisine ekleme, yükseklik hesaplama, düğüm sayma ve
* postorder dolaşım ile tüm düğümleri silerek değerleri dışarı alma işlemlerini gerçekleştirir.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#include "BST.hpp"
#include <algorithm> 

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    clear();
}


// Verilen değeri BST kurallarına göre ağaca ekler.
// Eşit değerlerin sola eklenmesi özellikle tercih edilmiştir.
void BST::insert(int value)
{
    Node* newNode = new Node(value);

    if (!root)
    {
        root = newNode;
        return;
    }

    Node* cur = root;
    Node* parent = nullptr;

    while (cur)
    {
        parent = cur;
        // Kural: Eşit değer gelirse sola eklenecektir.
        if (value <= cur->data) 
            cur = cur->left;
        else
            cur = cur->right;
    }

   
    if (value <= parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

int BST::heightRec(Node* node) const
{
    if (!node) return 0;
    int lh = heightRec(node->left);
    int rh = heightRec(node->right);
    return 1 + std::max(lh, rh);
}

// Ağacın yüksekliğini hesaplar.
// Yükseklik, kökten en derin yaprağa kadar olan düğüm sayısıdır.

int BST::getHeight() const
{
    return heightRec(root);
}

int BST::countRec(Node* node) const
{
    if (!node) return 0;
    return 1 + countRec(node->left) + countRec(node->right);
}

int BST::getNodeCount() const
{
    return countRec(root);
}

int BST::getRootData() const
{
    if (!root) return 0;
    return root->data;
}

void BST::postorderRemoveRec(Node* node, int* arr, int& currentIndex)
{
    if (!node) return;

    // Postorder Sırası: Sol -> Sağ -> Kök
    postorderRemoveRec(node->left, arr, currentIndex);
    postorderRemoveRec(node->right, arr, currentIndex);

    arr[currentIndex++] = node->data;
    
    // Düğümü bellekten SİL
    delete node; 
}



// Ağacı postorder (Sol-Sağ-Kök) dolaşım sırasına göre sökerek
// tüm düğüm değerlerini bir diziye aktarır.
// İşlem sonunda ağaç tamamen boşaltılır.

int* BST::extractPostorderValues(int& outSize)
{
    outSize = getNodeCount();
    if (outSize == 0) return nullptr;

    int* arr = new int[outSize];
    int idx = 0;

    postorderRemoveRec(root, arr, idx);

    root = nullptr; // Ağaç artık boş
    return arr;
}

void BST::clear()
{
    clearRec(root);
    root = nullptr;
}

void BST::clearRec(Node* node)
{
    if (!node) return;
    clearRec(node->left);
    clearRec(node->right);
    delete node;
}