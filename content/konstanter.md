## Konstanter

(som ni kanske vet)

**`const`** gör att variabel ***inte*** kan ***ändras*** efter att den ***skapats***
<!-- .element: class="fragment" -->

Det blir alltså en konstant
<!-- .element: class="fragment" -->

--

**`const`** kan användas både till ***medlemsvariabler*** och ***medlemsfunktioner*** 

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

--

```cpp[4]
includecpp({{Car6.1Short.hpp}})
```

--

### `const` medlemsfunktioner