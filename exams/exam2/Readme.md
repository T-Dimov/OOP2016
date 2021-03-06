#Контротлна 2 по ООП-практикум

Решенията на задачите се предават по e-mail на следния адрес:

* ttassist@abv.bg

Време за работа: 2 часа

Решението на всяка задача трябва да бъде под формата на файлове с окончание *.cpp* и *.h*, или архив на целите проекти (всяка задача да бъде в отделен solution) и ясно показват, за коя задача се отнасят. Файловете се изпращат като attachment-и в mail-a. Освен решения на задачите самият mail трябва да съдържа име и факултен номер, написани на кирилица (както и всякакъв друг текст). Успех!

## Задача

Реализирайте следните класове:

Абстрактен клас `RailwayStation`, които има следните член данни:
* име - низ с произволна дължина
* местоположение - град(низ с произволна дължина)
* брой коловози - цяло число

Клас `PassengerStation`, което е вид гара и има допълнителни характеристики:
* брой пътници, които може да поеме един коловоз
* maximumIncome - връща брой пътници * брой коловози * 0.322

Клас `CargoStation`, което е вид гара и има допълнителни характеристики:
* колко тона може да поеме един коловоз- цяло число
* maximumIncome - връща тонове товар * брой коловози * 0.69

Има и смесени гари, които могат да бъдат използвани и като товарни, и като пътнически `PCStation`.
* maximumIncome - връща (брой пътници + товар) * брой коловози / 1.8

Реализирайте за всеки клас:
* `get` и `set` методи за всички характеристики 
* канонично представяне, където е необходимо
* конструктор с параметри за всички член-данни

Клас `RailwayNetwork`, който съдържа динамичен масив от гари. С методи:
* добавяне на гара
* получаващ брой пътници и връща отговор дали гарите могат да поемат подаденият брой пътници. Да се напише подобен метод и за товарите.
* maximumTotalIncome, който пресмята максималния общ приход на гарите от мрежата, като събира максималните им приходи.
