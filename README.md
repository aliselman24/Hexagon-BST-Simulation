# Hexagon BST Simulation

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B)
![Data Structures](https://img.shields.io/badge/Topic-Binary%20Search%20Trees-green?style=for-the-badge)
![Algorithm](https://img.shields.io/badge/Algorithm-Zigzag%20Traversal-orange?style=for-the-badge)

## 📝 Proje Hakkında (About)
Bu proje, **Binary Search Tree (BST)** ve **Queue (Kuyruk)** veri yapılarını iç içe kullanarak karmaşık bir veri akış simülasyonu gerçekleştiren bir C++ uygulamasıdır. 

Sistem, `data.txt` dosyasından okunan verileri altıgen hücrelere (Hexagon) yerleştirir. Her altıgen, içinde 6 adet BST barındıran bir kuyruk yapısına sahiptir. Kullanıcı tarafından belirlenen tur sayısı boyunca, özel algoritmalarla (Zigzag dolaşım, Postorder silme) altıgenler arasında veri transferi sağlanır.

## 🚀 Teknik Özellikler (Technical Highlights)

Proje, standart veri yapılarının ötesinde, bu yapıların birbirleriyle etkileşimini yönetir:

* **Nested Data Structures (İç İçe Yapılar):** * Her `Hexagon` nesnesi, sabit boyutlu bir `Queue` yönetir.
    * Her `Queue`, 6 adet dinamik `Binary Search Tree (BST)` işaretçisi tutar.
* **Zigzag Mapping Algorithm:** 2 boyutlu ızgara üzerindeki altıgenler, satır bazlı "Yılan (Zigzag)" algoritması ile 1 boyutlu bir diziye haritalanarak veri akış sırası belirlenir.
* **Advanced BST Operations:** * **Extract Postorder:** Ağaçtan veri çekilirken *Postorder* (Sol-Sağ-Kök) sırası kullanılır ve çekilen düğümler bellekten silinir.
    * **Dynamic Height Calculation:** Simülasyon kararları için ağaçların anlık yükseklikleri hesaplanır.
* **Round-Robin Distribution:** Bir altıgenden çıkan veriler, hedef altıgenin içindeki 6 ağaca sırasıyla (dairesel döngü) dağıtılır.

## 🎮 Simülasyon Mantığı (Simulation Logic)

Sistem turlara (turns) dayalı çalışır ve her turda veri akışı şu kurallara göre gerçekleşir:

1. **Hedef Belirleme:** Veriler, Zigzag sırasına göre bir sonraki altıgene aktarılır.
2. **Veri Çıkarma (Extraction):**
    * **Tek Sayılı Turlar (1, 3, 5...):** Kuyruğun en başındaki (Index 0) BST boşaltılır.
    * **Çift Sayılı Turlar (2, 4, 6...):** Kuyruktaki *en yüksek (height)* BST bulunur ve boşaltılır.
3. **Veri Ekleme:** Çıkarılan veriler hedef altıgene `insert` edilirken ağaç kuralları (küçükler sola, büyükler sağa) korunur.

## 📷 Ekran Görüntüsü (Screenshot)

<img width="853" height="326" alt="image" src="https://github.com/user-attachments/assets/81488d0e-677d-4aa6-8308-5ffcaecf3996" />
<img width="853" height="326" alt="image" src="https://github.com/user-attachments/assets/81488d0e-677d-4aa6-8308-5ffcaecf3996" />


## 🛠 Kurulum ve Derleme (Installation)

Proje Windows ortamı için (`<windows.h>`) optimize edilmiştir.

**Derleme (G++):**
```bash
g++ Main.cpp System.cpp Hexagon.cpp QueueBST.cpp BST.cpp Node.cpp FileReader.cpp Utils.cpp -o HexSimulation
