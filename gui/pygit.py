
#!/usr/bin/env python

from Tkinter import *
from tkFileDialog import *
import os

counter = 0
counter1 = 0
text = ''

class application:
   
    def __init__(self, master):
	
        
        self.topframe = Frame(master)
        self.topframe.pack(side=TOP,fill=X)

        search = Button(self.topframe, text='search', width=10, height=1)              
        search['command'] = self.search           
        search.pack(side=LEFT, fill=X)
        
        self.midframe = Frame(master)
        self.midframe.pack(fill=BOTH, expand=True)

        self.fileybar = Scrollbar(self.midframe, orient='vertical')
        self.fileybar.pack(side=RIGHT, fill=Y)
        
        self.filetext=Text(self.midframe, wrap=WORD, background='white',
                           width=30, height=15, fg='black')
        self.filetext['state'] = 'disable'
        self.filetext.pack(side=RIGHT, fill=BOTH, expand=True)
       
        self.filetext.configure(yscrollcommand=self.fileybar.set)
        self.fileybar.config(command=self.filetext.yview)
        
        self.patchybar = Scrollbar(self.midframe, orient='vertical')
        self.patchybar.pack(side=LEFT, fill=Y)       

        self.patchtext=Text(self.midframe, wrap=WORD, background='white',
                             width=30, height=15, fg='black')
        self.patchtext['state'] = 'disable'
        self.patchtext.pack(side=LEFT, fill=BOTH, expand=True)

        self.patchtext.configure(yscrollcommand=self.patchybar.set)
        self.fileybar.config(command=self.patchtext.yview)
       
        self.botframe = Frame(master)
        self.botframe.pack(side=BOTTOM,fill=X)

        patch = Button(self.botframe, text='patch', fg='blue',
                       width=8, height=1, command=self.patch)
        patch.pack(side=LEFT)
    
        file = Button(self.botframe, text='file', fg='blue', 
                      width=8, height=1, command=self.file)
        file.pack(side=LEFT, expand=True)   
        
        exit = Button(self.botframe, text='exit', fg='red',
                      width=8, height=1, command=master.quit)
        exit.pack(side=RIGHT)
   

    def file(self):
        
        self.open_file(self.filetext)
        
        
    def search(self):
        ''' Now entry only appear once'''
        global counter
        if counter == 0:
            self.entry = Entry(self.topframe)
            self.entry.pack(side=LEFT, fill=X, expand=True) 
            self.entry.bind('<Return>', self.search_text)
        counter = counter+1

   
    def search_text(self, event):
        
        global counter1
        
        if counter1 != 0:
            self.filetext.tag_add('normal', 1.0, END)
            self.filetext.tag_configure('normal', background='white')  

        self.str = self.entry.get()
        length = len(self.str)
        
        lastpos = self.filetext.index('end-1c')
        start = 1.0
        
        while start != lastpos:            
            pos = self.filetext.search(self.str, start, stopindex=END)        
            
            if length > 1:
                for i in range(length-1):  
              # the 'pos' argument is always wrong, I can not fix it.
                    self.filetext.tag_add('highlight', pos )
                    self.filetext.tag_configure('highlight', background='yellow')
                    pos = pos + '+1c'
                    pos = self.filetext.index(pos)        
                    
            self.filetext.tag_add('highlight', pos)
            self.filetext.tag_configure('highlight', background='yellow')
            start = pos + '+1c'   
            start = self.filetext.index(start)
       '''the above code can not execute, though above code can search
and highlight the matched string '''    
        self.filetext.tag_delete('highlight') 
        counter1 = counter1 +1
        
   
    def patch(self):
        
        self.open_file(self.patchtext)

     
    def open_file(self, textname):
        
        global text
        textname['state'] = 'normal'
        pwd = os.getcwd()# get current working directory

        mask = [("Text and Python files","*.txt *.py *.pyw"), 
               ("muse files","*.muse"), ("All files","*.*")]  

        file = askopenfile(initialdir=pwd, filetypes=mask, mode='r')
        text = file.read()
        if text != None:
           textname.delete(1.0, END)
           textname.insert(END, text)

        textname['state'] = 'disable'
      
        
if __name__ == '__main__':        

    root = Tk()
    s = application(root)
    root.title('pygit')
    root.mainloop()
