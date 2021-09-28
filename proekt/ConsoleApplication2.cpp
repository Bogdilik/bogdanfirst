#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
using namespace std;
void rules();
int main()

{
    setlocale(LC_ALL, "Rus");
    string playerName;
    int balance; // Баланс игрока
    int bettingAmount;
    int guess;
    int dice; // Рандом
    char choice;
    srand(time(0)); // генерирует рандом 
    cout << "\n\t\t-------- Добрый день,путник, ты желаешь сыграть в *кости*? ---------\n\n";
    cout << "\n\nСкажи как тебя зовут: ";
    getline(cin, playerName);
    cout << "\n\nСколько у вас с собой золота?: $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nВ ваших корманах нашлось  $ " << balance << "\n";
        // Get player's betting balance
        do
        {
            cout << "Добро пожаловать в игру, " << playerName << ", Сколько хочешь поставить? : $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "\n Ты не можешь поставить Больше ,чем имеешь"
                << "\n  Хорошо подумал?... Сколько ставишь?:\n ";
        } while (bettingAmount > balance);
        // Get player's numbers
        do
        {
            cout << "Попробуй угадать сколько выпадет на игральной кости:";
            cin >> guess;
            if (guess <= 0 || guess > 6)
                cout << "\nНет,может выпасть от 1 до 6!\n"
                << "Попробуй еще раз:\n ";
        } while (guess <= 0 || guess > 6);
        dice = rand() % 6 + 1;
        if (dice == guess)
        {
            cout << "\n\n Мои поздравления,друг! Вот твой выигрыш!." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Видимо, удача не на твоей стороне $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\n На кубике число : " << dice << "\n";
        cout << "\n" << playerName << ", Твой баланс $ " << balance << "\n";
        if (balance == 0)
        {
            cout << "У кончилось все золото,уходи!  ";
            break;
        }
        cout << "\n\n-->Хочешь попробовать еще раз?  (y= Да)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "\n\nВ твоем кармане:  $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t-----Привет,друг!Вот мои правила:-----\n";
    cout << "\t1. Попробуй угадать какое число выпадет на игральной кости\n";
    cout << "\t2. Если угадаешь получишь в 10 раз больше\n";
    cout << "\t3. Попробуешь обмануть, потеряешь часть своих денег!\n\n";
}