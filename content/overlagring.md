## Överlagring

--

Eller: 

***Flera medlemsfunktioner*** som heter ***likadant***

--

Det fungerar även på vanliga funktioner...

```cpp
includecpp({{Overloading.cpp}})
```

```bash
includecpp({{OverloadingOut.txt}})
```

--

### Vad händer under huven?

I ***kompileringen*** kommer namn att ***manglas***

* `int f()` blir `_Z1fv` <!-- .element: class="fragment" -->
* `int f(int i)` blir  `_Z1fi` <!-- .element: class="fragment" -->

Note:
fv, funktionens namn och void
- void som i tomhet
- void, precis som returvärdet

fi, funktionens namn och int

Notera att returvärdet ej finns med i manglingen

Exemplet ovan är från Linux/GCC
--

### Varför mangling

Då vet länkaren vilken ***version*** av funktionen du anropar
