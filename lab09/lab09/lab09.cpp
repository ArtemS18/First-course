#include <iostream>
#include <fstream>
using namespace std;

const int max_size = 100;
const int l_word = 31;

struct Dictionary {
    char* eng;
    char* rus;

};

Dictionary dict[max_size];
int len = 0;

int Menu() {
    int choose;
    cout << "\n\nВведите число от 1 до 8: ";

    if (cin >> choose) {

    }
    else {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return choose;
}

bool Equals(char * element, char* word) {
    bool f2 = 1;
    if (strlen(element) == strlen(word)) {
        for (int g = 0; g < strlen(word) + 1; g++) {
            if (element[g] != word[g]) {
                f2 = 0;
                break;
            }

        }

    }
    else {
        f2 = 0;
    }
    return f2;
}

int CheckWord( char * word, int mode) {
    for (int i = 0; i < len; i++) {
        if (mode == 1) {
            if (Equals(dict[i].eng, word)) {
                return i;
            }
        }
        else if (mode == 2) {
            if (Equals(dict[i].rus, word)) {
                return i;
            }
        }
      
        else if (mode == 3) {
            if (Equals(dict[i].rus, word) || Equals(dict[i].eng, word)) {
                return i;
            }
        }

    }
    return -1;

}

void Copy(char* s1, char* s2) {
    for (int i = 0; i < strlen(s1) + 1; i++) {
        s1[i] = s2[i];
    }
}

bool Compare(char* word1, char* word2) {
    bool f = true;
    int minlen = min(strlen(word1), strlen(word2));
    for (int i = 0; i < minlen; i++) {
        if (int(word1[i]) > int(word2[i])) {
            return true;
        }
        else if (int(word1[i]) < int(word2[i])) {
            return false;
        }
    }
}

void Sorted(){
    for (int i = 0; i < len; i++) {
        for (int g = 0; g < len - i-1; g++) {
            if (Compare(dict[g].eng, dict[g+1].eng)) {
                swap(dict[g], dict[g + 1]);
            }
        }
    }
}


void AddWord() {

    char* eng = new char[l_word], * rus = new char[l_word];
    cout << "Введите слово на ангийском: ";cin >> eng;
    cout << "Введите слово на русском: ";cin >> rus;

    bool f = true;

    for (int i = 0; i < len; i++) {
        if (CheckWord( eng, 1) != -1) {
            f = false;
            break;
        }
    }
   
    if (f) {

        dict[len].eng = new char[strlen(eng) + 1];
        dict[len].rus = new char[strlen(rus) + 1];

        Copy(dict[len].eng, eng);
        Copy(dict[len].rus, rus);
        len++;
        Sorted();
    }
    else {
        cout << "Слово " << eng << " уже есть в словаре." << endl;
    }
}
void AddWord(char *eng, char* rus) {

    bool f = true;

    for (int i = 0; i < len; i++) {
        if (CheckWord(eng, 1) != -1) {
            f = false;
            break;
        }
    }

    if (f) {

        dict[len].eng = new char[strlen(eng) + 1];
        dict[len].rus = new char[strlen(rus) + 1];

        Copy(dict[len].eng, eng);
        Copy(dict[len].rus, rus);
        len++;
        Sorted();
    }
    else {
        cout << "Слово " << eng << " уже есть в словаре." << endl;
    }
}

void PrintAllDict() {
    for (int g = 0; g < len; g++) {
        cout << dict[g].eng << ' ' << dict[g].rus << endl;
    }
}
void RemoveWord() {
    char word[l_word];
    cout << "Что удалить?: "; cin >> word;
    int index = CheckWord( word, 3);

    if (index != -1) {
        Dictionary copy;
        for (int i = index; i < len; i++) { 
            copy = dict[i + 1];
            dict[i] = copy;
        }
        len--;
        cout << "Слово " << word << " удалено."<<endl;
    }
    else {
        cout << "Слово " << word << " не найдено."<<endl;
    }

}

void SaveDict() {
    ofstream f;
    const char filename[] = "dict.txt";
    f.open(filename, ios::binary);

    for (int i = 0; i < len; i++) {
        cout << dict[i].eng << ' ' << dict[i].rus;
        f << dict[i].eng<< " "<< dict[i].rus << " \n";
    }
    f.close();
    cout << "Словарь сохранен в " << filename << endl;

}

void getWord(char* line, char* word, int &index) {
    int l_line = strlen(line) + 1;
    int index_w = 0;
    while (line[index] != ' ' && line[index]!= '\n' && line[index]!='\0') {
        word[index_w] = line[index];
        index++;index_w++;
    }
    word[index_w] = '\0';
    index ++;
}



void DownloadDict() {
    ifstream f;
    const char filename[] = "dict.txt";
    f.open(filename, ios::binary);

    char line[l_word * 2 + 2];
    char eng[l_word], rus[l_word];

    while (f.getline(line, l_word*2+2)) {
        int index = 0;
        getWord(line, eng, index);
        getWord(line, rus, index);
        AddWord(eng, rus);
    }
    cout << "Успешно загружен словарь из " << filename << endl;
}

void Translete(int mode) {
    if (mode == 1) {
        char eng_word[l_word];
        cout << "Введите слово на английском: ";cin >> eng_word;

        int index = CheckWord(eng_word, 1);

        if (index != -1) {
            cout << "Перевод слова: "<< dict[index].rus << endl;
        }
        else {
            cout << "Слово " << eng_word << " не найдено." << endl;
        }
    }
    else if (mode == 2) {
        char rus_word[l_word];
        cout << "Введите слово на русском: ";cin >> rus_word;

        int index = CheckWord(rus_word, 2);

        if (index != -1) {
            cout << "Перевод слова: " << dict[index].eng << endl;
        }
        else {
            cout << "Слово " << rus_word << " не найдено." << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "1 - добавление слова в словарь \n"
        << "2 - удаление слова из словаря \n"
        << "3 - перевод слов с английского на русский \n"
        << "4 - перевод слов с русского на английский \n"
        << "5 - вывод на экран словаря \n"
        << "6 - сохранение словаря в файл \n"
        << "7 - загрузка словаря из файла\n"
        << "8 - выход из программы\n";
    while (true) {
        switch (Menu()) {
        case 1: AddWord(); break;
        case 2: RemoveWord(); break;
        case 3: Translete(1); break;
        case 4: Translete(2); break;
        case 5: PrintAllDict(); break;
        case 6: SaveDict(); break;
        case 7: DownloadDict(); break;
        case 8: return 0;
        default:
            cout << "Надо вводить число от 1 до 8" << endl;
            break;
        }
    }
    return 0;
}
