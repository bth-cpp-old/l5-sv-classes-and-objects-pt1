## Konstanter

--

(som ni kanske vet)

**`const`** gör att variabel ***inte*** kan ***ändras*** efter att den ***skapats***
<!-- .element: class="fragment" -->

Det blir alltså en konstant
<!-- .element: class="fragment" -->

--

**`const`** kan användas både till ***medlemsvariabler***, ***parametrar*** och ***medlemsfunktioner*** 

--

Ex:

```cpp[4]
includecpp({{Car4Short.hpp}})
```

--

Blir

```cpp[4]
includecpp({{Car6Short.hpp}})
```

--

### Men det kompilerar ju inte?!

```bash[2-4 | 9-12]
includecpp({{Car5ShortMainCompOut.txt}})

```
<!-- .element: class="r-stretch" -->

--

Kompileringsfelet fixar man med ***initialiseringslistor***!

```cpp[8]
includecpp({{Car6.1Short.hpp}})
```
<!-- .element: class="fragment" -->

--

### `const`-parametrar

Parametrar som är **`const`** kan ***inte*** modifieras ***i funktionen***

```cpp[8]
includecpp({{Car9Short.hpp}})
```
<!-- .element: class="fragment" -->

--

### `const`-medlemsfunktioner

En ***medlemsfunktion*** som är **`const`** kan ***inte*** modifiera ***medlemsvariabler***

```cpp[8]
includecpp({{Car10Short.hpp}})
```
<!-- .element: class="fragment" -->