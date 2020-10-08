






	<!doctype html>
	<html>

	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">

		<title>Classes and Objects pt1</title>

		<link rel="stylesheet" href="dist/reset.css">
		<link rel="stylesheet" href="dist/reveal.css">
		<link rel="stylesheet" href="dist/theme/serif.css" id="theme">

		<!-- Theme used for syntax highlighted code -->
		<link rel="stylesheet" href="plugin/highlight/monokai.css" id="highlight-theme">
	</head>

	<body>
		<div class="reveal">
			<div class="slides">
				<section data-separator-vertical="^--" data-separator-notes="^Note:" data-markdown>
					<script type="text/template">
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

Hur skapar man objekt från klasser?

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

```bash[|1|2-3]
Warning(s):
s.cpp:11:15: warning: unused variable 'myClass' [-Wunused-variable]
    SomeClass myClass;
              ^
1 warning generated.
```
<!-- .element: class="fragment" -->

--

```cpp[11]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		piIsh = 22.0f / 7.0f;
	}
};

int main() {
    SomeClass myClass;
    myClass.calcPiIsh();
}

```

```bash[|1|2-3|5-6]
Error(s):
s.cpp:14:13: error: 'calcPiIsh' is a private member of 'SomeClass'
    myClass.calcPiIsh();
            ^
s.cpp:7:10: note: implicitly declared private here
    void calcPiIsh(){
         ^
1 error generated.
```
<!-- .element: class="fragment" -->

--
<!-- .slide: data-transition="fade" -->
	
```cpp[2,5]
class SomeClass {
 private:
  float piIsh;

 public:
  void calcPiIsh() { piIsh = 22.0f / 7.0f; }
};

int main() {
    SomeClass myClass;
    myClass.calcPiIsh();
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

### Nu provkör vi!

```cpp[7-8| 10-12 | 13-14]
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
<!-- .element: class="r-stretch" -->

```
60 mph is 96.5604 Kmh
```

---

## Konstruktorer

--

```cpp[7-8]
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

--

### Konstruktorer...

Körs när objekt skapas
<!-- .element: class="fragment" -->

Kan användas tll att ***tvinga medlemsvariabler*** att bli ***initialiserade***
<!-- .element: class="fragment" -->

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

### Nu provkör vi igen!

```cpp[6]
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

### Om jag vill ha flera bilar då?

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

```bash[2-3 | 5-14]
Error(s):
s.cpp:24:9: error: no matching constructor for initialization of 'Car [10]'
    Car cars[10];
        ^
s.cpp:11:5: note: candidate constructor not viable: \
		requires single argument 'maxSpeed', but no arguments were provided
    Car(float maxSpeed) : maxSpeed(maxSpeed){}
    ^
s.cpp:1:7: note: candidate constructor (the implicit copy constructor) \
		not viable: requires 1 argument, but 0 were provided \
class Car {
      ^
s.cpp:1:7: note: candidate constructor (the implicit move constructor) \
	not viable: requires 1 argument, but 0 were provided \
1 error generated.
```
<!-- .element: class="r-stretch" -->

--

```cpp[11-14]
class Car {
  private:
	float speed;
	float maxSpeed;
	
	void sanityCheckSpeed(){
		if (speed < 0) speed = 0.0f;
		if (speed > maxSpeed) speed = maxSpeed;
	}
  public:
	Car(){
        speed = 0.0f;
        maxSpeed = 100;
    }
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
		SomeClass(float customPi){
        piIsh = customPi;
    }
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

```cpp[6,12]
class SomeClass {
 private:
  float piIsh;

 public:
  SomeClass(int customPi) = delete;
  SomeClass(float customPi) { piIsh = customPi; }
};

int main(){
    SomeClass myPi(22.0f / 7.0f);
    SomeClass mySecondPi(42);
}
```

```bash[2-3|5-6]
Error(s):
s.cpp:13:15: error: call to deleted constructor of 'SomeClass'
    SomeClass mySecondPi(42);
              ^          ~~
s.cpp:5:2: note: 'SomeClass' has been explicitly marked deleted here
        SomeClass(int customPi) = delete;
        ^
1 error generated.
```
<!-- .element: class="fragment" -->


---

## Överlagring

Eller: 

***Flera konstruktorer*** som heter ***likadant***?

--

Det fungerar även på vanliga funktioner...

```cpp
#include <iostream>

int f(){ return 42; }
int f(int i){ return i; }

