class Student:
    def __init__(self,number,name,sex,date,address,nuclass,department):
        self.number = number
        self.name = name
        self.sex = sex 
        self.date = date
        self.address = address
        self.nuclass = nuclass
        self.department = department
    def student(self):
        self.head = None 
    def check(self,x):
        if self.head == None :
            return False
        nstu = Student()
        self.head = nstu 
        while nstu!=None :
            if nstu.number == x:
                return True
            nstu = nstu.next 
        return False
    def InsertStudent(self,number,name,sex,date,address,nuclass,department):
        if check(number):
            print("Student already exist")
            return
        #create a new student
        nstu = Student()
        nstu.number = number
        nstu.name = name
        nstu.sex = sex
        nstu.date = date
        nstu.address = address
        nstu.nuclass = nuclass
        nstu.department = department

        #insert at begin 
        if self.head == None or self.head.number >= nstu.number :
            nstu.next = self.head 
            self.head = nstu
        else :
            nstu2 = Student(number,name,sex,date,address,nuclass,department)
            nstu2 = self.head 
            while(nstu2.next != None and nstu2.next.number < nstu.number):
                nstu.next = nstu2.next
                nstu2.next = nstu
            print("Successfully")
    def SortNumberofStudent(self,head):
        current = head
        index = Student(None)

        if head is None:
            return
        else:
            while current is not None:
                index = current.next
                while index is not None:
                    if current.number>index.number:
                        current.number,index.number=index.number,current.number

                    index = index.next
                current = current.next

    def printStudent(self):
        nstu = Student()
        nstu.number = self.number
        nstu.name = self.name
        nstu.sex = self.sex
        nstu.date = self.date
        nstu.address = self.address
        nstu.nuclass = self.nuclass
        nstu.department = self.department

        nstu = self.head
        while(nstu):
            print(str(nstu.number) + " ",end=" ")
            print(str(nstu.name)+ " ",end=" ")
            print(str(nstu.sex)+ " ",end=" ")
            print(str(nstu.date)+ " ",end=" ")
            print(str(nstu.address)+ " ",end=" ")
            print(str(nstu.nuclass)+ " ",end=" ")
            print(str(nstu.department)+ " ",end=" ")

            nstu = nstu.next
       
    def SearchStudent(self,date):
        if self.head is None:
            print("Error search")
            return
        else: 
            p = Student()
            p = self.head
            while(p):
                if p.date == date :
                    print("Number: ",p.number)
                    print("Name: ",p.name)
                    print("Sex: ",p.sex)
                    print("Date: ",p.date)
                    print("Address: ",p.address)
                    print("Class: ",p.nuclass)
                    print("Department: ",p.department)
                    return
                p = p.next
            if p == None:
                print("khong tim thay sinh vien")
    def DeleteStudent(self,date):
        
        temp = self.head
        if temp.head != None and temp.date == date:
            temp = temp.next
            del temp

        return 0

if __name__ == '__main__':
    lopETTN = Student(0,0,0,0,0,0,0)
    lopETTN.InsertStudent()
    lopETTN.SortNumberofStudent(lopETTN.head)
    lopETTN.printStudent()
    lopETTN.SearchStudent(9)
    lopETTN.DeleteStudent(9)
    lopETTN.printStudent()
