# Introduktion till klasser och objekt

Note:
This will only display in the notes window.
yhjj
hjhkhk

hjh
* a
* b

---

## Vad är en klass ?

En gruppering av funktioner och variabler
<!-- .element: class="fragment" -->

En mall som man skapar objekt från
<!-- .element: class="fragment" -->

![OO](images/class-object-featured-image.png "OO")
<!-- .element: class="fragment" -->

--

### Varför klasser?

Ni har jobbat med funktioner och variabler
<!-- .element: class="fragment" -->

Det kan bli grötigt i stora projekt
<!-- .element: class="fragment" -->

Med klasser kan man dela upp koden modulärt
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="slide-in fade-out" -->

```cpp[1|2|4-6]
include({{SomeClass1.hpp}})
```

--

<!-- .slide: data-transition="fade slide-out" -->
Funktioner i ett objekt kan nå variablerna i detsamma

```cpp[4-6]
include({{SomeClass2.hpp}})
```
<!-- .element: class="fragment" -->

--

Hur skapar man objekt från klasser?

```cpp[10]
include({{SomeClass2.hpp}})

include({{SomeClassMain1.cpp}})
```
<!-- .element: class="fragment" -->

```bash[|1|2|4]
include({{SomeClassMain1CompOut.txt}})
```
<!-- .element: class="fragment" -->

--

```cpp[12]
include({{SomeClass2.hpp}})

include({{SomeClassMain2.cpp}})
```

```bash[|1|6|7]
include({{SomeClassMain2CompOut.txt}})
```
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->
	
```cpp[2,4]
include({{SomeClass3.hpp}})

include({{SomeClassMain2.cpp}})

```

```bash
Compilation time: 0.25 sec
```
<!-- .element: class="fragment" -->

---

## Vad är `private` och `public`?

`private` - medlemmar nåbara *endast inom* klassen
<!-- .element: class="fragment" -->

`public` - medlemmar nåbara *utanför* klassen
<!-- .element: class="fragment" -->

Medlemmar är `private` om inget annat anges
<!-- .element: class="fragment" -->

--

### Varför `public`/`private`?

För att strukturera upp koden
<!-- .element: class="fragment" -->

Ger möjlighet till *Abstraktion* och *Inkapsling*
<!-- .element: class="fragment" -->

--

### Abstraktion

*Användaren behöver inte veta vad som händer under huven*

* Vet du hur en bils förbränningsmotor fungerar?
* Behöver du veta det? 
* Räcker det med att veta vad som händer när du trycker på gaspedalen?

--

### Inkapsling (Encapsulation)

*Saker som hänger ihop ska samlas*

--

### Ett exempel

--

```cpp[|3-4|6-9|11-22]
include({{Car1.hpp}})
```
<!-- .element: class="r-stretch" -->

--

### Nu provkör vi!

```cpp[7-8| 10-12 | 13-14]
include({{CarShort.hpp}})

include({{Car1Main.cpp}})
```
---

## `static` 

Hittills har alla funktioner och variabler varit ***medlemmar*** i klassen
--

De har varit ***knutna*** till en specifik ***instans*** 

--

Ex:

```cpp
Car volvo;
volvoPv.setup(100);

Car saab;
saab900Turbo.setup(200);

Car koeniggseggJeskoAbsolut;
koeniggseggJeskoAbsolut.setup(483);
```

--

Med **`static`** kan man skapa ***funktioner*** och ***variabler*** som ***delas*** av alla instanser av en ***klass***

--

```cpp
#include <iostream>

class MphConverter {
  private:
	static float mphToKmhFactor;

  public:
	static float toKmh(float mph){
		return mph*mphToKmhFactor;
	}
};

float MphConverter::mphToKmhFactor = 1.60934;

int main(){
	std::cout<<"60 mph is "<<MphConverter::toKmh(60)<<" Kmh";
}
```

```
60 mph is 96.5604 Kmh
```

---

## Konstruktorer

```cpp[7-8]
include({{CarShort.hpp}})

include({{Car1Main.cpp}})
```
hmm... inte så najs
<!-- .element: class="fragment" -->

--


* Körs när objekt skapas
* Tvinga medlemsvariabler att bli initialiserade

--

```cpp[1,11-14]
include({{Car2.hpp}})
```
<!-- .element: class="r-stretch" -->

--

### Nu provkör vi igen!

```cpp[6]
include({{CarShort.hpp}})

include({{Car2Main.cpp}})
```
Najsigare!

--

### Om jag vill ha flera bilar då?

--

```cpp[6]
include({{CarShort.hpp}})

include({{Car2Main2.cpp}})
```

