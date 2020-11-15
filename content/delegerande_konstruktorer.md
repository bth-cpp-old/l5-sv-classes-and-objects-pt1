## Delegerande Konstruktorer

--

Ibland behöver man ***återanvända*** logik från en konstruktor i en ***annan***

Med ***delegerande*** konstruktorer ***anropar*** man ***en annan*** konstruktor
<!-- .element: class="fragment" -->

Ungefär som i en initialiseringslista
<!-- .element: class="fragment" -->
--

### Exempelvis:

```cpp[8,9,13-14|10-11, 15-16]
includecpp({{Car7Short.hpp}})
```
<!-- .element: class="r-stretch" -->

Note:
I det här exemplet har vi tre konstruktorer.

Kod för att se till att maxSpeed är rimlig är duplicerad i två av konstruktorerna.

I övrigt används initialiseringslistor för övriga medlemsvariabler.

--

Blir:

```cpp[ 8 | 9 | 10-11 | 13 | 14]
includecpp({{Car8Short.hpp}})
```
<!-- .element: class="r-stretch" -->

Note:
- Första konstruktorn ser identisk ut

- Andra konstruktorn har kvar koden som var duplicerad
- Använder sig av första konstruktorn för att sätta speed till ett defaultvärde

- Tredje konstruktorn anropar konstruktor nr2
    - slippa duplicera kod
    - Sätter makeAndModel manuellt

Man kan inte blanda initialiseringslistor och delegerande konstruktorer.

--

### Pros & Cons

Logik kan ***återanvändas***
<!-- .element: class="fragment" -->

Kan ***inte*** kombineras med ***initialiseringslistor***
<!-- .element: class="fragment" -->
