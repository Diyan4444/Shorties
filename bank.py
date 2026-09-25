def add_user(user_list, user, password, password_list,history_list):
    if user not in user_list:
        user_list.append(user)
        password_list.append(password)
        history_list.append(["User added"])
        print(f"{user} added to the system.")
    else:
        print(f"{user} is already in the system.")
    return user_list



def remove_user(user_list, user,password_list, password,history_list,balance_list):
    if user in user_list:
        index = user_list.index(user)
        if password_list[index] != password:
            print("Incorrect password.")
            return user_list
        user_list.pop(index)
        password_list.pop(index)
        history_list.pop(index)
        balance_list.pop(index)
        print(f"{user} removed from the system.")
    else:
        print(f"{user} is not in the system.")
    return user_list


def login(user_list, password_list, user, password):
    if user in user_list:
        index = user_list.index(user)
        if password_list[index] == password:
            print(f"{user} logged in successfully.")
            return True
        else:
            print("Incorrect password.")
            return False
    else:
        print(f"{user} is not registered.")
        return False


def deposit(user_list, password_list, user, password, amount, balance_list, history_list):
    if login(user_list, password_list, user, password):
        index = user_list.index(user)
        balance_list[index] += amount
        print(f"{amount} deposited. New balance: {balance_list[index]}")
        history_list[index].append(f"user {user} Deposit: {amount}")
    else:
        print("Deposit failed due to login error.")
        return
    return balance_list

def withdraw(user_list, password_list, user, password, amount, balance_list, history_list):
    if login(user_list, password_list, user, password):
        index = user_list.index(user)
        if balance_list[index] >= amount:
            balance_list[index] -= amount
            print(f"{amount} withdrawn. New balance: {balance_list[index]}")
            history_list[index].append(f"user {user} Withdraw: {amount}")
        else:
            print("Insufficient funds.")
    else:
        print("Withdrawal failed due to login error.")
    return balance_list


def search_user(user_list, user):
    if user in user_list:
        print(f"{user} is registered.")
    else:
        print(f"{user} is not registered.")


def transfer(user_list, password_list, user_from, user_to, amount, balance_list, history_list):
    if user_from in user_list and user_to in user_list:
        index_from = user_list.index(user_from)
        index_to = user_list.index(user_to)
        if balance_list[index_from] >= amount:
            balance_list[index_from] -= amount
            balance_list[index_to] += amount
            print(f"{amount} transferred from {user_from} to {user_to}.")
            history_list[index_from].append(f"user {user_from} Transfer: {amount} to {user_to}")
            history_list[index_to].append(f"user {user_to} Received: {amount} from {user_from}")
        else:
            print("Insufficient funds for transfer.")
    else:
        print("One or both users are not registered.")
    return balance_list


def get_transaction_history(user_list, user, history_list):
    if user in user_list:
        index = user_list.index(user)
        return history_list[index]
    else:
        print(f"{user} is not registered.")
        return []


def get_balance(user_list, user, balance_list):
    if user in user_list:
        index = user_list.index(user)
        return balance_list[index]
    else:
        print(f"{user} is not registered.")
        return None


def account_details(user_list, user, balance_list, history_list):
    if user in user_list:
        index = user_list.index(user)
        print(f"Account details for {user}:")
        print(f"Balance: {balance_list[index]}")
        print("Transaction History:")
        for transaction in history_list[index]:
            print(transaction)
    else:
        print(f"{user} is not registered.")

user_list = []
password_list = []
balance_list = []
history_list = []
while True:
    print("\nBank Management System")
    print("1. Add User")
    print("2. Remove User")
    print("3. Deposit")
    print("4. Withdraw")
    print("5. Transfer")
    print("6. Search User")
    print("7. View Transaction History")
    print("8. View Balance")
    print("9. Account Details")
    print("10. Exit")
    choice = input("Enter your choice: ")
    
    if choice == '1':
        user = input("Enter username to add: ")
        password = input("Enter password for the user: ")
        user_list = add_user(user_list, user, password, password_list, history_list)
        balance_list.append(0)  # Initialize balance for new user
    elif choice == '2':
        user = input("Enter username to remove: ")
        password = input("Enter password for the user: ")
        user_list = remove_user(user_list, user, password_list, password, history_list, balance_list)
    elif choice == '3':
        user = input("Enter username: ")
        password = input("Enter password: ")
        amount = float(input("Enter amount to deposit: "))
        balance_list = deposit(user_list, password_list, user, password, amount, balance_list, history_list)
    elif choice == '4':
        user = input("Enter username: ")
        password = input("Enter password: ")
        amount = float(input("Enter amount to withdraw: "))
        balance_list = withdraw(user_list, password_list, user, password, amount, balance_list, history_list)
    elif choice == '5':
        user_from = input("Enter sender's username: ")
        user_to = input("Enter receiver's username: ")
        amount = float(input("Enter amount to transfer: "))
        balance_list = transfer(user_list, password_list, user_from, user_to, amount, balance_list, history_list)
    elif choice == '6':
        user = input("Enter username to search: ")
        search_user(user_list, user)
    elif choice == '7':
        user = input("Enter username to view transaction history: ")
        transactions = get_transaction_history(user_list, user, history_list)
        for transaction in transactions:
            print(transaction)
    elif choice == '8':
        user = input("Enter username to view balance: ")
        balance = get_balance(user_list, user, balance_list)
        if balance is not None:
            print(f"Balance for {user}: {balance}")
    elif choice == '9':
        user = input("Enter username to view account details: ")
        account_details(user_list, user, balance_list, history_list)
    elif choice == '10':
        print("Exiting the system.")
        break
    