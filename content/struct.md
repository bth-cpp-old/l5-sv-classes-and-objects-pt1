## struct

Som en klass typ

Men, allt är **`public`** istället för **`private`** per ***default***

--

```cpp[1]
incincludecpp({{SomeClass2.hpp}})
```

blir

```cpp[1]
incincludecpp({{SomeStruct.hpp}})
```

--

Använd **`struct`** istället för `class` när du vill ***gruppera data*** utan allt för mycket ***funktionalitet***. 

--

Exempelvis för ***aggregatklasser***
