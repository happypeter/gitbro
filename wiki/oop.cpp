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

A: this is a issue of grabage collection, below is what I found, and it confused me more:-)

http://en.wikipedia.org/wiki/C%2B%2B#Criticism
	Some have criticized C++ for not having garbage collection, Dr. Stroustrup even discusses this on his website, he states that the memory management capabilities of C++ essentially perform the same function as garbage collection without an implicit garbage collector.

http://en.wikipedia.org/wiki/Delete_(C%2B%2B)
	A call to delete must be made for every call to new to avoid a memory leak.

so the above two links convined me that I will be better off if I can use delete for all newed items, it is just safer.