int main(){
    std::cout<<f()<<std::endl;
    std::cout<<f(7)<<std::endl;
}
```

```bash
Compilation time: 0.52 sec, absolute running time: 0.16 sec

42
7

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
		speed = 0.0f;
		maxSpeed = p_maxSpeed;
	...
};
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
		speed = 0.0f;
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
};
```

är alltså egentligen
<!-- .element: class="fragment" -->

```cpp[5]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		(*this).piIsh = 22.0f / 7.0f;
	}
};
```
<!-- .element: class="fragment" -->

--

### `(*pointer).`

kan också skrivas som

### `pointer->`

--

```cpp[5]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		(*this).piIsh = 22.0f / 7.0f;
	}
};
```

är alltså samma som

```cpp[5]
class SomeClass {
	float piIsh;

	void calcPiIsh(){
		this->piIsh = 22.0f / 7.0f;
	}
};
```

--

De betyder ***samma sak***, men

### `->`

***föredras*** oftast

--

`this` kan också användas när en ***parameter*** har ***samma namn*** som en ***medlemsvariabel***

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

 public:
  Car(float maxSpeed) {
    speed = 0.0f;
    this->maxSpeed = maxSpeed;
  }
  ...
  };
```
<!-- .element: class="fragment" -->


---

## Initialiseringslistor

Ett annat sätt att initialisera medlemsvariabler

--

```cpp[6-9]
class Car {
 private:
  float speed;
  float maxSpeed;
  ...

 public:
  Car(float maxSpeed) {
    speed = 0.0f;
    this->maxSpeed = maxSpeed;
  }
  ...
  };

```

blir
<!-- .element: class="fragment" -->

```cpp[6]
class Car {
 private:
  float speed;
  float maxSpeed;
  ...
  Car(float maxSpeed) : speed(0.0f), maxSpeed(maxSpeed){}
  ...
};
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


---

## Konstanter

(som ni kanske vet)

**`const`** gör att variabel ***inte*** kan ***ändras*** efter att den ***skapats***
<!-- .element: class="fragment" -->

Det blir alltså en konstant
<!-- .element: class="fragment" -->

--

**`const`** kan användas både till ***medlemsvariabler***, ***parametrar*** och ***medlemsfunktioner*** 

--

Ex:

```cpp[4]
class Car {
 private:
  float speed;
  float maxSpeed;
  ...

 public:
  Car(float maxSpeed) {
    speed = 0.0f;
    this->maxSpeed = maxSpeed;
  }
  ...
  };
```

--

Blir

```cpp[4]
class Car {
 private:
  float speed;
  const float maxSpeed;
  ...

 public:
  Car(float maxSpeed) {
    speed = 0.0f;
    this->maxSpeed = maxSpeed;
  }
  ...
  };
```

--

### Men det kompilerar ju inte?!

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

--

Kompileringsfelet fixar man med ***initialiseringslistor***!

```cpp[8]
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

### `const`-parametrar

Parametrar som är **`const`** kan ***inte*** modifieras ***i funktionen***

```cpp[8]
class Car {
 private:
  float speed;
  const float maxSpeed;
  ...

 public:
  Car(const float maxSpeed) : speed(0.0f), maxSpeed(maxSpeed){}
  ...
};
```
<!-- .element: class="fragment" -->

--

### `const`-medlemsfunktioner

En ***medlemsfunktion*** som är **`const`** kan ***inte*** modifiera ***medlemsvariabler***

```cpp[8]
class Car {
 private:
  float speed;
  const float maxSpeed;
  ...

 public:
  float getSpeed() const { return speed; }
  ...
};
```
<!-- .element: class="fragment" -->

---

## Delegerande Konstruktorer

Ibland behöver man ***återanvända*** logik från en konstruktor i en ***annan***

--

```cpp
class Car {
  private:
    std::string makeAndModel
	float maxSpeed;
	float speed;
	...
  public:
	Car() : speed(0.0f), maxSpeed(100){}
    Car(float maxSpeed) : speed(0.0f){
        if (maxSpeed > 240) maxSpeed = 240;
        if (maxSpeed < 0) maxSpeed = 100;
    }
    Car(float maxSpeed, std::string makeAndModel)
		: speed(0.0f), makeAndModel(makeAndModel){
        if (maxSpeed > 240) maxSpeed = 240;
        if (maxSpeed < 0) maxSpeed = 100;
    }
};
```

--

