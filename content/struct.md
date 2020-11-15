## **`struct`**

--

Som en klass *typ*

Men, allt är **`public`** istället för **`private`** per ***default***
<!-- .element: class="fragment" -->

--

```cpp[1]
includecpp({{SomeClass2.hpp}})
```

blir

```cpp[1]
includecpp({{SomeStruct.hpp}})
```

--

### När ska man använda sig av `struct` ?

När du vill ***gruppera data*** utan allt för mycket ***funktionalitet***. 
<!-- .element: class="fragment" -->

Note:
Man tappar säkerhet med get-funktioner som har const ex dock

Större risk att man av misstag ändrar ett värde

--

Exempelvis för ***aggregatklasser***
