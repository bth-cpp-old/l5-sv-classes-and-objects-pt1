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
