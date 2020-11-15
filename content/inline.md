## `inline`

***Tipsar*** om att en funktion kan ***inlineas***

--

Vid ***inlining*** ersätts funktionsanropet med en ***copy-paste*** av funktionsdefinitionen

--

### Ett exempel:

```cpp[]
inline int add(int a, int b){
    return a+b;
}

int main(){
    int result = add (43, 1338);
}
```

blir:
<!-- .element: class="fragment" -->

```cpp
int main(){
    int result = 43 + 1338;
}
```
<!-- .element: class="fragment" -->

--

I verkligheten kommer din ***kompilator*** själv ***avgöra*** vad som inlineas och inte

**`inline`** är ett ***tips*** till kompilatorn, ***ingen instruktion***

--

`inline` kan dock användas för att definera samma funtion flera gånger ***(jättefarligt!)***

--

### Exempelvis:

```cpp[]
// add.hpp
inline int add(int a, int b){
    return a+b;
}

// foo.hpp
int foo(int a, int b);

// foo.cpp
#include "add.hpp"
int foo(int a, int b){
    return add(a,b);
}

// main.cpp
#include "add.hpp" 
#include "foo.hpp" 
int main(){
    return foo (43, 3);
}
```
<!-- .element: class="r-stretch" -->

Note:
Två headerfiler
    - add funktionsdefinition
    - foo funktionsdeklaration

två källfiler
    - foo, funktionsdefinition, använder add
    - main, använder foo. Inkluderar både foo.hpp och add.hpp

Notera: inga includeguards!
--

```bash[]
clang++ -c foo.cpp && clang++ -c main.cpp && clang++ main.o foo.o
/usr/bin/ld: foo.o: in function `add(int, int)':
foo.cpp:(.text+0x0): multiple definition of `add(int, int)'; \
    main.o:main.cpp:(.text+0x0): first defined here
clang: error: linker command failed with exit code 1 (use -v to \
    see invocation)
```

Note:
#include-direktivet gör ju en copy-paste av headern in i källfilen 

main.o och foo.o (en objektfil per källfil) kommer få varsin version av add()

Länkaren, som länkar samman objektfilerna, kommer gnälla då den hittar två definitioner av samma funktion
--

```cpp[2]
// add.hpp
inline int add(int a, int b){
    return a+b;
}

// foo.hpp
int foo(int a, int b);

// foo.cpp
#include "add.hpp"
int foo(int a, int b){
    return add(a,b);
}

// main.cpp
#include "add.hpp" 
#include "foo.hpp" 
int main(){
    return foo (43, 3);
}
```

--

```bash
clang++ foo.cpp main.cpp && ./a.out ; echo $?
46
```

Note:
Länkaren vet att det kan finnas flera definitioner, tack vara inline

allt är frid och fröjd

Vi kan köra programmet och returvärdet stämmer bra (43+3)