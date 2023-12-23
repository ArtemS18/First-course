#include <iostream>
#include <string>
using namespace std;

int daytime_c(short hour) {//функция для определения времени суток
    if (5 <= hour && hour < 12) {
        cout<< "утра ";
    }
    else if (12 <= hour && hour < 18) {
        cout<< "дня ";
    }
    else if (18 <= hour && hour <= 23) {
        cout<< "вечера ";
    }
    else {
        cout<< "ночи ";
    }
    return 0;
}

int hour_pad(short hour) {//функция для склонения слова "час"
    if (hour == 1 || hour == 21) {
        cout<<"час ";
    }
    else if (2 <= hour && hour <= 4 || 22 <= hour && hour <= 23) {
        cout<<"часа ";
    }
    else{
        cout<<"часов ";
    }
    return 0;
}

int minut_pad(short minut) {//функция для склонения слова "минута"
    short ost = minut % 10;
    if (minut == 0) {
        cout<<"ровно";
    }
    else if (ost == 0 || 5 <= ost && ost <= 9 || 11 <= minut && minut <= 14) {
        cout << "минут ";
    }
    else if (ost == 1) {
        cout << "минута ";
    }
    else {
        cout << "минуты ";
    }

    return 0;
}

short tip_hour(short hour){//функция для перевода часов из формата "24" в формат "12-12"
    short ans_hour = 0;
    if ((hour == 0) || (hour == 12 )) {
        ans_hour = 12;
    }
    else if (0<=hour&&hour<12) {
        ans_hour = hour;
    }
    else {
        ans_hour = hour - 12;
    }
    return ans_hour;
}

short main()
{
    while (1) {
        system("chcp 1251 > nul");
        short hour, minut, hour_lite;
        cin >> hour;
        cin >> minut;

        if (!(0 <= hour && hour <= 23 && 0 <= minut && minut <= 59)) {
            cout << hour << " ";
            cout << minut << " ";
            cout << "- введены недопустимые данные." << endl;
            break;
        }

        if (hour == 12 && minut == 00) {
            cout << "полдень" << endl;
            break;
        }
        else if (hour == 00 && minut == 00) {
            cout << "полночь" << endl;
            break;
        }

        hour_lite = tip_hour(hour);

        cout << hour_lite << " ";
        hour_pad(hour_lite);

        if (minut!=0) {
            cout << minut << " ";
            minut_pad(minut);
            daytime_c(hour);
            cout << endl;
        }
        else {
            daytime_c(hour);
            minut_pad(minut);
            cout << endl;
        }
    }
}