## Konstruktorer

```cpp[7-8]
include({{CarShort.hpp}})

include({{Car1Main.cpp}})
```
hmm... inte så najs
<!-- .element: class="fragment" -->

--


* Körs när objekt skapas
* Tvinga medlemsvariabler att bli initialiserade

--

```cpp[1,11-14]
include({{Car2.hpp}})
```
<!-- .element: class="r-stretch" -->

--

### Nu provkör vi igen!

```cpp[6]
include({{CarShort.hpp}})

include({{Car2Main.cpp}})
```
Najsigare!

--

### Om jag vill ha flera bilar då?

--

```cpp[6]
include({{CarShort.hpp}})

include({{Car2Main2.cpp}})
```

--

```bash[2-5, 6-18]
include({{Car2Main2CompOut.txt}})
```
<!-- .element: class="r-stretch" -->

--

```cpp[11-13]
include({{Car3.hpp}})
```
<!-- .element: class="r-stretch" -->

```bash
Compilation time: 0.23 sec
```
<!-- .element: class="fragment" -->

--

### Varför fungerade det innan?

Kompilatorn skapade en *default-konstruktor* åt oss
<!-- .element: class="fragment" -->

De försvinner när man skapar egna konstruktorer
<!-- .element: class="fragment" -->

Man kan be kompilatorn skapa en dock
<!-- .element: class="fragment" -->

--

### Exempel:

```cpp[5]
include({{SomeClass4.hpp}})

include({{SomeClass4Main.cpp}})

```

```bash
Compilation time: 0.22 sec
```
<!-- .element: class="fragment" -->

--

Man kan också be kompilatorn ta bort en konstruktor

--

### Exempel:

```cpp[5,13]
include({{SomeClass5.hpp}})

include({{SomeClass5Main.cpp}})
```

--

```bash
include({{SomeClass5MainCompOut.txt}})
```
