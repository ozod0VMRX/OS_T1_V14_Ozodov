/*
 * 1-topshiriq, 14-variant
 * 1-masala: saralangan massivda ikkilik qidiruv, qadamlar sonini chiqarish.
 * 2-masala: int *qidir(int *a, int n, int x) - topilgan elementga pointer
 *           yoki NULL qaytaradi, indeks (p - a) bilan topiladi.
 */
#include <stdio.h>

#define MAX 100

/* Massiv o'sish tartibida saralangan bo'lsa 1, aks holda 0 qaytaradi */
int saralanganmi(int a[], int n)
{
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return 0;
    return 1;
}

/* 1-masala: ikkilik qidiruv. Topilsa indeksni, topilmasa -1 ni qaytaradi.
   Qadamlar soni qadam pointeri orqali qaytadi. */
int ikkilik_qidiruv(int a[], int n, int x, int *qadam)
{
    int chap = 0, ong = n - 1;
    *qadam = 0;

    while (chap <= ong) {
        int orta = (chap + ong) / 2;
        (*qadam)++;
        if (a[orta] == x)
            return orta;
        else if (a[orta] < x)
            chap = orta + 1;     /* x o'ng yarmida */
        else
            ong = orta - 1;      /* x chap yarmida */
    }
    return -1;
}

/* 2-masala: xuddi shu qidiruv, lekin indekslar o'rniga pointerlar bilan.
   Topilsa elementga pointer, topilmasa NULL qaytaradi. */
int *qidir(int *a, int n, int x)
{
    int *chap = a;
    int *ong = a + n - 1;

    while (chap <= ong) {
        int *orta = chap + (ong - chap) / 2;
        if (*orta == x)
            return orta;
        else if (*orta < x)
            chap = orta + 1;
        else
            ong = orta - 1;
    }
    return NULL;
}

int main(void)
{
    int a[MAX];
    int n, x, qadam;

    /* --- Kiritish va tekshirish --- */
    printf("Elementlar soni (1..%d): ", MAX);
    if (scanf("%d", &n) != 1) {
        printf("Xato: son kiritilmadi.\n");
        return 1;
    }
    if (n < 1 || n > MAX) {
        printf("Xato: elementlar soni 1 va %d oralig'ida bo'lishi kerak.\n", MAX);
        return 1;
    }

    printf("%d ta elementni o'sish tartibida kiriting: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Xato: faqat butun sonlar kiriting.\n");
            return 1;
        }
    }
    if (!saralanganmi(a, n)) {
        printf("Xato: massiv saralanmagan, ikkilik qidiruv mumkin emas.\n");
        return 1;
    }

    printf("Qidiriladigan son: ");
    if (scanf("%d", &x) != 1) {
        printf("Xato: son kiritilmadi.\n");
        return 1;
    }

    /* --- 1-masala --- */
    printf("\n1-masala (indekslar bilan):\n");
    int indeks = ikkilik_qidiruv(a, n, x, &qadam);
    if (indeks != -1)
        printf("  %d topildi, indeksi = %d, qadamlar soni = %d\n", x, indeks, qadam);
    else
        printf("  %d topilmadi, qadamlar soni = %d\n", x, qadam);

    /* --- 2-masala --- */
    printf("\n2-masala (pointerlar bilan):\n");
    int *p = qidir(a, n, x);
    printf("  massiv boshi:   a = %p\n", (void *)a);
    if (p != NULL) {
        printf("  topilgan joy:   p = %p\n", (void *)p);
        printf("  *p = %d, indeks = p - a = %d\n", *p, (int)(p - a));
    } else {
        printf("  qidir() NULL qaytardi, %d massivda yo'q\n", x);
    }
    return 0;
}
