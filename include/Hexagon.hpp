/**
* @file Hexagon.hpp
* @description  Hexagon sınıfı, 6 adet BST içeren bir kuyruğu temsil eder.
 * Her altıgen, veri çekme ve dağıtma işlemlerinden sorumludur.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include "QueueBST.hpp"

class Hexagon
{
private:
    QueueBST queue;

public:
    Hexagon();

    QueueBST& getQueue();
    const QueueBST& getQueue() const;

    // removeIndex'teki ağacı postorder sök, değerleri diziye doldur
    int* extractBSTValues(int removeIndex, int& outCount);

    // values dizisini 6 BST'ye dağıt
    void distributeValues(int* values, int count);

    void clear();
};

#endif
