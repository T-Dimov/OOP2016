#Домашна работа №4


## Задачи

Решенията на задачите се предават по e-mail на следния адрес:

* ttassist@abv.bg

Срок за предаване: 10.06.2016

Решението на всяка задача трябва да бъде под формата на файлове с окончание *.cpp* и *.h*, или архив на целите проекти (всяка задача да бъде в отделен solution) и ясно показват, за коя задача се отнасят. Файловете се изпращат като attachment-и в mail-a. Освен решения на задачите самият mail трябва да съдържа име и факултен номер, написани на кирилица (както и всякакъв друг текст). Успех!


### Задача 1
#### D.D.D.
Да се реализира клас ```Engineer```. Всеки инженер има:
* ```name``` - символен низ с произволна дължина.
* ```yearsOfService``` - цяло неотрицателно число.
* ```getSalary``` - връща години стаж * 2 + 500.


Да се реализира клас ```Mentor```. **Менторите са инженери**, които обучават стажанти. Всеки ментор има:
* ```numberOfInterns``` - цяло неотрицателно число.
* ```getSalary``` - връща брой стажанти * 3 + 100.


Да се реализира клас ```QA``` - **Също са инженери**. Всеки QA има:
* ```numberOfTests``` - цяло неотрицателно число.
* ```getSalary``` - връща брой написани тестове + 200.

Да се дефинира клас ```Manager```. **Едновременно ментор и QA**. Нека класът има:
* ```title``` - символен низ с произволна дължина.
* ```numberOfProjects``` - цяло неотрицателно число.
* ```getSalary``` - връща броя на проектите * 3 + 1000.

Реализирайте за всеки клас:
* `get` и `set` методи за всички характеристики 
* канонично представяне, където е необходимо
* конструктор с параметри за всички член-данни


### Задача 2
#### Polymorph: Engineer
Да се реализира клас ```Company```, който да представлява масив от инженери (включително ментори, QA и мениджъри). Класът да се състои от:
* ```size``` - брой инженери в компанията
* ```capacity``` - максимален възможен брой инженери (при необходимост се увеличава)
* ```engineers``` - масив от указатели към **копия** на инженери
* ```totalSalary``` - връща общата заплата на инженерите в компанията 
* ```add``` - добавя инженер към компанията 

Успех!
