## Aggregatklasser

--

### En klass utan
1. Konstruktorer (och destruktorer)*
<!-- .element: class="fragment" -->
1. Privata icke-statiska medlemmar
<!-- .element: class="fragment" -->
1. Arv (basklasser och virtuella funktioner)*
<!-- .element: class="fragment" -->

*Vi kommer gå igenom vad detta är vid en senare föreläsning 😀
<!-- .element: class="fragment" -->

--

Fördel? De kan initieras med en ***initialiseringslista***

--
### Ett exempel:
```cpp[1|5|2|6]
includecpp({{aggregates.cpp}})
```