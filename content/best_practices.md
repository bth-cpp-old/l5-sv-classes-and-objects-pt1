## Best practices

--

###  `.hpp` och `.cpp`

Du bör lägga din ***klassdeklaration*** i en `*.hpp`-fil
<!-- .element: class="fragment" -->

Du bör lägga din ***klassdefinition*** i en `*.cpp`-fil
<!-- .element: class="fragment" -->

--
***Klassdeklaration*** i **`Car.hpp`**:

```cpp[|6,11-13|9-10]
includecpp({{Car11.hpp}})
```

--

***Klassdefinition*** i **`Car.cpp`**:

```cpp[|3,8,13,18]
includecpp({{Car11.cpp}})
```
<!-- .element: class="r-stretch" -->

--

### Ska man ha `public` eller `private` först?

Spelar ingen roll!
<!-- .element: class="fragment" -->

--

Public först-exempel:
```cpp
includecpp({{Car11.2.hpp}})
```

--
### Fördelar?

Lättare att förstå ditt API för andra
<!-- .element: class="fragment" -->

### Nackdelar?

Medlemsfunktioner hamnar före sina variabler
<!-- .element: class="fragment" -->

--

Välj en stil och följ den ***konsekvent***!

--

### Använd initialiseringlistor!

Risken för buggar minskar rejält
<!-- .element: class="fragment" -->
