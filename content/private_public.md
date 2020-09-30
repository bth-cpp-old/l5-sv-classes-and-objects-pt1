## Vad är `private` och `public`?

`private` - medlemmar nåbara *endast inom* klassen
<!-- .element: class="fragment" -->

`public` - medlemmar nåbara *utanför* klassen
<!-- .element: class="fragment" -->

Medlemmar är `private` om inget annat anges
<!-- .element: class="fragment" -->

--

### Varför `public`/`private`?

För att strukturera upp koden
<!-- .element: class="fragment" -->

Ger möjlighet till *Abstraktion* och *Inkapsling*
<!-- .element: class="fragment" -->

--

### Abstraktion

*Användaren behöver inte veta vad som händer under huven*

* Vet du hur en bils förbränningsmotor fungerar?
* Behöver du veta det? 
* Räcker det med att veta vad som händer när du trycker på gaspedalen?

--

### Inkapsling (Encapsulation)

*Saker som hänger ihop ska samlas*

--

### Ett exempel

--

```cpp[|3-4|6-9|11-22]
include({{Car1.hpp}})
```
<!-- .element: class="r-stretch" -->

--

### Nu provkör vi!

```cpp[7-8| 10-12 | 13-14]
include({{CarShort.hpp}})

include({{Car1Main.cpp}})
```