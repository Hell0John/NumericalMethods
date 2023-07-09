#include <stdio.h>

#include <math.h>

#define MAX 50
#define PI 3.141592
double fonksiyonuHesapla(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX], double x) {
  int i = 0, j;
  double terim, sonuc = 0, ustelus;
  while (polinom[0][i] != 0) { //polinom kismi hesaplar
    terim = pow(x, polinom[1][i]);
    terim = terim * polinom[0][i];
    sonuc = terim + sonuc;
    i = ++i;
  } //polinom kismi hesaplar
  i = 0;
  while (ustel[0][i] != 0) { //ustel kismi hesapla
    terim = 1;
    ustelus = 0;
    terim = pow(x, ustel[3][i]);
    terim = terim * ustel[2][i];
    ustelus = terim + ustelus;
    sonuc = sonuc + (ustel[0][i] * pow(ustel[1][i], ustelus));
    i = ++i;
  } //ustel kismi hesapla
  i = 0;
  while (trigo[0][i] != 0) { //trigonometrik k�sm� hesaplar
    terim = pow(x, trigo[3][i]);
    terim = terim * trigo[2][i];
    if (trigo[0][i] == 1) {
      terim = pow(sin(terim), trigo[4][i]);
    } else if (trigo[0][i] == 2) {
      terim = pow(cos(terim), trigo[4][i]);
    } else if (trigo[0][i] == 3) {
      terim = pow(tan(terim), trigo[4][i]);
    } else if (trigo[0][i] == 4) {
      terim = pow(1 / tan(terim), trigo[4][i]);
    }
    sonuc = sonuc + (terim * trigo[1][i]);
    i = ++i;
  } //trigonometrik k�sm� hesaplar
  i = 0;
  while (terstrigo[0][i] != 0) { //terstrigonometrik k��m� hesaplar
    terim = pow(x, terstrigo[3][i]);
    terim = terim * terstrigo[2][i];
    if (terstrigo[0][i] == 1) {
      terim = pow(asin(terim), terstrigo[4][i]);
    } else if (terstrigo[0][i] == 2) {
      terim = pow(acos(terim), terstrigo[4][i]);
    } else if (terstrigo[0][i] == 3) {
      terim = pow(atan(terim), terstrigo[4][i]);
    } else if (terstrigo[0][i] == 4) {
      terim = pow(atan(1 / terim), terstrigo[4][i]);
    }
    terim = (terim / 180) * PI;
    sonuc = sonuc + (terim * terstrigo[1][i]);
    i = ++i;
  } //terstrigonometrik k�sm� hesaplar	
  i = 0;
  while (logaritmik[0][i] != 0) {
    terim = pow(x, logaritmik[3][i]);
    terim = terim * logaritmik[2][i];
    terim = log(terim) / log(logaritmik[0][i]);
    terim = pow(terim, logaritmik[4][i]);
    terim = terim * logaritmik[0][i];
    sonuc = sonuc + terim;
    i = ++i;
  }

  return sonuc;
}
void fonksiyonuAl(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX]) {
  int count, control, polElemanSayisi, i;
  printf("\nFonksiyonunuzda polinom kisim bulunuyorsa 1 bulunmuyorsa 2 giriniz:");
  scanf("%d", & control);
  if (control == 1) { //Polinom kisim alma
    printf("\nPolinom kismin kac elemandan olustugunu giriniz:");
    scanf("%d", & polElemanSayisi);
    count = 1;
    for (i = 0; i < polElemanSayisi; i++) {
      printf("\n%d. elemanin tabanini giriniz:", count);
      scanf("%lf", & polinom[0][i]);
      printf("\n%d. elemanin ussunu giriniz:", count);
      scanf("%lf", & polinom[1][i]);
      count = ++count;
    }
    printf("\n\nFonksiyonunuzun eklenen kisim:\n");
    i = 0;
    while (polinom[0][i] != 0) {
      if (i == 0) {
        printf("%lf*x^%lf", polinom[0][i], polinom[1][i]);
      } else {
        printf(" + %lf*x^%lf", polinom[0][i], polinom[1][i]);
      }
      i = ++i;
    }
  } //Polinom kisim alma
  printf("\nFonksiyonunuzda ustel fonksiyonlu kisim bulunuyorsa 1 bulunmuyorsa 2 giriniz:");
  scanf("%d", & control);
  if (control == 1) { //ustel fonksiyonlu kisim alma
    printf("\nUstel fonksiyonlu kismin kac elemandan olustugunu giriniz:");
    scanf("%d", & polElemanSayisi);
    count = 1;
    for (i = 0; i < polElemanSayisi; i++) {
      printf("\n%d. elemanin katsayisini giriniz:(katsayi*ustelifadenintabani^(x'in katsayisi*x^x'in derecesi))", count);
      scanf("%lf", & ustel[0][i]);
      printf("\n%d. elemanin ustel ifadesinin tabanini giriniz:(katsayi*ustelifadenintabani^(x'in katsayisi*x^x'in derecesi))", count);
      scanf("%lf", & ustel[1][i]);
      printf("\n%d. elemanda x'in katsayisini giriniz:(katsayi*ustelifadenintabani^(x'in katsayisi*x^x'in derecesi))", count);
      scanf("%lf", & ustel[2][i]);
      printf("\n%d. elemanda x'in derecesini giriniz:(katsayi*ustelifadenintabani^(x'in katsayisi*x^x'in derecesi))", count);
      scanf("%lf", & ustel[3][i]);
      count = ++count;
    }
    printf("\n\nFonksiyonunuza eklenen kisim:\n");
    i = 0;
    while (ustel[0][i] != 0) {
      if (i == 0) {
        printf("%lf*%lf^(%lf*x^%lf)", ustel[0][i], ustel[1][i], ustel[2][i], ustel[3][i]);
      } else {
        printf(" + %lf*%lf^(%lf*x^%lf)", ustel[0][i], ustel[1][i], ustel[2][i], ustel[3][i]);
      }
      i = ++i;
    }
  } //ustel fonksiyon alma
  printf("\nFonksiyonunuzda trigonometrik ifadeli kisim bulunuyorsa 1 bulunmuyorsa 2 giriniz:");
  scanf("%d", & control);
  if (control == 1) { //Trigonometrik kisim alma
    printf("\nTrigonometrik ifadeli kismin kac elemandan olustugunu giriniz:");
    scanf("%d", & polElemanSayisi);
    count = 1;
    for (i = 0; i < polElemanSayisi; i++) {
      printf("\n%d. elemanin trigonometrik kisminin tipini giriniz:(sin:1,cos:2,tan:3,cot:4))", count);
      scanf("%lf", & trigo[0][i]);
      printf("\n%d. elemanin trigonometrik kisminin katsayisini giriniz:(katsayi*(sin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & trigo[1][i]);
      printf("\n%d. elemanda x'in katsayisini giriniz:(katsayi*(sin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & trigo[2][i]);
      printf("\n%d. elemanda x'in derecesini giriniz:(katsayi*(sin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & trigo[3][i]);
      printf("\n%d. elemanda trigonometrik kismin ussunu giriniz:(katsayi*(sin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & trigo[4][i]);
      count = ++count;
    }
    printf("\n\nFonksiyonunuza eklenen kisim:\n");
    i = 0;
    while (trigo[0][i] != 0) {
      if (i == 0) {
        if (trigo[0][i] == 1) {
          printf("%lf*(sin^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        } else if (trigo[0][i] == 2) {
          printf("%lf*(cos^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        } else if (trigo[0][i] == 3) {
          printf("%lf*(tan^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        } else if (trigo[0][i] == 4) {
          printf("%lf*(cot^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        }
      } else {
        if (trigo[0][i] == 1) {
          printf(" + %lf*(sin^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        } else if (trigo[0][i] == 2) {
          printf(" + %lf*(cos^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        } else if (trigo[0][i] == 3) {
          printf(" + %lf*(tan^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        } else if (trigo[0][i] == 4) {
          printf("+ %lf*(cot^(%lf*x^%lf))^%lf)", trigo[1][i], trigo[2][i], trigo[3][i], trigo[4][i]);
        }
      }
      i = ++i;
    }
  } //Trigonometrik kisim alma
  printf("\nFonksiyonunuzda ters trigonometrik ifadeli kisim bulunuyorsa 1 bulunmuyorsa 2 giriniz:");
  scanf("%d", & control);
  if (control == 1) { //ters Trigonometrik kisim alma
    printf("\nTrigonometrik ifadeli kismin kac elemandan olustugunu giriniz:");
    scanf("%d", & polElemanSayisi);
    count = 1;
    for (i = 0; i < polElemanSayisi; i++) {
      printf("\n%d. elemanin terstrigonometrik kisminin tipini giriniz:(arcsin:1,arccos:2,arctan:3,arccot:4))", count);
      scanf("%lf", & terstrigo[0][i]);
      printf("\n%d. elemanin terstrigonometrik kisminin katsayisini giriniz:(katsayi*(arcsin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & terstrigo[1][i]);
      printf("\n%d. elemanda x'in katsayisini giriniz:(katsayi*(arcsin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & terstrigo[2][i]);
      printf("\n%d. elemanda x'in derecesini giriniz:(katsayi*(arcsin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & terstrigo[3][i]);
      printf("\n%d. elemanda terstrigonometrik kismin ussunu giriniz:(katsayi*(arcsin(x'in katsayisi*x^x'in derecesi))^trigonometrikifadeninussu)", count);
      scanf("%lf", & terstrigo[4][i]);
      count = ++count;
    }
    printf("\n\nFonksiyonunuza eklenen kisim:\n");
    i = 0;
    while (terstrigo[0][i] != 0) {
      if (i == 0) {
        if (terstrigo[0][i] == 1) {
          printf("%lf*(arcsin^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        } else if (terstrigo[0][i] == 2) {
          printf("%lf*(arccos^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        } else if (terstrigo[0][i] == 3) {
          printf("%lf*(arctan^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        } else if (terstrigo[0][i] == 4) {
          printf("%lf*(arccot^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        }
      } else {
        if (terstrigo[0][i] == 1) {
          printf(" + %lf*(arcsin^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        } else if (terstrigo[0][i] == 2) {
          printf(" + %lf*(arccos^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        } else if (terstrigo[0][i] == 3) {
          printf(" + %lf*(arctan^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        } else if (terstrigo[0][i] == 4) {
          printf("+ %lf*(arccot^(%lf*x^%lf))^%lf)", terstrigo[1][i], terstrigo[2][i], terstrigo[3][i], terstrigo[4][i]);
        }
      }
      i = ++i;
    }
  } //ters Trigonometrik kisim alma
  printf("\nFonksiyonunuzda logaritmik ifadeli kisim bulunuyorsa 1 bulunmuyorsa 2 giriniz:");
  scanf("%d", & control);
  if (control == 1) { //logaritmik
    printf("\nLogaritmik ifadeli kismin kac elemandan olustugunu giriniz:");
    scanf("%d", & polElemanSayisi);
    count = 1;
    for (i = 0; i < polElemanSayisi; i++) {
      printf("\n%d. elemanin logaritma tabanini giriniz:(katsayi*(logtabani(x'in katsayisi*x^x'in derecesi))^logifadeninussu)", count);
      scanf("%lf", & logaritmik[0][i]);
      printf("\n%d. elemanin logaritmik kisminin katsayisini giriniz:(katsayi*(logtabani(x'in katsayisi*x^x'in derecesi))^logifadeninussu)", count);
      scanf("%lf", & logaritmik[1][i]);
      printf("\n%d. elemanda x'in katsayisini giriniz:(katsayi*(logtabani(x'in katsayisi*x^x'in derecesi))^logifadeninussu)", count);
      scanf("%lf", & logaritmik[2][i]);
      printf("\n%d. elemanda x'in derecesini giriniz:(katsayi*(logtabani(x'in katsayisi*x^x'in derecesi))^logifadeninussu)", count);
      scanf("%lf", & logaritmik[3][i]);
      printf("\n%d. elemanda logaritmik kismin ussunu giriniz:(katsayi*(logtabani(x'in katsayisi*x^x'in derecesi))^logifadeninussu)", count);
      scanf("%lf", & logaritmik[4][i]);
      count = ++count;
    }
    printf("\n\nFonksiyonunuza eklenen kisim:\n");
    i = 0;
    while (logaritmik[0][i] != 0) {
      if (i == 0) {
        printf("%lf*(log%lf(%lf*x^%lf))^%lf)", logaritmik[1][i], logaritmik[0][i], logaritmik[2][i], logaritmik[3][i], logaritmik[4][i]);
      } else {
        printf(" + %lf*(log%lf(%lf*x^%lf))^%lf)", logaritmik[1][i], logaritmik[0][i], logaritmik[2][i], logaritmik[3][i], logaritmik[4][i]);
      }
      i = ++i;
    }
  } //logaritmik				

} //fonksiyonu al
void bisection(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX]) {
  double ust, alt, hata, ustDeger, altDeger, hataMiktari, ortaDeger;
  int iterasyon, i, j, k, asd = 3;
  do {
    printf("\nAraligin ust ve alt x degerlerini giriniz(Carpimlari negatif olmali.)\nUst sinir:");
    scanf("%lf", & ust);
    printf("\nAlt sinir:");
    scanf("%lf", & alt);
    if (fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, ust) * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, alt) >= 0) {
      printf("\nCarpimlar negatif degil. Tekrar giriniz.");
    }
  } while (fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, ust) * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, alt) >= 0);
  printf("\nIstediginiz maksimum hatayi giriniz:");
  scanf("%lf", & hata);
  printf("\nMaksimum iterasyon sayisini giriniz:");
  scanf("%d", & iterasyon);
  for (i = 0; i < iterasyon; i++) {
    k = 1;
    printf("\n\n%d. iterasyon:\n\n", i + 1);
    ustDeger = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, ust);
    altDeger = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, alt);
    ortaDeger = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, (ust + alt) / 2);
    printf("Ust Sinir:%lf\nAlt Sinir:%lf\nf(ust)=%lf\nf(alt)=%lf", ust, alt, ustDeger, altDeger);
    printf("\nOrta:%lf\nf(orta)=%lf", (ust + alt) / 2, ortaDeger);
    for (j = 0; j < i + 1; j++) {
      k = k * 2;
    }
    hataMiktari = (ust - alt) / k;
    printf("\n%d iterasyondaki hata:%lf", i + 1, fabs(hataMiktari));
    if (fabs(hataMiktari) <= hata) {
      printf("\n%lf(%d. iterasyondaki hata)<=%lf oldugundan kok %lf'dir.", fabs(hataMiktari), i + 1, hata, (ust + alt) / 2);
      i = iterasyon;
    } else {
      if (ortaDeger * altDeger < 0) {
        ust = (ust + alt) / 2;
      } else {
        alt = (ust + alt) / 2;
      }
    }

  }
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }

} //bisection
void regulaFalsi(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX]) {
  double ust, alt, orta, hata, ustDeger, altDeger, hataMiktari, ortaDeger;
  int iterasyon, i, j, k, asd = 3;
  do {
    printf("\nAraligin ust ve alt x degerlerini giriniz(Carpimlari negatif olmali.)\nUst sinir:");
    scanf("%lf", & ust);
    printf("\nAlt sinir:");
    scanf("%lf", & alt);
    if (fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, ust) * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, alt) >= 0) {
      printf("\nCarpimlar negatif degil. Tekrar giriniz.");
    }
  } while (fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, ust) * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, alt) >= 0);
  printf("\nIstediginiz maksimum hatayi giriniz:");
  scanf("%lf", & hata);
  printf("\nMaksimum iterasyon sayisini giriniz:");
  scanf("%d", & iterasyon);
  for (i = 0; i < iterasyon; i++) {
    k = 1;
    printf("\n%d. iterasyon:\n", i + 1);
    ustDeger = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, ust);
    altDeger = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, alt);
    orta = (ustDeger * alt - altDeger * ust) / (ustDeger - altDeger);
    ortaDeger = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, orta);
    printf("Ust sinir:%lf\nAlt sinir:%lf\nAra deger:%lf\nf(ust)=%lf\nf(alt)=%lf\nf(ara)=%lf", ust, alt, orta, ustDeger, altDeger, ortaDeger);
    for (j = 0; j < i + 1; j++) {
      k = k * 2;
    }
    hataMiktari = (ust - alt) / k;
    printf("\n%d iterasyondaki hata:%lf", i + 1, fabs(hataMiktari));
    if (fabs(hataMiktari) <= hata) {
      printf("\n%lf(%d. iterasyondaki hata)<=%lf oldugundan kok %lf'dir.", fabs(hataMiktari), i + 1, hata, orta);
      i = iterasyon;
    } else {
      if (ortaDeger * altDeger < 0) {
        ust = orta;
      } else {
        alt = orta;
      }
    }

  } //for
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //regulafalsi
double polinomTurev(double polinom[2][MAX], double x) {
  int i = 0;
  double terim, sonuc = 0;
  while (polinom[0][i] != 0) {
    if (polinom[1][i] == 0) {
      terim = 0;
    } else {
      terim = pow(x, polinom[1][i] - 1);
      terim = terim * polinom[1][i] * polinom[0][i];
    }
    sonuc = sonuc + terim;
    i = ++i;
  }
  return sonuc;
} //polinom turev
void newtonRaphson(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX]) {
  double x, hata, iterasyon, xDeger, turev, x1;
  int i, asd = 3;
  printf("\nBaslangic x degerini giriniz:");
  scanf("%lf", & x);
  printf("\nMaksimum hatayi giriniz:");
  scanf("%lf", & hata);
  printf("\nMaksimum iterasyon sayisini giriniz:");
  scanf("%lf", & iterasyon);
  for (i = 0; i < iterasyon; i++) {
    printf("\n%d. iterasyon:\n", i + 1);
    xDeger = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, x);
    turev = polinomTurev(polinom, x);
    x1 = x - (xDeger / turev);
    printf("xn=%lf\nf(xn)=%lf\nf'(xn)=%lf\nxn+1=%lf\n", x, xDeger, turev, x1);

    if (fabs(x1 - x) <= hata) {
      printf("\n%lf(%d. iterasyondaki hata)<=%lf oldugundan kok %lf'dir.", fabs(x1 - x), i + 1, hata, x1);
      i = iterasyon;
    } else {
      x = x1;
    }
  }
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //newtonraphson
void matrisTersi() {
  double matris[MAX][MAX], k;
  int i, j, N, l, asd = 3;
  printf("NxN lik matrisin N degerini giriniz:");
  scanf("%d", & N);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("matris[%d][%d] :", i + 1, j + 1);
      scanf("%lf", & matris[i][j]);
    }
  }
  for (i = 0; i < N; i++) {
    for (j = N; j < 2 * N; j++) {
      if (i == j - N) {
        matris[i][j] = 1;
      } else {
        matris[i][j] = 0;
      }
    }
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i != j) {
        k = matris[j][i] / matris[i][i];
        for (l = 0; l < 2 * N; l++) {
          matris[j][l] = matris[j][l] - k * matris[i][l];
        }
      }
    }
  }
  for (i = 0; i < N; i++) {
    for (j = N; j < 2 * N; j++) {
      matris[i][j] = matris[i][j] / matris[i][i];
    }
  }
  for (i = 0; i < N; i++) {
    for (j = N; j < 2 * N; j++) {
      printf("%lf", matris[i][j]);
    }
    printf("\n");
  }
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //matris tersi
gaussEliminasyon() {
  double matris[MAX][MAX], k;
  int i, j, l, N, asd = 3;
  printf("NxN lik matrisin N degerini giriniz:");
  scanf("%d", & N);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("matris[%d][%d] :", i + 1, j + 1);
      scanf("%lf", & matris[i][j]);
    }
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%lf ", matris[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < N; i++) {
    printf("C[%d] :", i + 1);
    scanf("%lf", & matris[i][N]);
    printf("\n");
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i != j) {
        k = matris[j][i] / matris[i][i];
        for (l = 0; l <= N; l++) {
          matris[j][l] = matris[j][l] - k * matris[i][l];
        }
      }
    }
  }
  for (i = 0; i < N; i++) {
    for (j = N; j <= N; j++) {
      matris[i][j] = matris[i][j] / matris[i][i];
    }
  }
  for (i = 0; i < N; i++) {
    printf("x%d=%lf\n", i + 1, matris[i][N]);
  }
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //gaus eliminasyon
void gaussSeidal() {
  int i, j, N, l, iterasyon, sayac, asd = 3;
  double matris[MAX][MAX], bilinmeyen[MAX], k, hata, terim, hataMiktari;
  printf("\nBilinmeyen sayisini giriniz:");
  scanf("%d", & N);
  printf("\nMaksimum hatayi giriniz:");
  scanf("%lf", & hata);
  printf("\nMaksimum iterasyon miktarini giriniz:");
  scanf("%d", & iterasyon);
  printf("\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("matris[%d][%d] :", i + 1, j + 1);
      scanf("%lf", & matris[i][j]);
    }
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%lf ", matris[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < N; i++) {
    printf("\nC(%d) degerini giriniz(ornek:2x+y+z=C):", i + 1);
    scanf("%lf", & matris[i][N]);
  }
  for (i = 0; i < N; i++) {
    printf("\nBilinmeyenlere verilecek degerleri giriniz:");
    scanf("%lf", & bilinmeyen[i]);
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N - 1; j++) {
      if (fabs(matris[i][i]) < fabs(matris[j + 1][i])) {
        for (l = 0; l <= N; l++) {
          k = matris[j][l];
          matris[j][l] = matris[j + 1][l];
          matris[j + 1][l] = k;
        }

      }
    }
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j <= N; j++) {
      printf(" %lf", matris[i][j]);
    }
    printf("\n");
  }
  sayac = 0;
  hataMiktari = hata + 1;
  while (sayac < iterasyon && hataMiktari > hata) {
    printf("\n%d. Iterasyon : ", sayac + 1);
    for (i = 0; i < N; i++) {
      terim = 0;
      for (j = 0; j < N; j++) {

        if (i != j) {
          terim = matris[i][j] * bilinmeyen[j] + terim;
        }
      }
      terim = matris[i][N] - terim;
      if (hataMiktari > fabs(bilinmeyen[i] - (terim / matris[i][i]))) {
        hataMiktari = fabs(bilinmeyen[i] - (terim / matris[i][i]));
      }
      bilinmeyen[i] = terim / matris[i][i];
      printf("\nx%d: %lf", i + 1, bilinmeyen[i]);

    }
    sayac = ++sayac;
  }
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //gausseidal
void sayisalTurev(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX]) {
  double h, x, sonuc;
  int tur, asd = 3;
  printf("\nAlmak istediginiz sayisal turev turunu seciniz(Ileri:1,Geri:2,Merkezi:3):");
  scanf("%d", & tur);
  printf("\nh degerini giriniz:");
  scanf("%lf", & h);
  printf("\nx degerini giriniz:");
  scanf("%lf", & x);
  if (tur == 1) {
    sonuc = (fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, x + h) - fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, x)) / h;
    printf("\nIleri turev degeri: %lf", sonuc);
  } else if (tur == 2) {
    sonuc = (fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, x) - fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, x - h)) / h;
    printf("\nGeri turev degeri: %lf", sonuc);
  } else if (tur == 3) {
    sonuc = (fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, x + (h / 2)) - fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, x - (h / 2))) / h;
    printf("\nMerkezi turev degeri: %lf", sonuc);
  }
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //sayisal turev
void simpson(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX]) {
  int tur, i, asd = 3;
  double baslangic, bitis, h, k, n, sonuc = 0;
  printf("\nIstediginiz simpson kuralini giriniz(1/3):1,(3/8):2");
  scanf("%d", & tur);
  printf("\nBaslangic degerini giriniz:");
  scanf("%lf", & baslangic);
  printf("\nBitis degerini giriniz:");
  scanf("%lf", & bitis);
  printf("\nKac parcaya bolunecegini giriniz:");
  scanf("%lf", & n);
  h = (bitis - baslangic) / n;
  if (tur == 1) {

    sonuc = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, bitis) + fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, baslangic);
    for (i = 1; i <= n - 1; i++) {
      k = baslangic + i * h;
      if (i % 2 == 0) {
        sonuc = sonuc + 2 * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, k);
      } else {
        sonuc = sonuc + 4 * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, k);
      }
    }
    sonuc = sonuc * h / 3;
  } else if (tur == 2) {
    sonuc = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, bitis) + fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, baslangic);
    for (i = 1; i <= n - 1; i++) {
      k = baslangic + i * h;
      if (i % 3 == 0) {
        sonuc = sonuc + 2 * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, k);
      } else {
        sonuc = sonuc + 3 * fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, k);
      }
    }
    sonuc = sonuc * h * 3 / 8;
  }
  printf("\nSonuc: %lf", sonuc);
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //simpson
void trapez(double polinom[2][MAX], double ustel[4][MAX], double logaritmik[5][MAX], double trigo[5][MAX], double terstrigo[5][MAX]) {
  double baslangic, bitis, h, sonuc, k;
  int i, n, asd = 3;
  printf("\nBaslangic degerini giriniz:");
  scanf("%lf", & baslangic);
  printf("\nBitis degerini giriniz:");
  scanf("%lf", & bitis);
  printf("\nKac parcaya bolunecegini yaziniz:");
  scanf("%d", & n);
  h = (bitis - baslangic) / n;
  sonuc = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, baslangic) + fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, bitis);
  k = baslangic + h;
  while (k < bitis) {
    sonuc = fonksiyonuHesapla(polinom, ustel, logaritmik, trigo, terstrigo, k) + sonuc;
    k = k + h;
  }
  sonuc = sonuc * h;
  printf("\nSonuc: %lf", sonuc);
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //trapez
void enterpolasyon() {
  int i, j, asd = 3;
  double matris[MAX][MAX] = {
    0
  }, h, n, sabit, x, sonuc, sonsonuc = 0;
  printf("\nx degerlerinin baslangic degerini giriniz:\n");
  scanf("%lf", & matris[0][0]);
  printf("\nx degerleri arasindaki farki giriniz:\n");
  scanf("%lf", & h);
  printf("\nKac adet deger girilecegini giriniz:\n");
  scanf("%lf", & n);
  printf("f(%lf):\n", matris[0][0]);
  scanf("%lf", & matris[0][1]);
  for (i = 1; i < n; i++) {
    matris[i][0] = matris[i - 1][0] + h;
    printf("\nf(%lf):\n", matris[i][0]);
    scanf("%lf", & matris[i][1]);
  }
  for (i = 2; i <= n; i++) {
    for (j = 0; j <= n - i; j++)
      matris[j][i] = matris[j + 1][i - 1] - matris[j][i - 1];
  }
  printf("\nx degeri giriniz:");
  scanf("%lf", & x);
  printf("\nFonksiyon: %lf ", matris[0][1]);
  i = 2;
  while (matris[0][i] != 0) {
    printf(" +(");
    for (j = 1; j < i; j++) {
      if (matris[j - 1][0] != 0) {
        printf(" (x-%lf)", matris[j - 1][0]);
      } else {
        printf(" (x)");
      }
    }
    if (i - 1 != 1) {

      printf(" ) / %d!*%lf^%d", i - 1, h, i - 1);
    } else {
      printf(" ) / %lf", h);
    }
    i = ++i;
  }

  i = 2; //hesaplama
  while (matris[0][i] != 0) {
    sonuc = 1;
    sabit = 1;
    for (j = 1; j < i; j++) { //bolunen kisim
      sabit = j * sabit * h;
    }
    for (j = 1; j < i; j++) {
      sonuc = (x - matris[j - 1][0]) * sonuc;
    }
    sonuc = matris[0][i] * sonuc;
    sonuc = sonuc / sabit;
    sonsonuc = sonuc + sonsonuc;
    i = ++i;
  }
  sonsonuc = sonsonuc + matris[0][1];
  printf("\n\nSonuc : %lf", sonsonuc);
  while (asd != 1) {

    printf("\nMenuye donmek icin 1 giriniz:");
    scanf("%d", & asd);
  }
} //enterpolasyon

