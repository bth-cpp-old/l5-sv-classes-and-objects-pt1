## Best practices

--

###  `SomeClass.hpp` och `SomeClass.cpp`

Du bör lägga din ***klassdeklaration*** i en `*.hpp`-fil

```cpp
includecpp({{Car11.hpp}})
```

--

och din ***klassdefinition*** i en `*.cpp`-fil

```cpp
includecpp({{Car11.cpp}})
```
<!-- .element: class="r-stretch" -->

--

## Ska man ha `public` eller `private` först?

```cpp
includecpp({{Car11.2.hpp}})
```
<!-- .element: class="fragment" -->

--

Spelar ingen roll!

Välj en stil och följ den konsekvent!
<!-- .element: class="fragment" -->

--

### Använd initialiseringlistor!

Risken för buggar minskar rejält
<!-- .element: class="fragment" -->
