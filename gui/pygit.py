
#!/usr/bin/env python

from Tkinter import *

class application:
   
    def __init__(self, master):
	
        
        self.topframe = Frame(master)
        self.topframe.pack(side=TOP,fill=X)

        search = Button(self.topframe, text='search', width=10,
                        height=1, command=self.search)
        search.pack(side=LEFT, fill=X)

        self.midframe = Frame(master)
        self.midframe.pack(fill=BOTH, expand=True)

        self.fileybar = Scrollbar(self.midframe, orient='vertical')
        self.fileybar.pack(side=RIGHT, fill=Y)
        
        self.filetext=Text(self.midframe, wrap=WORD, background='white',
                           width=30, height=15, fg='black')
        self.filetext.pack(side=RIGHT, fill=BOTH, expand=True)
       
        self.filetext.configure(yscrollcommand=self.fileybar.set)
        self.fileybar.config(command=self.filetext.yview)
        
        self.patchybar = Scrollbar(self.midframe, orient='vertical')
        self.patchybar.pack(side=LEFT, fill=Y)       

        self.patchtext=Text(self.midframe, wrap=WORD, background='white',
                             width=30, height=15, fg='black')
        self.patchtext.pack(side=LEFT, fill=BOTH, expand=True)

        self.patchtext.configure(yscrollcommand=self.patchybar.set)
        self.fileybar.config(command=self.patchtext.yview)
       
        self.botframe = Frame(master)
        self.botframe.pack(side=BOTTOM,fill=X)

        patch = Button(self.botframe, text='patch', fg='blue',
                       width=8, height=1, command=None)
        patch.pack(side=LEFT)
    
        file = Button(self.botframe, text='file', fg='blue', 
                      width=8, height=1, command=self.open_file)
        file.pack(side=LEFT, expand=True)   
        
        exit = Button(self.botframe, text='exit', fg='red',
                      width=8, height=1, command=master.quit)
        exit.pack(side=RIGHT)
   

    def open_file(self):
        
        f = open('11.txt', 'r')
        while True:
            text = f.readline()
            if text == '':
                break
            self.filetext.insert(END, text)
        

    def search(self):
        '''Each time click search button, then display a entry widget, which is stupid'''
        
        self.entry = Entry(self.topframe)
        self.entry.pack(side=LEFT, fill=X, expand=True) 
        self.string=self.entry.get()
        self.entry.bind('<Return>', self.search_text)
        
   
    def search_text(self, event):
        
        self.filetext.search(self.string, END, nocase=1)

   
    def patch(self):
        print "hello" 
        
        
if __name__ == '__main__':        

    root = Tk()
    s = application(root)
    root.title('pygit')
    root.mainloop()
