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