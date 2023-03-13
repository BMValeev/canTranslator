Данная программа служит для приема и ретрансляции сообщений по can шине


## Структура

Само приложение состоит из 5 классов:

**canString** класс для анализа и работы со строкой can

**udpSender** класс для отправления данных по udp

**argParser** класс для анализа входных данных и ввода их в приложение как параметры для работы программы

**dataLoader** класс для сохранения и загрузки неотправленных сообщений

**processController** класс который осуществляет основную логику работы приложения

## Сборка:

*mdkir build; cd build; cmake ../; make;*

Для запуска желательно скопировать файл куда сохраняются неотправленные сообщения, чтобы при перезапуске они отправились еще раз

*cp ../log.txt .;*


## Тесты

Сделал два теста на проверку canString и udpSender

Тесты сделаны на **boost**. Если тесты не активны, то библиотека не требуется.

Сборка с тестами активируется запуском cmake с опцией -DENABLE_TESTS=1. После чего собирается цель test_canTranslator

*mdkir build; cd build; cmake -DENABLE_TESTS=1 ../; make test_canTranslator;*


