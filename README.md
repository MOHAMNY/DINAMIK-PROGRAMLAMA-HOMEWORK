# Makine Planlama Problemi - Minimum Süre Hesaplama

Bu proje, bir üretim hattında sıralı olarak yapılması gereken işlerin farklı makinelerde yapılma sürelerini ve makineler arası geçiş maliyetlerini göz önünde bulundurarak *minimum toplam süreyi* hesaplar.

## Problem Tanımı

- n adet iş sıralı olarak yapılmalıdır.
- Her iş m farklı makinede yapılabilir.
- Her işin her makinedeki süresi farklıdır (time[n][m]).
- Bir işten diğerine geçerken makine değiştiriliyorsa bir geçiş maliyeti vardır (cost[m][m]).
- Amaç: Tüm işleri minimum toplam sürede tamamlamak.

## Kullanılan Yöntem

Bu problem, *Matrix Chain Multiplication* probleminin genelleştirilmiş bir versiyonudur ve *Dinamik Programlama (Dynamic Programming)* ile çözülmektedir.

- dp[i][j]: i. işin j. makinede yapılması durumunda o ana kadarki minimum süredir.
- İlk iş için sadece işlem süreleri kullanılır.
- Diğer işler için tüm makinelerden olası geçişler ve maliyetler kontrol edilerek minimum süre güncellenir.

## Kodun Açıklaması

- min(int a, int b): Küçük olanı döndüren yardımcı fonksiyon.
- enKisaSüreyiHesapla(...): Asıl algoritmayı içeren fonksiyon.
- main(): Test verileriyle algoritmanın çalıştırılması.

## Örnek Girdi

```c
int time[3][3] = {
    {4, 2, 3},
    {2, 1, 3},
    {3, 2, 1}
};

int cost[3][3] = {
    {0, 1, 2},
    {1, 0, 2},
    {2, 1, 0}
};
```
## Örnek Çıktı
```
Minimum toplam süre: 6
