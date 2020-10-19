## Delegerande Konstruktorer

--

Ibland behöver man ***återanvända*** logik från en konstruktor i en ***annan***

Med ***delegerande*** konstruktorer ***anropar*** man ***en annan*** konstruktor
<!-- .element: class="fragment" -->

Ungefär som i en initialiseringslista
<!-- .element: class="fragment" -->
--

Ex:

```cpp[10-11, 15-16]
includecpp({{Car7Short.hpp}})
```
<!-- .element: class="r-stretch" -->

--

Blir:

```cpp[10-11 | 13]
includecpp({{Car8Short.hpp}})
```
<!-- .element: class="r-stretch" -->

--

### Pros & Cons

Logik kan ***återanvändas***

Kan ***inte*** kombineras med ***initialiseringslistor***