```cpp
class Car {
  private:
    std::string makeAndModel
	  float maxSpeed;
	  float speed;
	  ...
  public:
	  Car() : speed(0.0f), maxSpeed(100){}
    Car(float maxSpeed) : Car() {
        if (maxSpeed > 240) maxSpeed = 240;
        if (maxSpeed < 0) maxSpeed = 100;
    }
    Car(float maxSpeed, std::string makeAndModel): Car(maxSpeed){
        this->makeAndModel = makeAndModel;
    }
};
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
incincludecpp(SomeClass2.hpp)
```

blir

```cpp[1]
incincludecpp(SomeStruct.hpp)
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

Fördel? De kan initieras med en ***Initialiseringslista***

--

```cpp
struct Vec3f { float x, y, z; };
struct Box { Vec3f min, max; };

int main(){
	Box myBox = { {1.0f, 2.0f, 3.0f}, {2.0f, 3.0f, 4.0f} };
}

```

---

## Aliasing

```cpp
typedef int cm;
```

eller

```cpp
using cm = int;
```

--

Används som typ:

```cpp
struct Box {
    cm length;
    cm height;
    cm width;
};
```

--

### Praktiska att använda ihop med klasser

```cpp
struct Box {
    using cm = int;
    cm length;
    cm height;
    cm width;
};

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

struct Box {
    cm length;
    cm height;
    cm width;
};

int main(){
    Box b;
    inch length = 20;
    b.length = length;
}
```

--

Alias är ***inte riktiga*** typer, de är ***svaga*** (eng: weak) typer



---

## `inline`

***Tipsar*** om att en funktion kan ***inlineas***

--

Vid ***inlining*** ersätts funktionsanropet med en ***copy-paste*** av funktionsdefinitionen

--

Ex:

```cpp
inline void add(int a, int b){
    return a+b:
}

int main(){
    int result = add (43, 1338);
}
```

blir:

```cpp
int main(){
    int result = 43 + 1338;
}
```

--

I verkligheten kommer din ***kompilator*** själv ***avgöra*** vad som inlineas och inte

**`inline`** är ett ***tips*** till kompilatorn, ***ingen instruktion***

---

## Best practices

--

###  `SomeClass.hpp` och `SomeClass.cpp`

Du bör lägga din ***klassdeklaration*** i en `*.hpp`-fil

```cpp
class Car {
 private:
  float speed;
  const float maxSpeed;

  void sanityCheckSpeed();

 public:
  Car() : speed(0.0f), maxSpeed(100) {}
  Car(const float maxSpeed) : speed(0.0f), maxSpeed(maxSpeed) {}
  void accelerate(float pedalFactor);
  void applyBreak(float pedalFactor);
  float getSpeed() const;
};
```

--

och din ***klassdefinition*** i en `*.cpp`-fil

```cpp
#include <Car.hpp>

void Car::sanityCheckSpeed() {
  if (speed < 0) speed = 0.0f;
  if (speed > maxSpeed) speed = maxSpeed;
}

void Car::accelerate(float pedalFactor) {
  speed += 10 * pedalFactor;
  sanityCheckSpeed();
}
void Car::applyBreak(float pedalFactor) {
  speed -= 10 * pedalFactor;
  sanityCheckSpeed();
}
float Car::getSpeed() const { return speed; }
```
<!-- .element: class="r-stretch" -->

--

## Ska man ha `public` eller `private` först?

```cpp
class Car {
 public:
  Car() : speed(0.0f), maxSpeed(100) {}
  Car(const float maxSpeed) : speed(0.0f), maxSpeed(maxSpeed) {}
  void accelerate(float pedalFactor);
  void applyBreak(float pedalFactor);
  float getSpeed() const;

 private:
  float speed;
  const float maxSpeed;

  void sanityCheckSpeed();
};
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

					</script>
				</section>
			</div>
		</div>

		<script src="dist/reveal.js"></script>
		<script src="plugin/notes/notes.js"></script>
		<script src="plugin/markdown/markdown.js"></script>
		<script src="plugin/highlight/highlight.js"></script>
		<script>
			// More info about initialization & config:
			// - https://revealjs.com/initialization/
			// - https://revealjs.com/config/
			Reveal.initialize({
				hash: true,
				slideNumber: true,

				// Learn about plugins: https://revealjs.com/plugins/
				plugins: [RevealMarkdown, RevealHighlight, RevealNotes]
			});
		</script>
	</body>

	</html>