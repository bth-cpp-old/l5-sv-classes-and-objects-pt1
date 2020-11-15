## Aliasing

Note:
Vi ger en typ (ett heltal, float, klass etc) ett alias

--

### Exempelvis:

```cpp
typedef int cm;
```

eller

```cpp
using cm = int;
```

--

Används som **`typ`**:

```cpp
include({{Box1.hpp}})
```

--

### Praktiska att använda ihop med klasser

```cpp[2, 10]
include({{Box2.hpp}})

int main(){
    Box b;
    Box::cm length = 20;
    b.length = length;
}
```

--

### Nackdelar

```cpp[1,2|12,13]
using inch = int;
include({{Box1.hpp}})

int main(){
    Box b;
    inch length = 20;
    b.length = length;
}
```
Note:
I det här exemplet

Två alias för samma typ

Den ena kan användas istället för den andra

Man får ingen varning
--

Alias är ***inte*** riktiga ***starka typer***, de är ***svaga typer***

(engelska: ***strong*** - ***weak***)
<!-- .element: class="fragment" -->
