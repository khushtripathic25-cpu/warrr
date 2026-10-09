books = []

def store_books():
    n = int(input("Enter number of books: "))

    for i in range(n):
        books.append(int(input("Enter Book ID: ")))

    books.sort()
    print("Book IDs stored:", books)


def linear_search():
    key = int(input("Enter Book ID to search: "))

    for i in range(len(books)):
        if books[i] == key:
            print("Book Available")
            print("Location:", i + 1)
            return

    print("Book Not Available")


def binary_search():
    key = int(input("Enter Book ID to search: "))

    low = 0
    high = len(books) - 1

    while low <= high:
        mid = (low + high) // 2

        if books[mid] == key:
            print("Book Available")
            print("Location:", mid + 1)
            return
        elif books[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    print("Book Not Available")


def display_books():
    print("Book IDs:", books)


while True:
    print("1. Store Book IDs")
    print("2. Display Book IDs")
    print("3. Linear Search")
    print("4. Binary Search")
    print("5. Exit")

    choice = int(input("Enter choice: "))

    if choice == 1:
        store_books()
    elif choice == 2:
        display_books()
    elif choice == 3:
        linear_search()
    elif choice == 4:
        binary_search()
    elif choice == 5:
        print("Program terminated.")
        break