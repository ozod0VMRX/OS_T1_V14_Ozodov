# OS_T1_V14_Ozodov

Operatsion tizimlar fanidan topshiriq, 14-variant.
Muallif: Ozodov Xudoyshukur Faxriddin o'g'li

## Tuzilma

```
1-topshiriq/   C asoslari, kompilyatsiya bosqichlari, pointerlar
2-topshiriq/   Pointerlar va dinamik xotira (malloc/free)
```

## 1-topshiriq

### A qism: kompilyatsiya bosqichlari

```bash
cd 1-topshiriq
gcc -E hello.c -o hello.i   # preprotsessor
gcc -S hello.i -o hello.s   # kompilyator (assembler kodi)
gcc -c hello.s -o hello.o   # assembler (obyekt fayl)
gcc hello.o -o hello        # linker (bajariluvchi fayl)
./hello
```

### B qism: ikkilik qidiruv va pointerlar

```bash
cd 1-topshiriq
gcc -Wall -Wextra -o main main.c
./main
```

Dastur massiv va qidiriladigan sonni so'raydi, so'ng 1-masala (indekslar bilan, qadamlar soni) va 2-masala (`qidir()` funksiyasi, pointerlar) natijasini ketma-ket chiqaradi.

## 2-topshiriq: zinapoyali massivda Paskal uchburchagi

i-qatorda i + 1 ta element bo'lgan Paskal uchburchagi dinamik xotirada quriladi.

```bash
cd 2-topshiriq
gcc -Wall -Wextra -g -o main main.c
./main
./main < test.txt
```

Valgrind:

```bash
valgrind --leak-check=full ./main < test.txt 2> valgrind.txt
```
