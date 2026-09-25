import numpy as np
def add_book(book_list, book):
    book_list.append(book)
    return book_list
def remove_book(book_list, book):
    if book in book_list:
        book_list.remove(book)
    else:
        print(f"{book} not found in the list.")
    return book_list
def add_member(member_list, member):
    member_list.append(member)
    return member_list
def remove_member(member_list, member):
    if member in member_list:
        member_list.remove(member)
    else:
        print(f"{member} not found in the list.")
    return member_list
def borrow_book(book_list, member_list, book, member,history):
    if book in book_list and member in member_list:
        book_list.remove(book)
        print(f"{member} borrowed {book}.")
        history.append((member, book))
    else:
        print(f"Either {book} is not available or {member} is not a registered member.")
    return book_list
def return_book(book_list, member_list, book, member, history):
    if (member, book) in history:
        book_list.append(book)
        print(f"{member} returned {book}.")
    else:
        print(f"{member} did not borrow {book}.")
    return book_list
def get_borrow_history(history):
    return history
def get_available_books(book_list):
    return book_list
def get_registered_members(member_list):
    return member_list
member_list = []
book_list = []
history = []
while True:
    print("\nLibrary Management System")
    print("1. Add Book")
    print("2. Remove Book")
    print("3. Add Member")
    print("4. Remove Member")
    print("5. Borrow Book")
    print("6. Return Book")
    print("7. View Borrow History")
    print("8. View Available Books")
    print("9. View Registered Members")
    print("10. Exit")
    choice = input("Enter your choice: ")
    if choice == '1':
        book = input("Enter book name to add: ")
        book_list = add_book(book_list, book)
        print(f"{book} added to the library.")
    elif choice == '2':
        book = input("Enter book name to remove: ")
        book_list = remove_book(book_list, book)
    elif choice == '3':
        member = input("Enter member name to add: ")
        member_list = add_member(member_list, member)
        print(f"{member} added as a member.")
    elif choice == '4':
        member = input("Enter member name to remove: ")
        member_list = remove_member(member_list, member)
    elif choice == '5':
        book = input("Enter book name to borrow: ")
        member = input("Enter member name: ")
        book_list = borrow_book(book_list, member_list, book, member, history)
    elif choice == '6':
        book = input("Enter book name to return: ")
        member = input("Enter member name: ")
        book_list = return_book(book_list, member_list, book, member, history)
    elif choice == '7':
        print("Borrow History:")
        for record in get_borrow_history(history):
            print(f"{record[0]} borrowed {record[1]}")
            print(f"{record[0]} returned {record[1]}")
    elif choice == '8':
        print("Available Books:")
        for book in get_available_books(book_list):
            print(book)
    elif choice == '9':
        print("Registered Members:")
        for member in get_registered_members(member_list):
            print(member)
    elif choice == '10':
        break
    else:
        print("Invalid choice. Please try again.")