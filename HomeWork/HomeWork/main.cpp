#include <conio.h>

void CIN(char* line, int& i) {
    char ch;
    do {
        ch = _getch();
        if ((97 <= int(ch) && int(ch) <= 122) || ch == 32) {
            line[i] = ch;
            i++;
            _putch(ch);
        }
        else if (int(ch) == 8 && i > 0) {
            i--;
            _putch(8);
            _putch(32);
            _putch(8);
        }
    } while (ch != '.');
    line[i] = '\0';
    _putch(ch);
}

void PrintWord(char* line, int index_l, int len) { //ov, ova, in, ina, ev, eva -> idze
    int g = index_l;
    int index_r;
    while (line[g] != ' ' && g < len) {
        g++;
    }
    index_r = g - 1;
    int f = 0;
    for (int i = index_l; i <= index_r; i++) {
        if (i + 1 == index_r) {
            if ((line[i] == 'o' && line[i + 1] == 'v')||
                (line[i] == 'i' && line[i + 1] == 'n')||
                (line[i] == 'e' && line[i + 1] == 'v')) {
                f = 1;
            }
        }
        else if (i + 2 == index_r) { //absov absin auidfdf auidfdf absina adcev adf auidfdf.
            if ((line[i] == 'o' && line[i + 1] == 'v' && line[i + 2] == 'a')||
                (line[i] == 'i' && line[i + 1] == 'n' && line[i + 2] == 'a')||
                (line[i] == 'e' && line[i + 1] == 'v' && line[i + 2] == 'a')) {
                f = 2;
            }
        }
    }
    for (int i = index_l; i <= index_r; i++) {
        if ((i + 1 == index_r) && f == 1) {
            _putch('i');
            _putch('d');
            _putch('z');
            _putch('e');
            break;

        }

        else if ((i + 2 == index_r) && f == 2) {
            _putch('i');
            _putch('d');
            _putch('z');
            _putch('e');
            break;

        }
        else {
            _putch(line[i]);
        }
    }
    _putch(' ');
}


int main()
{
    // gsd gg ggh gg gg gg df gg.
    //vaiov   goev        odjibud          vai   aev jdkvai vai fjkdjfkjds skdov j     vai    vai     ksdjf jk jks 
    //goev vaiov   goev        odjibud          vai   aev jdkvai vai fjkdjfkjds skdov j     vai    vai     ksdjf jk jks goev goev kjdkfj goev   .
    //      shsjdh sjhdjh ygy io io io shsjdh          .
    char* line = new char[1000];
    int len = 0;
    CIN(line, len);

    _putch('\n');
    int end_index_l = 0, end_index_r = 0;
    bool f = true;
    for (int i = len - 1; i > 0; i--) {
        if ((line[i] != ' ') && f) {
            end_index_r = i;
            f = false;
        }
        else if (line[i] == ' ' && !f) {
            end_index_l = i + 1;
            break;
        }
    }
    //std::cout << '\n' << end_index_l << ' ' << end_index_r<< len;
    int index_l, len_word = end_index_r - end_index_l + 1;
    bool wf = true;
    for (int i = 0; i < end_index_l; i++) {
        if (line[i] != ' ' && wf) {
            index_l = i;
            int k = 0;
            bool cf = true;

            while ((end_index_l + k < len) && line[index_l + k] != ' ') {
                if (line[index_l + k] != line[end_index_l + k]) {
                    cf = false;
                    //std::cout <<"err: " << line[index_l + k] <<' ' << index_l + k << ' ' << line[end_index_l + k]<<' ' << end_index_l + k << '\n';
                    break;
                }
                k++;
            }
            if (k != len_word || line[index_l + k] != ' ') {
                cf = false;
            }
            if (!cf) {
                PrintWord(line, index_l, len);
            }
            wf = false;
        }
        else if (line[i] == ' ') {
            wf = true;
        }
    }
}

// hjh iowe ui oqwqw.