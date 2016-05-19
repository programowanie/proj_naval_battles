## Naval Battles

Program symuluje bitwę morską 15 vs. 15 okrętów.

Przebieg:
>	Każda strona (PC vs. PC) ma 4 niszczyciele, 4 krążowniki, 4 pancerniki i 3 lotniskowce. Gra odbywa się turami. W trakcie tury losowany jest statek naprzemiennie z każdej ze stron a dla niego też losowo, dobierany jest przeciwnik. Symulacja kończy się, gdy zostaną wyeliminowane wszystkie statki z jednej ze stron lub zostaną lotniskowce bez eskadr.


Klasy statków (parametry statków są stałe):

- niszczyciel – dzięki lekkiemu opancerzeniu jest niezwykle szybki i zwrotny co przekłada się na możliwość uniku ostrzału (pierwszy parametr - współczynnik uniku). Może korzystać z zasłony dymnej (metoda), podczas ataku z zasadzki, niszczyciel jest w stanie zniszczyć każdego przeciwnika. Atak możliwy za pomocą torped (organiczna ilość) lub dział (2 parametry, jedna metoda - atak) itp. dalej.
- krążownik – najbardziej wszechstronny okręt, posiada mocny pancerz jak i siłę ognia, średni współczynnik uniku ostrzału. Atak możliwy za pomocą dział, posiada także działa przeciwlotnicze pozwalające zniszczyć wrogie eskadry z lotniskowców.
- pancernik – posiadają niewielką prędkość i znikomą manewrowość – co oznacza brak możliwości uniku ostrzału. Największy pancerz i siła ognia. Możliwość ataku jak u krążowników. 
- lotniskowiec – atakuje przeciwnika za pomocą eskadry samolotów. Jeśli eskadry zostaną zniszczone w poprzednich turach, staje się bezbronny.

Dodatki:

- flagi sygnałowe, losowane dla wszystkich lub części statków dające określone bonusy

To tylko koncept, nie oświadczam, że w trakcie pisania nie dojdę do wniosku, że coś można zupełnie zmienić.
