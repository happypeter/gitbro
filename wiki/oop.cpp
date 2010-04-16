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

YET, luckily qt make life easier by 

http://lists.trolltech.com/qt-interest/2003-12/msg00849.html

	> I've often seen in QT examples that the QObjects are created
	> dynamically, but i've never seen their destruction.
	> like this:
	> 
	> QMyWidget::QMyWidget(...):QMainWindow(...)
	> {
	>     QPushButton * button=new QPushButton(this);
	>     connect(...);
	> }
	> 
	> Is Qt delete they automatically? or is it cleaner to delete they in a
	> destructor function?

	QObjects automatically delete their children, it's one of the first things
	you can read in the tutorials or basic docs.

	See doc/html/objecttrees.html

