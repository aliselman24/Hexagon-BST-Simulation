/**
* @file QueueBST.cpp
* @description QueueBST sınıfı, her altıgen için sabit boyutlu (6 adet)
 * ikili arama ağacından oluşan bir kuyruk yapısını temsil eder.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/

#include "QueueBST.hpp"

QueueBST::QueueBST() : initialized(false)
{
    for (int i = 0; i < 6; ++i)
        trees[i] = nullptr;
}

QueueBST::~QueueBST()
{
    clear();
}


// Kuyruğun her zaman 6 adet BST içermesini garanti eder.
// İlk kez çağrıldığında BST nesneleri oluşturulur.
void QueueBST::ensureSixTrees()
{
    if (initialized) return;

    for (int i = 0; i < 6; ++i)
        trees[i] = new BST();

    initialized = true;
}

BST* QueueBST::at(int index) const
{
    if (index < 0 || index >= 6) return nullptr;
    return trees[index];
}

int QueueBST::count() const
{
    return 6;
}

// İlgili BST'yi sil ve diğerlerini kaydır
// Belirtilen indisteki BST'yi kuyruktan çıkarır.
// Ardındaki ağaçları sola kaydırır ve çıkarılan BST'yi kuyruğun sonuna ekler.
// Böylece kuyruk yapısı korunur.

void QueueBST::removeAndShift(int index)
{
    if (index < 0 || index >= 6) return;

    // BST zaten postorder ile boşaltıldı
    BST* removed = trees[index];

    for (int i = index; i < 5; ++i)
        trees[i] = trees[i + 1];

    trees[5] = removed; // AYNI BST sona taşınır
}


void QueueBST::clear()
{
    for (int i = 0; i < 6; ++i)
    {
        if (trees[i])
        {
            delete trees[i];
            trees[i] = nullptr;
        }
    }
    initialized = false;
}