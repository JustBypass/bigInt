//
// Created by Admin on 22.10.2021.
//

#ifndef CMAKE_TUR_MENU_H
#define CMAKE_TUR_MENU_H


template<typename T>
int getNum(T& a)
{
    int rc = 0;
    std::cin >> a;
    if (!std::cin.good())
        rc = 1; // Обнаружена ошибка ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return rc;
};

template<class T>
class menu {

private:
    T cl;
    std::string _menu = "1.Get_Sum\n"
                        "2.Minus_function:\n"
                        "3.Divide_on_10\n"
                        "4.Multiply_on_10\n"
                        "5.Change_quantity\n"
                        "6.Enter_number\n"
                        "7.Get_number:\n";
    std::string _choose = "--->Choose the variant:\n";
    std::string _error = "You are wrong,repeat!\n";
    std::string _chooseConstr = "--->Choose your constructot\n";
    std::string _choosingConstrMenu =
            "1.By the string\n"
            "2.By the long long\n"
            "3.By the int\n";
public:
    int mainloop() {
        try {
            int r = 1;
            T _num;
            int ch;
            while(true){
                std::cout<<_choosingConstrMenu ;
                std::cout<<_chooseConstr;
                getNum(ch);
                if(ch == 1)
                {
                    _num = "0";
                    break;
                }
                else if(ch == 2){
                    _num = (long long)0;
                    break;
                }
                else if(ch == 3){
                    _num = (int)0;
                    break;
                }
            }
            int rc = 1;
            bool flag = true;
            while(true){
                if(rc == 0)
                    break;
                std::cout << _menu;
                do {
                    std::cout << _choose;
                    getNum(rc);
                    if (rc == 0)
                        break;
                    if (rc > 7 || rc < 0) {
                        std::cout << _error;
                        break;
                    }
                    switch (rc) {
                        case 1: {
                            T a(0);
                            std::cout << "Enter number:";
                            std::cin >> a;
                            _num = (_num + a);
                            break;
                        }
                        case 2:{	T a("0");
                            std::cout << "Enter number to minus:\n";
                            std::cin >> a;
                            _num = (_num - a);
                            break;
                        }
                        case 3:
                        {
                            _num >>= 1;//>>=
                            std::cout << _num;
                            break;
                        }
                        case 4:
                        {
                            std::cout << _num;
                            _num <<= 1;
                            break;
                        }
                        case 5:{
                            std::cin >> _num;

                            break;
                        }
                        case 6:{
                            _num.returnExternal();
                            std::cout << std::endl;
                            break;
                        }
                        case 7: {	std::cout << "Your number:" << _num << std::endl; break; }	}
                    break;
                } while (true);

            }
        }
        catch (...) {
            std::cerr<< "Unknown error occured!\n";
            return -1;
        }
        return 0;
    }
};
#endif //CMAKE_TUR_MENU_H
