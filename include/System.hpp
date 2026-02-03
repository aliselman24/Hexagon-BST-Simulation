/**
* @file System.hpp
* @description System sınıfı, simülasyonun ana kontrol mekanizmasını oluşturur.
 * Altıgenlerin zigzag sıralamasını yönetir,
 * turları çalıştırır ve ekran çıktısını üretir.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Hexagon.hpp"

class System
{
private:
    Hexagon* hexagons;
    int hexCount;
    int rows;
    int cols;
    int* zigzagOrder;

    void buildZigzagOrder();
    int computeHexRatio(const Hexagon& hex) const;
    int getNextHexIndex(int currentIndex) const;

public:
    System(Hexagon* arr, int count);
    ~System();

    void run(int tourCount);
    void runSingleTour(int tourNumber);

    // Yükleme ekranı ve Tur bilgisi için parametreler
    void printScreen(int tour, int totalTours = 0, int currentLine = 0, int totalLines = 0) const;
};

#endif