/**
* @file Utils.hpp
* @description SUtils namespace'i proje boyunca tekrar eden küçük yardımcı işlemleri toplar.
 * Amaç: Kod tekrarını azaltmak, okuma/formatlama işlemlerini tek bir yerde standardize etmektir.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace Utils
{
    // Baştaki ve sondaki boşlukları temizler
    std::string trim(const std::string& s);

    // String'i belirtilen genişliğe sabitle (sola yasla)
    std::string padRight(const std::string& s, int width);

    // String'i belirtilen genişliğe sabitle (ortala)
    std::string padCenter(const std::string& s, int width);

    // Sayı mı?
    bool isNumber(const std::string& s);

    
}

#endif