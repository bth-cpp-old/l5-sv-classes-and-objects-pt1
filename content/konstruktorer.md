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

Exempel:

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

Exempel:

```cpp[6,12]
includecpp({{SomeClass5.hpp}})

includecpp({{SomeClass5Main.cpp}})
```

```bash[2-3|5-6]
includecpp({{SomeClass5MainCompOut.txt}})
```
<!-- .element: class="fragment" -->

--

### Varför ska man ha en konstruktor?

För att ***initiera*** variabler
<!-- .element: class="fragment" -->

Annars får de ***slumpmässiga*** värden
<!-- .element: class="fragment" -->

--

Exempel:

```cpp[]
includecpp({{SomeClass4.2.hpp}})

includecpp({{SomeClass4Main2.cpp}})
```
<!-- .element: class="r-stretch" -->

--

```bash
mattias@Osborne1:/mnt/c/temp$ clang++ -std=c++11 test.cpp -o test
mattias@Osborne1:/mnt/c/temp$ ./test
pi: -9.92432e+17
pi: 4.59163e-41
pi: 0
```

Om man ***inte initierar*** en variabel kommer den få det ***värde*** som ligger på dess plats i ***minnet*** sen ***tidigare***!
<!-- .element: class="fragment" -->

--

### Kan vara jättedåligt!

* Best case: Konstiga buggar
<!-- .element: class="fragment" -->
* Worst case: Rejäla säkerhetshål
<!-- .element: class="fragment" -->

Ex:
https://www.usenix.org/conference/woot20/presentation/cho
<!-- .element: class="fragment" -->