--

```bash[2-5, 6-18]
include({{Car2Main2CompOut.txt}})
```
<!-- .element: class="r-stretch" -->

--

```cpp[11-13]
include({{Car3.hpp}})
```
<!-- .element: class="r-stretch" -->

```bash
Compilation time: 0.23 sec
```
<!-- .element: class="fragment" -->

--

### Varför fungerade det innan?

Kompilatorn skapade en *default-konstruktor* åt oss
<!-- .element: class="fragment" -->

De försvinner när man skapar egna konstruktorer
<!-- .element: class="fragment" -->

Man kan be kompilatorn skapa en dock
<!-- .element: class="fragment" -->

--

### Exempel:

```cpp[5]
include({{SomeClass4.hpp}})

include({{SomeClass4Main.cpp}})

```

```bash
Compilation time: 0.22 sec
```
<!-- .element: class="fragment" -->

--

Man kan också be kompilatorn ta bort en konstruktor

--

### Exempel:

```cpp[5,13]
include({{SomeClass5.hpp}})

include({{SomeClass5Main.cpp}})
```

--

```bash
include({{SomeClass5MainCompOut.txt}})
```

---

## Överlagring

Eller: 

***Flera konstruktorer*** som heter ***likadant***?

--

Det fungerar även på vanliga funktioner...

```cpp
include({{Overloading.cpp}})
```

```bash
Compilation time: 0.12 sec, absolute running time: 0.18 sec
```

--

### Vad händer under huven?

I ***kompileringen*** kommer namn att ***manglas***

* `int f()` blir `_Z1fv`
* `int f(int i)` blir  `_Z1fi`

--

### Varför

Då vet kompilatorn vilken ***version*** av funktionen du anropar

---

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

---

## `this`

Ett ***nyckelord*** (***keyword***) som fungerar som en ***pekare*** till det ***aktuella objektet***

--

När du i en ***medlemsfunktion*** använt dig av en annan ***medlem*** har `this` ***implicit*** använts

--

D.v.s., kompilatorn har lagt till `this` åt dig

--

```cpp[5]
include({{SomeClass2.hpp}})
};
```

blir
<!-- .element: class="fragment" -->

```cpp[5]
include({{SomeClass2.1.hpp}})
```
<!-- .element: class="fragment" -->

--

`this` kan också användas när en ***parameter** har ***samma namn*** som en ***medlemsvariabel***

Som i fallet med klassen `Car`. Låt oss ta en ny titt!
<!-- .element: class="fragment" -->

--

```cpp[6-8]
include({{Car3Short.hpp}})
```

blir
<!-- .element: class="fragment" -->

```cpp[6-8]
include({{Car4Short.hpp}})
```
<!-- .element: class="fragment" -->

---

## Konstanter

`const` gör att variabel inte kan ändras efter att den skapats.

Det blir alltså en konstant

--

```cpp[4]
include({{Car4Short.hpp}})
```

blir
<!-- .element: class="fragment" -->

```cpp[4]
include({{Car5Short.hpp}})
};
```
<!-- .element: class="fragment" -->

--

```bash[2-4 | 9-12]
include({{Car5ShortMainCompOut.txt}})

```
<!-- .element: class="r-stretch" -->

---

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

---

## Delegerande Konstruktorer

Ibland behöver man ***återanvända*** logik från en konstruktor i en ***annan***

--

```cpp
include({{Car7Short.hpp}})
```

--

```cpp
include({{Car8Short.hpp}})
```

--

### Pros & Cons

Logik kan ***återanvändas***

Kan ***inte*** kombineras med ***initialiseringslistor***

---

## struct

Som en klass typ

Men, allt är **`public`** istället för **`private`** per ***default***

--

```cpp[1]
include({{SomeClass2.hpp}})
```

blir

```cpp[1]
include({{SomeStruct.hpp}})
```

--

Använd **`struct`** istället för `class` när du vill ***gruppera data*** utan allt för mycket ***funktionalitet***. 

--

Exempelvis för ***aggregatklasser***

---

## Aggregatklasser

En klass utan:
* Konstruktorer (och destruktorer)*
* Privata icke-statiska medlemmar
* Utan arv (basklasser och virtuella funktioner)*

Vi kommer gå igenom vad detta är vid en senare föreläsning :-)

--

### Med initialiseringslista

```cpp
struct Vec3f { float x, y, z; };
struct Box { Vec3f min, max; };

int main(){
	Box myBox = { {1.0f, 2.0f, 3.0f}, {2.0f, 3.0f, 4.0f} };
}

```

---
## typedef


## inline

## Best practices
