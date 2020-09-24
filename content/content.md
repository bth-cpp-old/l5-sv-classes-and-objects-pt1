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

## Varför klasser?

Ni har jobbat med funktioner och variabler
<!-- .element: class="fragment" -->

Det kan bli grötigt i stora projekt
<!-- .element: class="fragment" -->

Med klasser kan man dela upp koden modulärt
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="slide-in fade-out" -->

```cpp[1|2|4-6]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		...
	}
};
```

--

<!-- .slide: data-transition="fade slide-out" -->
Funktioner i ett objekt kan nå variablerna i detsamma

```cpp[4-6]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		piIsh = 22.0f / 7.0f;
	}
};
```
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="slide-in fade" -->

Hur skapar man objekten från klasserna?

```cpp[10]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		piIsh = 22.0f / 7.0f;
	}
};

int main() {
    SomeClass myClass;
}
```
<!-- .element: class="fragment" -->

```bash[|1|2|4]
Warning(s):
35285585/source.cpp:16:15: warning: unused variable 'myClass' \
     [-Wunused-variable]
    SomeClass myClass;
              ^
1 warning generated.
```
<!-- .element: class="fragment" -->

--

<!-- .slide: data-transition="fade" -->
	
```cpp[12]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		piIsh = 22.0f / 7.0f;
	}
};

int main() {
    SomeClass myClass;
    myClass.calcPiIsh());
}
```

```bash[|1|6|7]
Error(s):
240841000/source.cpp:17:13: error: 'memberFunctionA' is a  \
    member of 'SomeClass'
    myClass.calcPiIsh();
            ^
240841000/source.cpp:7:7: note: implicitly declared private here
        void calcPiIsh(){
             ^
1 error generated.
```
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->
	
```cpp[2,4]
class SomeClass {
  private:
	float piIsh;
  public:
	void calcPiIsh(){
		piIsh = 22.0f / 7.0f;
	}
};

int main() {
    SomeClass myClass;
    myClass.calcPiIsh());
}
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

## Varför `public`/`private`?

För att strukturera upp koden
<!-- .element: class="fragment" -->

Ger möjlighet till *Abstraktion* och *Inkapsling*
<!-- .element: class="fragment" -->

--

## Abstraktion

*Användaren behöver inte veta vad som händer under huven*

* Vet du hur en bils förbränningsmotor fungerar?
* Behöver du veta det? 
* Räcker det med att veta vad som händer när du trycker på gaspedalen?

--

## Inkapsling (Encapsulation)

*Saker som hänger ihop ska samlas*

--

## Ett exempel

--

```cpp[|3-4|6-9|11-22]
class Car {
  private:
	float speed;
	float maxSpeed;
  
	void sanityCheckSpeed(){
		if (speed < 0) speed = 0.0f;
		if (speed > maxSpeed) speed = maxSpeed;
	}
  public:
	void setup(float p_maxSpeed){
		speed = 0.0f;
		maxSpeed = p_maxSpeed;
	}
	void accelerate(float pedalFactor){
		speed += 10 * pedalFactor;
		sanityCheckSpeed();
	}
	void applyBreak(float pedalFactor){
		speed -= 10 * pedalFactor;
		sanityCheckSpeed();
	}
};
```
<!-- .element: class="r-stretch" -->

--

## Nu provkör vi!

```cpp[|7-8| 10-12 | 13-14 | 7-8 ]
class Car {
  ...
};

int main() {
    Car minVolvo242Gl;
    minVolvo242Gl.setup(120);
    
    minVolvo242Gl.accelerate(1.0f); // Full gas!
    minVolvo242Gl.accelerate(1.0f); // Bra drag!
    minVolvo242Gl.accelerate(1.0f); // Nu börjar det gå lite fort..
    minVolvo242Gl.applyBreak(42.0f); // Rådjur!!!
    minVolvo242Gl.applyBreak(1.0f); // Puh!!! Vi överlevde!
}
```
hmm... inte så najs
<!-- .element: class="fragment" -->

---

## Konstruktorer

* Körs när objekt skapas
* Tvinga medlemsvariabler att bli initialiserade

--

```cpp[1,11-14]
class Car {
  private:
	float speed;
	float maxSpeed;
  
