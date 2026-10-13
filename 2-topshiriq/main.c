/*
 * 2-topshiriq, 14-variant
 * "Zinapoyali" massiv: i-qatorda i + 1 ta element bo'lgan Paskal
 * uchburchagini dinamik xotirada qurish.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_QATOR 20

/* Qatorlar sonini o'qiydi va tekshiradi. Natija n pointeri orqali qaytadi.
   To'g'ri bo'lsa 1, xato bo'lsa 0 qaytaradi. */
int qatorlar_soni(int *n)
{
    printf("Qatorlar soni (1..%d): ", MAX_QATOR);
    if (scanf("%d", n) != 1) {
        printf("Xato: son kiritilmadi.\n");
        return 0;
    }
    if (*n < 1 || *n > MAX_QATOR) {
        printf("Xato: qatorlar soni 1 va %d oralig'ida bo'lishi kerak.\n", MAX_QATOR);
        return 0;
    }
    return 1;
}

/* Uchburchakni bo'shatadi: avval har bir qator, keyin qatorlar massivi */
void bushat(int **q, int n)
{
    for (int i = 0; i < n; i++)
        free(q[i]);
    free(q);
}

/* Paskal uchburchagini quradi. i-qator uchun i + 1 ta joy ajratiladi.
   Xotira yetmasa, ajratilganlarni bo'shatib NULL qaytaradi. */
int **uchburchak_qur(int n)
{
    int **q = malloc(n * sizeof(int *));
    if (q == NULL)
        return NULL;

    for (int i = 0; i < n; i++) {
        q[i] = malloc((i + 1) * sizeof(int));
        if (q[i] == NULL) {
            bushat(q, i);            /* faqat ajratilgan i ta qatorni */
            return NULL;
        }
        q[i][0] = 1;                 /* qatorning boshi */
        q[i][i] = 1;                 /* qatorning oxiri */
        for (int j = 1; j < i; j++)  /* o'rtasi: tepadagi ikki son yig'indisi */
            q[i][j] = q[i - 1][j - 1] + q[i - 1][j];
    }
    return q;
}

/* Uchburchakni markazlashtirib chiqaradi */
void chiqar(int **q, int n)
{
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < (n - 1 - i) * 3; s++)
            printf(" ");
        for (int j = 0; j <= i; j++)
            printf("%6d", q[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int n;

    if (!qatorlar_soni(&n))
        return 1;

    int **q = uchburchak_qur(n);
    if (q == NULL) {
        printf("Xato: xotira ajratilmadi.\n");
        return 1;
    }

    printf("\nPaskal uchburchagi (%d qator):\n\n", n);
    chiqar(q, n);
    printf("\nq massivi manzili: %p\n", (void *)q);

    bushat(q, n);
    q = NULL;
    printf("Xotira bo'shatildi.\n");
    return 0;
}
