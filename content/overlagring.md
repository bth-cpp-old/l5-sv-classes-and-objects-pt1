
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
