# FChat
This is a simple C++ chat program built for learning purposes. The program uses Client/Server communication paradigm. The server listens to port 50885 and accepts unlimited number of connections (clients). The received message from any client is sent to all connected clients. Clients can be run from different computers in the same local or wide network, but the project was only tested using the same computer (Ubuntu 18.04.5 LTS x86_64) and different terminals for each client (127.0.0.1 loopback IP was used for the server address).



<p align="center">
<img align="center" src="https://user-images.githubusercontent.com/45536639/119264821-573a1680-bbed-11eb-818f-0f69092156f1.png"> 
</p>

## Prerequisites

FBrowser is built with Qt Creator 4.5.2, based on Qt 5.9.5 (GCC 7.3.0, 64 bit), on Ubuntu 18.04.5 LTS (x86_64)

## Running 
Build the project for your machine with the version of Qt creator mentioned above. If you have the same machine you can run the executables ``` ./Client ``` and ``` ./Server ``` found in ``` build-Client-Desktop-Debug ``` and ``` build-Server-Desktop-Debug directories ``` directories. The server should be started before the clients.

## Authors

* **Fedi Salhi** [FediSalhi](https://github.com/FediSalhi)
