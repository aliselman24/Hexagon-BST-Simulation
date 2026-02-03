/**
* @file System.cpp
* @description System sınıfı, simülasyonun ana kontrol mekanizmasını oluşturur.
 * Altıgenlerin zigzag sıralamasını yönetir,
 * turları çalıştırır ve ekran çıktısını üretir.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#include "System.hpp"
#include "Utils.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <algorithm>
#include <windows.h> 

// İmleci gizleme fonksiyonu (Görsellik için)
void hideCursor()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

System::System(Hexagon* arr, int count)
{
    hexagons = arr;
    hexCount = count;
    cols = 6; 
    rows = (hexCount + cols - 1) / cols; 

    zigzagOrder = new int[hexCount];
    buildZigzagOrder();
    
    hideCursor();
    // Başlangıç temizliği
    system("cls");
}

System::~System()
{
    delete[] zigzagOrder;
}

// Altıgenlerin ekranda zigzag (yılan) düzeninde
// gezilmesini sağlayan indeks dizisini oluşturur.
void System::buildZigzagOrder()
{
    int idx = 0;
    for (int r = 0; r < rows; ++r)
    {
        if (r % 2 == 0) 
        {
            for (int c = 0; c < cols; ++c)
            {
                int val = r * cols + c;
                if (val < hexCount) zigzagOrder[idx++] = val;
            }
        }
        else 
        {
            for (int c = cols - 1; c >= 0; --c)
            {
                int val = r * cols + c;
                if (val < hexCount) zigzagOrder[idx++] = val;
            }
        }
    }
}

int System::getNextHexIndex(int currentIndex) const
{
    for (int i = 0; i < hexCount; ++i)
    {
        if (zigzagOrder[i] == currentIndex)
        {
            int nextPos = (i + 1) % hexCount; 
            return zigzagOrder[nextPos];
        }
    }
    return -1;
}

void System::run(int tourCount)
{
    // Döngü her döndüğünde printScreen çağrılacak.
    // printScreen içinde cls olduğu için temizlenip basılacak..
    for (int t = 1; t <= tourCount; ++t)
    {
        runSingleTour(t);          
        printScreen(t, tourCount); 
    }
}

// Tek bir turu çalıştırır.
// Tek turlarda: kuyruk başındaki BST,
// Çift turlarda: en yüksek yüksekliğe sahip BST sökülür.
// Sökülen değerler bir sonraki altıgene dağıtılır.
void System::runSingleTour(int tourNumber)
{
    if (hexCount == 0) return;
    
    bool isOdd = (tourNumber % 2 == 1); 

    int** extractedValues = new int*[hexCount];
    int* extractedCounts = new int[hexCount];

    // AŞAMA 1: VERİLERİ ÇEK
    for (int i = 0; i < hexCount; ++i)
    {
        int srcIdx = zigzagOrder[i];
        Hexagon& srcHex = hexagons[srcIdx];
        QueueBST& q = srcHex.getQueue();
        q.ensureSixTrees();

        int removeIdx = 0; 

        if (!isOdd) 
        {
            int bestH = -1;
            int bestIndex = 0; 
            for (int k = 0; k < 6; ++k)
            {
                BST* t = q.at(k);
                if (!t || t->getRootData() == 0) continue; 
                int h = t->getHeight();
                
                if (h > bestH)
                {
                    bestH = h;
                    bestIndex = k;
                }
            }
            removeIdx = bestIndex;
        }
        
        extractedValues[srcIdx] = srcHex.extractBSTValues(removeIdx, extractedCounts[srcIdx]);
    }

    // AŞAMA 2: VERİLERİ DAĞIT
    for (int i = 0; i < hexCount; ++i)
    {
        int srcIdx = zigzagOrder[i];
        int* vals = extractedValues[srcIdx];
        int cnt = extractedCounts[srcIdx];

        if (vals && cnt > 0)
        {
            int targetIdx = getNextHexIndex(srcIdx);
            hexagons[targetIdx].distributeValues(vals, cnt);
            delete[] vals;
        }
        else if (vals) delete[] vals;
    }

    delete[] extractedValues;
    delete[] extractedCounts;
}


// Bir altıgen için oran hesaplar.
// Oran = kuyruk başındaki BST'nin kök değeri /
//        en yüksek öncelikli BST'nin kök değeri
int System::computeHexRatio(const Hexagon& hex) const
{
    const QueueBST& q = hex.getQueue();
    BST* front = q.at(0);
    if (!front || front->getRootData() == 0) return -1; 

    BST* priority = nullptr;
    int bestH = -1;

    for (int i = 0; i < 6; ++i)
    {
        BST* t = q.at(i);
        if (!t || t->getRootData() == 0) continue; 
        int h = t->getHeight();

        if (h > bestH)
        {
            bestH = h;
            priority = t;
        }
    }
    
    if (!priority) return -1; 
    int a = front->getRootData();
    int b = priority->getRootData();
    if (b == 0) return 0; 
    return a / b;
}


// Sistemin mevcut durumunu ekrana basar.
// Altıgenler zigzag düzende gösterilir.
// Boş durumlar '--' ile ifade edilir.
void System::printScreen(int tour, int totalTours, int currentLine, int totalLines) const
{
    
    system("cls");

    if (tour == 0)
    {
        std::cout << "VERI YUKLENIYOR... Satir : " << currentLine << " / " << totalLines << "          \n";
    }
    else
    {
        std::cout << "TUR " << tour << " / " << totalTours 
                  << " | Toplam Altigen: " << hexCount << "          \n";
    }

    std::cout << "--------------------------------------\n";

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            int pos = r * cols + c;
            
            if (pos >= hexCount)
            {
                std::cout << std::setw(5) << ""; 
                continue;
            }

            int idx = zigzagOrder[pos];
            int ratio = computeHexRatio(hexagons[idx]);

            if (ratio < 0) 
            {
                std::cout << std::setw(5) << "--"; 
            }
            else
            {
                std::cout << std::setw(5) << ratio;
            }
        }
        std::cout << "      \n"; 
    }
}