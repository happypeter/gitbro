#dyncamic storage allocation

Q: why I have to use new and delete? I know its advatage over C malloc() and free(),
but my question is that what's the point to use Dynamic allocation at all? 

A: the realated chapeter in `thinking in C++` does not satisfied me, the answer there was
that you do not know how many objects you need, so you need to use new to allocated them on
the go. But that is ridiculous, if you do not know how many objects to define, how come you know
how many to `new`!!!

Q: It seems that if you use stack area, that is to allocate your memeroy with the local defination,
the storage will be freeed, when the execution reaches the ending `}`. But the `new`ed area on the heap
does not follow that rule, `Thinking in C++` tells me you need to be responsible to delete the objects, 
but I never did so, but my programs just run so well, why? 

A: 
