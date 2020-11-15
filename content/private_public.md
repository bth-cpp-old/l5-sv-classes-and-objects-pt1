## Vad är `private` och `public`?

--

`private` - medlemmar nåbara *endast inom* klassen

`public` - medlemmar nåbara *utanför* klassen
<!-- .element: class="fragment" -->

Medlemmar i en ***klass*** är `private` om inget annat anges
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
<!-- .element: class="fragment" -->

* Vet du hur en bils förbränningsmotor fungerar? <!-- .element: class="fragment" -->
* Behöver du veta det? <!-- .element: class="fragment" -->
* Räcker det med att veta vad som händer när du trycker på gaspedalen?<!-- .element: class="fragment" -->


--

### Inkapsling (Encapsulation)

*Saker som hänger ihop ska samlas*
<!-- .element: class="fragment" -->

Note:
Här skulle exemplet kunna vara:
Bil som klass
Bra att ha hjkul, dörrar, gaspedaler etc i samma klass,
samlat 
--

### Ett exempel

--

```cpp[|2-9|10-22|3-4|6-9|11-22]
includecpp({{Car1.hpp}})
```
<!-- .element: class="r-stretch" -->

--

### Nu provkör vi!

```cpp[6 | 7| 9-11 | 12-13]
includecpp({{CarShort.hpp}})

includecpp({{Car1Main.cpp}})
```