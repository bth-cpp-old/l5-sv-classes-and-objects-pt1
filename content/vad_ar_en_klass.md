## Vad är en klass ?

--

En gruppering av funktioner och variabler

En mall som man skapar objekt från
<!-- .element: class="fragment" -->

![OO](images/class-object-featured-image.png "OO")
<!-- .element: class="fragment" -->

--

### Varför klasser?

Ni har jobbat med funktioner och variabler
<!-- .element: class="fragment" -->

Det kan bli grötigt i stora projekt
<!-- .element: class="fragment" -->

Med klasser kan man dela upp koden modulärt
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->
***Klasser*** har ***namn***

```cpp[1]
includecpp({{SomeClass1.hpp}})
```

--
<!-- .slide: data-transition="fade" -->
***Medlemsvariabler***

```cpp[2]
includecpp({{SomeClass1.hpp}})
```

--
<!-- .slide: data-transition="fade" -->
***Medlemsfunktioner***

```cpp[4-6]
includecpp({{SomeClass1.hpp}})
```

--

<!-- .slide: data-transition="fade slide-out" -->
***Funktioner*** i ett objekt kan ***nå variabler*** i ***densamma***

```cpp[4-6]
includecpp({{SomeClass2.hpp}})
```

--
<!-- .slide: data-transition="slide-in fade-out" -->

Hur skapar man objekt från klasser?

```cpp[10]
includecpp({{SomeClass2.hpp}})

includecpp({{SomeClass2Main1.cpp}})
```
<!-- .element: class="fragment" -->

```bash[1|2-3]
includecpp({{SomeClass2MainCompOut1.txt}})
```
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->

Hur använder man dem?

```cpp[11]
includecpp({{SomeClass2.hpp}})

includecpp({{SomeClass2Main2.cpp}})
```

```bash[1|2-3|5]
includecpp({{SomeClass2MainCompOut2.txt}})
```
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->

Och hur fixar man det där kompileringsfelet?

```cpp[2,5]
includecpp({{SomeClass3.hpp}})

includecpp({{SomeClass2Main2.cpp}})

```

```bash
Compilation time: 0.25 sec
```
<!-- .element: class="fragment" -->