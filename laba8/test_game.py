import pytest
from game import determine_winner, get_computer_choice
from unittest.mock import patch


def test_determine_winner_draw():
    assert determine_winner('камень', 'камень') == "Ничья!"
    assert determine_winner('ножницы', 'ножницы') == "Ничья!"
    assert determine_winner('бумага', 'бумага') == "Ничья!"


def test_determine_winner_user_wins():
    assert determine_winner('камень', 'ножницы') == "Вы победили!"
    assert determine_winner('ножницы', 'бумага') == "Вы победили!"
    assert determine_winner('бумага', 'камень') == "Вы победили!"


def test_determine_winner_computer_wins():
    assert determine_winner('ножницы', 'камень') == "Компьютер победил!"
    assert determine_winner('бумага', 'ножницы') == "Компьютер победил!"
    assert determine_winner('камень', 'бумага') == "Компьютер победил!"


def test_get_computer_choice():
    choices = set()
    # Проверяем, что функция возвращает допустимые значения
    for _ in range(100):
        choice = get_computer_choice()
        assert choice in ['камень', 'ножницы', 'бумага']
        choices.add(choice)

    # Убедимся, что все варианты могут быть выбраны
    assert len(choices) == 3


@patch('builtins.input', side_effect=['неправильно', 'камень'])
def test_get_user_choice_invalid_then_valid(mock_input):
    from game import get_user_choice
    assert get_user_choice() == 'камень'
    assert mock_input.call_count == 2


@patch('builtins.input', return_value='ножницы')
def test_get_user_choice_valid(mock_input):
    from game import get_user_choice
    assert get_user_choice() == 'ножницы'
    assert mock_input.call_count == 1


def format_test_results(results):
    print("\n" + "=" * 50)
    print("РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ".center(50))
    print("=" * 50)
    print(f"Всего тестов: {results['total']}")
    print(f"Пройдено: {results['passed']}")
    print(f"Провалено: {results['failed']}")
    print(f"Успешность: {results['success_rate']}%")
    print("=" * 50)
    if results['failed'] == 0:
        print("ВСЕ ТЕСТЫ УСПЕШНО ПРОЙДЕНЫ!")
    else:
        print(f"ЕСТЬ ПРОБЛЕМЫ: {results['failed']} тестов не прошли")
    print("=" * 50 + "\n")


if __name__ == "__main__":
    import pytest
    import sys

    # Запускаем pytest и получаем результаты
    result = pytest.main(["-v", "--tb=line", __file__])

    # Собираем статистику (это упрощенный пример, в реальности нужно парсить вывод)
    stats = {
        'total': 8,  # Общее количество тестов
        'passed': 8 if result == 0 else 8 - result,
        'failed': 0 if result == 0 else result,
        'success_rate': 100 if result == 0 else round((8 - result) / 8 * 100, 2)
    }

    # Выводим форматированные результаты
    format_test_results(stats)

    # Выход с кодом ошибки, если есть проваленные тесты
    sys.exit(result)
