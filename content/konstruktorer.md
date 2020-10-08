## Konstruktorer

--

```cpp[7-8]
includecpp({{CarShort.hpp}})

includecpp({{Car1Main.cpp}})
```
hmm... inte så najs
<!-- .element: class="fragment" -->

--

### Konstruktorer...

Körs när objekt skapas
<!-- .element: class="fragment" -->

Kan användas tll att ***tvinga medlemsvariabler*** att bli ***initialiserade***
<!-- .element: class="fragment" -->

--

```cpp[1,11-14]
includecpp({{Car2.hpp}})
```
<!-- .element: class="r-stretch" -->

--

### Nu provkör vi igen!

```cpp[6]
includecpp({{CarShort.hpp}})

includecpp({{Car2Main.cpp}})
```
Najsigare!

--

### Om jag vill ha flera bilar då?

--

```cpp[6]
includecpp({{CarShort.hpp}})

includecpp({{Car2Main2.cpp}})
```

--

```bash[2-3 | 5-14]
includecpp({{Car2Main2CompOut.txt}})
```
<!-- .element: class="r-stretch" -->

--

```cpp[11-14]
includecpp({{Car3.hpp}})
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
includecpp({{SomeClass4.hpp}})

includecpp({{SomeClass4Main.cpp}})

```

```bash
Compilation time: 0.22 sec
```
<!-- .element: class="fragment" -->

--

Man kan också be kompilatorn ta bort en konstruktor

--

### Exempel:

```cpp[6,12]
includecpp({{SomeClass5.hpp}})

includecpp({{SomeClass5Main.cpp}})
```

```bash[2-3|5-6]
includecpp({{SomeClass5MainCompOut.txt}})
```
<!-- .element: class="fragment" -->
