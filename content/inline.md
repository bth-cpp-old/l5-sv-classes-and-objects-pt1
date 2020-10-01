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