### 🔐 **Название проекта:** **SimpleAuthTCP**  

### 📜 **Описание проекта:**  
**SimpleAuthTCP** — это учебный клиент-серверный проект, реализующий простую систему аутентификации пользователей через TCP-сокеты с использованием WinSock2. Клиент позволяет пользователям регистрироваться и входить в систему, отправляя запросы серверу, который обрабатывает их и возвращает соответствующий ответ.  

Проект создан в рамках учебной работы студента **KDG**.  

### 🚀 **Функционал:**  
✅ Регистрация пользователей  
✅ Вход в систему  
✅ Обмен данными между клиентом и сервером по TCP  
✅ Минимальные зависимости (WinSock2)  

### 🛠 **Как запустить:**  
1. Скомпилируйте и запустите сервер (**server.exe**).  
2. Скомпилируйте и запустите клиент (**client.exe**).  
3. Взаимодействуйте через консольный интерфейс (регистрация, вход).  

### 📌 **Требования:**  
- Windows  
- Компилятор с поддержкой **C++** и **WinSock2**  
- Microsoft Visual Studio (рекомендуется)  

### 📂 **Структура проекта:**  
```
/SimpleAuthTCP
│── client.cpp   # Код клиента
│── server.cpp   # Код сервера
│── README.md    # Описание проекта
│── LICENSE      # Лицензия
```

---

## 📝 **Лицензия**  
Этот проект распространяется под лицензией **MIT**.  

### 📜 **MIT License**  

```
Copyright (c) 2025 KDG

Данная лицензия разрешает лицам, получившим копию данного программного обеспечения и сопутствующей документации (в дальнейшем именуемыми "Программное Обеспечение"), безвозмездно использовать Программное Обеспечение без ограничений, включая неограниченное право на использование, копирование, изменение, объединение, публикацию, распространение, сублицензирование и/или продажу копий Программного Обеспечения, а также предоставление лицам, которым предоставляется данное Программное Обеспечение, этих прав, при соблюдении следующих условий:

Указанное выше уведомление об авторских правах и данные условия должны быть включены во все копии или значимые части данного Программного Обеспечения.

ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ "КАК ЕСТЬ", БЕЗ КАКИХ-ЛИБО ГАРАНТИЙ, ЯВНЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ ОГРАНИЧИВАЯСЬ, ГАРАНТИЯМИ КОММЕРЧЕСКОЙ ПРИГОДНОСТИ, СООТВЕТСТВИЯ ОПРЕДЕЛЕННОЙ ЦЕЛИ И НЕНАРУШЕНИЯ ПРАВ. НИ В КОЕМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ ОТВЕТСТВЕННОСТИ ПО ИСКАМ, УЩЕРБАМ ИЛИ ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ В СЛЕДСТВИИ ИСПОЛЬЗОВАНИЯ ДАННОГО ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
```  