int main() {
  double polinom[2][MAX] = {
    0
  }, ustel[4][MAX] = {
    0
  }, logaritmik[5][MAX] = {
    0
  }, trigo[5][MAX] = {
    0
  }, terstrigo[5][MAX] = {
    0
  };
  int menu = 1, i, j;
  double x = 3.5, y = PI / 3, z = 0.5, t = 0, val = 180 / PI, m = 0.9; //fonksiyonu hesaplamay� deneme de�erleri
  while (menu != 0) {
    for (i = 0; i < 2; i++) {
      for (j = 0; j < MAX; j++) {
        polinom[i][j] = 0;
      }
    }
    for (i = 0; i < 4; i++) {
      for (j = 0; j < MAX; j++) {
        ustel[i][j] = 0;
      }
    }
    for (i = 0; i < 5; i++) {
      for (j = 0; j < MAX; j++) {
        logaritmik[i][j] = 0;
      }
    }
    for (i = 0; i < 5; i++) {
      for (j = 0; j < MAX; j++) {
        trigo[i][j] = 0;
      }
    }
    for (i = 0; i < 5; i++) {
      for (j = 0; j < MAX; j++) {
        terstrigo[i][j] = 0;
      }
    }
    system("cls");
    printf("Sayisal analiz projesi    Yavuz Cetin    21011004\n\n\nBisection yontemi:1\nRegula Falsi yontemi:2\nNewton Raphson yontemi:3\nNxN'lik matrisin tersini alma:4\n");
    printf("Gauss Eliminasyon yontemi:5\nGauss Seidal yontemi:6\nSayisal Turev:7\nSimpson yontemleri:8\nTrapez yontemi:9\nGregory Newton Enterpolasyonu:10\nProgramdan cik:0\n\nGirdi:");
    scanf("%d", & menu);
    if (menu == 1) {
      fonksiyonuAl(polinom, ustel, logaritmik, trigo, terstrigo);
      bisection(polinom, ustel, logaritmik, trigo, terstrigo);
    } else if (menu == 2) {
      fonksiyonuAl(polinom, ustel, logaritmik, trigo, terstrigo);
      regulaFalsi(polinom, ustel, logaritmik, trigo, terstrigo);
    } else if (menu == 3) {
      fonksiyonuAl(polinom, ustel, logaritmik, trigo, terstrigo);
      newtonRaphson(polinom, ustel, logaritmik, trigo, terstrigo);
    } else if (menu == 4) {
      matrisTersi();
    } else if (menu == 5) {
      gaussEliminasyon();
    } else if (menu == 6) {
      gaussSeidal();
    } else if (menu == 7) {
      fonksiyonuAl(polinom, ustel, logaritmik, trigo, terstrigo);
      sayisalTurev(polinom, ustel, logaritmik, trigo, terstrigo);
    } else if (menu == 8) {
      fonksiyonuAl(polinom, ustel, logaritmik, trigo, terstrigo);
      simpson(polinom, ustel, logaritmik, trigo, terstrigo);
    } else if (menu == 9) {
      fonksiyonuAl(polinom, ustel, logaritmik, trigo, terstrigo);
      trapez(polinom, ustel, logaritmik, trigo, terstrigo);
    } else if (menu == 10) {
      enterpolasyon();
    }

  }
  return 1;
}