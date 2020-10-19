## Aliasing

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

```cpp
include({{Box2.hpp}})

int main(){
    Box b;
    Box::cm length = 20;
    b.length = length;
}
```

--

### Nackdelar

```cpp
using cm = int;
using inch = int;

include({{Box1.hpp}})

int main(){
    Box b;
    inch length = 20;
    b.length = length;
}
```
<!-- .element: class="r-stretch" -->

--

Alias är ***inte*** riktiga ***starka typer***, de är ***svaga typer*** typer

(engelska: ***strong*** - ***weak***)
<!-- .element: class="fragment" -->
