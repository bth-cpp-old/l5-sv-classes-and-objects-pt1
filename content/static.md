## `static` 

--

Hittills har alla funktioner och variabler varit ***medlemmar*** i klassen
--

De har varit ***knutna*** till en specifik ***instans*** 

--

Ex:

```cpp
class Car{...};

Car volvoPv(100);

Car saab900Turbo(200);

Car koeniggseggJeskoAbsolut(483);
```

--

Med **`static`** kan man skapa ***funktioner*** och ***variabler*** som ***delas*** av alla instanser av en ***klass***

--

### Ett exempel

```[5|8-10|13|16]cpp
includecpp({{MphConverter.cpp}})
```
<!-- .element: class="r-stretch" -->

```
60 mph is 96.5604 Kmh
```
<!-- .element: class="fragment" -->

Note:
- Först skapar vi en variabel som delas av alla instanser av klassen (objekt)
- Den är dessutom const

- Sen har vi en statisk medlemsfunktion som delas av alla instanser (objekt)
- Den använder variabeln ovan