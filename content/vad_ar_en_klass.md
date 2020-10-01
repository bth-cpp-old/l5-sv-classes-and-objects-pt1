## Vad är en klass ?

En gruppering av funktioner och variabler
<!-- .element: class="fragment" -->

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
<!-- .slide: data-transition="slide-in fade-out" -->

```cpp[1|2|4-6]
includecpp({{SomeClass1.hpp}})
```

--

<!-- .slide: data-transition="fade slide-out" -->
Funktioner i ett objekt kan nå variablerna i detsamma

```cpp[4-6]
includecpp({{SomeClass2.hpp}})
```
<!-- .element: class="fragment" -->

--

Hur skapar man objekt från klasser?

```cpp[10]
includecpp({{SomeClass2.hpp}})

includecpp({{SomeClass2Main.cpp}})
```
<!-- .element: class="fragment" -->

```bash[|1|2|4]
includecpp({{SomeClass2MainCompOut.txt}})
```
<!-- .element: class="fragment" -->

--

```cpp[12]
includecpp({{SomeClass2.hpp}})

includecpp({{SomeClass1Main.cpp}})
```

```bash[|1|6|7]
includecpp({{SomeClass2MainCompOut.txt}})
```
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->
	
```cpp[2,4]
includecpp({{SomeClass3.hpp}})

includecpp({{SomeClass1Main.cpp}})

```

```bash
Compilation time: 0.25 sec
```
<!-- .element: class="fragment" -->