import numpy as np

def add_item(item_list, item,id_list, id,stock_list,stock,history_list):
    if item not in item_list:
        item_list.append(item)
        id_list.append(id)
        stock_list.append(stock)
        history_list.append(f"added({item}, {id}, {stock})")
        print(f"{item} added to the list.")
    else:
        print(f"{item} is already in the list.")
    return item_list

def remove_item(item_list, item,id_list,stock_list,history_list):
    if item in item_list:
        index = item_list.index(item)
        item_list.pop(index)
        id_list.pop(index)
        stock_list.pop(index)
        history_list.pop(index)
        print(f"{item} removed from the list.")
    else:
        print(f"{item} is not in the list.")
    return item_list

def update_stock(item_list, item, new_stock, stock_list,history_list,id_list):
    if item in item_list:
        index = item_list.index(item)
        stock_list[index] = new_stock
        history_list.append(f"updated({item}, {id_list[index]}, {new_stock})")
        print(f"Stock for {item} updated to {new_stock}.")
    else:
        print(f"{item} is not in the list.")
    return stock_list

def search_item(item_list, item):
    if item in item_list:
        print(f"{item} is available in the list.")
    else:
        print(f"{item} is not available in the list.")

def sell_product(item_list, item, id_list, stock_list, quantity, history_list):
    if item in item_list:
        index = item_list.index(item)
        if stock_list[index] >= quantity:
            stock_list[index] -= quantity
            history_list.append(f"sold({item}, {id_list[index]}, {quantity})")
            print(f"{quantity} of {item} sold. Remaining stock: {stock_list[index]}")
        else:
            print(f"Not enough stock for {item}. Available: {stock_list[index]}")
    else:
        print(f"{item} is not available in the list.")
    return stock_list


def warning(item_list, stock_list, threshold):
    for i in range(len(item_list)):
        if stock_list[i] < threshold:
            print(f"Warning: Stock for {item_list[i]} is below the threshold of {threshold}. Current stock: {stock_list[i]}")
        else:
            print(f"Stock for {item_list[i]} is above the threshold. Current stock: {stock_list[i]}")


np.stock_list = []
np.item_list = []
np.id_list = []
np.history_list = []
threshold = int(input("Enter stock threshold: "))

while True:
    print("\nShop Management System")
    print("1. Add Item")
    print("2. Remove Item")
    print("3. Update Stock")
    print("4. Search Item")
    print("5. Sell Product")
    print("6. History")
    print("7. Exit")

    choice = input("Enter your choice: ")
    
    if choice == '1':
        item = input("Enter item name to add: ")
        id = input("Enter item ID: ")
        stock = int(input("Enter initial stock: "))
        np.item_list = add_item(np.item_list, item,np.id_list, id,np.stock_list,stock,np.history_list)
    
    elif choice == '2':
        item = input("Enter item name to remove: ")
        np.item_list = remove_item(np.item_list, item,np.id_list,np.stock_list,np.history_list)
    
    elif choice == '3':
        item = input("Enter item name to update stock: ")
        new_stock = int(input("Enter new stock value: "))
        np.stock_list = update_stock(np.item_list, item, new_stock,np.stock_list,np.history_list,np.id_list)
    
    elif choice == '4':
        item = input("Enter item name to search: ")
        search_item(np.item_list, item)
    
    elif choice == '5':
        item = input("Enter item name to sell: ")
        quantity = int(input("Enter quantity to sell: "))
        np.stock_list = sell_product(np.item_list, item,np.id_list,np.stock_list, quantity,np.history_list)
        warning(np.item_list, np.stock_list, threshold)


    elif choice == '6': 
        for i in np.history_list:
            print(i)
    
    elif choice == '7':
        print("Exiting Shop Management System.")
        break

    else:
        print("Invalid choice. Please try again.")
