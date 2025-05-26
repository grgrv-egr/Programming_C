import random

def get_user_choice():
    while True:
        user_choice = input("Выберите: камень, ножницы или бумага? ").lower()
        if user_choice in ['камень', 'ножницы', 'бумага']:
            return user_choice
        print("Неверный ввод. Попробуйте еще раз.")

def get_computer_choice():
    return random.choice(['камень', 'ножницы', 'бумага'])

def determine_winner(user_choice, computer_choice):
    if user_choice == computer_choice:
        return "Ничья!"

    winning_combinations = {
        'камень': 'ножницы',
        'ножницы': 'бумага',
        'бумага': 'камень'
    }

    if winning_combinations[user_choice] == computer_choice:
        return "Вы победили!"
    else:
        return "Компьютер победил!"

def play_game():
    print("Добро пожаловать в игру 'Камень, ножницы, бумага'!")
    user_choice = get_user_choice()
    computer_choice = get_computer_choice()

    print(f"\nВаш выбор: {user_choice}")
    print(f"Выбор компьютера: {computer_choice}")

    result = determine_winner(user_choice, computer_choice)
    print(f"\nРезультат: {result}")
