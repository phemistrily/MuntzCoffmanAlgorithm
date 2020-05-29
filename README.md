# MuntzCoffmanAlgorithm

Problem rozpatrujemy dla systemu komputerowego P = {P1,P2,...,Pm}, gdzie m oznacza ilość
procesorów identycznych. Procesory mogą być dostępne w ograniczonych odstępach czasu
lub być zablokowane. Odstępy czasowe nazwijmy p, z których każde jest identyfikowane
przez oddzielny przedział czasu [bl , el ], dla l = 1, ..., p, a liczba ml definiuje liczbę
dostępnych procesorów. Zakładamy, że sąsiednie okna czasowe różnią się zestawem
dostępnych procesorów. Zestawy dostępnych procesorów są niepuste (całkowicie
zablokowane okna są pomijane).
Zadania oznaczymy jako zbiór T = {T1,T2,...,Tn}, gdzie n oznacza ilość zadań do wykonania.
Mogą również istnieć pewne ograniczenia pierwszeństwa między zadaniami, dla przykładu, gdy wyniki jednego zadania są danymi wejściowymi dla innego zadania. Na przykład Zadanie
Ti musi zostać zakończone, nim rozpoczniemy przetwarzanie zadania Tj. Oznaczmy to jako
Ti < Tj. Zbiór takich relacji określa nam pierszeństwo zadań. Czas gotowości od zadania Tj
oznaczamy przez rj dla j = 1, ..., n. Kiedy podział zadań jest zabroniony wszystkie zadania
muszą być wykonywane w sposób ciągły na tym samym procesorze od początku do samego
końca. Oznacza to, że każde zadanie może zostać zawieszone i zrestartowane później bez
dodatkowych kosztów ogólnych. Czas przetwarzania Tj oznaczamy jako tj . Zadanie jest
gotowe, gdy nie zostało ukończone, dotarło i wszyscy jego poprzednicy są wykonani.

# Złożoność obliczeniowa

Dla problemu P|pmtn,tree|Cmax algorytm Muntz-Coffmana jest w postaci algorytmu o
złożoności O(n2
)

# Treść Algorytmu:

1. I = 0. Dla wszystkich zadań oblicz h(j).
2. Do póki ∃j∈T tj > 0 wykonuj:
3. Do póki ( ∃j∈T tj > 0 ) wykonuj:
4. stwórz listę Q gotowych zadań
5. przelicz:
τ 0 := min{∞, minTj ,Tj+1∈Q{ h(j)−h(j+1) βj−βj+1 : βj 6= βj+1, and h(j) > h(j +
1)}
τ 00 := minTj∈Q{ tj ) βj : βj > 0};
6. τ := min{τ 0 , τ 00};
7. dodaj zadania Tj w interwale [t, t+τ ]
8. for Tj ∈ Q wykonuj h(j) := h(j) − τβj , tj := tj − τβj ; usuń zadania z tj = 0 z listy
Q i T ;
9. t := t + τ ;
zakończ
