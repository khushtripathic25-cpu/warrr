# Student Record Management using 1D and 2D Arrays

roll_no = []
name = []
marks = []
students = []


def insert_student():
    r = int(input("Enter Roll Number: "))
    n = input("Enter Name: ")
    m = float(input("Enter Marks: "))

    roll_no.append(r)
    name.append(n)
    marks.append(m)
    students.append([r, n, m])

    print("Student record inserted successfully.")


def display_students():
    if not students:
        print("No student records available.")
        return

    print("Roll No. Name Marks")

    for s in students:
        print(s[0], s[1], s[2])


def search_student():
    r = int(input("Enter Roll Number to search: "))

    for s in students:
        if s[0] == r:
            print("Student Found!")
            print("Roll No:", s[0])
            print("Name:", s[1])
            print("Marks:", s[2])
            return

    print("Student record not found.")


def delete_student():
    r = int(input("Enter Roll Number to delete: "))

    for i in range(len(students)):
        if students[i][0] == r:
            students.pop(i)
            roll_no.pop(i)
            name.pop(i)
            marks.pop(i)

            print("Student record deleted successfully.")
            return

    print("Student record not found.")


while True:
    print("Student Record Management")
    print("1. Insert Student")
    print("2. Display Students")
    print("3. Search Student")
    print("4. Delete Student")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        insert_student()
    elif choice == 2:
        display_students()
    elif choice == 3:
        search_student()
    elif choice == 4:
        delete_student()
    elif choice == 5:
        print("Program terminated.")
        break
    else:
        print("Invalid choice.")