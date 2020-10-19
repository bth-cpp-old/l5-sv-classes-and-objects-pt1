## Initialiseringslistor

--

Ett annat sätt att initialisera medlemsvariabler

--

```cpp[6-9]
includecpp({{Car4Short.hpp}})

```

blir
<!-- .element: class="fragment" -->

```cpp[6]
includecpp({{Car5Short.hpp}})
```
<!-- .element: class="fragment" -->

--

### Fördelar?

Prestanda*
<!-- .element: class="fragment" -->

Färre kopieringar -> högre prestanda
<!-- .element: class="fragment" -->

\*Kompilatorn ***kan*** dock optimera bort kopieringar ***själv***
<!-- .element: class="fragment" -->

--

### Fördelar?

Mindre risk för fel

Det händer att man glömmer `this`  exempelvis
<!-- .element: class="fragment" -->