	void sanityCheckSpeed(){
		if (speed < 0) speed = 0.0f;
		if (speed > maxSpeed) speed = maxSpeed;
	}
  public:
	Car(float p_maxSpeed){
		speed = 0.0f;
		maxSpeed = p_maxSpeed;
	}
	void accelerate(float pedalFactor){
		speed += 10 * pedalFactor;
		sanityCheckSpeed();
	}
	void applyBreak(float pedalFactor){
		speed -= 10 * pedalFactor;
		sanityCheckSpeed();
	}
};
```
<!-- .element: class="r-stretch" -->

--

## Nu provkör vi igen!

```cpp[7]
class Car {
  ...
};

int main() {
    Car minNyaVolvo242Gl(120);
    
    minNyaVolvo242Gl.accelerate(1.0f); // Full gas!
    minNyaVolvo242Gl.accelerate(1.0f); // Bra drag!
    minNyaVolvo242Gl.accelerate(1.0f); // Det börjar gå lite fort..
    minNyaVolvo242Gl.applyBreak(42.0f); // Rådjur!!!
    minNyaVolvo242Gl.applyBreak(1.0f); // Puh!!! Vi överlevde!
}
```
Najsigare!

--

## Om jag vill ha flera bilar då?

--

```cpp[6]
class Car {
  ...
};

int main() {
    Car cars[10];
}
```

--

```bash[2-5, 6-18]
Error(s):
193206876/source.cpp:24:9: error: no matching constructor for \
	initialization of 'Car [10]'
    Car cars[10];
        ^
193206876/source.cpp:11:5: note: candidate constructor not viable: \
	requires single argument 'maxSpeed', but no arguments were provided
    Car(float maxSpeed) : maxSpeed(maxSpeed){}
    ^
193206876/source.cpp:1:7: note: candidate constructor \
	(the implicit copy constructor) not viable: \
	requires 1 argument, but 0 were provided \
class Car {
      ^
193206876/source.cpp:1:7: note: candidate constructor \
	(the implicit move constructor) not viable: \
	requires 1 argument, but 0 were provided \
1 error generated.
```
<!-- .element: class="r-stretch" -->

--

```cpp[11]
class Car {
  private:
	float speed;
	const float maxSpeed;
	
