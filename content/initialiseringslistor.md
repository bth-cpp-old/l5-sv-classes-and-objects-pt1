## Initialiseringslistor

Ett annat sätt att initialisera medlemsvariabler

--

```cpp[6-9]
include({{Car5Short.hpp}})

```

blir
<!-- .element: class="fragment" -->

```cpp[6]
include({{Car6Short.hpp}})
```
<!-- .element: class="fragment" -->

--

Fördelar?

Prestanda*
<!-- .element: class="fragment" -->

Färre kopieringar -> högre prestanda
<!-- .element: class="fragment" -->

\*Kompilatorn **kan** dock optimera bort kopieringar
<!-- .element: class="fragment" -->

--

Fördelar?

Mindre risk för fel

Det händer att man glömmer `this?  exempelvis
<!-- .element: class="fragment" -->
