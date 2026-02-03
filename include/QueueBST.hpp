/**
* @file QueueBST.hpp
* @description QueueBST sınıfı, her altıgen için sabit boyutlu (6 adet)
 * ikili arama ağacından oluşan bir kuyruk yapısını temsil eder.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#ifndef QUEUEBST_HPP
#define QUEUEBST_HPP

#include "BST.hpp"

class QueueBST
{
private:
    BST* trees[6];   // Her altıgende daima 6 BST
    bool initialized;

public:
    QueueBST();
    ~QueueBST();

    // 6 BST’nin var olduğundan emin ol
    void ensureSixTrees();

    // 0..5 indexli BST'ye eriş
    BST* at(int index) const;

    // Her zaman 6 döner
    int count() const;

    // Belirtilen indeksteki BST'yi siler ve kalanları kaydırır (SHIFT)
    void removeAndShift(int index);

    // Tüm BST'leri temizle ve sil
    void clear();
};

#endif