	void sanityCheckSpeed(){
		if (speed < 0) speed = 0.0f;
		if (speed > maxSpeed) speed = maxSpeed;
	}
  public:
	Car() : maxSpeed(100){}
	Car(float p_maxSpeed){
        speed = 0.0f;
        maxSpeed = p_maxSpeed;
    }
	void accelerate(float pedalFactor){
		speed += 10 * pedalFactor;
		sanityCheckSpeed();
	}
	void applyBreak(float pedalFactor){
		speed -= 10 * pedalFactor;
	  	sanityCheckSpeed();
	}
};
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
class SomeClass {
  private:
	float piIsh;
  public:
	SomeClass() = default;
	SomeClass(float customPi) : piIsh(customPi){}
};

int main(){
    SomeClass myPis[42];
    SomeClass myPi(22.0f / 7.0f);
}
```

```bash
Compilation time: 0.22 sec
```
<!-- .element: class="fragment" -->

--

Man kan också be kompilatorn ta bort en konstruktor

--

### Exempel:

```cpp[]
class SomeClass {
  private:
	float piIsh;
  public:
	SomeClass() = default;
	SomeClass(float customPi) : piIsh(customPi){}
};

int main(){
    SomeClass myPi(22.0f / 7.0f);
    SomeClass mySecondPi(myPi);
}
```

```bash
Compilation time: 0.22 sec
```

--

```cpp[6]
class SomeClass {
  private:
	float piIsh;
  public:
	SomeClass() = default;
	SomeClass(SomeClass&) = delete;
	SomeClass(float customPi) : piIsh(customPi){}
};

int main(){
    SomeClass myPi(22.0f / 7.0f);
    SomeClass mySecondPi(myPi);
}
```

```bash
Error(s):
source.cpp:12:15: error: call to deleted constructor of 'SomeClass'
    SomeClass mySecondPi(myPi);
              ^          ~~~~
source.cpp:6:2: note: 'SomeClass' has been explicitly marked \
    deleted here
        SomeClass(SomeClass&) = delete;
        ^
1 error generated.
```

---

## Överlagring

Eller: 

***Flera konstruktorer*** som heter ***likadant***?

--

Det fungerar även på vanliga funktioner...

```cpp
#include <cassert>

int f(){ return 42; }
int f(int i){ return i; }

int main(){
    assert( f() == 42);
    assert( f(7) == 7);
}
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
class Car {
	private:
	float speed;
	float maxSpeed;
  	...
	Car(float p_maxSpeed){
		speed = 0.0f;
		maxSpeed = p_maxSpeed;
	...
};
```

Varför heter `p_maxSpeed`, inte `maxSpeed`... ?

--
<!-- .slide: data-transition="fade" -->

```cpp[4,8]
class Car {
	private:
	float speed;
	float maxSpeed;
  	...
	Car(float p_maxSpeed){
		model = p_model;
		maxSpeed = p_maxSpeed;
	...
};
```

En medlemsvariabel heter redan `maxSpeed`

--
<!-- .slide: data-transition="fade slide-out" -->

```cpp[4,6,8]
class Car {
	private:
	float speed;
	float maxSpeed;
  	...
	Car(float p_maxSpeed){
		model = p_model;
		maxSpeed = p_maxSpeed;
	...
};
```
Om medlemsvariabeln inte ska ***gå ur scope*** måste parametern heta något annat

--

Typ `p_maxSpeed`

Eller...
<!-- .element: class="fragment" -->

---

## Låt mig introducera

--

## `this`

Ett ***nyckelord*** (***keyword***) som fungerar som en ***pekare*** till det ***aktuella objektet***

--

När du i en ***medlemsfunktion*** använt dig av en annan ***medlem*** har `this` ***implicit*** använts

--

D.v.s., kompilatorn har lagt till `this` åt dig

--

```cpp[5]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		piIsh = 22.0f / 7.0f;
	}
};
```

blir
<!-- .element: class="fragment" -->

```cpp[5]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		this->piIsh = 22.0f / 7.0f;
	}
};
```
<!-- .element: class="fragment" -->

--

`this` kan också användas när en ***parameter** har ***samma namn*** som en ***medlemsvariabel***

Som i fallet med klassen `Car`. Låt oss ta en ny titt!
<!-- .element: class="fragment" -->

--

```cpp[6-8]
class Car {
	private:
	float speed;
	float maxSpeed;
  	...
	Car(float p_maxSpeed){
		speed = 0.0f;
		maxSpeed = p_maxSpeed;
	...
};
```

blir
<!-- .element: class="fragment" -->

```cpp[6-8]
class Car {
	private:
	float speed;
	float maxSpeed;
  	...
	Car(float maxSpeed){
		speed = 0.0f;
		this->maxSpeed = maxSpeed;
	...
};
```
<!-- .element: class="fragment" -->

---

## Konstanter

`const` gör att variabel inte kan ändras efter att den skapats.

Det blir alltså en konstant

--

```cpp[4]
class Car {
	private:
	float speed;
	float maxSpeed;
  	...
	Car(float maxSpeed){
		speed = 0.0f;
		this->maxSpeed = maxSpeed;
	...
};
```

blir
<!-- .element: class="fragment" -->

```cpp[4]
class Car {
	private:
	float speed;
	const float maxSpeed;
  	...
	Car(float maxSpeed){
		speed = 0.0f;
		this->maxSpeed = maxSpeed;
	...
};
```
<!-- .element: class="fragment" -->

--

```bash[2-4 | 9-12]
Error(s):
1172188222/source.cpp:11:2: error: constructor for 'Car' must explicitly \
	initialize the const member 'maxSpeed'
        Car(float p_maxSpeed){
        ^
1172188222/source.cpp:4:14: note: declared here
        const float maxSpeed;
                    ^
1172188222/source.cpp:12:12: error: cannot assign to non-static data \
	member 'maxSpeed' with const-qualified type 'const float'
                maxSpeed = p_maxSpeed;
                ~~~~~~~~ ^
1172188222/source.cpp:4:14: note: non-static data member 'maxSpeed' \
	declared const here
        const float maxSpeed;
        ~~~~~~~~~~~~^~~~~~~~
2 errors generated.
```
<!-- .element: class="r-stretch" -->

---

## Initialiseringslistor

Ett annat sätt att initialisera medlemsvariabler

--

```cpp[7-9]
class Car {
  private:
	float speed;
	const float maxSpeed;
	...
  public:
	Car(float maxSpeed){
        speed = 0.0f;
		this->maxSpeed = maxSpeed;
	}
	...
  };
```

blir
<!-- .element: class="fragment" -->

```cpp[7]
class Car {
  private:
	float speed;
	const float maxSpeed;
	...
  public:
	Car(float maxSpeed) : speed(0.0f), maxSpeed(maxSpeed){}
	...
  };
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

Mindre risk för fallet

Det händer att man glömmer `this?  exempelvis
<!-- .element: class="fragment" -->

---

## Delegerande Konstruktorer

## Aggregatklasser


## typedef

## static 

## inline

## struct