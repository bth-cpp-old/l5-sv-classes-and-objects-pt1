## `this`

--

Ett ***nyckelord*** (***keyword***) som fungerar som en ***pekare*** till det ***aktuella objektet***

--

När du i en ***medlemsfunktion*** använt dig av en annan ***medlem*** har `this` ***implicit*** använts

--

D.v.s., kompilatorn har lagt till `this` åt dig

--

```cpp[5]
includecpp({{SomeClass2.hpp}})
```

är alltså egentligen
<!-- .element: class="fragment" -->

```cpp[5]
includecpp({{SomeClass2.1.hpp}})
```
<!-- .element: class="fragment" -->

--

### `(*pointer).`

kan också skrivas som

### `pointer->`

--

```cpp[5]
includecpp({{SomeClass2.1.hpp}})
```

är alltså samma som

```cpp[5]
includecpp({{SomeClass2.2.hpp}})
```

--

De betyder ***samma sak***, men

### `->`

***föredras*** oftast

--

`this` kan också användas när en ***parameter*** har ***samma namn*** som en ***medlemsvariabel***

--
<!-- .slide: data-transition="slide-in fade-out" -->
Som i fallet med klassen `Car`

```cpp[6,8]
includecpp({{Car3Short.hpp}})
```

--
<!-- .slide: data-transition="fade" -->

som blir

```cpp[6-8]
includecpp({{Car4Short.hpp}})
```

Note:
Här berättar vi för kompilatorn att:
- just instansens variabel av namnet
- som ska tilldelas värdet från parametern