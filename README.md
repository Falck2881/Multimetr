# :zap: Multimetr :zap: 

> Сразу уточним данное приложение ничего общего с физическим измерительным прибором не имеет.
> Нужно было выдумать прибор который может параллельно вычислять на разных **N** каналах напряжение. Так и появился :stars: Multimetr.

- Данное приложение явлется частью реализации `application client-server`, в нашем случаи мы `client`.
- Где тогда `server` он тут - https://github.com/Falck2881/ServerMultimetr

___

## OC

Только симейство Linux

## :clapper: Start 

* Step 1 - Запустите `server` - https://github.com/Falck2881/ServerMultimetr

**Example**
```
  $ cd ServerMultimetr
  $ ./ServerMultimetr.sh
```
___

* Step 2 - Запустите приложение Multimetr в любом из следующих режимов `shell | GUI`
 
**Example**
```
  $ cd Multimetr
  $ ./Multimetr.sh GUI
```
> Вы всегда можете воспользоваться командой `help`

___

## Example execution the program ##

* Вывод сервера 

![изображение](https://github.com/Falck2881/Multimetr/assets/100667839/a9ac9e40-ca00-4acb-980c-246831c15b52)

* Приложение в режиме `GUI` 

![изображение](https://github.com/Falck2881/Multimetr/assets/100667839/7d0a9e1e-31d6-4360-b412-76e45429ea0c)

* Вывод приложения в режиме `shell` 

![изображение](https://github.com/Falck2881/Multimetr/assets/100667839/eccdd233-813a-4d10-9a03-b34bff388ad9)

> Как можно заметить в shell нам нужно использовать команды и соответствующие параметры чтобы работать с приложением 

___

## How this working ##

**Самое важеное что стоит помнить что все взаимодействие происходит внутри ядра.**

* Step 1 - Клиент создаёт на своей стороне доменный сокет Unix. Далее ОС вернул нам 
  файловый дескриптор, он нам понадобиться чтобы работать с сокетом. 
```C++
void Socket::create()
{
    socket_fd = Sys::createSocket(AF_UNIX,SOCK_STREAM,0);

    if(technicalSupport.exists(socket_fd)){
        memset(&domain,0,sizeof(domain));
        domain.sun_family = AF_UNIX;
        strncpy(domain.sun_path, pathToAddress.data(), sizeof(domain.sun_path) - 1);
    }
}
```
* Step 2 - Подключаемся к домену(адрессу) используя наш файловый дескриптор 
```C++
bool Socket::connect()
{
    const int result{Sys::connectWithServer(socket_fd, domain)};

    if(technicalSupport.successfullyConnection(result))
        return true;
    else{
        close();
        return false;
    }
}
```
* Step 3 - Если все хорошо то мы увидим приглашение на ввод в режиме shell или окно GUI.
  Если все плохо то вы забыли подключиться к серверу, и будут выводиться сообщения о попытке подключения к серверу.
  Вам надо будет подключиться к серверу чтобы пользоваться в дальнейшем приложением. 
