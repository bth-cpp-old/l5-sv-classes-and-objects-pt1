traceon(`M', `include', `patsubst')dnl

define(`M', `include(OverloadingOut.txt)')dnl
#define(`M', `,,,,')dnl

#M
#patsubst(defn(`M'),`,',`.')
#defn(`include(OverloadingOut.txt)')


changequote(`{{', `}}')dnl
esyscmd({{sed 's/,/&#44;/g' ../src/OverloadingOut.txt}})

define({{filter}},{{esyscmd({{sed -e 's/,/\&#44;/g' -e 's/</\&lt;/g' -e 's/>/\&gt;/g' -e 's/,/\&#44;/g' -n -e '$2,$3 p' ../src/$1 }})}})dnl
#define({{filterlt}},{{patsubst(filterff($1,$2,$3),{{<}},{{&lt;}})}})dnl
#define({{filtergt}},{{patsubst(filterlt($1,$2,$3),{{>}},{{&gt;}})}})dnl
define({{includecpp}},{{filter($1,{{1}},{{$}})}})dnl
define({{includecpplines}},{{filter($1,$2,$3)}})dnl

traceon({{filterff}},{{filterlt}},{{filtergt}},{{includecpp}})dnl

includecpp({{Overloading.cpp}})
includecpplines({{Car8Short.hpp}}, {{1}},{{$}})

#filterff({{OverloadingOut.txt}})
