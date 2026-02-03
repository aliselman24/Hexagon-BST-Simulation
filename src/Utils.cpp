/**
* @file Utils.cpp
* @description SUtils namespace'i proje boyunca tekrar eden küçük yardımcı işlemleri toplar.
 * Amaç: Kod tekrarını azaltmak, okuma/formatlama işlemlerini tek bir yerde standardize etmektir.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#include "Utils.hpp"
#include <algorithm>
#include <cctype>



namespace Utils
{
    // Baştaki ve sondaki whitespace karakterlerini temizler.
    // Örnek: "   123  " -> "123"
    std::string trim(const std::string& s)
    {
        if (s.empty()) return s;

        size_t start = 0;
        while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
            start++;

        size_t end = s.size() - 1;
        while (end > start && std::isspace(static_cast<unsigned char>(s[end])))
            end--;

        return s.substr(start, end - start + 1);
    }

    // String uzunluğu width'ten küçükse sağa boşluk ekler.
    std::string padRight(const std::string& s, int width)
    {
        if ((int)s.length() >= width)
            return s;

        return s + std::string(width - s.length(), ' ');
    }

    // String'i belirtilen genişlikte ortalar (sol ve sağ padding).
    std::string padCenter(const std::string& s, int width)
    {
        if ((int)s.length() >= width)
            return s;

        int total = width - (int)s.length();
        int left = total / 2;
        int right = total - left;

        return std::string(left, ' ') + s + std::string(right, ' ');
    }

    // Tüm karakterleri rakam mı kontrol eder.
    bool isNumber(const std::string& s)
    {
        if (s.empty()) return false;

        for (char c : s)
        {
            if (!std::isdigit(static_cast<unsigned char>(c)))
                return false;
        }
        return true;
    }
}
