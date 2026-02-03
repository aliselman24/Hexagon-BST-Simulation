/**
* @file Hexagon.cpp
* @description  Hexagon sınıfı, 6 adet BST içeren bir kuyruğu temsil eder.
 * Her altıgen, veri çekme ve dağıtma işlemlerinden sorumludur.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#include "Hexagon.hpp"

Hexagon::Hexagon() {}

QueueBST& Hexagon::getQueue()
{
    return queue;
}

const QueueBST& Hexagon::getQueue() const
{
    return queue;
}


// Kuyruktaki belirtilen BST'den postorder sırasıyla
// tüm değerleri çıkarır ve ağacı kuyruktan kaldırır.
int* Hexagon::extractBSTValues(int removeIndex, int& outCount)
{
    queue.ensureSixTrees();

    BST* target = queue.at(removeIndex);
    if (!target)
    {
        outCount = 0;
        return nullptr;
    }

    // 1. Değerleri postorder sırasıyla çıkar
    int* values = target->extractPostorderValues(outCount);

    // 2. BST kuyruktan kaldırılır ve kalanlar kaydırılır
    queue.removeAndShift(removeIndex); 
    
    return values;
}

// Verilen değerleri, kuyruktaki BST'lere
// round-robin (dairesel) mantıkla dağıtır.
void Hexagon::distributeValues(int* values, int count)
{
    if (!values || count <= 0) return;

    queue.ensureSixTrees();

    int idx = 0; // kuyruk başı

    for (int i = 0; i < count; ++i)
    {
        BST* t = queue.at(idx);
        t->insert(values[i]);

        idx++;
        if (idx == 6)
            idx = 0;
    }
}

void Hexagon::clear()
{
    queue.clear();
}