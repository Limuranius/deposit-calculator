#include <iostream>

double getPercentage(int months) {
    switch(months) {
        case 1:
            return 0.02;
        case 3:
            return 0.03;
        case 6:
            return 0.045;
        case 12:
            return 0.055;
        default:
            return -1;
    }
}

bool checkDeposit(double deposit) {
    return (deposit >= 10000) && (deposit <= 500000);
}

bool checkMonths(int months) {
    return (months == 1) || (months == 3) || (months == 6) || (months == 12);
}

int main() {
    double percentage;
    double deposit;
    double initDeposit;
    int months;

    bool depositCorrectFlag;
    bool monthsCorrectFlag;

    do {
        std::cout << "Введите размер депозита: ";
        std::cin >> deposit;
        depositCorrectFlag = checkDeposit(deposit);
        if (!depositCorrectFlag) {
            std::cout << "Данные введены неверно. Попробуйте снова\n";
        }
    } while (!depositCorrectFlag);

    do {
        std::cout << "Введите кол-во месяцев: ";
        std::cin >> months;
        monthsCorrectFlag = checkMonths(months);
        if (!monthsCorrectFlag) {
            std::cout << "Данные введены неверно. Попробуйте снова\n";
        }
    } while (!monthsCorrectFlag);

    percentage = getPercentage(months);
    initDeposit = deposit;

    for (int i = 0; i < months; i++) {
        deposit *= 1.0 + percentage;
    }

    std::cout << "Ваш изначальный депозит: " << initDeposit << std::endl;
    std::cout << "Размер вклада через " << months << " мес.: " << deposit << std::endl;
    std::cout << "Ваш доход: " << deposit - initDeposit << std::endl;
}
