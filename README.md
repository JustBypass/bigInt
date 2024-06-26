## Класс "Большое десятичное число"

### Состояние класса
Класс "Большое десятичное число" хранит длину числа (количество цифр) и массив значений десятичных цифр в прямом коде. Память под массив выделяется статически.

### Протокол класса

#### Конструкторы:
- Пустой конструктор
- Конструктор с инициализацией значения типа long
- Конструктор с инициализацией значения как строки символов

#### Методы:
- Ввод числа из входного потока
- Вывод значения числа в выходной поток
- Получение дополнительного кода числа
- Сложение и вычитание чисел
- Деление на 10
- Умножение на 10

### Перегруженные операторы
- Оператор сложения
- Оператор вычитания
- Оператор умножения

### Дополнительные возможности
- Копирующий конструктор
- Перегруженный оператор присваивания

### Прикладная программа
Разработать прикладную программу, использующую класс "Большое десятичное число" для выполнения задания, согласованного с преподавателем.

### Дополнительное задание
Реализовать выделение памяти динамически во время выполнения программы (с использованием указателя на char) без лишнего использования памяти.

### Диалоговая программа
Реализовать диалоговую программу для отладки и тестирования методов класса, позволяющую вводить параметры методов и обрабатывать ошибочные ситуации с помощью механизма исключений.

Чтобы собрать решение, нужно скачать googletest(https://github.com/google/googletest) и поместить его в корень решения

Далее нужно создать директорию build командой:
```
mkdir build
```

Если вы хотите запустить графическое приложение на Qt, необходимо в cmakelists в в основной директории сменить значение VAR на "5",далее перейти в директорию build, где необходимо выполнить команду в терминале:

```
make ../
```

После успешной сборки:
```
cmake --build .
```
