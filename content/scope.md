## Variablers *scope*

<!-- .slide: data-transition="slide-in fade" -->

```cpp[6]
include({{Car3Short.hpp}})
```

Varför heter `p_maxSpeed`, inte `maxSpeed`... ?

--
<!-- .slide: data-transition="fade" -->

```cpp[4,8]
include({{Car3Short.hpp}})
};
```

En medlemsvariabel heter redan `maxSpeed`

--
<!-- .slide: data-transition="fade slide-out" -->

```cpp[4,6,8]
include({{Car3Short.hpp}})
```
Om medlemsvariabeln inte ska ***gå ur scope*** måste parametern heta något annat

--

Typ `p_maxSpeed`

Eller...
<!-- .element: class="fragment" -->
