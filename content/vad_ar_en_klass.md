## Vad är en klass ?

--

En gruppering av funktioner och variabler

En mall som man skapar objekt från
<!-- .element: class="fragment" -->

![OO](images/class-object-featured-image.png "OO")
<!-- .element: class="fragment" -->

Note:
Man kan se det på flera sätt

I grund och botten: en gruppering

men kan dock se det som en mall

--

### Varför klasser?

Ni har jobbat med funktioner och variabler
<!-- .element: class="fragment" -->

Det kan bli grötigt i stora projekt
<!-- .element: class="fragment" -->

Med klasser kan man dela upp koden modulärt
<!-- .element: class="fragment" -->

Man kan tänka sig koden som en uppsättning "grejer"
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->

### Klassens anatomi

***Klasser*** har ***namn***

```cpp[1]
includecpp({{SomeClass1.hpp}})
```

--
<!-- .slide: data-transition="fade" -->

### Klassens anatomi

***Medlemsvariabler***

```cpp[2]
includecpp({{SomeClass1.hpp}})
```
Note:
Dags för ett exempel!

--
<!-- .slide: data-transition="fade" -->

### Klassens anatomi

***Medlemsfunktioner***

```cpp[4-6]
includecpp({{SomeClass1.hpp}})
```
Note:
Medlemsfunktioner kan också kallas metoder. Jag har (o)vanan att använda det ordet.

--
<!-- .slide: data-transition="fade slide-out" -->

### Klassens anatomi

***Funktioner*** i ett objekt kan ***nå variabler*** i ***objektet***

```cpp[4-6]
includecpp({{SomeClass2.hpp}})
```
Note:
Vad är då Objekt
--
<!-- .slide: data-transition="slide-in fade-out" -->

Hur skapar man objekt från klasser?

```cpp[10]
includecpp({{SomeClass2.hpp}})

includecpp({{SomeClass2Main1.cpp}})
```
<!-- .element: class="fragment" -->

```bash[2-3]
includecpp({{SomeClass2MainCompOut1.txt}})
```
<!-- .element: class="fragment" -->

Note:
Objekt är , som vi sa tidigare, en instans av en klass

--
<!-- .slide: data-transition="fade" -->

Hur använder man objekt?

```cpp[11]
includecpp({{SomeClass2.hpp}})

includecpp({{SomeClass2Main2.cpp}})
```

```bash[2-3|5]
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
<!-- .element: class="fragment" -->

```bash
Compilation time: 0.25 sec
```
<!-- .element: class="fragment" -->